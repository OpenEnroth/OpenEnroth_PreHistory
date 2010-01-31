#include <windows.h>

void nullsub_1();

extern int bUseLoResSprites;
extern int bUseRegistry;
extern int bLoadingFromCD;

extern float aMusicVolumeLevels[];

extern unsigned char byte_4D8410[];
extern unsigned char memory_4F2688[];

extern unsigned char *aNPCProfessionNames[];
extern unsigned char *aAMPMNames[];
extern unsigned char *aMoonPhaseNames[];
extern unsigned char *aSpellNames[];
extern unsigned char *aCharacterConditionNames[];
extern unsigned char *aSkillNames[];
extern unsigned char *aClassNames[];
extern unsigned char *aMonthNames[];
extern unsigned char *aDayNames[];
extern unsigned char *aSpellSchoolNames[];
extern unsigned char *aAttributeNames[];
extern unsigned char *pGlobalTXT_LocalizationStrings[];

extern PCMWAVEFORMAT sPCMWaveFormat;



extern struct CD3DRenderer *pD3DRenderer;
extern struct class17      *pClass17_Icons_LOD;
extern struct class17      *pClass17_Events_LOD;
extern struct class17      *pClass17_Bitmaps_LOD;
extern struct class17      *pClass17_Sprites_LOD;
extern struct class31      *pClass31_global;
extern struct CVideoPlayer *pVideoPlayer;
extern char class28_global[];
extern char class23_instance[];


extern char ExistingFileName[];
extern unsigned char pStringBuffer[];


extern unsigned char cGameCDDriveLetter;


extern void *Dst_global;










int __fastcall ReadWindowsRegistry(const char *pKeyName, int iDefaultValue);
LSTATUS __stdcall sub_4ABC9B(char a1);


void *__stdcall call_new(int, int, int);
int             call_delete(int result, unsigned int a2);