#include "AudioPlayer.h"
#include "VideoPlayer.h"
#include "libs\AIL\AIL.h"
#include "libs\Smacker\Smacker.h"
#include "clock.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "FrameTables.h"

#include "RenderD3D3.h"

#include "data.h"
#include "_lod.h"


LSTATUS __stdcall CheckA3DSupport(char a1);





//----- (MM7.exe::004AB8CE) --------------------------------------------------------
Result::Code AudioPlayer::Initialize(OSWindow *pTargetWindow, wchar_t cCDDriveLetter)
{
 pWindow = pTargetWindow;
 dword_0002AC = 0;
 dword_0002C8 = 64;
 dword_0002CC = 2;



 hAudioSnd = CreateFileW(L"Sounds\\Audio.snd", GENERIC_READ, 1, 0, 3, 0x8000080, 0);
 if (hAudioSnd == INVALID_HANDLE_VALUE)
 {
  MessageBoxW(0, L"Can't open file: Audio.snd", L"AudioPlayer error", 0);
  return Result::NotFound;
 }

 DWORD w;
 ReadFile(hAudioSnd, &uNumSoundHeaders, 4, &w, 0);

 pSoundHeaders = NamedMemAlloc(SoundHeader, uNumSoundHeaders, "AudioPlayer sound headers");
 ReadFile(hAudioSnd, pSoundHeaders, uNumSoundHeaders * sizeof(SoundHeader), &w, 0);





 AIL_startup();
 if (bCanLoadFromCD)
   hAILRedbook = AIL_redbook_open_drive(cCDDriveLetter);
 hDigDriver = GetFirstHardwareDigitalDriver();


 if (!bNo3DSound)
 {
  ReadWindowsRegistryString("3DSoundProvider", p3DSoundProvider, 128, "NONE");
  CheckA3DSupport(1);

  HPROVIDER  hNextProvider;
  char      *pNextProviderName;

    int v16 = 0;
    while (AIL_enumerate_3D_providers(&v16, &hNextProvider, &pNextProviderName))
    {
      if (!strcmpi(p3DSoundProvider, "None") ||
          !strcmp(p3DSoundProvider, pNextProviderName))
      {
        if ( AIL_open_3D_provider(hNextProvider) )
        {
          bEAXSupported = false;
          b3DSoundInitialized = false;
          h3DSoundProvider = 0;

          lstrcpyA(p3DSoundProvider, "None");
        }
        else
        {
         int v14;
          b3DSoundInitialized = true;
          h3DSoundProvider = hNextProvider;
          *(_DWORD *)(this + 16) = 4;
          AIL_3D_provider_attribute(hNextProvider, (int)"EAX environment selection", (int)&v14);
          if ( v14 != -1 )
            bEAXSupported = true;

        sub_4AC0A2(this);
        break;
        }
      }
    }
  }

 memset(pMixerChannels, 0, 16 * sizeof(MixerChannel));
 for (unsigned int i = 0; i < uMixerChannels; ++i)
 {
  pMixerChannels[i].hSample = AIL_allocate_sample_handle(hDigDriver);

  if (!pMixerChannels[i].hSample)
    break;
 }

 bPlayerReady = true;

 if (hAILRedbook)
 {
  AIL_redbook_stop(hAILRedbook);
  uNumRedbookTracks = AIL_redbook_tracks(hAILRedbook);
  sRedbookVolume = AIL_redbook_volume(hAILRedbook);
 }



 pSoundList = MemAlloc(SoundList, 1);
 pSoundList->Initialize(L"dsounds.bin");


 return Result::Success;
}



AudioPlayer::AudioPlayer()
{
 uMixerChannels = 16;

 uMasterVolume = 127;

 bEAXSupported = false;
 b3DSoundInitialized = false;
 h3DSoundProvider = 0;

 hAILRedbook = 0;
 hDigDriver = 0;

 hSequence = 0;
 hStream = 0;

 uCurrentMusicTrackStartMS = 0;
 uCurrentMusicTrackEndMS = 0;

 bPlayerReady = false;
}





//----- (004AA306) --------------------------------------------------------
void AudioPlayer::sub_4AA306(int a2, signed int a3, unsigned int uNumRepeats, signed int a5, int a6, int a7, unsigned int uVolume, int sPlaybackRate)
{
  int v13; // edi@13
  signed int v14; // ecx@17
  signed int v15; // eax@20
  int v16; // eax@24
  signed int v17; // eax@25
  char *v18; // eax@28
  signed int v19; // eax@29
  double v20; // st7@32
  char *v21; // eax@32
  signed int v22; // ecx@32
  signed int v23; // ecx@33
  int v24; // esi@53
  int v25; // esi@61
  int v26; // esi@67
  double v27; // st7@68
  int v28; // ST18_4@68
  int v29; // ebx@68
  int v30; // eax@68
  int v31; // ecx@69
  int v32; // esi@69
  char v33; // zf@70
  int v34; // eax@70
  int v35; // ST18_4@70
  int v36; // ebx@70
  int v37; // eax@70
  signed int v38; // ebx@74
  int v39; // edi@79
  int v40; // esi@79
  int v41; // ebx@80
  int v42; // edi@82
  int v43; // esi@82
  double v44; // st7@91
  char *v45; // eax@92
  double v46; // st7@93
  char *v47; // eax@93
  signed int v48; // ecx@93
  char *v49; // eax@97
  double v50; // st7@104
  int v51; // ST18_4@104
  int v52; // ebx@104
  int v53; // eax@104
  float v54; // ST0C_4@106
  float v55; // ST04_4@106
  int v56; // edx@106
  char *v57; // eax@114
  int v58; // edx@115
  int v59; // ecx@115
  Actor *v60; // eax@118
  int v61; // esi@126
  int v64; // edi@134
  int v65; // ebx@141
  int v68; // eax@143
  int v70; // eax@153
  int v74; // ebx@159
  signed int v75; // ebx@160
  char *v76; // edi@164
  int v77; // edx@166
  int v78; // ecx@166
  int v79; // eax@167
  char *v80; // edi@168
  char *v81; // edi@173
  int v82; // eax@183
  int v83; // eax@183
  int v85; // [sp+14h] [bp-60h]@84
  int v86; // [sp+14h] [bp-60h]@115
  float v87; // [sp+24h] [bp-50h]@32
  float v88; // [sp+28h] [bp-4Ch]@32
  float v89; // [sp+2Ch] [bp-48h]@47
  float v90; // [sp+30h] [bp-44h]@68
  float v91; // [sp+34h] [bp-40h]@68
  float v92; // [sp+50h] [bp-24h]@1
  int v93; // [sp+54h] [bp-20h]@12
  int v94; // [sp+58h] [bp-1Ch]@68
  int v95; // [sp+5Ch] [bp-18h]@68
  signed int v101; // [sp+84h] [bp+10h]@93
  float v102; // [sp+84h] [bp+10h]@104
  float v103; // [sp+8Ch] [bp+18h]@104
  signed int v104; // [sp+90h] [bp+1Ch]@32
  int v105; // [sp+90h] [bp+1Ch]@52
  int v106; // [sp+90h] [bp+1Ch]@60
  int v107; // [sp+90h] [bp+1Ch]@68


 if (!bPlayerReady ||
     !hDigDriver ||
     !a2 || bNoSound)
   return;

 //if (!uSoundVolumeMultiplier)
 //  return

 unsigned int uSoundIdx;
 for (uSoundIdx = 0; uSoundIdx < pSoundList->uNumSounds; ++uSoundIdx)
   if (pSoundList->pSounds[uSoundIdx].uSoundID == a2)
     break;

 if (uSoundIdx == pSoundList->uNumSounds)
   return;


  v92 = 0.0;
 unsigned int uDefaultVolume = 10000;

  v93 = 120 * uSoundIdx;

 Range<unsigned int>  cChannelsToUse;
 MixerChannel        *pFreeChannel;
  if ( !b3DSoundInitialized || ~pSoundList->pSounds[uSoundIdx].dword_000028 & 0x02)
  {
    if ( a3 < 0 )
    {
      if ( a3 == -1 )
      {
        cChannelsToUse = Range<unsigned int>(13, 13);
        goto LABEL_133;
      }
      cChannelsToUse = Range<unsigned int>(14, 14);

LABEL_123:
      if ( a3 )
      {
        if ( a3 != -1 )
        {
          v95 = 0;
          if (uMixerChannels > 0 )
          {
            v61 = (int)pMixerChannels;
            do
            {
             if (AIL_sample_status(this->pMixerChannels[v95].hSample) == AIL::Sample::Playing &&
                 this->pMixerChannels[v95].dword_000004 == a3 &&
                 AIL_sample_status(this->pMixerChannels[v95].hSample) == AIL::Sample::Playing)
              {
               if (pMixerChannels[v95].uSourceTrackIdx == uSoundIdx)
                  return;
                AIL_end_sample(this->pMixerChannels[v95].hSample);
                this->sub_4ABE55(&this->pMixerChannels[v95]);
              }
              ++v95;
              v61 += 16;
            }
            while ( v95 < this->uMixerChannels);
          }
        }
      }

LABEL_133:
      pFreeChannel = 0;
      for (unsigned int i = cChannelsToUse.min; i <= cChannelsToUse.max; ++i)
      {
       if (AIL_sample_status(pMixerChannels[i].hSample) == AIL::Sample::Done)
       {
        pFreeChannel = &pMixerChannels[i];

        AIL_end_sample(pFreeChannel->hSample);
        if (pFreeChannel->uSourceTrackIdx)
          sub_4ABE55(pFreeChannel);

        break;
       }
      }


      if (pFreeChannel)
      {
LABEL_150:
        if (uDefaultVolume == 10000)
          uDefaultVolume = uMasterVolume;
        if (!a7)
        {
          v70 = (int)&pSoundList->pSounds[uSoundIdx];
          if (!pSoundList->pSounds[uSoundIdx].pSoundData[0])
          {
            if (pSoundList->pSounds[uSoundIdx].dword_000024 == 2)
              sub_4A9A67(pSoundList, a2, 0);
          }
        }

        if (!pSoundList->pSounds[uSoundIdx].pSoundData[a7])
          pSoundList->pSounds[uSoundIdx].pSoundData[a7] = LoadSound(pSoundList->pSounds[uSoundIdx].pSoundName, nullptr, pSoundList->pSounds[uSoundIdx].uSoundID);
        if (!pSoundList->pSounds[uSoundIdx].pSoundData[a7]) // file size == 0
          return;

        AIL_init_sample(pFreeChannel->hSample);
        AIL_set_sample_file(pFreeChannel->hSample, pSoundList->pSounds[uSoundIdx].pSoundData[a7] + (a7 ? 0 : 1), -1);

        if (uVolume)
          AIL_set_sample_volume(pFreeChannel->hSample, uVolume);
        else
          AIL_set_sample_volume(pFreeChannel->hSample, uDefaultVolume);

        v74 = a5;
        if ( a5 != -1 )
        {
          if ( !a5 )
            v74 = pParty_global->sPartyPosX;
          if ( !a6 )
            a6 = pParty_global->sPartyPosY;
          if (uNumRepeats)
            AIL_set_sample_loop_count(pFreeChannel->hSample, uNumRepeats - 1);
          v82 = sub_4AB66C(v74, a6);
          AIL_set_sample_pan(pFreeChannel->hSample, v82);
          v83 = sub_4AB6B1_GetSoundStrengthByDistanceFromParty(v74, a6, pParty_global->sPartyPosZ);
          AIL_set_sample_volume(pFreeChannel->hSample, v83);
          v75 = a3;
          goto LABEL_184;
        }
        v75 = a3;
        if ( (a3 & 7) == 1 )
        {
          if ( uCurrentlyLoadedLevelType != 1 )
            goto LABEL_184;
          v81 = (char *)Src + 80 * (a3 >> 3);
          if ( !*((_DWORD *)v81 + 1) )
            return;
          if ( !sub_4AB6B1_GetSoundStrengthByDistanceFromParty(**((_WORD **)v81 + 14), **((_WORD **)v81 + 15), **((_WORD **)v81 + 16)) )
          {
            AIL_end_sample(pFreeChannel->hSample);
            this->sub_4ABE55(pFreeChannel);
            return;
          }
          v77 = **((_WORD **)v81 + 15);
          v78 = **((_WORD **)v81 + 14);
          goto LABEL_167;
        }
        if ( (a3 & 7) == 2 )
        {
          v76 = (char *)pLayingItemsList + 112 * (a3 >> 3);
          if ( !sub_4AB6B1_GetSoundStrengthByDistanceFromParty(*((_DWORD *)v76 + 1), *((_DWORD *)v76 + 2), *((_DWORD *)v76 + 3)) )
            return;
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v80 = (char *)pActors + 836 * (a3 >> 3);
            if ( !sub_4AB6B1_GetSoundStrengthByDistanceFromParty(*((_WORD *)v80 + 71), *((_WORD *)v80 + 72), *((_WORD *)v80 + 73)) )
              return;
            v77 = *((_WORD *)v80 + 72);
            v78 = *((_WORD *)v80 + 71);
            goto LABEL_167;
          }
          if ( (a3 & 7) != 5 )
          {
LABEL_184:
            if (uNumRepeats)
              AIL_set_sample_loop_count(pFreeChannel->hSample, uNumRepeats - 1);

            pFreeChannel->uSourceTrackIdx = uSoundIdx;
            pFreeChannel->dword_000004 = v75;
            pFreeChannel->uSourceTrackID = a2;
            AIL_start_sample(pFreeChannel->hSample);
            if (sPlaybackRate)
              AIL_set_sample_playback_rate(pFreeChannel->hSample, sPlaybackRate);
            if ( (v75 & 7) == 4 )
              AIL_sample_ms_position(pFreeChannel->hSample, &sLastTrackLengthMS, 0);
            return;
          }
          v76 = (char *)&pLevelDecorations[(a3 >> 3)];
          if ( !sub_4AB6B1_GetSoundStrengthByDistanceFromParty(*((_DWORD *)v76 + 1), *((_DWORD *)v76 + 2), *((_DWORD *)v76 + 3)) )
            return;
          AIL_set_sample_loop_count(pFreeChannel->hSample, uNumRepeats - 1);
        }
        v77 = *((_DWORD *)v76 + 2);
        v78 = *((_DWORD *)v76 + 1);
LABEL_167:
        v79 = sub_4AB66C(v78, v77);
        AIL_set_sample_pan(pFreeChannel->hSample, v79);
        goto LABEL_184;
      }


      v65 = cChannelsToUse.min;
      v95 = uDefaultVolume;
      if (cChannelsToUse.min <= cChannelsToUse.max)
      {
        pFreeChannel = 0;
        for (unsigned int i = cChannelsToUse.min; i <= cChannelsToUse.max; ++i)
        {
         v68 = AIL_sample_volume(pMixerChannels[i].hSample);
         if (v68 < v95)
         {
          v95 = v68;
           pFreeChannel = &pMixerChannels[i];
         }
        }

        /*do
        {
         v68 = AIL_sample_volume(pMixerChannels[i].hSample);
          if ( v68 < v95 )
          {
            v95 = v68;
            pFreeChannel = &pMixerChannels[i];
          }
          ++v65;
          v67 += 16;
        }
        while ( v65 <= cChannelsToUse.max );*/


        if (pFreeChannel)
        {
LABEL_149:
          AIL_end_sample(pFreeChannel->hSample);
          this->sub_4ABE55(pFreeChannel);
          goto LABEL_150;
        }
        v65 = cChannelsToUse.min;
      }
      if ( v65 != 13 )
        return;
      goto LABEL_149;
    }
    if ( (a3 & 7) == 2 )
    {
      cChannelsToUse = Range<unsigned int>(5, 7);
      v57 = (char *)pLayingItemsList + 112 * (a3 >> 3);
    }
    else
    {
      if ( (a3 & 7) == 3 )
      {
        cChannelsToUse = Range<unsigned int>(0, 3);
        v60 = &pActors[a3 >> 3];
        v58 = v60->sActorPosY;
        v86 = v60->sActorPosZ;
        v59 = v60->sActorPosX;
LABEL_116:
        uDefaultVolume = sub_4AB6B1_GetSoundStrengthByDistanceFromParty(v59, v58, v86);
        if ( !uDefaultVolume)
          return;
        goto LABEL_123;
      }
      if ( (a3 & 7) != 5 )
      {
        if ( (a3 & 7) == 6 )
          cChannelsToUse = Range<unsigned int>(8, 9);
        else
          cChannelsToUse = Range<unsigned int>(10, 12);
        goto LABEL_123;
      }
      cChannelsToUse = Range<unsigned int>(4, 4);
      v57 = (char *)&pLevelDecorations[(a3 >> 3)];
    }
    v86 = *((_DWORD *)v57 + 3);
    v58 = *((_DWORD *)v57 + 2);
    v59 = *((_DWORD *)v57 + 1);
    goto LABEL_116;
  }
  v13 = 13;
  if ( a3 < 0 )
  {
    v16 = num_structs_0;
    if ( a3 == -1 )
    {
      if ( v16 < 16 )
        v13 = v16 - 1;
      cChannelsToUse.max = v13;
      goto LABEL_46;
    }
    if ( v16 >= 16 )
      v16 = 14;
    v13 = v16;
    goto LABEL_45;
  }
  if ( (a3 & 7) == 2 )
  {
    v23 = num_structs_0;
    if ( v23 < 16 )
    {
      v13 = 5 * v23 / 16;
      cChannelsToUse.max = 7 * v23 / 16;
    }
    else
    {
      cChannelsToUse.max = 7;
      v13 = 5;
    }
    v18 = (char *)pLayingItemsList + 112 * (a3 >> 3);
  }
  else
  {
    if ( (a3 & 7) == 3 )
    {
      v19 = num_structs_0;
      v13 = 0;
      if ( v19 < 16 )
        cChannelsToUse.max = 3 * v19 / 16;
      else
        cChannelsToUse.max = 3;
      v21 = (char *)pActors + 836 * (a3 >> 3);
      v22 = *((_WORD *)v21 + 72);
      v87 = (double)*((_WORD *)v21 + 71);
      v104 = *((_WORD *)v21 + 73);
      v88 = (double)v22;
      v20 = (double)v104;
      goto LABEL_47;
    }
    if ( (a3 & 7) != 5 )
    {
      v14 = num_structs_0;
      if ( (a3 & 7) == 6 )
      {
        if ( v14 >= 16 )
        {
          cChannelsToUse.max = 9;
          v13 = 8;
          goto LABEL_46;
        }
        v13 = 8 * v14 / 16;
        v15 = 9 * v14;
      }
      else
      {
        if ( v14 >= 16 )
        {
          cChannelsToUse.max = 12;
          v13 = 10;
LABEL_46:
          v87 = (double)pParty_global->sPartyPosX;
          v88 = (double)pParty_global->sPartyPosY;
          v20 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
          goto LABEL_47;
        }
        v13 = 10 * v14 / 16;
        v15 = 12 * v14;
      }
      v16 = v15 / 16;
LABEL_45:
      cChannelsToUse.max = v16;
      goto LABEL_46;
    }
    v17 = num_structs_0;
    if ( v17 < 16 )
    {
      v13 = v17 / 4;
      cChannelsToUse.max = v17 / 4;
    }
    else
    {
      v13 = 4;
      cChannelsToUse.max = 4;
    }
    v18 = (char *)&pLevelDecorations[(a3 >> 3)];
  }
  v87 = (double)*((signed int *)v18 + 1);
  v88 = (double)*((signed int *)v18 + 2);
  v20 = (double)*((signed int *)v18 + 3);
LABEL_47:
  v89 = v20;
  if ( uCurrentlyLoadedLevelType == 1 )
    sub_4AAEA6((int)&v87);
  else
    sub_436523((RenderVertex *)&v87, 1);
  if ( a3 )
  {
    if ( a3 != -1 )
    {
      v105 = 0;
      if (num_structs_0 > 0 )
      {
        v24 = (int)struct_0;
        do
        {
          if ( AIL_3D_sample_status(*(_DWORD *)v24) == 4
            && *(_DWORD *)(v24 + 4) == a3
            && AIL_3D_sample_status(*(_DWORD *)v24) == 4 )
          {
            if ( *(_DWORD *)(v24 + 8) == uSoundIdx)
              return;
            AIL_end_3D_sample(*(_DWORD *)v24);
            AudioPlayer_sub_4ABF23(this, v24);
          }
          ++v105;
          v24 += 16;
        }
        while ( v105 < num_structs_0);
      }
    }
  }
  v106 = v13;
  if ( v13 <= cChannelsToUse.max )
  {
    v25 = (int)&struct_0[v13];
    while ( AIL_3D_sample_status(*(_DWORD *)v25) != 2 )
    {
      ++v106;
      v25 += 16;
      if ( v106 > cChannelsToUse.max )
        goto LABEL_67;
    }
    AIL_end_3D_sample(*(_DWORD *)v25);
    if ( *(_DWORD *)(v25 + 8) )
      AudioPlayer_sub_4ABF23(this, v25);
  }
LABEL_67:
  v26 = cChannelsToUse.max;
  if ( v106 == cChannelsToUse.max + 1 )
  {
    v95 = -1;
    v107 = 0;
    *(float *)&cChannelsToUse.min = v91 * -0.01220703125;
    *(float *)&uDefaultVolume = 0.0;
    v27 = v90 * 0.01220703125;
    *(float *)&uVolume = v27;
    v28 = abs((signed)v27);
    v29 = abs((signed)*(float *)&uDefaultVolume);
    v30 = abs((signed)*(float *)&cChannelsToUse.min);
    v94 = sub_4621DA(v30, v29, v28);
    sPlaybackRate = v13;
    if ( v13 > v26 )
      goto LABEL_192;
    v31 = (int)this;
    v32 = (int)&struct_0[v13];
    do
    {
      AIL_3D_position(v31, *(_DWORD *)v32, (long)&cChannelsToUse.min, (int)&uDefaultVolume, (int)&uVolume);
      v35 = abs((signed)*(float *)&uVolume);
      v36 = abs((signed)*(float *)&uDefaultVolume);
      v37 = abs((signed)*(float *)&cChannelsToUse.min);
      v34 = sub_4621DA(v37, v36, v35);
      v33 = v107 == v34;
      if ( v107 < v34 )
      {
        v107 = v34;
        v33 = 1;
      }
      if ( v33 && v94 < v107 )
      {
        v38 = sPlaybackRate;
        v95 = sPlaybackRate;
      }
      else
      {
        v38 = v95;
      }
      ++sPlaybackRate;
      v32 += 16;
    }
    while ( sPlaybackRate <= cChannelsToUse.max );
    if ( v38 == -1 )
    {
LABEL_192:
      v38 = 13;
      if ( v13 != 13 )
        return;
    }
    v39 = (int)this;
    v40 = (int)&struct_0[v38];
    AIL_end_3D_sample(*(_DWORD *)v40);
    AudioPlayer_sub_4ABF23((AudioPlayer *)v39, v40);
    v106 = v38;
  }
  v41 = v93;
  if ( *(_DWORD *)(v93 + pSoundList->pSounds + 112) || sub_4A9A67(pSoundList, a2, 0) )
  {
    v42 = (int)this + 16 * v106;
    v43 = (int)&struct_0[v106];
    if ( AIL_set_3D_sample_file((long)&bEAXSupported, *(_DWORD *)(v42 + 20), *(_DWORD *)(v41 + pSoundList->pSounds + 112)) )
    {
      if ( uNumRepeats )
        v85 = uNumRepeats - 1;
      else
        v85 = 1;
      AIL_set_3D_sample_loop_count(*(_DWORD *)v43, v85);
      if ( a5 == -1 )
      {
        if ( (a3 & 7) == 1 )
        {
          if ( uCurrentlyLoadedLevelType != 1 )
            goto LABEL_103;
          v49 = (char *)Src + 80 * (a3 >> 3);
          if ( !*((_DWORD *)v49 + 1) )
            return;
          v87 = (double)**((_WORD **)v49 + 14);
          v88 = (double)**((_WORD **)v49 + 15);
          v46 = (double)**((_WORD **)v49 + 16);
LABEL_101:
          v89 = v46;
          if ( uCurrentlyLoadedLevelType == 1 )
          {
            sub_4AAEA6((int)&v87);
            goto LABEL_104;
          }
LABEL_103:
          sub_436523((RenderVertex *)&v87, 1);
LABEL_104:
          AIL_start_3D_sample(*(_DWORD *)v43);
          AIL_set_3D_sample_float_distances(*(_DWORD *)v43, 100.0, 20.0, 100.0, 20.0);
          AIL_set_3D_sample_volume(*(_DWORD *)v43, s3DSoundVolume);
          v103 = v91 * -0.01220703125;
          v50 = v90 * 0.01220703125;
          v102 = v50;
          v51 = abs((signed)v50);
          v52 = abs(0);
          v53 = abs((signed)v103);
          if ( sub_4621DA(v53, v52, v51) <= 100 )
          {
            AIL_set_3D_position(*(_DWORD *)v43, LODWORD(v103), 0.0, LODWORD(v102));
            v54 = -v102;
            v55 = -v103;
            AIL_set_3D_orientation(*(_DWORD *)v43, LODWORD(v55), 0.0, LODWORD(v54), 0.0, 1.0, 0.0);
            v56 = (int)this;
            *(_DWORD *)(v42 + 24) = a3;
            *(_DWORD *)(v42 + 28) = uSoundIdx;
            *(_DWORD *)(16 * (v106 + 2) + v56) = a2;
          }
          else
          {
            AIL_end_3D_sample(*(_DWORD *)v43);
            AudioPlayer_sub_4ABF23(this, v42 + 20);
          }
          return;
        }
        if ( (a3 & 7) == 2 )
        {
          v45 = (char *)pLayingItemsList + 112 * (a3 >> 3);
        }
        else
        {
          if ( (a3 & 7) == 3 )
          {
            v47 = (char *)pActors + 836 * (a3 >> 3);
            v48 = *((_WORD *)v47 + 72);
            v87 = (double)*((_WORD *)v47 + 71);
            v101 = *((_WORD *)v47 + 73);
            v88 = (double)v48;
            v46 = (double)v101;
            goto LABEL_101;
          }
          if ( (a3 & 7) != 5 )
          {
            v87 = (double)pParty_global->sPartyPosX;
            v44 = (double)pParty_global->sPartyPosY;
LABEL_100:
            v88 = v44;
            v46 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
            goto LABEL_101;
          }
          v45 = (char *)&pLevelDecorations[(a3 >> 3)];
        }
        v87 = (double)*((signed int *)v45 + 1);
        v88 = (double)*((signed int *)v45 + 2);
        v46 = (double)*((signed int *)v45 + 3);
        goto LABEL_101;
      }
      v87 = (double)a5;
      v44 = (double)a6;
      goto LABEL_100;
    }
  }
}






//----- (004AA13F) --------------------------------------------------------
Result::Code AudioPlayer::PlayMusicTrack(unsigned int uTrackID)
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_stop(hAILRedbook);
  AIL_redbook_track_info(hAILRedbook, uTrackID, &uCurrentMusicTrackStartMS, &uCurrentMusicTrackEndMS);
  AIL_redbook_play(hAILRedbook, uCurrentMusicTrackStartMS + 1, uCurrentMusicTrackEndMS);

  uCurrentMusicTrackLength = 128 * (uCurrentMusicTrackEndMS - uCurrentMusicTrackStartMS) / 1000;

  return Result::Success;
 }
 return Result::Generic;
}



Result::Code AudioPlayer::PlayMusicTrack(unsigned int uTrackID, float fVolume)
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_stop(hAILRedbook);
  AIL_redbook_track_info(hAILRedbook, uTrackID, &uCurrentMusicTrackStartMS, &uCurrentMusicTrackEndMS);

  AIL_redbook_set_volume(hAILRedbook, fVolume);
  AIL_redbook_play(hAILRedbook, uCurrentMusicTrackStartMS + 1, uCurrentMusicTrackEndMS);

  uCurrentMusicTrackLength = 128 * (uCurrentMusicTrackEndMS - uCurrentMusicTrackStartMS) / 1000;
  sRedbookVolume = AIL_redbook_volume(hAILRedbook);

  return Result::Success;
 }
 return Result::Generic;
}




Result::Code AudioPlayer::StopMusic()
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_stop(hAILRedbook);

  return Result::Success;
 }
 return Result::Generic;
}

Result::Code AudioPlayer::PauseMusic()
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_pause(pAudioPlayer->hAILRedbook);

  return Result::Success;
 }
 return Result::Generic;
}

Result::Code AudioPlayer::ResumeMusic()
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_resume(pAudioPlayer->hAILRedbook);

  return Result::Success;
 }
 return Result::Generic;
}

//----- (MM7.exe::004AA214) --------------------------------------------------------
Result::Code AudioPlayer::SetMasterVolume(float fVolume)
{
 if (bPlayerReady)
 {
  uMasterVolume = fVolume;
  if (hDigDriver)
    AIL_set_digital_master_volume(hDigDriver, uMasterVolume);

  if (b3DSoundInitialized)
    s3DSoundVolume = 0.5f * fVolume;

  return Result::Success;
 }
 return Result::Generic;
}

//----- (004AA1F3) --------------------------------------------------------
Result::Code AudioPlayer::SetMusicVolume(float fVolume)
{
 if (bPlayerReady && hAILRedbook)
 {
  AIL_redbook_set_volume(hAILRedbook, fVolume);
  sRedbookVolume = AIL_redbook_volume(hAILRedbook);

  return Result::Success;
 }
 return Result::Generic;
}



//----- (004AB71F) --------------------------------------------------------
Result::Code AudioPlayer::MessWithChannels(Range<unsigned int> *pChannels)
{
 if (!bPlayerReady || bNoSound)
   return Result::Generic;

 if (b3DSoundInitialized)
 {
  int v3 = 0;
  if (num_structs_0 > 0)
  {
   do
   {
    if (pChannels->InRange(v3))
    {
     if (struct_0[v3].a[2])
     {
      if (pSoundList->pSounds[struct_0[v3].a[2]].dword_000024 != 1 )
      {
       AIL_end_3D_sample(struct_0[v3].a[0]);
       AudioPlayer_sub_4ABF23(this, (int)&struct_0[v3]);
      struct_0[v3].a[2] = 0;
      }
     }
    }
    ++v3;
   }
   while ( v3 < num_structs_0 );
  }
 }


 if (hDigDriver)
   for (unsigned int i = 0; i < uMixerChannels; ++i)
   {
    if (pChannels->InRange(i))
    {
     if (pSoundList->pSounds[pMixerChannels[i].uSourceTrackIdx].dword_000024 != 1)
     {
      AIL_end_sample(pMixerChannels[i].hSample);
      sub_4ABE55(&pMixerChannels[i]);
      pMixerChannels[i].dword_000004 = 0;
     }
    }
   }

 if (hSequence)
   AIL_end_sequence(hSequence);
 if (hStream)
   AIL_pause_stream(hStream, 1);

 return Result::Success;
}

//----- (MM7.exe::004ABAF7) --------------------------------------------------------
HDIGDRIVER AudioPlayer::GetFirstHardwareDigitalDriver()
{
  int v0; // ecx@1
  int i;
  //size_t v2; // eax@4
  int v4; // [sp-4h] [bp-20h]@5
  HDIGDRIVER hDrv;

 AIL_set_preference(15, 0);
 AIL_set_preference(33, 1);

  v0 = dword_4F00DC;

 pDeviceNames[0][0] = 0;
 uNumDevices = 0;

  if (dword_4F00DC < 11025)
    return 0;

 i = 0;
 while (true)
 {
  while (true)
  {
   PCMWAVEFORMAT sPCMWaveFormat;
   sPCMWaveFormat.wf.wFormatTag = 1;
   sPCMWaveFormat.wf.nChannels = dword_4F00E4;
   sPCMWaveFormat.wf.nSamplesPerSec = v0;
   sPCMWaveFormat.wf.nBlockAlign = dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wf.nAvgBytesPerSec = v0 * dword_4F00E4 * dword_4F00E0 / 8;
   sPCMWaveFormat.wBitsPerSample = dword_4F00E0;

   if (!AIL_waveOutOpen(&hDrv, 0, -1, (WAVEFORMAT *)(&sPCMWaveFormat)))
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
    strcpy((char *)pDeviceNames[i], "Device: ");

    AIL_digital_configuration(hDrv, array_000BF0 + i, array_000C30 + i, pDeviceNames[i] + 8);

    uNumDevices = ++i;

    if (AIL_get_preference(15))
      return hDrv;
    if (!strstr(pDeviceNames[i - 1], "Emulated"))
      return hDrv;

    AIL_waveOutClose(v4, (int)hDrv);
    AIL_set_preference(15, 1);
LABEL_8:
    AIL_set_preference(15, 1);
    v0 = dword_4F00DC;
LABEL_12:
    if ( v0 < 11025 )
      return 0;
  }
}
















SoundList::SoundList()
{
 uNumSounds = 0;
 pSounds = 0;

 uTotalLoadedSoundSize = 0;
}

SoundList::~SoundList()
{
}

//----- (004A9E89) --------------------------------------------------------
Result::Code SoundList::Initialize(const wchar_t *pSourceFile)
{
 unsigned int *pRawData = (unsigned int *)LODFile_Events_LOD.LODFile_LoadRaw(pSourceFile, 1);
 if (!pRawData)
   return Result::Generic;

 uNumSounds = *pRawData;

 pSounds = NamedMemAlloc(SoundDesc, uNumSounds, "SoundList::SoundDesc");
 memcpy(pSounds, pRawData + 1, uNumSounds * sizeof(SoundDesc));

 MemFree(pRawData);
 return Result::Success;
}


//----- (004A96FF) --------------------------------------------------------
AudioPlayer::SoundHeader *AudioPlayer::FindSound_BinarySearch(Range<unsigned int> *pSearchRange, const char *pSourceFile)
{
 Range<unsigned int> cBounds = *pSearchRange;

 dword_F1B4C8 = -1;
 while (true)
 {
  unsigned int pCenter = cBounds.min + cBounds.Length() / 2;

  int cmp = strcmpi(pSourceFile, pSoundHeaders[pCenter].pSoundName);
  if (!cmp)
    dword_F1B4C8 = pCenter;

  if (cmp < 0)
    cBounds.max = pCenter;
  else
    cBounds.min = pCenter;

  if (cBounds.Length() < 5)
    break;
 }

 if (dword_F1B4C8 != -1)
   return &pSoundHeaders[dword_F1B4C8];

 for (unsigned int i = _min(cBounds.min, cBounds.min - 12); i < _min(cBounds.max + 16, pSearchRange->max); ++i)
   if (!strcmpi(pSourceFile, pSoundHeaders[i].pSoundName))
   {
    dword_F1B4C8 = i;
    return &pSoundHeaders[i];
   }
 return 0;



/*
  AudioPlayer::SoundHeader *pHeader;


  int v3; // ebx@1
  int v4; // esi@1
  int result; // eax@2
  signed int v6; // ebx@11
  int v7; // eax@11
  char v8; // zf@11
  int v9; // edi@13
  int v10; // esi@14
  int v11; // esi@20
  int v12; // [sp+Ch] [bp-4h]@1

  v3 = pSearchRange->max;
  v12 = pSearchRange->max;
  v4 = pSearchRange->min;

  while ( 1 )
  {
    v6 = v3 - v4;
    v7 = (v6 / 2 + v4);
    v8 = &pAudioPlayer->pSoundHeaders[v7] == 0;
    pHeader = pAudioPlayer->pSoundHeaders + v7;

    if ( v8 )
      return (int)pHeader;

    result = _strcmpi(pSourceFile, pHeader->pSoundName);
    if (!result)
      dword_F1B4C8 = v6 / 2 + v4;

    if ( v4 == v12 )
      goto LABEL_17;

    if ( result < 0 )
      break;
    if ( v6 <= 4 )
    {
      v9 = v4;
      if ( v4 < v12 )
      {
        v11 = 52 * v4;
        do
        {
         result = _strcmpi(pSourceFile, pAudioPlayer->pSoundHeaders[v9].pSoundName);
          if ( !result )
            goto LABEL_24;
          ++v9;
          v11 += 52;
        }
        while ( v9 < v12 );
      }
LABEL_17:
      dword_F1B4C8 = -1;
      return (int)pHeader;
    }
    v4 += v6 / 2;
LABEL_10:
    v3 = v12;
  }
  if ( v6 > 4 )
  {
    v12 = v6 / 2 + v4;
    goto LABEL_10;
  }
  v9 = v4;
  if ( v4 >= v12 )
    goto LABEL_17;
  v10 = 52 * v4;
  while ( 1 )
  {
   result = _strcmpi(pSourceFile, pAudioPlayer->pSoundHeaders[v4].pSoundName);
    if ( !result )
      break;
    ++v9;
    v10 += 52;
    if ( v9 >= v12 )
      goto LABEL_17;
  }
LABEL_24:
  dword_F1B4C8 = v9;
  return (int)pHeader;*/
}



//----- (004A97C6) --------------------------------------------------------
unsigned int *AudioPlayer::LoadSound(const char *pSoundName, unsigned char *pOutBuffer, _DWORD a3)
{
 DWORD w;

 for (unsigned int i = 0; i < 3000; ++i)
   if (struct_F1B4D8[i].dword_000000 == a3)
     return struct_F1B4D8[i].pSoundData;

 SoundHeader *pSoundHeader = pAudioPlayer->FindSound_BinarySearch(&Range<unsigned int>(0, pAudioPlayer->uNumSoundHeaders), pSoundName);
 if (!pSoundHeader)
   return 0;

 if (!pOutBuffer)
   pOutBuffer = NamedMemAlloc(unsigned char, pSoundHeader->uUncompressedSize + 4, pSoundName);

 SetFilePointer(pAudioPlayer->hAudioSnd, pSoundHeader->uFileOffset, 0, FILE_BEGIN);
 if (pSoundHeader->uCompressedSize >= pSoundHeader->uUncompressedSize)
 {
  pSoundHeader->uCompressedSize = pSoundHeader->uUncompressedSize;
  if (pSoundHeader->uUncompressedSize)
    ReadFile(pAudioPlayer->hAudioSnd, pOutBuffer + 4, pSoundHeader->uUncompressedSize, &w, 0);
  else
  {
   Game_sub_40E2C8(0, "Can't load sound file!", 0);
   sub_466D09(0, 0, 0, 0, 0, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Sound.cpp", __LINE__);
  }
 }
 else
 {
  unsigned char *pZipBuffer = MemAlloc(unsigned char, pSoundHeader->uCompressedSize);
  {
   ReadFile(pAudioPlayer->hAudioSnd, pZipBuffer, pSoundHeader->uCompressedSize, &w, 0);
   MemUnzip(pOutBuffer + 4, &pSoundHeader->uUncompressedSize, pZipBuffer, pSoundHeader->uCompressedSize);
  }
  MemFree(pZipBuffer);
 }


 if (pOutBuffer)
 {
  *(unsigned int *)pOutBuffer = pSoundHeader->uUncompressedSize;

  for (unsigned int i = 0; i < 3000; ++i)
    if (!struct_F1B4D8[i].pSoundData)
    {
     dword_F1B4D0 = i;

     lstrcpyA(struct_F1B4D8[i].string_000004, pSoundName);
     struct_F1B4D8[i].dword_000000 = a3;
     struct_F1B4D8[i].pSoundData = (unsigned int *)pOutBuffer;
     break;
    }
  return (unsigned int *)pOutBuffer;
 }

 return 0;
}




//----- (004A9953) --------------------------------------------------------
Result::Code SoundList::LoadSounds()
{
  int v2; // esi@1
  signed int v3; // edi@2
  int v5; // eax@7
  int v6; // ebx@7
  int v8; // eax@7
  int v9; // eax@8
  char v11; // [sp+7Ch] [bp-2Ch]@10
  int v12; // [sp+90h] [bp-18h]@11
  char v13; // [sp+A0h] [bp-8h]@12
  int v14; // [sp+A4h] [bp-4h]@1

  v2 = (int)this;
  v14 = 1;

 if (!pAudioPlayer->b3DSoundInitialized)
   return Result::Success;

 for (unsigned int i = 1; i < uNumSounds; ++i)
 {
  if (!pSounds[i].pSoundName[0])
    continue;

  pSounds[i].pSoundData[0] = pAudioPlayer->LoadSound(pSounds[i].pSoundName, nullptr, pSounds[i].uSoundID);
     
  uTotalLoadedSoundSize += *(pSounds[i].pSoundData[0]);
  if (pSounds[i].dword_000024 != 1 ||
      ~pSounds[i].dword_000028 & 2 || !pSounds[i].pSoundData[0])
    continue;

      v8 = *(pSounds[i].pSoundData[0]);
      v6 = (int)(pSounds[i].pSoundData[0] + 1);
      v5 = AIL_file_type(v6, v8);
      if ( !v5 )
        goto LABEL_15;
      v9 = v5 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          if ( AIL_WAV_info(v6, (int)&v11) )
          {
            if ( v12 != 2 )
            {
              if ( !AIL_decompress_ADPCM((int)&v11, v3 + *(_DWORD *)(v2 + 4) + 112, (int)&v13) )
              {
                *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 112) = 0;
                *(_BYTE *)(v3 + *(_DWORD *)(v2 + 4) + 116) = 1;
              }
            }
          }
          goto LABEL_16;
        }
LABEL_15:
        *(_BYTE *)(v3 + *(_DWORD *)(v2 + 4) + 116) = 0;
        goto LABEL_16;
      }
      *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 112) = *(_DWORD *)(v3 + *(_DWORD *)(v2 + 4) + 44);
LABEL_16:
      SoundList_sub_4A9DCD(v2, v14, 1);
  }

 return Result::Success;
}


//----- (004A9D79) --------------------------------------------------------
void SoundList_sub_4A9D79(SoundList *_this, bool a2)
{
  int i; // ebx@1
  int v3; // edi@1
  void *v4; // esi@1
  int v5; // eax@2
  int v6; // ecx@2
  void *v7; // eax@5

  if (bNoSound)
    return;

  v4 = _this;
  v3 = 0;
  for ( i = 0; i < _this->uNumSounds; ++i, v3 += 120 )
  {
    v5 = (int)&_this->pSounds[i];
    v6 = _this->pSounds[i].dword_000024;
    if ( v6 != 1 )
    {
      if ( a2 || v6 != 4 )
      {
        v7 = _this->pSounds[i].pSoundData[0];
        if ( v7 )
        {
          sub_4A96BE(v7);
          _this->pSounds[i].pSoundData[0] = nullptr;
        }
        _this->pSounds[i].dword_000028 &= 0xFFFFFFFEu;
      }
    }
  }
}

//----- (004A96BE) --------------------------------------------------------
void *__thiscall sub_4A96BE(void *_this)
{
  void *result; // eax@1
  int v2; // esi@1

  v2 = 0;
  result = &struct_F1B4D8[0].pSoundData;
  while ( *(void **)result != _this )
  {
    result = (char *)result + 128;
    ++v2;
    if ( (signed int)result >= (signed int)&unk_F79154 )
      return result;
  }
  //MemFree( (void *)(int)_this);
  MemFree(_this);
  return memset(&struct_F1B4D8[v2], 0, sizeof(struct unnamed_F1B4D8));
}




//----- (004A9A67) --------------------------------------------------------
int sub_4A9A67(SoundList *_this, int a2, int a3)
{
  int v3; // edi@1
  signed int v4; // edx@2
  struct SoundDesc *v9; // eax@3
  int v12; // eax@8
  int v13; // esi@8
  int v14; // eax@12
  int v15; // eax@14
  int v16; // eax@18
  int v17; // eax@20
  int v18; // ebx@20
  int v19; // ebx@20
  int v20; // eax@20
  int v21; // eax@21
  int v22; // ST04_4@26
  char v23[0x78]; // [sp+Ch] [bp-A0h]@12
  char v24; // [sp+84h] [bp-28h]@23
  int v25; // [sp+98h] [bp-14h]@24
  int v26; // [sp+A8h] [bp-4h]@2
  int i;

  if (bNoSound)
    return 0;
  v3 = (int)_this;
  v4 = _this->uNumSounds;
  v26 = 1;
  if (_this->uNumSounds <= 0) // if (nosound)
    return 0;

  v9 = _this->pSounds;
  i = 1;
  while (_this->pSounds[i].dword_000014 != a2)
  {
    v26 = ++i;
    if ( i >= _this->uNumSounds)
      return 0;
  }
  v13 = 120 * i;
  v12 = (int)&_this->pSounds[i];
  if ( *(_DWORD *)(v12 + 40) & 2 && *(_DWORD *)(v12 + 112) || !(*(_DWORD *)(v12 + 40) & 2) && *(_DWORD *)(v12 + 44) )
    return v26;
  wsprintfA(v23, "%s", v12);
  v14 = v13 + *(_DWORD *)(v3 + 4);
  if ( !*(_DWORD *)(v14 + 44) )
    *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 44) = (long)pAudioPlayer->LoadSound(v23, nullptr, *(_DWORD *)(v14 + 32));
  v15 = v13 + *(_DWORD *)(v3 + 4);
  if ( !*(_DWORD *)(v15 + 44) )
    return 0;
  if ( a3 )
    *(_DWORD *)(v15 + 40) |= 1u;
  if ( !pAudioPlayer->b3DSoundInitialized || (v16 = v13 + *(_DWORD *)(v3 + 4), !(*(_BYTE *)(v16 + 40) & 2)) || !*(_DWORD *)(v16 + 44) )
    return v26;
  v19 = *(_DWORD *)(v16 + 44);
  v20 = *(_DWORD *)v19;
  v18 = v19 + 4;
  v17 = AIL_file_type(v18, v20);
  if ( !v17 )
  {
LABEL_29:
    *(_BYTE *)(*(_DWORD *)(v3 + 4) + v13 + 116) = 0;
    return 0;
  }
  v21 = v17 - 1;
  if ( v21 )
  {
    if ( v21 == 1 )
    {
      if ( AIL_WAV_info(v18, (int)&v24) )
      {
        if ( v25 != 2 )
        {
          if ( !AIL_decompress_ADPCM((int)&v24, *(_DWORD *)(v3 + 4) + v13 + 112, (int)&a2) )
          {
            v22 = v26;
            *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 112) = 0;
            *(_BYTE *)(*(_DWORD *)(v3 + 4) + v13 + 116) = 1;
            SoundList_sub_4A9DCD(v3, v22, 0);
          }
        }
      }
      return v26;
    }
    goto LABEL_29;
  }
  *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 112) = *(_DWORD *)(*(_DWORD *)(v3 + 4) + v13 + 44);
  return v26;
}






//----- (004AAFCF) --------------------------------------------------------
void AudioPlayer::sub_4AAFCF()
{
  int v1; // ebx@1
  int v2; // edi@1
  char v3; // zf@1
  int v4; // eax@2
  char v5; // zf@3
  unsigned __int8 v6; // zf@4
  unsigned __int8 v7; // sf@4
  int v8; // esi@5
  int v9; // ebx@6
  int v10; // ebx@9
  int v11; // ebx@10
  int v12; // ebx@11
  double v13; // st7@13
  char *v14; // eax@14
  char *v15; // eax@15
  signed int v16; // edx@15
  char *v17; // eax@19
  double v18; // st6@22
  double v19; // st7@22
  double v20; // st5@23
  double v21; // st3@24
  double v22; // st4@24
  double v23; // st6@28
  double v24; // st7@32
  int v25; // ST1C_4@32
  int v26; // ebx@32
  int v27; // eax@32
  float v28; // ST10_4@34
  float v29; // ST08_4@34
  int v30; // esi@38
  int v34; // esi@44
  signed int v35; // eax@45
  char *v36; // eax@49
  int v37; // eax@50
  char *v38; // edi@50
  int v39; // edx@51
  int v40; // ecx@51
  int v41; // eax@53
  char *v42; // edi@53
  char *v43; // edi@56
  int v44; // eax@57
  int v45; // eax@60
  int v46; // edi@65
  int v47; // eax@68
  int v48; // ebx@68
  __int16 *v49; // esi@68
  int v50; // ST1C_4@68
  int v51; // edi@68
  int v52; // eax@68
  int v53; // edi@69
  __int16 v54; // ax@69
  int v55; // eax@71
  __int16 v56; // ax@73
  signed int v57; // eax@88
  float v58; // [sp+24h] [bp-48h]@13
  float v59; // [sp+28h] [bp-44h]@13
  float v60; // [sp+2Ch] [bp-40h]@21
  float v61; // [sp+30h] [bp-3Ch]@26
  float v62; // [sp+34h] [bp-38h]@26
  float v63; // [sp+38h] [bp-34h]@26
  float v64; // [sp+50h] [bp-1Ch]@1
  float v65; // [sp+54h] [bp-18h]@22
  float v66; // [sp+58h] [bp-14h]@22
  int v67; // [sp+5Ch] [bp-10h]@15
  float v68; // [sp+60h] [bp-Ch]@23
  int v69; // [sp+64h] [bp-8h]@4
  int v70; // [sp+68h] [bp-4h]@1

  runtime_warning();
  return;

  v2 = (int)this;
  v1 = 0;
  v70 = (int)this;
  v3 = *(_DWORD *)(v2 + 668) == 0;
  v64 = 0.0;
  if ( !v3 )
  {
    v4 = v2 + 720;
    *(_DWORD *)v4 -= cEventTimer.int_00001C;
    if ( *(_DWORD *)(v2 + 720) <= 0 )
    {
      v5 = *(_DWORD *)(v2 + 4) == 0;
      *(_DWORD *)v4 = 32;
      if ( !v5 )
      {
        v6 = *(_DWORD *)(v2 + 16) == 0;
        v7 = *(_DWORD *)(v2 + 16) < 0;
        v69 = 0;
        if ( !(v7 | v6) )
        {
          v8 = v2 + 20;
          while ( 1 )
          {
            v9 = *(_DWORD *)(v8 + 4) & 7;
            if ( AIL_3D_sample_status(*(_DWORD *)v8) == 2 )
            {
              AIL_end_3D_sample(*(_DWORD *)v8);
              AudioPlayer_sub_4ABF23((AudioPlayer *)v2, v8);
            }
            if ( AIL_3D_sample_status(*(_DWORD *)v8) != 4 )
              goto LABEL_35;
            v10 = v9 - 1;
            if ( v10 )
              break;
            if ( uCurrentlyLoadedLevelType != 1 )
              goto LABEL_31;
            v17 = (char *)Src + 80 * (*(_DWORD *)(v8 + 4) >> 3);
            if ( *((_DWORD *)v17 + 1) )
            {
              v67 = **((_WORD **)v17 + 14);
              v58 = (double)v67;
              v67 = **((_WORD **)v17 + 15);
              v59 = (double)v67;
              v67 = **((_WORD **)v17 + 16);
              v13 = (double)v67;
              goto LABEL_21;
            }
LABEL_35:
            ++v69;
            v8 += 16;
            if ( v69 >= *(_DWORD *)(v2 + 16) )
            {
              v1 = 0;
              goto LABEL_37;
            }
          }
          v11 = v10 - 1;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( !v12 )
            {
              v15 = (char *)pActors + 836 * (*(_DWORD *)(v8 + 4) >> 3);
              v67 = *((_WORD *)v15 + 71);
              v16 = *((_WORD *)v15 + 72);
              v58 = (double)v67;
              v67 = *((_WORD *)v15 + 73);
              v59 = (double)v16;
              v13 = (double)v67;
              goto LABEL_21;
            }
            if ( v12 != 2 )
            {
              v58 = (double)pParty_global->sPartyPosX;
              v59 = (double)pParty_global->sPartyPosY;
              v13 = (double)pParty_global->uEyelevel + (double)pParty_global->sPartyPosZ;
              goto LABEL_21;
            }
            v14 = (char *)&pLevelDecorations[(*(_DWORD *)(v8 + 4) >> 3)];
          }
          else
          {
            v14 = (char *)pLayingItemsList + 112 * (*(_DWORD *)(v8 + 4) >> 3);
          }
          v58 = (double)*((signed int *)v14 + 1);
          v59 = (double)*((signed int *)v14 + 2);
          v13 = (double)*((signed int *)v14 + 3);
LABEL_21:
          v60 = v13;
          if ( uCurrentlyLoadedLevelType == 1 )
          {
            v19 = *(float *)&dword_51B718;
            v18 = *(float *)&dword_51B71C;
            v65 = flt_51B710;
            LODWORD(v66) = dword_51B714;
            if ( dword_51B6F8 )
            {
              v68 = v58 - (double)pParty_global->sPartyPosX;
              *(float *)&v67 = v59 - (double)pParty_global->sPartyPosY;
              v20 = v60 - (double)pParty_global->sPartyPosZ;
              if ( pD3DRenderer->pRenderD3D3 )
              {
                v22 = *(float *)&v67 * v66 + v68 * v65;
                v21 = v68 * v66 - *(float *)&v67 * v65;
              }
              else
              {
                v22 = v68 * v65 - *(float *)&v67 * v66;
                v21 = v68 * v66 + *(float *)&v67 * v65;
              }
              v61 = v22 * v19 - v20 * v18;
              v62 = v21;
              v63 = v22 * v18 + v20 * v19;
            }
            else
            {
              v68 = v58 - (double)pParty_global->sPartyPosX;
              *(float *)&v67 = v59 - (double)pParty_global->sPartyPosY;
              if ( pD3DRenderer->pRenderD3D3 )
              {
                v61 = *(float *)&v67 * v66 + v68 * v65;
                v23 = v68 * v66 - *(float *)&v67 * v65;
              }
              else
              {
                v61 = v68 * v65 - *(float *)&v67 * v66;
                v23 = v68 * v66 + *(float *)&v67 * v65;
              }
              v62 = v23;
              v63 = v60 - (double)pParty_global->sPartyPosZ;
            }
          }
          else
          {
LABEL_31:
            sub_436523((RenderVertex *)&v58, 1);
          }
          v68 = v62 * -0.01220703125;
          v24 = v61 * 0.01220703125;
          *(float *)&v67 = v24;
          v25 = abs((signed)v24);
          v26 = abs(0);
          v27 = abs((signed)v68);
          if ( sub_4621DA(v27, v26, v25) <= 100 )
          {
            AIL_set_3D_position(*(_DWORD *)v8, LODWORD(v68), 0.0, v67);
            v28 = -*(float *)&v67;
            v29 = -v68;
            AIL_set_3D_orientation(*(_DWORD *)v8, LODWORD(v29), 0.0, LODWORD(v28), 0.0, 1.0, 0.0);
          }
          else
          {
            AIL_end_3D_sample(*(_DWORD *)v8);
            AudioPlayer_sub_4ABF23((AudioPlayer *)v2, v8);
          }
          goto LABEL_35;
        }
      }
LABEL_37:
      if ( *(_DWORD *)(v2 + 1000) > v1 )
      {
        v30 = v2 + 744;
        do
        {
          if ( AIL_sample_status((HSAMPLE)*(_DWORD *)v30) == 2 )
          {
            AIL_end_sample((HSAMPLE)*(_DWORD *)v30);
            this->sub_4ABE55(&this->pMixerChannels[v1]);
          }
          ++v1;
          v30 += 16;
        }
        while ( v1 < *(_DWORD *)(v2 + 1000) );
        v1 = 0;
      }
      v69 = v1;

      //v33 = __SETO__(uMixerChannels, v1);
      //v31 = uMixerChannels == v1;
      //v32 = uMixerChannels - v1 < 0;
      //if ( !((unsigned __int8)(v32 ^ v33) | v31) )
      if (uMixerChannels > v1)
      {
        v34 = v2 + 744;
        while ( 1 )
        {
          v35 = *(_DWORD *)(v34 + 4);
          if ( (*(_DWORD *)(v34 + 4) & 7) == 1 )
          {
            if ( uCurrentlyLoadedLevelType == 1 )
            {
              v43 = (char *)Src + 80 * (v35 >> 3);
              if ( !*((_DWORD *)v43 + 1) )
              {
LABEL_61:
                v2 = v70;
                goto LABEL_62;
              }
              v44 = sub_4AB6B1_GetSoundStrengthByDistanceFromParty(**((_WORD **)v43 + 14), **((_WORD **)v43 + 15), **((_WORD **)v43 + 16));
              if ( !v44 )
              {
LABEL_58:
                AIL_end_sample(*(HSAMPLE *)v34);
                this->sub_4ABE55((AudioPlayer::MixerChannel *)v34);
                goto LABEL_61;
              }
              AIL_set_sample_volume(*(HSAMPLE *)v34, v44);
              v39 = **((_WORD **)v43 + 15);
              v40 = **((_WORD **)v43 + 14);
LABEL_60:
              v45 = sub_4AB66C(v40, v39);
              AIL_set_sample_pan(*(HSAMPLE *)v34, v45);
              goto LABEL_61;
            }
          }
          else
          {
            if ( (*(_DWORD *)(v34 + 4) & 7) == 2 )
            {
              v36 = (char *)pLayingItemsList + 112 * (v35 >> 3);
              goto LABEL_53;
            }
            if ( (*(_DWORD *)(v34 + 4) & 7) == 3 )
            {
              v38 = (char *)pActors + 836 * (v35 >> 3);
              v37 = sub_4AB6B1_GetSoundStrengthByDistanceFromParty(*((_WORD *)v38 + 71), *((_WORD *)v38 + 72), *((_WORD *)v38 + 73));
              if ( !v37 )
                goto LABEL_58;
              AIL_set_sample_volume(*(HSAMPLE *)v34, v37);
              v39 = *((_WORD *)v38 + 72);
              v40 = *((_WORD *)v38 + 71);
              goto LABEL_60;
            }
            if ( (*(_DWORD *)(v34 + 4) & 7) == 5 )
            {
              v36 = (char *)&pLevelDecorations[(v35 >> 3)];
LABEL_53:
              v42 = v36;
              v41 = sub_4AB6B1_GetSoundStrengthByDistanceFromParty(*((_DWORD *)v36 + 1), *((_DWORD *)v36 + 2), *((_DWORD *)v36 + 3));
              if ( !v41 )
                goto LABEL_58;
              AIL_set_sample_volume(*(HSAMPLE *)v34, v41);
              v39 = *((_DWORD *)v42 + 2);
              v40 = *((_DWORD *)v42 + 1);
              goto LABEL_60;
            }
          }
LABEL_62:
          ++v69;
          v34 += 16;
          if ( v69 >= *(_DWORD *)(v2 + 1000) )
          {
            v1 = 0;
            break;
          }
        }
      }
      if ( dword_4E28F8_PartyCantJumpIfTrue != v1 )
      {
        v46 = v2 + 808;
        if ( AIL_sample_status(*(HSAMPLE *)v46) == 4 )
          AIL_end_sample(*(HSAMPLE *)v46);
        return;
      }
      v69 = v1;
      if ( dword_6807E0 <= v1 )
        return;
      while ( 1 )
      {
        LODWORD(v66) = 1;
        v48 = 4 * v69 + 6817720;
        v49 = (short *)&pLevelDecorations[dword_6807B8[v69]];
        v50 = abs(*((_DWORD *)v49 + 3) - pParty_global->sPartyPosZ);
        v51 = abs(*((_DWORD *)v49 + 2) - pParty_global->sPartyPosY);
        v52 = abs(*((_DWORD *)v49 + 1) - pParty_global->sPartyPosX);
        v47 = sub_4621DA(v52, v51, v50);
        if ( v47 <= 8192 )
          break;
LABEL_89:
        ++v69;
        if ( v69 >= dword_6807E0 )
          return;
      }
      v53 = (int)&pDecorationDescriptionList->pDescriptions[*v49];
      v54 = *(_WORD *)(v53 + 74);
      v67 = (~(unsigned __int8)*(_WORD *)(v53 + 74) & 0x40) >> 6;
      if ( HIBYTE(v54) & 3 )
      {
        LOWORD(v47) = v49[13];
        LODWORD(v65) = 0;
        v67 = 2;
        if ( (_WORD)v47 )
        {
          v55 = v47 - 32;
          v49[13] = v55;
          if ( (_WORD)v55 < 0 )
            v49[13] = 0;
        }
      }
      v56 = *(_WORD *)(v53 + 74);
      if ( !(HIBYTE(v56) & 1) )
      {
        if ( !(HIBYTE(v56) & 2) )
          goto LABEL_84;
        if (LODWORD(v65) )
          goto LABEL_85;
      }
      LODWORD(v66) = 0;
      if ( (unsigned int)pParty_global->uCurrentHour >= 5 && (unsigned int)pParty_global->uCurrentHour < 6
        || (unsigned int)pParty_global->uCurrentHour >= 0x14 && (unsigned int)pParty_global->uCurrentHour < 0x15 )
      {
        if ( !v49[13] )
        {
          if ( rand() % 100 < 100 )
            LODWORD(v66) = 1;
        }
        LODWORD(v65) = 1;
      }
LABEL_84:
      if ( !LODWORD(v65) )
      {
LABEL_87:
        if (LODWORD(v66) )
        {
          v57 = 8 * *(_DWORD *)v48;
          LOBYTE(v57) = v57 | 5;
          ((AudioPlayer *)v70)->sub_4AA306(*(_WORD *)(v53 + 76), v57, v67, -1, 0, 0, 0, 0);
        }
        goto LABEL_89;
      }
LABEL_85:
      if ( !v49[13] )
        v49[13] = (rand() % 15 + 1) << 7;
      goto LABEL_87;
    }
  }
}

//----- (004AC041) --------------------------------------------------------
signed int AudioPlayer_sub_4AC041_ProbablyPrepare3DEnv(AudioPlayer *_this)
{
  signed int result; // eax@1
  int v2; // esi@1
  unsigned int v3; // [sp+4h] [bp-4h]@3

  v2 = (int)_this;
  runtime_warning(level name should not be globally-defined);
 MapInfo *pMapInfo = pMapStats->GetMapInfo((char *)pClass51_global->pLocationFileName);
  if (_this->b3DSoundInitialized)
  {
    if (_this->bEAXSupported )
    {
     v3 = pMapInfo->uEAXEnv;
      if ( v3 >= 0x1A )
      {
        result = AudioPlayer_sub_4AC004((int)_this);
        *(_DWORD *)(v2 + 532) = -1;
      }
      else
      {
        AIL_set_3D_provider_preference(*(_DWORD *)(v2 + 12), (int)"EAX environment selection", (int)&v3);
        result = v3;
        *(_DWORD *)(v2 + 532) = v3;
      }
    }
  }
  return 0;
}



//----- (004AA258) --------------------------------------------------------
void __thiscall AudioPlayer_sub_4AA258(AudioPlayer *_this, int a2)
{
  int v2; // esi@1
  int v3; // edi@4
  int v4; // ebx@5
  int v5; // ebx@11
  int v6; // edi@12

  v2 = (int)_this;
  if (_this->bPlayerReady)
  {
    if ( *(_DWORD *)(_this + 4) && a2 && (v3 = 0, *(_DWORD *)(_this + 16) > 0) )
    {
      v4 = (int)_this + 20;
      while ( *(_DWORD *)(v4 + 4) != a2 || AIL_3D_sample_status(*(_DWORD *)v4) != 4 )
      {
        ++v3;
        v4 += 16;
        if ( v3 >= *(_DWORD *)(v2 + 16) )
          goto LABEL_9;
      }
      AIL_end_3D_sample(*(_DWORD *)(16 * v3 + v2 + 20));
    }
    else
    {
LABEL_9:
      if ( *(_DWORD *)(v2 + 680) )
      {
        if ( a2 )
        {
          v5 = 0;
          if ( *(_DWORD *)(v2 + 1000) > 0 )
          {
            v6 = v2 + 744;
            do
            {
              if ( *(_DWORD *)(v6 + 4) == a2 )
              {
                if ( AIL_sample_status(*(HSAMPLE *)v6) == 4 )
                {
                  AIL_end_sample(*(HSAMPLE *)v6);
                  _this->sub_4ABE55(&_this->pMixerChannels[v5]);
                }
              }
              ++v5;
              v6 += 16;
            }
            while ( v5 < *(_DWORD *)(v2 + 1000) );
          }
        }
      }
    }
  }
}



//----- (004AC004) --------------------------------------------------------
int __thiscall AudioPlayer_sub_4AC004(int _this)
{
  int v1; // edi@1
  int result; // eax@2
  int v3; // ST00_4@2
  int v4; // ST00_4@2
  float v5; // [sp+4h] [bp-4h]@2

  v1 = _this;
  if ( *(_DWORD *)_this )
  {
    v3 = *(_DWORD *)(_this + 12);
    v5 = 0.0;
    AIL_set_3D_provider_preference(v3, (int)"EAX effect volume", (int)&v5);
    v4 = *(_DWORD *)(v1 + 12);
    v5 = 1.0;
    result = AIL_set_3D_provider_preference(v4, (int)"EAX damping", (int)&v5);
  }
  return result;
}

//----- (004AC0A2) --------------------------------------------------------
signed int sub_4AC0A2(AudioPlayer *_this)
{
  int v1; // ebx@1
  int v2; // esi@1
  signed int v3; // eax@1
  char v4; // zf@1
  int v5; // edi@2
  int v6; // eax@4
  int v8; // ebx@7
  int v9; // eax@8
  int v10; // ebx@14
  unsigned int v11; // eax@14
  int v12; // [sp+1Ch] [bp-8h]@1
  int v13; // [sp+20h] [bp-4h]@6

  v2 = (int)_this;
  runtime_warning(level name should not be globally-defined);
  //v3 = CMapStats_FindLocation(pMapStats,CurrentLevelName);
  v4 = _this->b3DSoundInitialized == 0;
  v1 = v3;
  v12 = v3;
  if (_this->b3DSoundInitialized)
  {
    v5 = v2 + 16;
    AIL_3D_provider_attribute(_this->h3DSoundProvider, (int)"Maximum supported samples", v2 + 16);
    if ( *(_DWORD *)(v2 + 16) > 32 )
      *(_DWORD *)v5 = 32;
    v6 = *(_DWORD *)v5;
    if ( !*(_DWORD *)v5 )
    {
      *(_DWORD *)(v2 + 4) &= v6;
      return -1;
    }
    v13 = 0;
    if ( v6 > 0 )
    {
      v8 = v2 + 20;
      while ( 1 )
      {
        v9 = AIL_allocate_3D_sample_handle(*(_DWORD *)(v2 + 12));
        *(_DWORD *)v8 = v9;
        if ( !v9 )
          break;
        AIL_set_3D_sample_float_distances(v9, 4096.0, 256.0, 4096.0, 256.0);
        AIL_set_3D_sample_volume(*(_DWORD *)v8, *(_DWORD *)(v2 + 8));
        ++v13;
        v8 += 16;
        if ( v13 >= *(_DWORD *)v5 )
          goto LABEL_12;
      }
      *(_DWORD *)v5 = v13;
LABEL_12:
      v1 = v12;
    }
    if ( *(_DWORD *)v2 )
    {
      v10 = 68 * v1;
      v11 = pMapStats->pMapInfos[v1].uEAXEnv;
      v12 = pMapStats->pMapInfos[v1].uEAXEnv;
      if ( v11 >= 0x1A )
      {
        AudioPlayer_sub_4AC004(v2);
        *(_DWORD *)(v2 + 532) = -1;
      }
      else
      {
        AIL_set_3D_provider_preference(*(_DWORD *)(v2 + 12), (int)"EAX environment selection", (int)&v12);
        *(_DWORD *)(v2 + 532) = v12;
      }
    }
  }
  return 1;
}


//----- (004ABF23) --------------------------------------------------------
int AudioPlayer_sub_4ABF23(AudioPlayer *_this, int a2)
{
  int result; // eax@1
  int v3; // ebx@1
  int v4; // esi@1
  unsigned __int8 v5; // zf@5
  unsigned __int8 v6; // sf@5
  int v7; // edi@6
  int v8; // eax@8
  int v9; // ST04_4@8
  int v10; // ecx@12
  int v11; // eax@13
  int v12; // edi@13
  unsigned __int8 v13; // sf@13
  unsigned __int8 v14; // of@13
  int v15[16]; // [sp+Ch] [bp-48h]@8
  int v16; // [sp+4Ch] [bp-8h]@5
  int v17; // [sp+50h] [bp-4h]@5

  if (bNoSound || !pSoundList)
    return 0;
  result = (int)pSoundList->pSounds;
  v3 = 0;
  v4 = (int)_this;
  if ( pSoundList->pSounds )
  {
    result = 120 * *(_DWORD *)(a2 + 8) + (int)pSoundList->pSounds;
    if ( *(_DWORD *)(result + 36) == 2 )
    {
      if ( *(_DWORD *)(result + 112) )
      {
        if ( !(*(_BYTE *)(result + 40) & 1) )
        {
          v5 = *(_DWORD *)(_this + 16) == 0;
          v6 = *(_DWORD *)(_this + 16) < 0;
          v16 = 0;
          v17 = 0;
          if ( v6 | v5 )
            goto LABEL_16;
          v7 = (int)_this + 20;
          do
          {
            result = *(_DWORD *)(a2 + 12);
            if ( result == *(_DWORD *)(v7 + 12) )
            {
              v8 = v17;
              v9 = *(_DWORD *)v7;
              ++v17;
              v15[v8] = v3;
              result = AIL_3D_sample_status(v9);
              if ( result == 4 )
                ++v16;
            }
            ++v3;
            v7 += 16;
          }
          while ( v3 < *(_DWORD *)(v4 + 16) );
          if ( !v16 )
          {
LABEL_16:
            result = SoundList_sub_4A9DCD((int)pSoundList, *(_DWORD *)(a2 + 8), 1);
            v10 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v11 = v15[v10];
                v12 = 16 * (v11 + 2);
                result = 16 * v11;
                ++v10;
                *(_DWORD *)(v12 + v4) = 0;
                compile_error();//v14 = __SETO__(v10, v17);
                v13 = v10 - v17 < 0;
                *(_DWORD *)(result + v4 + 28) = 0;
              }
              while ( v13 ^ v14 );
            }
          }
        }
      }
    }
  }
  return result;
}


//----- (004ABC9B) --------------------------------------------------------
LSTATUS __stdcall CheckA3DSupport(char a1)
{
  LSTATUS result; // eax@1
  DWORD cbData; // [sp+8h] [bp-Ch]@1
  BYTE Data[4]; // [sp+Ch] [bp-8h]@1
  HKEY hKey; // [sp+10h] [bp-4h]@1

  if (bNoSound)
    return 0;

  hKey = 0;
  cbData = 4;
  *(_DWORD *)Data = 0;
  result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Aureal\\A3D", 0, 0x2001Fu, &hKey);
  if ( !result )
  {
    if ( a1 )
      RegQueryValueExA(hKey, "SplashAudio", 0, 0, &::Data, &cbData);
    else
      *(_DWORD *)Data = *(_DWORD *)&::Data;
    RegSetValueExA(hKey, "SplashAudio", 0, 4u, Data, 4u);
    *(_DWORD *)Data = 0;
    if ( a1 )
      RegQueryValueExA(hKey, "SplashScreen", 0, 0, &dword_F1B4B0, &cbData);
    else
      *(_DWORD *)Data = *(_DWORD *)&dword_F1B4B0;
    RegSetValueExA(hKey, "SplashScreen", 0, 4u, Data, 4u);
    result = RegCloseKey(hKey);
  }
  return result;
}

//----- (004ABD5B) --------------------------------------------------------
void __thiscall AudioPlayer_sub_4ABD5B(int _this)
{
  int v1; // edi@1
  int v2; // esi@1
  int v3; // ebx@3
  int v4; // ebx@6
  int v5; // edi@7
  int v6; // edi@13
  int v7; // edx@14
  int v8; // ecx@14
  void *v9; // ecx@15

  v2 = _this;
  v1 = 0;
  if ( *(_DWORD *)(_this + 668) )
  {
    CloseHandle(pVideoPlayer->hMightVid);
    CloseHandle(pVideoPlayer->hMagicVid);
    pAudioPlayer->MessWithChannels(&Range<unsigned int>(0, 16));
    if ( *(_DWORD *)(v2 + 1000) > 0 )
    {
      v3 = v2 + 744;
      do
      {
        AIL_release_sample_handle(*(_DWORD *)v3);
        ++v1;
        v3 += 16;
      }
      while ( v1 < *(_DWORD *)(v2 + 1000) );
    }
    if ( ReadWindowsRegistry("Disable3DSound", 0) != 1 )
    {
      v4 = 0;
      CheckA3DSupport(0);
      if ( *(_DWORD *)(v2 + 16) > 0 )
      {
        v5 = v2 + 20;
        do
        {
          if ( *(_DWORD *)v5 )
          {
            AIL_release_3D_sample_handle(*(_DWORD *)v5);
            *(_DWORD *)v5 = 0;
          }
          ++v4;
          v5 += 16;
        }
        while ( v4 < *(_DWORD *)(v2 + 16) );
      }
      if ( *(_DWORD *)(v2 + 12) )
      {
        AIL_close_3D_provider(*(_DWORD *)(v2 + 12));
        *(_DWORD *)(v2 + 12) = 0;
      }
    }
    v6 = v2 + 676;
    if ( *(_DWORD *)(v2 + 676) )
    {
      AIL_redbook_stop(*(HREDBOOK *)(v2 + 676));
      //AIL_redbook_set_volume((HREDBOOK)v8, v7, *(_DWORD *)v6, *(_DWORD *)(v2 + 536));
      AIL_redbook_set_volume((HREDBOOK)v8, v7);
      AIL_redbook_close(*(_DWORD *)v6);
    }
    AIL_shutdown();
    sub_4A9D3E(pSoundList);
    v9 = *(void **)(v2 + 3192);
    if ( v9 )
      sub_4A96BE(v9);
    CloseHandle(*(HANDLE *)(v2 + 700));
  }
}



//----- (004ABE55) --------------------------------------------------------
int AudioPlayer::sub_4ABE55(AudioPlayer::MixerChannel *pChannel)
{
  unsigned __int8 v5; // zf@5
  unsigned __int8 v6; // sf@5
  int v10; // ecx@12
  int v11; // edi@13
  int v14[16]; // [sp+Ch] [bp-48h]@8
  int v15; // [sp+4Ch] [bp-8h]@5
  int v16; // [sp+50h] [bp-4h]@5

 if (bNoSound || !pSoundList || !pSoundList->pSounds)
   return 0;

 SoundDesc *pDesc = &pSoundList->pSounds[pChannel->uSourceTrackIdx];
 if (pDesc->dword_000024 == 2 &&
     pDesc->pSoundData[0])
 {
  if (~pDesc->dword_000028 & 0x01)
  {
          v5 = uMixerChannels == 0;
          v6 = uMixerChannels < 0;
          v15 = 0;
          v16 = 0;


      for (unsigned int i = 0; i < uMixerChannels; ++i)
      {
            if (pChannel->uSourceTrackID == pMixerChannels[i].uSourceTrackID)
            {
              ++v16;
              v14[v16++] = i;
              if (AIL_sample_status(pMixerChannels[i].hSample) == AIL::Sample::Playing)
                ++v15;
            }
      }


          if (!v15 || !uMixerChannels)
          {
            SoundList_sub_4A9DCD((int)pSoundList, pChannel->uSourceTrackIdx, 1);
            v10 = 0;
            if ( v16 > 0 )
            {
              do
              {
                v11 = 16 * v14[v10];
                int result = 16 * (v14[v10++] + 47);
                *(_DWORD *)(v11 + (int)this + 756) = 0;
                //v13 = __SETO__(v10, v16);
                //v12 = v10 - v16 < 0;
                *(_DWORD *)(result + (int)this) = 0;
              }
              while (v10 < v16);
            }
          }
        }
    }
}



//----- (004A9DCD) --------------------------------------------------------
int __thiscall SoundList_sub_4A9DCD(int _this, int a2, char a3)
{
  int result; // eax@1
  int v4; // edi@1
  int v5; // esi@1
  void *v6; // ecx@8

  v5 = 120 * a2;
  v4 = _this;
  result = 120 * a2 + *(_DWORD *)(_this + 4);
  if ( *(_DWORD *)(result + 36) != 1 )
  {
    if ( *(_BYTE *)(result + 40) & 2 )
    {
      if ( *(_DWORD *)(result + 112) )
      {
        if ( a3 )
        {
          if ( *(_BYTE *)(result + 116) )
            AIL_mem_free_lock(*(_DWORD *)(result + 112));
          *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 112) = 0;
          *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 40) &= 0xFFFFFFFEu;
        }
      }
    }
    result = *(_DWORD *)(v4 + 4);
    v6 = *(void **)(result + v5 + 44);
    if ( v6 )
    {
      sub_4A96BE(v6);
      *(_DWORD *)(*(_DWORD *)(v4 + 4) + v5 + 44) = 0;
      result = *(_DWORD *)(v4 + 4) + v5 + 40;
      *(_DWORD *)result &= 0xFFFFFFFEu;
    }
  }
  return result;
}


//----- (004AB6B1) --------------------------------------------------------
int __fastcall sub_4AB6B1_GetSoundStrengthByDistanceFromParty(int a1, int a2, int a3)
{
  int v3; // esi@1
  int v4; // edi@1
  int v5; // ST08_4@1
  int v6; // esi@1
  int v7; // eax@1
  int result; // eax@2
  int v9; // [sp+10h] [bp+8h]@1

  v3 = a2;
  v4 = a1;
  v5 = abs(a3 - pParty_global->sPartyPosZ);
  v6 = abs(v3 - pParty_global->sPartyPosY);
  v7 = abs(v4 - pParty_global->sPartyPosX);
  v9 = sub_4621DA(v7, v6, v5);
  if ( v9 <= 8192 )
    result = 114 - (signed __int64)((double)v9 * (1.0 / 8192.0) * 100.0);
  else
    result = 0;
  return result;
}
