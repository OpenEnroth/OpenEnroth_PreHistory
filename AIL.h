#include "defs.h"

void MSS32_DLL_Initialize();


int __stdcall AIL_startup();
HREDBOOK __stdcall AIL_redbook_open_drive(long drive);
int __stdcall AIL_set_preference(unsigned int number, int value);
int __stdcall AIL_waveOutOpen(HDIGDRIVER *drv, HWAVEOUT *phWaveOut, int wDeviceID, WAVEFORMAT *pFormat);
int __stdcall AIL_get_preference(unsigned int number);
int __stdcall AIL_digital_configuration(HDIGDRIVER drv, int *rate, int *format, char *string);
HSAMPLE __stdcall AIL_allocate_sample_handle(HDIGDRIVER hDrv);
unsigned int __stdcall AIL_redbook_tracks(HREDBOOK hRedbook);
int __stdcall AIL_redbook_volume(HREDBOOK hRedbook);
unsigned int __stdcall AIL_redbook_stop(HREDBOOK hRedbook);
void __stdcall AIL_set_digital_master_volume(HDIGDRIVER hDrv, float master_volume);
int __stdcall AIL_redbook_set_volume(HREDBOOK hRedbook, int volume);
unsigned int __stdcall AIL_redbook_pause(HREDBOOK hRedbook);
void __stdcall AIL_redbook_track_info(HREDBOOK hRedbook, unsigned int uTrackNum, unsigned int *pStartMS, unsigned int *pEndMS);
unsigned int __stdcall AIL_redbook_play(HREDBOOK hRedbook, unsigned int uStartMS, unsigned int uEndMS);  	
unsigned int __stdcall AIL_redbook_resume(HREDBOOK);




// sub_4D8364: using guessed type int __stdcall AIL_enumerate_3D_providers(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_enumerate_3D_providers(long a1, long a2, long a3);

// sub_4D8368: using guessed type int __fastcall AIL_open_3D_provider(_DWORD, _DWORD);
int __fastcall AIL_open_3D_provider(long a1, long a2);

// sub_4D836C: using guessed type int __stdcall AIL_3D_provider_attribute(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_3D_provider_attribute(long a1, long a2, long a3);

// sub_4D8358: using guessed type int __fastcall AIL_waveOutClose(_DWORD, _DWORD);
int __fastcall AIL_waveOutClose(long a1, long a2);

// sub_4D831C: using guessed type int __stdcall AIL_redbook_resume(_DWORD);
//int __stdcall AIL_redbook_resume(long a1);

// sub_4D82DC: using guessed type int __stdcall AIL_set_3D_provider_preference(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_provider_preference(long a1, long a2, long a3);

// sub_4D8330: using guessed type int __stdcall AIL_allocate_3D_sample_handle(_DWORD);
int __stdcall AIL_allocate_3D_sample_handle(long a1);

// sub_4D8394: using guessed type int __stdcall AIL_set_3D_sample_float_distances(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_float_distances(long a1, long a2, long a3, long a4, long a5);

// sub_4D8398: using guessed type int __stdcall AIL_set_3D_sample_volume(_DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_volume(long a1, long a2);

// sub_4D82E4: using guessed type int __stdcall AIL_release_sample_handle(_DWORD);
int __stdcall AIL_release_sample_handle(long a1);

// sub_4D8338: using guessed type int __stdcall AIL_release_3D_sample_handle(_DWORD);
int __stdcall AIL_release_3D_sample_handle(long a1);

// sub_4D833C: using guessed type int __stdcall AIL_close_3D_provider(_DWORD);
int __stdcall AIL_close_3D_provider(long a1);

// sub_4D8340: using guessed type int __stdcall AIL_redbook_close(_DWORD);
int __stdcall AIL_redbook_close(long a1);

// sub_4D8344: using guessed type int __stdcall AIL_shutdown();
int __stdcall AIL_shutdown();

// sub_4D82FC: using guessed type int __stdcall AIL_end_sample(_DWORD);
int __stdcall AIL_end_sample(long a1);

// sub_4D8300: using guessed type int __stdcall AIL_end_3D_sample(_DWORD);
int __stdcall AIL_end_3D_sample(long a1);

// sub_4D837C: using guessed type int __stdcall AIL_end_sequence(_DWORD);
int __stdcall AIL_end_sequence(long a1);

// sub_4D8380: using guessed type int __stdcall AIL_pause_stream(_DWORD, _DWORD);
int __stdcall AIL_pause_stream(long a1, long a2);

// sub_4D82E0: using guessed type int __stdcall AIL_set_sample_file(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_sample_file(long a1, long a2, long a3);

// sub_4D82E8: using guessed type int __stdcall AIL_start_sample(_DWORD);
int __stdcall AIL_start_sample(long a1);

// sub_4D82EC: using guessed type int __stdcall AIL_set_sample_playback_rate(_DWORD, _DWORD);
int __stdcall AIL_set_sample_playback_rate(long a1, long a2);

// sub_4D82F0: using guessed type int __stdcall AIL_sample_ms_position(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_sample_ms_position(long a1, long a2, long a3);

// sub_4D82F4: using guessed type int __stdcall AIL_3D_sample_status(_DWORD);
int __stdcall AIL_3D_sample_status(long a1);

// sub_4D82F8: using guessed type int __stdcall AIL_sample_status(_DWORD);
int __stdcall AIL_sample_status(long a1);

// sub_4D8334: using guessed type int __stdcall AIL_set_sample_loop_count(_DWORD, _DWORD);
int __stdcall AIL_set_sample_loop_count(long a1, long a2);

// sub_4D8378: using guessed type int __stdcall AIL_set_sample_volume(_DWORD, _DWORD);
int __stdcall AIL_set_sample_volume(long a1, long a2);

// sub_4D8384: using guessed type int __thiscall AIL_3D_position(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __fastcall AIL_3D_position(long a1, long a2, long a3, long a4, long a5);

// sub_4D8388: using guessed type int __thiscall AIL_set_3D_sample_file(_DWORD, _DWORD, _DWORD);
int __fastcall AIL_set_3D_sample_file(long a1, long a2, long a3);

// sub_4D838C: using guessed type int __stdcall AIL_set_3D_sample_loop_count(_DWORD, _DWORD);
int __stdcall AIL_set_3D_sample_loop_count(long a1, long a2);

// sub_4D8390: using guessed type int __stdcall AIL_start_3D_sample(_DWORD);
int __stdcall AIL_start_3D_sample(long a1);

// sub_4D839C: using guessed type int __stdcall AIL_set_3D_position(_DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_position(long a1, long a2, long a3, long a4);

// sub_4D83A0: using guessed type int __stdcall AIL_set_3D_orientation(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
int __stdcall AIL_set_3D_orientation(long a1, long a2, long a3, long a4, long a5, long a6, long a7);

// sub_4D83A4: using guessed type int __thiscall AIL_sample_volume(_DWORD, _DWORD);
int __stdcall AIL_sample_volume(long a1, long a2);

// sub_4D83A8: using guessed type int __stdcall AIL_init_sample(_DWORD);
int __stdcall AIL_init_sample(long a1);

// sub_4D83AC: using guessed type int __stdcall AIL_set_sample_pan(_DWORD, _DWORD);
int __stdcall AIL_set_sample_pan(long a1, long a2);

// sub_4D8310: using guessed type int __stdcall AIL_file_type(_DWORD, _DWORD);
int __stdcall AIL_file_type(long a1, long a2);

// sub_4D8314: using guessed type int __stdcall AIL_WAV_info(_DWORD, _DWORD);
int __stdcall AIL_WAV_info(long a1, long a2);

// sub_4D8318: using guessed type int __stdcall AIL_decompress_ADPCM(_DWORD, _DWORD, _DWORD);
int __stdcall AIL_decompress_ADPCM(long a1, long a2, long a3);

// sub_4D830C: using guessed type int __stdcall AIL_mem_free_lock(_DWORD);
int __stdcall AIL_mem_free_lock(long a1);