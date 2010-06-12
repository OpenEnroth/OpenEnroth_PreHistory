#include "AIL.h"

int (__stdcall *mss32_AIL_startup)() = 0;
HREDBOOK (__stdcall *mss32_AIL_redbook_open_drive)(long) = 0;
int (__stdcall *mss32_AIL_set_preference)(unsigned int, int) = 0;
int (__stdcall *mss32_AIL_waveOutOpen)(HDIGDRIVER, HWAVEOUT *, int, WAVEFORMAT *) = 0;
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
void MSS32_DLL_Initialize()
{
 void *pDll = LoadLibraryW(L"mss32.dll");

 mss32_AIL_startup = GetProcAddress(pDll, "_AIL_startup@0");
 mss32_AIL_redbook_open_drive = GetProcAddress(pDll, "_AIL_redbook_open_drive@4");
 mss32_AIL_set_preference = GetProcAddress(pDll, "_AIL_set_preference@8");
 mss32_AIL_waveOutOpen = GetProcAddress(pDll, "_AIL_waveOutOpen@16");
 mss32_AIL_get_preference = GetProcAddress(pDll, "_AIL_get_preference@4");
 mss32_AIL_digital_configuration = GetProcAddress(pDll, "_AIL_digital_configuration@16");
 mss32_AIL_allocate_sample_handle = GetProcAddress(pDll, "_AIL_allocate_sample_handle@4");
 mss32_AIL_redbook_tracks = GetProcAddress(pDll, "_AIL_redbook_tracks@4");
 mss32_AIL_redbook_volume = GetProcAddress(pDll, "_AIL_redbook_volume@4");
 mss32_AIL_redbook_stop = GetProcAddress(pDll, "_AIL_redbook_stop@4");
 mss32_AIL_set_digital_master_volume = GetProcAddress(pDll, "_AIL_set_digital_master_volume@8");
 mss32_AIL_redbook_set_volume = GetProcAddress(pDll, "_AIL_redbook_set_volume@8");
 mss32_AIL_redbook_pause = GetProcAddress(pDll, "_AIL_redbook_pause@4");
 mss32_AIL_redbook_track_info = GetProcAddress(pDll, "_AIL_redbook_track_info@16");
 mss32_AIL_redbook_play = GetProcAddress(pDll, "_AIL_redbook_play@12");
 mss32_AIL_redbook_resume = GetProcAddress(pDll, "_AIL_redbook_resume@4");
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
int __stdcall AIL_waveOutOpen(HDIGDRIVER drv, HWAVEOUT *phWaveOut, int wDeviceID, WAVEFORMAT *pFormat)
{
 return (mss32_AIL_waveOutOpen)(drv, phWaveOut, wDeviceID, pFormat);
}

// sub_4D8364: using guessed type int __stdcall AIL_enumerate_3D_providers(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_enumerate_3D_providers(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D8368: using guessed type int __fastcall AIL_open_3D_provider(_DWORD, _DWORD);
int __fastcall AIL_open_3D_provider(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D836C: using guessed type int __stdcall AIL_3D_provider_attribute(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_3D_provider_attribute(long a1, long a2, long a3)
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

// sub_4D82FC: using guessed type int __stdcall AIL_end_sample(_DWORD);
int __stdcall AIL_end_sample(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8300: using guessed type int __stdcall AIL_end_3D_sample(_DWORD);
int __stdcall AIL_end_3D_sample(long a1)
{
 runtime_warning();//__asm int 3
 return 0;
}

// sub_4D837C: using guessed type int __stdcall AIL_end_sequence(_DWORD);
int __stdcall AIL_end_sequence(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8380: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);
int __stdcall AIL_pause_stream(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D82E0: using guessed type int __stdcall AIL_set_sample_file(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_sample_file(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D82E8: using guessed type int __stdcall AIL_start_sample(_DWORD);
int __stdcall AIL_start_sample(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D82EC: using guessed type int __stdcall AIL_set_sample_playback_rate(_DWORD, _DWORD);
int __stdcall AIL_set_sample_playback_rate(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D82F0: using guessed type int __stdcall AIL_sample_ms_position(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_sample_ms_position(long a1, long a2, long a3)
{
 __asm int 3
 return 0;
}

// sub_4D82F4: using guessed type int __stdcall AIL_3D_sample_status(_DWORD);
int __stdcall AIL_3D_sample_status(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D82F8: using guessed type int __stdcall AIL_sample_status(_DWORD);
int __stdcall AIL_sample_status(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D8334: using guessed type int __stdcall AIL_set_sample_loop_count(_DWORD, _DWORD);
int __stdcall AIL_set_sample_loop_count(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D8378: using guessed type int __stdcall AIL_set_sample_volume(_DWORD, _DWORD);
int __stdcall AIL_set_sample_volume(long a1, long a2)
{
 __asm int 3
 return 0;
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

// sub_4D83A4: using guessed type int __thiscall AIL_sample_volume(_DWORD, _DWORD);
int __fastcall AIL_sample_volume(long a1, long a2)
{
 __asm int 3
 return 0;
}

// sub_4D83A8: using guessed type int __stdcall AIL_init_sample(_DWORD);
int __stdcall AIL_init_sample(long a1)
{
 __asm int 3
 return 0;
}

// sub_4D83AC: using guessed type int __stdcall AIL_set_sample_pan(_DWORD, _DWORD);
int __stdcall AIL_set_sample_pan(long a1, long a2)
{
 __asm int 3
 return 0;
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