#include "AIL.h"

int (__stdcall *mss32_AIL_startup)() = 0;
HREDBOOK (__stdcall *mss32_AIL_redbook_open_drive)(long) = 0;
int (__stdcall *mss32_AIL_set_preference)(unsigned int, int) = 0;
int (__stdcall *mss32_AIL_waveOutOpen)(HDIGDRIVER *, HWAVEOUT *, int, WAVEFORMAT *) = 0;
int (__stdcall *mss32_AIL_get_preference)(unsigned int) = 0;
int (__stdcall *mss32_AIL_digital_configuration)(HDIGDRIVER, int *, int *, char *) = 0;
HSAMPLE (__stdcall *mss32_AIL_allocate_sample_handle)(HDIGDRIVER) = 0;
unsigned int (__stdcall *mss32_AIL_redbook_tracks)(HREDBOOK) = 0;
int (__stdcall *mss32_AIL_redbook_volume)(HREDBOOK) = 0;
unsigned int (__stdcall *mss32_AIL_redbook_stop)(HREDBOOK) = 0;
void (__stdcall *mss32_AIL_set_digital_master_volume)(HDIGDRIVER, float) = 0;
int (__stdcall *mss32_AIL_redbook_set_volume)(HREDBOOK, int) = 0;
unsigned int (__stdcall *mss32_AIL_redbook_pause)(HREDBOOK) = 0;
void (__stdcall *mss32_AIL_redbook_track_info)(HREDBOOK, unsigned int, unsigned int *, unsigned int *) = 0;
unsigned int (__stdcall *mss32_AIL_redbook_play)(HREDBOOK, unsigned int, unsigned int) = 0;
unsigned int (__stdcall *mss32_AIL_redbook_resume)(HREDBOOK) = 0;
AIL::Sample::Status (__stdcall *mss32_AIL_sample_status)(HSAMPLE) = 0;
int (__stdcall *mss32_AIL_sample_volume)(HSAMPLE) = 0;
int (__stdcall *mss32_AIL_enumerate_3D_providers)(int *, HPROVIDER *, char **) = 0;
DWORD (__stdcall *mss32_AIL_open_3D_provider)(HPROVIDER) = 0;
int (__stdcall *mss32_AIL_end_sample)(HSAMPLE) = 0;
int (__stdcall *mss32_AIL_set_sample_volume)(HSAMPLE, long) = 0;
int (__stdcall *mss32_AIL_set_sample_pan)(HSAMPLE, long) = 0;
void (__stdcall *mss32_AIL_end_sequence)(HSEQUENCE) = 0;
void (__stdcall *mss32_AIL_pause_stream)(HSTREAM, int) = 0;
void (__stdcall *mss32_AIL_init_sample)(HSAMPLE) = 0;
int (__stdcall *mss32_AIL_set_sample_file)(HSAMPLE, const void *, int) = 0;
void (__stdcall *mss32_AIL_set_sample_loop_count)(HSAMPLE, int) = 0;
void (__stdcall *mss32_AIL_set_sample_playback_rate)(HSAMPLE, int) = 0;
void (__stdcall *mss32_AIL_sample_ms_position)(HSAMPLE, int *, int *) = 0;
void (__stdcall *mss32_AIL_start_sample)(HSAMPLE) = 0;
void MSS32_DLL_Initialize()
{
 HMODULE pDll = LoadLibraryW(L"mss32.dll");

 mss32_AIL_startup = (int (__stdcall *)())GetProcAddress(pDll, "_AIL_startup@0");
 mss32_AIL_redbook_open_drive = (HREDBOOK (__stdcall *)(long))GetProcAddress(pDll, "_AIL_redbook_open_drive@4");
 mss32_AIL_set_preference = (int (__stdcall *)(unsigned int, int))GetProcAddress(pDll, "_AIL_set_preference@8");
 mss32_AIL_waveOutOpen = (int (__stdcall *)(HDIGDRIVER *, HWAVEOUT *, int, WAVEFORMAT *))GetProcAddress(pDll, "_AIL_waveOutOpen@16");
 mss32_AIL_get_preference = (int (__stdcall *)(unsigned int))GetProcAddress(pDll, "_AIL_get_preference@4");
 mss32_AIL_digital_configuration = (int (__stdcall *)(HDIGDRIVER, int *, int *, char *))GetProcAddress(pDll, "_AIL_digital_configuration@16");
 mss32_AIL_allocate_sample_handle = (HSAMPLE (__stdcall *)(HDIGDRIVER))GetProcAddress(pDll, "_AIL_allocate_sample_handle@4");
 mss32_AIL_redbook_tracks = (unsigned int (__stdcall *)(HREDBOOK))GetProcAddress(pDll, "_AIL_redbook_tracks@4");
 mss32_AIL_redbook_volume = (int (__stdcall *)(HREDBOOK))GetProcAddress(pDll, "_AIL_redbook_volume@4");
 mss32_AIL_redbook_stop = (unsigned int (__stdcall *)(HREDBOOK))GetProcAddress(pDll, "_AIL_redbook_stop@4");
 mss32_AIL_set_digital_master_volume = (void (__stdcall *)(HDIGDRIVER, float))GetProcAddress(pDll, "_AIL_set_digital_master_volume@8");
 mss32_AIL_redbook_set_volume = (int (__stdcall *)(HREDBOOK, int))GetProcAddress(pDll, "_AIL_redbook_set_volume@8");
 mss32_AIL_redbook_pause = (unsigned int (__stdcall *)(HREDBOOK))GetProcAddress(pDll, "_AIL_redbook_pause@4");
 mss32_AIL_redbook_track_info = (void (__stdcall *)(HREDBOOK, unsigned int, unsigned int *, unsigned int *))GetProcAddress(pDll, "_AIL_redbook_track_info@16");
 mss32_AIL_redbook_play = (unsigned int (__stdcall *)(HREDBOOK, unsigned int, unsigned int))GetProcAddress(pDll, "_AIL_redbook_play@12");
 mss32_AIL_redbook_resume = (unsigned int (__stdcall *)(HREDBOOK))GetProcAddress(pDll, "_AIL_redbook_resume@4");
 mss32_AIL_sample_status = (AIL::Sample::Status (__stdcall *)(HSAMPLE))GetProcAddress(pDll, "_AIL_sample_status@4");
 mss32_AIL_sample_volume = (int (__stdcall *)(HSAMPLE))GetProcAddress(pDll, "_AIL_sample_volume@4");
 mss32_AIL_enumerate_3D_providers = (int (__stdcall *)(int *, HPROVIDER *, char **))GetProcAddress(pDll, "_AIL_enumerate_3D_providers@12");
 mss32_AIL_open_3D_provider = (DWORD (__stdcall *)(HPROVIDER))GetProcAddress(pDll, "_AIL_open_3D_provider@4");
 mss32_AIL_end_sample = (int (__stdcall *)(HSAMPLE))GetProcAddress(pDll, "_AIL_end_sample@4");
 mss32_AIL_set_sample_volume = (int (__stdcall *)(HSAMPLE, long))GetProcAddress(pDll, "_AIL_set_sample_volume@8");
 mss32_AIL_set_sample_pan = (int (__stdcall *)(HSAMPLE, long))GetProcAddress(pDll, "_AIL_set_sample_pan@8");
 mss32_AIL_end_sequence = (void (__stdcall *)(HSEQUENCE))GetProcAddress(pDll, "_AIL_end_sequence@4");
 mss32_AIL_pause_stream = (void (__stdcall *)(HSTREAM, int))GetProcAddress(pDll, "_AIL_pause_stream@8");
 mss32_AIL_init_sample = (void (__stdcall *)(HSAMPLE))GetProcAddress(pDll, "_AIL_init_sample@4");
 mss32_AIL_set_sample_file = (int (__stdcall *)(HSAMPLE, const void *, int))GetProcAddress(pDll, "_AIL_set_sample_file@12");
 mss32_AIL_set_sample_loop_count = (void (__stdcall *)(HSAMPLE, int))GetProcAddress(pDll, "_AIL_set_sample_loop_count@8");
 mss32_AIL_set_sample_playback_rate = (void (__stdcall *)(HSAMPLE, int))GetProcAddress(pDll, "_AIL_set_sample_playback_rate@8");
 mss32_AIL_sample_ms_position = (void (__stdcall *)(HSAMPLE, int *, int *))GetProcAddress(pDll, "_AIL_sample_ms_position@12");
 mss32_AIL_start_sample = (void (__stdcall *)(HSAMPLE))GetProcAddress(pDll, "_AIL_start_sample@4");
}



unsigned int __stdcall AIL_redbook_play(HREDBOOK hRedbook, unsigned int uStartMS, unsigned int uEndMS)
{
 return (mss32_AIL_redbook_play)(hRedbook, uStartMS, uEndMS);
}

void __stdcall AIL_redbook_track_info(HREDBOOK hRedbook, unsigned int uTrackNum, unsigned int *pStartMS, unsigned int *pEndMS)
{
 (mss32_AIL_redbook_track_info)(hRedbook, uTrackNum, pStartMS, pEndMS);
}

unsigned int __stdcall AIL_redbook_resume(HREDBOOK hRedbook)
{
 return (mss32_AIL_redbook_resume)(hRedbook);
}

int __stdcall AIL_enumerate_3D_providers(int *a1, HPROVIDER *pOutProv, char **pOutName)
{
 return (mss32_AIL_enumerate_3D_providers)(a1, pOutProv, pOutName);
}



int __stdcall AIL_sample_volume(HSAMPLE s)
{
 return (mss32_AIL_sample_volume)(s);
}

AIL::Sample::Status __stdcall AIL_sample_status(HSAMPLE a1)
{
 return (mss32_AIL_sample_status)(a1);
}

// sub_4D8304: using guessed type int __stdcall AIL_set_digital_master_volume(_DWORD, _DWORD);
void __stdcall AIL_set_digital_master_volume(HDIGDRIVER hDrv, float master_volume)
{
 (mss32_AIL_set_digital_master_volume)(hDrv, master_volume);
}

// sub_4D8370: using guessed type int __stdcall AIL_allocate_sample_handle(_DWORD);
HSAMPLE __stdcall AIL_allocate_sample_handle(HDIGDRIVER hDrv)
{
 return (mss32_AIL_allocate_sample_handle)(hDrv);
}

// sub_4D8308: using guessed type int __fastcall AIL_redbook_set_volume(_DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_redbook_set_volume(HREDBOOK hRedbook, int volume)
{
 return (mss32_AIL_redbook_set_volume)(hRedbook, volume);
}

// sub_4D8324: using guessed type int __stdcall AIL_redbook_stop(_DWORD);
unsigned int __stdcall AIL_redbook_stop(HREDBOOK hRedbook)
{
 return (mss32_AIL_redbook_stop)(hRedbook);
}

// sub_4D835C: using guessed type int __stdcall AIL_startup();
int __stdcall AIL_startup()
{
 return (mss32_AIL_startup)();
}

// sub_4D8360: using guessed type int __stdcall AIL_redbook_open_drive(_DWORD);
HREDBOOK __stdcall AIL_redbook_open_drive(long drive)
{
 return (mss32_AIL_redbook_open_drive)(drive);
}

// sub_4D834C: using guessed type int __stdcall AIL_waveOutOpen(_DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_waveOutOpen(HDIGDRIVER *drv, HWAVEOUT *phWaveOut, int wDeviceID, WAVEFORMAT *pFormat)
{
 return (mss32_AIL_waveOutOpen)(drv, phWaveOut, wDeviceID, pFormat);
}


DWORD __stdcall AIL_open_3D_provider(HPROVIDER a2)
{
 return (mss32_AIL_open_3D_provider)(a2);
}

// sub_4D836C: using guessed type int __stdcall AIL_3D_provider_attribute(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_3D_provider_attribute(HPROVIDER a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D8374: using guessed type int __stdcall AIL_redbook_tracks(_DWORD);
unsigned int __stdcall AIL_redbook_tracks(HREDBOOK hRedbook)
{
 return (mss32_AIL_redbook_tracks)(hRedbook);
}

// sub_4D83B0: using guessed type int __stdcall AIL_redbook_volume(_DWORD);
int __stdcall AIL_redbook_volume(HREDBOOK hRedbook)
{
 return (mss32_AIL_redbook_volume)(hRedbook);
}

// sub_4D8348: using guessed type int __stdcall AIL_set_preference(_DWORD, _DWORD);
int __stdcall AIL_set_preference(unsigned int number, int value)
{
 return (mss32_AIL_set_preference)(number, value);
}

// sub_4D8350: using guessed type int __stdcall AIL_digital_configuration(_DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_digital_configuration(HDIGDRIVER drv, int *rate, int *format, char *string)
{
 return (mss32_AIL_digital_configuration)(drv, rate, format, string);
}

// sub_4D8354: using guessed type int __stdcall AIL_get_preference(_DWORD);
int __stdcall AIL_get_preference(unsigned int number)
{
 return (mss32_AIL_get_preference)(number);
}

// sub_4D8358: using guessed type int __fastcall AIL_waveOutClose(_DWORD, _DWORD);
int __fastcall AIL_waveOutClose(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8320: using guessed type int __stdcall AIL_redbook_pause(_DWORD);
unsigned int __stdcall AIL_redbook_pause(HREDBOOK hRedbook)
{
 return (mss32_AIL_redbook_pause)(hRedbook);
}

// sub_4D82DC: using guessed type int __stdcall AIL_set_3D_provider_preference(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_provider_preference(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D8330: using guessed type int __stdcall AIL_allocate_3D_sample_handle(_DWORD);
int __stdcall AIL_allocate_3D_sample_handle(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8394: using guessed type int __stdcall AIL_set_3D_sample_float_distances(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_float_distances(long a1, long a2, long a3, long a4, long a5)
{
 __asm int 3
 return 0;
}

// sub_4D8398: using guessed type int __stdcall AIL_set_3D_sample_volume(_DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_volume(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D82E4: using guessed type int __stdcall AIL_release_sample_handle(_DWORD);
int __stdcall AIL_release_sample_handle(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8338: using guessed type int __stdcall AIL_release_3D_sample_handle(_DWORD);
int __stdcall AIL_release_3D_sample_handle(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D833C: using guessed type int __stdcall AIL_close_3D_provider(_DWORD);
int __stdcall AIL_close_3D_provider(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8340: using guessed type int __stdcall AIL_redbook_close(_DWORD);
int __stdcall AIL_redbook_close(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8344: using guessed type int __stdcall AIL_shutdown();
int __stdcall AIL_shutdown()
{
 __asm int 3
 return 0;
}

int __stdcall AIL_end_sample(HSAMPLE a1)
{
 return (mss32_AIL_end_sample)(a1);
}

// sub_4D8300: using guessed type int __stdcall AIL_end_3D_sample(_DWORD);
int __stdcall AIL_end_3D_sample(long a1)
{
 runtime_warning();//__asm int 3
 return 0;
}


void __stdcall AIL_end_sequence(HSEQUENCE a1)
{
 (mss32_AIL_end_sequence)(a1);
}

void __stdcall AIL_pause_stream(HSTREAM a1, int onoff)
{
 (mss32_AIL_pause_stream)(a1, onoff);
}

int __stdcall AIL_set_sample_file(HSAMPLE s, const void *file_image, int block)
{
 return (mss32_AIL_set_sample_file)(s, file_image, block);
}

void __stdcall AIL_start_sample(HSAMPLE s)
{
 (mss32_AIL_start_sample)(s);
}

void __stdcall AIL_set_sample_playback_rate(HSAMPLE s, int rate)
{
 (mss32_AIL_set_sample_playback_rate)(s, rate);
}

void __stdcall AIL_sample_ms_position(HSAMPLE s, int *pTotalMS, int *pCurrentMS)
{
 (mss32_AIL_sample_ms_position)(s, pTotalMS, pCurrentMS);
}

// sub_4D82F4: using guessed type int __stdcall AIL_3D_sample_status(_DWORD);
int __stdcall AIL_3D_sample_status(long a1)
{
 __asm int 3
 return 0;
}

void __stdcall AIL_set_sample_loop_count(HSAMPLE s, int num)
{
 (mss32_AIL_set_sample_loop_count)(s, num);
}

int __stdcall AIL_set_sample_volume(HSAMPLE a1, long a2)
{
 return (mss32_AIL_set_sample_volume)(a1, a2);
}

// sub_4D8384: using guessed type int __thiscall AIL_3D_position(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __fastcall AIL_3D_position(long a1, long a2, long a3, long a4, long a5)
{
 __asm int 3
 return 0;
}

// sub_4D8388: using guessed type int __thiscall AIL_set_3D_sample_file(_DWORD, _DWORD, _DWORD);
int __fastcall AIL_set_3D_sample_file(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D838C: using guessed type int __stdcall AIL_set_3D_sample_loop_count(_DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_loop_count(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8390: using guessed type int __stdcall AIL_start_3D_sample(_DWORD);
int __stdcall AIL_start_3D_sample(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D839C: using guessed type int __stdcall AIL_set_3D_position(_DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_position(long a1, long a2, long a3, long a4)
{
 __asm int 3
 return 0;
}

// sub_4D83A0: using guessed type int __stdcall AIL_set_3D_orientation(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_orientation(long a1, long a2, long a3, long a4, long a5, long a6, long a7)
{
 __asm int 3
 return 0;
}

void __stdcall AIL_init_sample(HSAMPLE a1)
{
 (mss32_AIL_init_sample)(a1);
}

int __stdcall AIL_set_sample_pan(HSAMPLE a1, long a2)
{
 return (mss32_AIL_set_sample_pan)(a1, a2);
}

// sub_4D8310: using guessed type int __stdcall AIL_file_type(_DWORD, _DWORD);
int __stdcall AIL_file_type(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8314: using guessed type int __stdcall AIL_WAV_info(_DWORD, _DWORD);
int __stdcall AIL_WAV_info(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8318: using guessed type int __stdcall AIL_decompress_ADPCM(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_decompress_ADPCM(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D830C: using guessed type int __stdcall AIL_mem_free_lock(_DWORD);
int __stdcall AIL_mem_free_lock(long a1)
{
 __asm int 3
 return 0;
}