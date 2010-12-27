#pragma once
#include "CoreDefinitions.h"
#include "Extras\List.h"


struct Event
{
 int          dword_000000; // event type?
 int          dword_000004;
 unsigned int uEventOffsetInEVT; // dword @ 000008
};
//sizeof == 0C




void Level_LoadEvtAndStr(const char *pLevelName);

void LoadLevel_InitializeLevelStr();
void LoadLevel_InitializeLevelEvt();











/*
class EventEngine
{
 public:
            EventEngine();
   virtual ~EventEngine();

   Result::Code Initialize();
   Result::Code LoadModule(const char *pModuleName);

 protected:
   struct EventModule
   {
    unsigned int   uModuleSize;
    unsigned char *pModule;
    unsigned int   uNumEvents;
    Event         *pEvents;
   };

   List<EventModule *> cModules;
};
*/
