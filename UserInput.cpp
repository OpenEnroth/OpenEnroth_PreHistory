#include <windows.h>

#include "UserInput.h"
#include "Game.h"

#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"



//----- (00459ED1) --------------------------------------------------------
void UserInput::sub_459ED1(int a2)
{
 if (pKeyboard->bUsingAsyncClass)
 {
  if (pAsyncKeyboard)
    CAsyncKeyboard_Resume(pAsyncKeyboard);
 }

 dword_000204 = 0;

 if (ptr_000208)
   ptr_000208[16] = a2;
}


//----- (00459F10) --------------------------------------------------------
bool UserInput::sub_459F10(unsigned int uKey)
{
  int v3; // [sp-4h] [bp-4h]@3

 uLastKeyPressed = uKey;
  if ( dword_506E68 == -1 )
  {
    if ( dword_69B004 == 1 )
    {
      if ( uKey != 8 )
      {
        if ( uKey == 9 )
          return 1;
        if ( uKey == 13 )
          goto LABEL_3;
        if ( uKey == 27 )
          goto LABEL_15;
        if (uNumKeysPressed >= dword_0000FC)
          return true;
        pPressedKeysBuffer[uNumKeysPressed++] = uKey;
LABEL_24:
        pPressedKeysBuffer[uNumKeysPressed] = 0;
        return true;
      }
    }
    else
    {
      if ( dword_69B004 != 2 )
        return 0;
      if ( uKey != 8 )
      {
        if ( uKey == 13 )
          goto LABEL_3;
        if ( uKey != 27 )
        {
          if ( uKey >= 48 )
          {
            if ( uKey <= 57 )
            {
              if ( (signed int)(unsigned __int8)uNumKeysPressed < dword_0000FC)
                pPressedKeysBuffer[uNumKeysPressed++] = uKey;
            }
          }
          return true;
        }
LABEL_15:
        v3 = 3;
        goto LABEL_4;
      }
    }
    if (!uNumKeysPressed)
      return true;
    --uNumKeysPressed;
    goto LABEL_24;
  }
 pPressedKeysBuffer[uNumKeysPressed++] = uKey;
 pPressedKeysBuffer[uNumKeysPressed] = 0;

LABEL_3:
  v3 = 2;

LABEL_4:
 pUserInput->sub_459ED1(v3);
 return true;
}

//----- (00459E5A) --------------------------------------------------------
void UserInput::sub_459E5A(int a2, int a3, int a4)
{
  int v4; // esi@1

  v4 = (int)this;
 memset(pPressedKeysBuffer, 0, 257);
  *(_BYTE *)(v4 + 513) = 0;
  if ( a2 )
    *(_DWORD *)(v4 + 516) = 2;
  else
    *(_DWORD *)(v4 + 516) = 1;
  *(_DWORD *)(v4 + 252) = a3;
  *(_DWORD *)(v4 + 520) = a4;
  *(_DWORD *)(a4 + 64) = 1;
  if (pKeyboard->bUsingAsyncClass)
  {
    if (pAsyncKeyboard)
      CAsyncKeyboard_suspend(pAsyncKeyboard);
  }
}

//----- (0045A960) --------------------------------------------------------
LSTATUS __fastcall sub_45A960(const CHAR *a1, const char *a2)
{
  const CHAR *v3; // esi@1
  char *v4; // eax@1
  char *v5; // eax@1
  char *v6; // eax@1
  char *v7; // eax@1
  char *v8; // eax@1
  char *v9; // eax@1
  char *v10; // eax@1
  char *v11; // eax@1
  char *v12; // eax@1
  char *v13; // eax@1
  char *v14; // eax@1
  char *v15; // eax@1
  char *v16; // eax@1
  char *v17; // eax@1
  char *v18; // eax@1
  char *v19; // eax@1
  char *v20; // eax@1
  char *v21; // eax@1
  char *v22; // eax@1
  char *v23; // eax@1
  char *v24; // eax@1
  char *v25; // eax@1
  char *v26; // eax@1
  char *v27; // eax@1
  char *v28; // eax@1
  char *v29; // eax@1
  char *v30; // eax@1
  char *v31; // eax@1

  v3 = a1;
  v4 = sub_45AE2C(*((_DWORD *)a1 + 3));
  CreateRegistryKey("Keyboard::Key::Forward", v4);
  v5 = sub_45AE2C(*((_DWORD *)v3 + 4));
  CreateRegistryKey("KEY_BACKWARD", v5);
  v6 = sub_45AE2C(*((_DWORD *)v3 + 5));
  CreateRegistryKey("KEY_LEFT", v6);
  v7 = sub_45AE2C(*((_DWORD *)v3 + 6));
  CreateRegistryKey("KEY_RIGHT", v7);
  v8 = sub_45AE2C(*((_DWORD *)v3 + 11));
  CreateRegistryKey("Keyboard::Key::Attack", v8);
  v9 = sub_45AE2C(*((_DWORD *)v3 + 10));
  CreateRegistryKey("Keyboard::Key::CastREADY", v9);
  v10 = sub_45AE2C(*((_DWORD *)v3 + 7));
  CreateRegistryKey("Keyboard::Key::Yell", v10);
  v11 = sub_45AE2C(*((_DWORD *)v3 + 8));
  CreateRegistryKey("Keyboard::Key::Jump", v11);
  v12 = sub_45AE2C(*((_DWORD *)v3 + 9));
  CreateRegistryKey("KEY_COMBAT", v12);
  v13 = sub_45AE2C(*((_DWORD *)v3 + 12));
  CreateRegistryKey("KEY_EVENTTRIGGER", v13);
  v14 = sub_45AE2C(*((_DWORD *)v3 + 13));
  CreateRegistryKey("Keyboard::Key::Cast", v14);
  v15 = sub_45AE2C(*((_DWORD *)v3 + 14));
  CreateRegistryKey("Keyboard::Key::Pass", v15);
  v16 = sub_45AE2C(*((_DWORD *)v3 + 15));
  CreateRegistryKey("KEY_CHARCYCLE", v16);
  v17 = sub_45AE2C(*((_DWORD *)v3 + 16));
  CreateRegistryKey("KEY_QUEST", v17);
  v18 = sub_45AE2C(*((_DWORD *)v3 + 17));
  CreateRegistryKey("KEY_QUICKREF", v18);
  v19 = sub_45AE2C(*((_DWORD *)v3 + 18));
  CreateRegistryKey("Keyboard::Key::Rest", v19);
  v20 = sub_45AE2C(*((_DWORD *)v3 + 19));
  CreateRegistryKey("KEY_TIMECAL", v20);
  v21 = sub_45AE2C(*((_DWORD *)v3 + 20));
  CreateRegistryKey("KEY_AUTONOTES", v21);
  v22 = sub_45AE2C(*((_DWORD *)v3 + 21));
  CreateRegistryKey("KEY_MAPBOOK", v22);
  v23 = sub_45AE2C(*((_DWORD *)v3 + 23));
  CreateRegistryKey("KEY_LOOKUP", v23);
  v24 = sub_45AE2C(*((_DWORD *)v3 + 24));
  CreateRegistryKey("KEY_LOOKDOWN", v24);
  v25 = sub_45AE2C(*((_DWORD *)v3 + 25));
  CreateRegistryKey("KEY_CENTERVIEWPT", v25);
  v26 = sub_45AE2C(*((_DWORD *)v3 + 26));
  CreateRegistryKey("KEY_ZOOMIN", v26);
  v27 = sub_45AE2C(*((_DWORD *)v3 + 27));
  CreateRegistryKey("KEY_ZOOMOUT", v27);
  v28 = sub_45AE2C(*((_DWORD *)v3 + 28));
  CreateRegistryKey("KEY_FLYUP", v28);
  v29 = sub_45AE2C(*((_DWORD *)v3 + 29));
  CreateRegistryKey("KEY_FLYDOWN", v29);
  v30 = sub_45AE2C(*((_DWORD *)v3 + 30));
  CreateRegistryKey("Keyboard::Key::Land", v30);
  v31 = sub_45AE2C(*((_DWORD *)v3 + 22));
  CreateRegistryKey("KEY_ALWAYSRUN", v31);
 return 0;
}

//----- (0045AE2C) --------------------------------------------------------
char *__stdcall sub_45AE2C(signed int a1)
{
  const char *v2; // [sp-4h] [bp-8h]@2

  if ( a1 == 38 )
  {
    v2 = "UP";
LABEL_53:
    strcpy(&word_69ADE0, v2);
    return &word_69ADE0;
  }
  if ( a1 == 40 )
  {
    v2 = "DOWN";
    goto LABEL_53;
  }
  if ( a1 == 37 )
  {
    v2 = "бкебн";
    goto LABEL_53;
  }
  if ( a1 == 39 )
  {
    v2 = "бопюбн";
    goto LABEL_53;
  }
  if ( a1 == 13 )
  {
    v2 = "RETURN";
    goto LABEL_53;
  }
  if ( a1 == 32 )
  {
    v2 = "SPACE";
    goto LABEL_53;
  }
  if ( a1 == 34 )
  {
    v2 = "PAGE_DOWN";
    goto LABEL_53;
  }
  if ( a1 == 33 )
  {
    v2 = "PAGE_UP";
    goto LABEL_53;
  }
  if ( a1 == 9 )
  {
    v2 = "TAB";
    goto LABEL_53;
  }
  if ( a1 == 109 )
  {
    v2 = "SUBTRACT";
    goto LABEL_53;
  }
  if ( a1 == 107 )
  {
    v2 = "ADD";
    goto LABEL_53;
  }
  if ( a1 == 35 )
  {
    v2 = "END";
    goto LABEL_53;
  }
  if ( a1 == 46 )
  {
    v2 = "DELETE";
    goto LABEL_53;
  }
  if ( a1 == 36 )
  {
    v2 = "HOME";
    goto LABEL_53;
  }
  if ( a1 == 45 )
  {
    v2 = "INSERT";
    goto LABEL_53;
  }
  if ( a1 == 110 )
  {
    v2 = "DECIMAL";
    goto LABEL_53;
  }
  if ( a1 == 188 )
  {
    v2 = "COMMA";
    goto LABEL_53;
  }
  if ( a1 == 186 )
  {
    v2 = "SEMICOLON";
    goto LABEL_53;
  }
  if ( a1 == 190 )
  {
    v2 = "PERIOD";
    goto LABEL_53;
  }
  if ( a1 == 191 )
  {
    v2 = "SLASH";
    goto LABEL_53;
  }
  if ( a1 == 222 )
  {
    v2 = "SQUOTE";
    goto LABEL_53;
  }
  if ( a1 == 220 )
  {
    v2 = "BACKSLASH";
    goto LABEL_53;
  }
  if ( a1 == 17 )
  {
    v2 = "CONTROL";
    goto LABEL_53;
  }
  if ( a1 == 8 )
  {
    v2 = "BACKSPACE";
    goto LABEL_53;
  }
  if ( a1 < 65 || a1 > 90 )
  {
    v2 = "-мер -";
    goto LABEL_53;
  }
  word_69ADE0 = a1;
 // *(_WORD *)&word_69ADE0 = (unsigned __int8)word_69ADE0;
  return &word_69ADE0;
}

unsigned int UserInput::GetVirtualCodeMappings(unsigned int *pOutKeys)
{
 memcpy(pOutKeys, pVirtualKeyCodesMapping, 30 * sizeof(unsigned int));
 return Error::Success;
}

//----- (00459C82) --------------------------------------------------------
int UserInput::sub_459C82_LooksLikeBindKey(unsigned int uKey)
{
  return pVirtualKeyCodesMapping[uKey];
}


bool UserInput::IsShiftToggled()
{
 return pKeyboard->IsShiftToggled();
}

//----- (0045B06E) --------------------------------------------------------
bool Win32Keyboard::IsShiftToggled()
{
 if (bUsingAsyncClass)
 {
  if (CAsyncKeyboard_sub_45B4EC((void *)pAsyncKeyboard, 0x2A))
      return true;
  return CAsyncKeyboard_sub_45B4EC((void *)pAsyncKeyboard, 0x36);
 }
 else
   return GetAsyncKeyState(VK_SHIFT) != 0;
}


//----- (MM7.exe::0045AFD9) --------------------------------------------------------
Win32Keyboard::Win32Keyboard()
{
 detor_ptr = (void (*)(OSKeyboard *))0x4D86B4;
 bUsingAsyncClass = false;

 if (dword_F79D7C == 2)
 {
  if (dword_F79D70 == 4)
    bUsingAsyncClass = false;
 }
}

//----- (0045B0A9) --------------------------------------------------------
bool Win32Keyboard::IsKeyBeingHeld(unsigned int vKey)
{
 if (bUsingAsyncClass)
 {
  EnterCriticalSection(&pGame->class01_obj->cs4);
  bool v4 = *((_BYTE *)pAsyncKeyboard + CAsyncKeyboard_sub_45B57D((void *)pAsyncKeyboard, vKey) + 265) >> 7;
  LeaveCriticalSection(&pGame->class01_obj->cs4);
  return v4;
 }
 else
   return (GetAsyncKeyState(vKey) & 0x8001) != 0;
}


//----- (0045B0CE) --------------------------------------------------------
bool Win32Keyboard::IsKeyPressed(unsigned int vKey)
{
 if (bUsingAsyncClass)
 {
  EnterCriticalSection(&pGame->class01_obj->cs4);
  bool v4 = *((_BYTE *)pAsyncKeyboard + CAsyncKeyboard_sub_45B57D((void *)pAsyncKeyboard, vKey) + 521) >> 7;
  LeaveCriticalSection(&pGame->class01_obj->cs4);
  return v4;
 }
 else
   return GetAsyncKeyState(vKey) & 1;
}










bool UserInput::IsKeyToggled(Keyboard::Key::Type eKey)
{
 if (eKey > 29)
   return false;

 if (pActionToggleConditions[eKey] == Keyboard::Toggle::Holding)
   return pKeyboard->IsKeyBeingHeld(pVirtualKeyCodesMapping[eKey]);
 else
   return pKeyboard->IsKeyPressed(pVirtualKeyCodesMapping[eKey]);
}



//----- (00459CC4) --------------------------------------------------------
unsigned int UserInput::SetDefaultKeyMapping()
{
 pVirtualKeyCodesMapping[Keyboard::Key::Forward] = KeyNameToVKeyCode("UP");
 pActionToggleConditions[Keyboard::Key::Forward] = Keyboard::Toggle::Holding;

 pVirtualKeyCodesMapping[Keyboard::Key::Backwards] = KeyNameToVKeyCode("DOWN");
 pActionToggleConditions[Keyboard::Key::Backwards] = Keyboard::Toggle::Holding;

 pVirtualKeyCodesMapping[Keyboard::Key::TurnLeft] = KeyNameToVKeyCode("бкебн");
 pActionToggleConditions[Keyboard::Key::TurnLeft] = Keyboard::Toggle::Holding;

 pVirtualKeyCodesMapping[Keyboard::Key::TurnRight] = KeyNameToVKeyCode("бопюбн");
 pActionToggleConditions[Keyboard::Key::TurnRight] = Keyboard::Toggle::Holding;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Yell] = KeyNameToVKeyCode("Y");
 pActionToggleConditions[Keyboard::Key::Yell] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Jump] = KeyNameToVKeyCode("X");
 pActionToggleConditions[Keyboard::Key::Jump] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Combat] = KeyNameToVKeyCode("RETURN");
 pActionToggleConditions[Keyboard::Key::Combat] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::CastReady] = KeyNameToVKeyCode("S");
 pActionToggleConditions[Keyboard::Key::CastReady] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::Attack] = KeyNameToVKeyCode("A");
 pActionToggleConditions[Keyboard::Key::Attack] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Interact] = KeyNameToVKeyCode("SPACE");
 pActionToggleConditions[Keyboard::Key::Interact] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Cast] = KeyNameToVKeyCode("C");
 pActionToggleConditions[Keyboard::Key::Cast] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::Pass] = KeyNameToVKeyCode("B");
 pActionToggleConditions[Keyboard::Key::Pass] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::CharCycle] = KeyNameToVKeyCode("TAB");
 pActionToggleConditions[Keyboard::Key::CharCycle] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::OpenQuestbook] = KeyNameToVKeyCode("Q");
 pActionToggleConditions[Keyboard::Key::OpenQuestbook] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::OpenQuickRef] = KeyNameToVKeyCode("Z");
 pActionToggleConditions[Keyboard::Key::OpenQuickRef] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Rest] = KeyNameToVKeyCode("R");
 pActionToggleConditions[Keyboard::Key::Rest] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::OpenCalendar] = KeyNameToVKeyCode("T");
 pActionToggleConditions[Keyboard::Key::OpenCalendar] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::OpenAutonotes] = KeyNameToVKeyCode("N");
 pActionToggleConditions[Keyboard::Key::OpenAutonotes] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::OpenMap] = KeyNameToVKeyCode("M");
 pActionToggleConditions[Keyboard::Key::OpenMap] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::AlwaysRun] = KeyNameToVKeyCode("U");
 pActionToggleConditions[Keyboard::Key::AlwaysRun] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::LookUp] = KeyNameToVKeyCode("PAGE_DOWN");
 pActionToggleConditions[Keyboard::Key::LookUp] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::LookDown] = KeyNameToVKeyCode("DELETE");
 pActionToggleConditions[Keyboard::Key::LookDown] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::CenterView] = KeyNameToVKeyCode("END");
 pActionToggleConditions[Keyboard::Key::CenterView] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::ZoomIn] = KeyNameToVKeyCode("ADD");
 pActionToggleConditions[Keyboard::Key::ZoomIn] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::ZoomOut] = KeyNameToVKeyCode("SUBTRACT");
 pActionToggleConditions[Keyboard::Key::ZoomOut] = Keyboard::Toggle::OneTimePress;
 
 pVirtualKeyCodesMapping[Keyboard::Key::FlyUp] = KeyNameToVKeyCode("PAGE_UP");
 pActionToggleConditions[Keyboard::Key::FlyUp] = Keyboard::Toggle::Holding;
 
 pVirtualKeyCodesMapping[Keyboard::Key::FlyDown] = KeyNameToVKeyCode("INSERT");
 pActionToggleConditions[Keyboard::Key::FlyDown] = Keyboard::Toggle::Holding;
 
 pVirtualKeyCodesMapping[Keyboard::Key::Land] = KeyNameToVKeyCode("HOME");
 pActionToggleConditions[Keyboard::Key::Land] = Keyboard::Toggle::OneTimePress;

 pVirtualKeyCodesMapping[Keyboard::Key::StrafeLeft] = KeyNameToVKeyCode("[");
 pActionToggleConditions[Keyboard::Key::StrafeLeft] = Keyboard::Toggle::Holding;

 pVirtualKeyCodesMapping[Keyboard::Key::StrafeRight] = KeyNameToVKeyCode("]");
 pActionToggleConditions[Keyboard::Key::StrafeRight] = Keyboard::Toggle::Holding;

 return Error::Success;
}


//----- (00459FFC) --------------------------------------------------------
unsigned int UserInput::SetKeyMappingFromRegistry()
{
 HKEY hKeySoft;
 if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE", 0, 0x2001F, &hKeySoft))
   return Error::FileNotFound;

 HKEY hKeyNWC;
 if (RegCreateKeyExW(hKeySoft, L"New World Computing", 0, L"", 0, 983103, 0, &hKeyNWC, 0))
 {
  RegCloseKey(hKeySoft);
  return Error::FileNotFound;
 }

 HKEY hKeyMM7;
 if (RegCreateKeyExW(hKeyNWC, L"Might and Magic VII", 0, L"", 0, 0xF003F, 0, &hKeyMM7, 0))
 {
  RegCloseKey(hKeyNWC);
  RegCloseKey(hKeySoft);
  return Error::FileNotFound;
 }

 HKEY hKeyV1_0;
 if (RegCreateKeyExW(hKeyMM7, L"1.0", 0, L"", 0, 0xF003F, 0, &hKeyV1_0, 0))
 {
  RegCloseKey(hKeyMM7);
  RegCloseKey(hKeyNWC);
  RegCloseKey(hKeySoft);
  return Error::FileNotFound;
 }

 char  pResult[256];
 DWORD uBufferSize = 256;

 unsigned int uKey;
 if (RegQueryValueExA(hKeyV1_0, "KEY_FORWARD", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[0] = KeyNameToVKeyCode("UP");
 else pVirtualKeyCodesMapping[0] = uKey;
 pActionToggleConditions[0] = Keyboard::Toggle::Holding;

 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_BACKWARD", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[1] = KeyNameToVKeyCode("DOWN");
 else pVirtualKeyCodesMapping[1] = uKey;
 pActionToggleConditions[1] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_LEFT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[2] = KeyNameToVKeyCode("бкебн");
 else pVirtualKeyCodesMapping[2] = uKey;
 pActionToggleConditions[2] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_RIGHT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[3] = KeyNameToVKeyCode("бопюбн");
 else pVirtualKeyCodesMapping[3] = uKey;
 pActionToggleConditions[3] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_YELL", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[4] = KeyNameToVKeyCode("Y");
 else pVirtualKeyCodesMapping[4] = uKey;
 pActionToggleConditions[4] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_JUMP", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[5] = KeyNameToVKeyCode("X");
 else pVirtualKeyCodesMapping[5] = uKey;
 pActionToggleConditions[5] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_COMBAT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[6] = KeyNameToVKeyCode("RETURN");
 else pVirtualKeyCodesMapping[6] = uKey;
 pActionToggleConditions[6] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_CASTREADY", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[7] = KeyNameToVKeyCode("S");
 else pVirtualKeyCodesMapping[7] = uKey;
 pActionToggleConditions[7] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_ATTACK", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[8] = KeyNameToVKeyCode("A");
 else pVirtualKeyCodesMapping[8] = uKey;
 pActionToggleConditions[8] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_EVENTTRIGGER", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[9] = KeyNameToVKeyCode("SPACE");
 else pVirtualKeyCodesMapping[9] = uKey;
 pActionToggleConditions[9] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_CAST", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::Cast] = KeyNameToVKeyCode("C");
 else pVirtualKeyCodesMapping[Keyboard::Key::Cast] = uKey;
 pActionToggleConditions[Keyboard::Key::Cast] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_PASS", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::Pass] = KeyNameToVKeyCode("B");
 else pVirtualKeyCodesMapping[Keyboard::Key::Pass] = uKey;
 pActionToggleConditions[Keyboard::Key::Pass] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_CHARCYCLE", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::CharCycle] = KeyNameToVKeyCode("TAB");
 else pVirtualKeyCodesMapping[Keyboard::Key::CharCycle] = uKey;
 pActionToggleConditions[Keyboard::Key::CharCycle] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_QUEST", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::OpenQuestbook] = KeyNameToVKeyCode("Q");
 else pVirtualKeyCodesMapping[Keyboard::Key::OpenQuestbook] = uKey;
 pActionToggleConditions[Keyboard::Key::OpenQuestbook] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_QUICKREF", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::OpenQuickRef] = KeyNameToVKeyCode("Z");
 else pVirtualKeyCodesMapping[Keyboard::Key::OpenQuickRef] = uKey;
 pActionToggleConditions[Keyboard::Key::OpenQuickRef] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_REST", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::Rest] = KeyNameToVKeyCode("R");
 else pVirtualKeyCodesMapping[Keyboard::Key::Rest] = uKey;
 pActionToggleConditions[Keyboard::Key::Rest] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_TIMECAL", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::OpenCalendar] = KeyNameToVKeyCode("T");
 else pVirtualKeyCodesMapping[Keyboard::Key::OpenCalendar] = uKey;
 pActionToggleConditions[Keyboard::Key::OpenCalendar] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_AUTONOTES", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::OpenAutonotes] = KeyNameToVKeyCode("N");
 else pVirtualKeyCodesMapping[Keyboard::Key::OpenAutonotes] = uKey;
 pActionToggleConditions[Keyboard::Key::OpenAutonotes] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_MAPBOOK", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::OpenMap] = KeyNameToVKeyCode("M");
 else pVirtualKeyCodesMapping[Keyboard::Key::OpenMap] = uKey;
 pActionToggleConditions[Keyboard::Key::OpenMap] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_ALWAYSRUN", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::AlwaysRun] = KeyNameToVKeyCode("U");
 else pVirtualKeyCodesMapping[Keyboard::Key::AlwaysRun] = uKey;
 pActionToggleConditions[Keyboard::Key::AlwaysRun] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_LOOKUP", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::LookUp] = KeyNameToVKeyCode("PAGE_DOWN");
 else pVirtualKeyCodesMapping[Keyboard::Key::LookUp] = uKey;
 pActionToggleConditions[Keyboard::Key::LookUp] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_LOOKDOWN", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::LookDown] = KeyNameToVKeyCode("DELETE");
 else pVirtualKeyCodesMapping[Keyboard::Key::LookDown] = uKey;
 pActionToggleConditions[Keyboard::Key::LookDown] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_CENTERVIEWPT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::CenterView] = KeyNameToVKeyCode("END");
 else pVirtualKeyCodesMapping[Keyboard::Key::CenterView] = uKey;
 pActionToggleConditions[Keyboard::Key::CenterView] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_ZOOMIN", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::ZoomIn] = KeyNameToVKeyCode("ADD");
 else pVirtualKeyCodesMapping[Keyboard::Key::ZoomIn] = uKey;
 pActionToggleConditions[Keyboard::Key::ZoomIn] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_ZOOMOUT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::ZoomOut] = KeyNameToVKeyCode("SUBTRACT");
 else pVirtualKeyCodesMapping[Keyboard::Key::ZoomOut] = uKey;
 pActionToggleConditions[Keyboard::Key::ZoomOut] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_FLYUP", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::FlyUp] = KeyNameToVKeyCode("PAGE_UP");
 else pVirtualKeyCodesMapping[Keyboard::Key::FlyUp] = uKey;
 pActionToggleConditions[Keyboard::Key::FlyUp] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_FLYDOWN", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::FlyDown] = KeyNameToVKeyCode("INSERT");
 else pVirtualKeyCodesMapping[Keyboard::Key::FlyDown] = uKey;
 pActionToggleConditions[Keyboard::Key::FlyDown] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_LAND", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::Land] = KeyNameToVKeyCode("HOME");
 else pVirtualKeyCodesMapping[Keyboard::Key::Land] = uKey;
 pActionToggleConditions[Keyboard::Key::Land] = Keyboard::Toggle::OneTimePress;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_STEPLEFT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::StrafeLeft] = KeyNameToVKeyCode("[");
 else pVirtualKeyCodesMapping[Keyboard::Key::StrafeLeft] = uKey;
 pActionToggleConditions[Keyboard::Key::StrafeLeft] = Keyboard::Toggle::Holding;
 
 uBufferSize = 256;
 if (RegQueryValueExA(hKeyV1_0, "KEY_STEPRIGHT", 0, 0, (BYTE *)pResult, &uBufferSize) ||
     !lstrcmpiA(pResult, "DEFAULT") || (uKey = KeyNameToVKeyCode(pResult)) == -1)
   pVirtualKeyCodesMapping[Keyboard::Key::StrafeRight] = KeyNameToVKeyCode("]");
 else pVirtualKeyCodesMapping[Keyboard::Key::StrafeRight] = uKey;
 pActionToggleConditions[Keyboard::Key::StrafeRight] = Keyboard::Toggle::Holding;

 RegCloseKey(hKeyV1_0);
 RegCloseKey(hKeyMM7);
 RegCloseKey(hKeyNWC);
 RegCloseKey(hKeySoft);

 return Error::Success;
}




unsigned int UserInput::Initialize()
{
#ifdef _WIN32
 pKeyboard = MemAlloc(Win32Keyboard, 1);
#else
 runtime_error;
#endif

 if (SetKeyMappingFromRegistry())
   SetDefaultKeyMapping();

 return Error::Success;
}




unsigned int Win32Keyboard::Reset(unsigned int uVirtualKey)
{
 GetAsyncKeyState(uVirtualKey);
 return Error::Success;
}

unsigned int Win32Keyboard::Reset(unsigned int *pVirtualKeys, unsigned int uNumKeys)
{
 for (unsigned int i = 0; i < uNumKeys; ++i)
   GetAsyncKeyState(pVirtualKeys[i]);

 return Error::Success;
}

//----- (00459E3F) --------------------------------------------------------
unsigned int UserInput::ResetKeyboard()
{
 uLastKeyPressed = 0;
 return pKeyboard->Reset(pVirtualKeyCodesMapping, 30);
}





UserInput::UserInput()
{
 uLastKeyPressed = 0;

 pKeyboard = 0;

 dword_506E68 = -1;
}






//----- (0045ABCA) --------------------------------------------------------
unsigned int UserInput::KeyNameToVKeyCode(const char *pKey)
{
 if (!lstrcmpiA(pKey, "UP"))
   return VK_UP;
 else if (!lstrcmpiA(pKey, "DOWN"))
   return VK_DOWN;
 else if (!lstrcmpiA(pKey, "бкебн"))
   return VK_LEFT;
 else if (!lstrcmpiA(pKey, "бопюбн"))
   return VK_RIGHT;
 else if (!lstrcmpiA(pKey, "RETURN"))
   return VK_RETURN;
 else if (!lstrcmpiA(pKey, "SPACE"))
   return VK_SPACE;
 else if (!lstrcmpiA(pKey, "PAGE_DOWN"))
   return VK_NEXT;
 else if (!lstrcmpiA(pKey, "PAGE_UP"))
   return VK_PRIOR;
 else if (!lstrcmpiA(pKey, "TAB"))
   return VK_TAB;
 else if (!lstrcmpiA(pKey, "SUBTRACT"))
   return VK_SUBTRACT;
 else if (!lstrcmpiA(pKey, "ADD"))
   return VK_ADD;
 else if (!lstrcmpiA(pKey, "END"))
   return VK_END;
 else if (!lstrcmpiA(pKey, "DELETE"))
   return VK_DELETE;
 else if (!lstrcmpiA(pKey, "HOME"))
   return VK_HOME;
 else if (!lstrcmpiA(pKey, "INSERT"))
   return VK_INSERT;
 else if (!lstrcmpiA(pKey, "COMMA"))
   return VK_OEM_COMMA;
 else if (!lstrcmpiA(pKey, "DECIMAL"))
   return VK_DECIMAL;
 else if (!lstrcmpiA(pKey, "SEMICOLON"))
   return VK_OEM_1;
 else if (!lstrcmpiA(pKey, "PERIOD"))
   return VK_OEM_PERIOD;
 else if (!lstrcmpiA(pKey, "SLASH"))
   return VK_OEM_2;
 else if (!lstrcmpiA(pKey, "SQUOTE"))
   return VK_OEM_7;
 else if (!lstrcmpiA(pKey, "BACKSLASH"))
   return VK_OEM_5;
 else if (!lstrcmpiA(pKey, "BACKSPACE"))
   return VK_BACK;
 else if (!lstrcmpiA(pKey, "CONTROL"))
   return VK_CONTROL;
 else if (*pKey == '[')
   return VK_OEM_4;
 else if (*pKey == ']')
   return VK_OEM_6;
 else if (*pKey >= '0' && *pKey <= '9')
   return *pKey;
 else if (*pKey >= 'A' && *pKey <= 'Z')
   return *pKey;
 else return -1;
}
