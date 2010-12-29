#include "Cursor.h"

#include "..\mm7_unparsed_data.h"

#include "..\Game.h"
#include "..\UserInput.h"

#include "..\_lod.h"


//----- (MM7.exe::00467E4E) --------------------------------------------------------
struct GUICursor *GUICursor_ctor(struct GUICursor *_this, struct class01 *class01_obj)
{
 _this->uCursorTextureID = 0;
 _this->dword_000028 = 0;
 _this->pWindow = 0;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;
 _this->ptr_00003C = 0;
 _this->ptr_000090 = 0;
 _this->class01_obj = class01_obj;
 return _this;
}

//----- (MM7.exe::0046A080) --------------------------------------------------------
int GUICursor_fn1(struct GUICursor *_this, int a2)
{
 return _this->dword_000004 = a2;
}

//----- (MM7.exe::00469C39) --------------------------------------------------------
POINT *GUICursor_GetMousePos(struct GUICursor *_this, POINT *pOut)
{
 int *v3; // edx@1

 v3 = (int *)pAsyncMouse;
 if (pAsyncMouse)
 {
  pOut->x = v3[6];
  pOut->y = v3[7];
 }
 else
 {
  GetCursorPos(pOut);
  ScreenToClient(pAppWindow->GetAPIHandle(), pOut);
 }
 return pOut;
}

//----- (00469860) --------------------------------------------------------
void GUICursor_GetMouseClickPos(struct GUICursor *_this, int *pX, int *pY)
{
  if (pAsyncMouse)
  {
    *pX = *(_DWORD *)(pAsyncMouse + 24);
    *pY = *(_DWORD *)(pAsyncMouse + 28);
  }
  else
  {
    *pX = _this->uMouseClickX;
    *pY = _this->uMouseClickY;
  }
}

//----- (0046A08A) --------------------------------------------------------
void GUICursor_OnMouseLeftButton(struct GUICursor *_this, int x, int y)
{
 _this->uMouseClickX = x;
 _this->uMouseClickY = y;
}

//----- (00469C65) --------------------------------------------------------
void GUICursor_sub_469C65(struct GUICursor *_this, OSWindow *pTargetWindow)
{
 _this->dword_000004 = 0;

 _this->dword_000010 = 1;

 _this->pWindow = pTargetWindow;
 _this->ptr_000030 = 0;
 _this->dword_000034 = 0;
 _this->ptr_000038 = 0;

 _this->dword_0000C4 = 0;
 _this->dword_0000C8 = 0;

 _this->uMouseClickY = 0;

 GUICursor_SetCursorBitmap(_this, "MICON3");
 GUICursor_SetCursorBitmap(_this, "MICON2");
 GUICursor_SetCursorBitmap(_this, "MICON1");
}



//----- (00469903) --------------------------------------------------------
void GUICursor_SetCursorBitmap(GUICursor *_this, const char *pSource)
{
 HCURSOR hCursor;
  int v9; // eax@21
  struct tagPOINT Point; // [sp+14h] [bp-8h]@20

 if (!_this->dword_000010 || !pSource)
   return;

 if (_strcmpi("MICON2", pSource))
    pGame->dword_000E24 &= 0xFFFFFFEF;
 else pGame->dword_000E24 |= 0x10;

 if (_strcmpi((char *)_this->array_0000F5, pSource))
   strcpy((char *)_this->array_0000F5, pSource);

 GUICursor_sub_469BA3(_this);

 if (_strnicmp(pSource, "MICON1", 5))
 {
#ifdef OLD_CODE
  v9 = LODFile_Icons_LOD.LODFile_LoadTexture(pSource, 2);
#else
  wchar_t pTextureNameW[256];
  wsprintfW(pTextureNameW, L"%S", pSource);

  v9 = LODFile_Icons_LOD.LODFile_LoadTexture_New(pTextureNameW);
#endif
  _this->uCursorTextureID = v9;
  _this->dword_000028 = v9;
  GUICursor_sub_469BE6(_this);

  _this->dword_00000C = 0;
  _this->dword_000014[0] = 1;
  _this->dword_000004 = 1;
  if (!bTextureLoading)
  {						  
   cTexture_Free(_this->uCursorTextureID != -1 ? &LODFile_Icons_LOD.aLODHeaders[_this->uCursorTextureID] : 0);
   LODFile_Icons_LOD.LODFile_sub_40F9C5();
  }
  return;
 }

 _this->dword_000004 = 0;
 _this->dword_00000C = 1;
 if (!strcmp(pSource, "MICON1"))
 {
  hCursor = LoadCursorA(GetModuleHandleW(0), "Arrow");
  SetClassLongPtrW(_this->pWindow->GetAPIHandle(), GCL_HCURSOR, (LONG_PTR)(hCursor));
  if (pAsyncMouse)
  {
   CAsyncMouse_sub_46B342(pAsyncMouse, 0.0, 0.0);
   CAsyncMouse_sub_46AE97((void *)pAsyncMouse, (void *)pSource);
  }
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
 else if (!strcmp(pSource, "MICON2"))
 {
  hCursor = LoadCursorA(GetModuleHandleW(0), "Target");
  SetClassLongPtrW(_this->pWindow->GetAPIHandle(), GCL_HCURSOR, (LONG_PTR)(hCursor));
  if (pAsyncMouse)
  {
   CAsyncMouse_sub_46B342(pAsyncMouse, 14.0, 14.0);
   CAsyncMouse_sub_46AE97((void *)pAsyncMouse, (void *)pSource);
  }
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
 else if (!strcmp(pSource, "MICON3"))
 {
  hCursor = LoadCursorA(0, (LPCSTR)0x7F02);
  SetClassLongPtrW(_this->pWindow->GetAPIHandle(), GCL_HCURSOR, (LONG_PTR)(hCursor));

  if (pAsyncMouse)
    CAsyncMouse_sub_46AE97((void *)pAsyncMouse, (void *)pSource);
  else
  {
   GetCursorPos(&Point);
   SetCursorPos(Point.x, Point.y);
  }
 }
}

//----- (004698A6) --------------------------------------------------------
void GUICursor_ResetDefaultCursorAfterItemDragging(struct GUICursor *_this)
{
 ItemGen_Reset(&pParty_global->pickedItem);
 if (_strcmpi((char *)_this->array_0000F5, "MICON2"))
   GUICursor_SetCursorBitmap(_this, "MICON1");
}

//----- (00469BA3) --------------------------------------------------------
int GUICursor_sub_469BA3(struct GUICursor *_this)
{
 _this->dword_000004 = 0;

 if (_this->ptr_000030)
 {
  MemFree(_this->ptr_000030);
  _this->ptr_000030 = 0;
 }

 if (_this->ptr_000038)
 {
  MemFree(_this->ptr_000038);
  _this->ptr_000038 = 0;
 }

 if (_this->ptr_000090)
 {
  MemFree(_this->ptr_000090);
  _this->ptr_000090 = 0;
 }

 return 0;
}

