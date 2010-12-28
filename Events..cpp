#include "Events.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"








//----- (00444360) --------------------------------------------------------
void Level_LoadEvtAndStr(const char *pLevelName)
{
 char pEvtFilename[128],
      pStrFilename[128];

 wsprintfA(pEvtFilename, "%s.evt", pLevelName);
 uLevelEVT_Size = LoadFileToBuffer(pEvtFilename, pLevelEVT, 9216);

 wsprintfA(pStrFilename, "%s.str", pLevelName);
 uLevelStrFileSize = LoadFileToBuffer(pStrFilename, pLevelStr, 9216);

 if (uLevelStrFileSize)
   LoadLevel_InitializeLevelStr();

 if (uLevelEVT_Size)
   LoadLevel_InitializeLevelEvt();
}



//----- (00443EF8) --------------------------------------------------------
void __cdecl LoadLevel_InitializeLevelEvt()
{
 int i, j;

 if (!uLevelEVT_Size)
   return;

 memset(&array_5B5928, 0, 100 * sizeof(unnamed_5B5928));

 dword_5B65C8 = 0;

 uLevelEVT_NumEvents = 0;
 memset(pLevelEVT_Events, 128, 4400 * 12);

 for (i = 0, j = 0; j < uLevelEVT_Size; ++i)
 {
  pLevelEVT_Events[i].dword_000000 = pLevelEVT[j + 1] + ((unsigned short)pLevelEVT[j + 2] << 8);
  pLevelEVT_Events[i].dword_000004 = pLevelEVT[j + 3];
  pLevelEVT_Events[i].uEventOffsetInEVT = j;
  j += pLevelEVT[j] + 1;

  uLevelEVT_NumEvents++;
 }
}



//----- (00443E31) --------------------------------------------------------
void __cdecl LoadLevel_InitializeLevelStr()
{
 unsigned int uMaxStringLen; // esi@1
  int v5; // ebx@4
  char errstr[100]; // [sp+Ch] [bp-68h]@9
  int v10; // [sp+70h] [bp-4h]@1
 int i;

 memset(uLevelStrOffsets, 0, 500 * sizeof(unsigned int));

 uMaxStringLen = 0;
 uLevelStrNumStrings = 0;

 v10 = 0;
 for (i = 0; i < uLevelStrFileSize; ++i)
 {
     if ( !pLevelStr[i] )
      {
       uLevelStrOffsets[uLevelStrNumStrings++] = i + 1;
       if ( (signed __int16)(i - (_WORD)v10) > uMaxStringLen )
         uMaxStringLen = i - v10;
       v10 = i;
     }
 }
 uLevelStrNumStrings--;

 if (uMaxStringLen > 800 )
 {
   wsprintfA(errstr, "MAX_EVENT_TEXT_LENGTH needs to be increased to %lu", uMaxStringLen + 1);
   erroneous_printf(errstr);
 }

 for (i = 0; i < uLevelStrNumStrings; ++i)
 {
  if (RemoveQuote((char *)&pLevelStr[uLevelStrOffsets[i]]) != &pLevelStr[uLevelStrOffsets[i]] )
    uLevelStrOffsets[i]++;
 }
}




//----- (00443DA1) --------------------------------------------------------
int Initialize_GlobalEVT()
{
 int result;
  int v1; // esi@1
 struct Event *pEvent;

 uGlobalEVT_Size = LoadFileToBuffer("global.evt", pGlobalEVT, 46080);

 uGlobalEVT_NumEvents = 0;
 memset(pGlobalEVT_Events, 128, 4400 * sizeof(struct Event));
 pEvent = pGlobalEVT_Events + uGlobalEVT_NumEvents; //result = 12 * uGlobalEVT_NumEvents + (pGlobalEVT_Events + 4);
 for (v1 = 0; v1 < uGlobalEVT_Size; v1 += pGlobalEVT[v1] + 1)
 {
      uGlobalEVT_NumEvents++;
      pEvent->dword_000000 = pGlobalEVT[v1 + 1] + ((unsigned int)pGlobalEVT[v1 + 2] << 8);
      pEvent->dword_000004 = pGlobalEVT[v1 + 3];
      pEvent->uEventOffsetInEVT = v1;
      pEvent++;//result += 12;
 }
 return uGlobalEVT_Size;
}
















/*
Result::Code EventEngine::LoadModule(const char *pModuleName)
{
 EventModule *pModule = MemAlloc(EventEngine::EventModule, 1);

 pModule->pModule = MemAlloc(unsigned char, 46080);
 pModule->uModuleSize = LoadFileToBuffer(pModuleName, pModule->pModule, 46080);

 pModule->pEvents = MemAlloc(Event, 4400);
 memset(pModule->pEvents, 128, 4400 * sizeof(Event));

 pModule->uNumEvents = 0;

 Event *pEvent = pModule->pEvents;
 for (unsigned int i = 0; i < pModule->uModuleSize; i += pModule->pModule[i] + 1)
 {
  pEvent->dword_000000 = pModule->pModule[v1 + 1] + ((unsigned int)pModule->pModule[v1 + 2] << 8);
  pEvent->dword_000004 = pModule->pModule[v1 + 3];
  pEvent->uEventOffsetInEVT = i;

  pEvent++;
  pModule->uNumEvents++;
 }

 return Result::Success;
}

Result::Code EventEngine::Initialize()
{
 cModules.Clear();

 return Result::Success;
}

EventEngine::EventEngine()
{
}

EventEngine::~EventEngine()
{
}

*/