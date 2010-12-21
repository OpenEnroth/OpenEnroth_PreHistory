#include "GUIProgressBar.h"

#include "defs.h"
#include "..\mm7_unparsed_data.h"
#include "..\mm7_unparsed_functions.h"

#include "..\_lod.h"
#include "..\UserInput.h"

//----- (004435E2) --------------------------------------------------------
void LevelLoadingUI_Release(struct class56 *_this)
{
  void *v1; // esi@1
  int v6; // eax@8
  int v7; // eax@9

  v1 = _this;
 if (pAsyncMouse)
   CAsyncMouse_sub_46B105((void *)pAsyncMouse);
}


//----- (004435CD) --------------------------------------------------------
void LevelLoadingUI_UpdateAndDrawProgressBar(struct class56 *_this)
{
 if (++_this->uProgressCurrent > _this->uProgressMax)
   _this->uProgressCurrent = _this->uProgressMax;
 DrawLoadingScreen(_this);
}

//----- (00443484) --------------------------------------------------------
bool LevelLoadingUI_Initialize(struct class56 *_this, unsigned int uProgressBarType)
{
  void *v2; // esi@1
  int v5; // ecx@8
  int v6; // edi@8
  int v7; // edx@14
  const char *v8; // [sp-8h] [bp-84h]@20
  char Str1[32]; // [sp+4h] [bp-78h]@16
  wchar_t Str1W[32];
 int i;

  v2 = _this;
  if ( pAsyncMouse)
    CAsyncMouse_suspend(pAsyncMouse);

  if (uProgressBarType)
    _this->uProgressBarType = uProgressBarType;

  if (_this->uProgressBarType == 1)
  {
    v5 = 0;
    for (i = 1; i < 6; ++i)
      if (_this->array_000010[i] == 1)
        ++v5;

  //  v6 = (int)_this->array_000010[0];

    if (v5 == 5 )
      memset(_this->array_000010, 0, 8);

    v7 = rand() % 5 + 1;
    if (_this->array_000010[v7] == 1 )
    {
      do
        v7 = rand() % 5 + 1;
      while ( _this->array_000010[v7] == 1 );
    }
#ifndef OLD_CODE

    wsprintfW(Str1W, L"loading%d", v7);

    _this->uTextureID_Loading = LODFile_Icons_LOD.LODFile_LoadTexture_New( Str1W);
    _this->_addon_loadprog_id_in_Icons_LOD = LODFile_Icons_LOD.LODFile_LoadTexture_New( L"loadprog");
#else
    wsprintfA(Str1, "loading%d.pcx", v7);
	// realy or not
	_this->loading = MemAlloc(cPCXTexture, 1);
	_this->loading->PCXTexture_Zero();
    _this->loading->LODPCXLoad( Str1,2); 
    _this->loadprog = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture( "loadprog",2)];
#endif
    _this->uX = 122;
    _this->uY = 151;
    _this->uWidth = 449;
    _this->uHeight = 56;

    _this->uProgressMax = 26;
    _this->uProgressCurrent = 0;

    DrawLoadingScreen((class56 *)v2);
  }
  else
  {
   if (pParty_global->uAlignment == PARTY_ALIGNMENT_GOOD)
     LODFile_Icons_LOD.LODFile_sub_410522( _this->loadprog, "bardata-b", 2);
   else if (pParty_global->uAlignment == PARTY_ALIGNMENT_NEUTRAL)
     LODFile_Icons_LOD.LODFile_sub_410522(_this->loadprog, "bardata", 2);
   else
     LODFile_Icons_LOD.LODFile_sub_410522( _this->loadprog, "bardata-C", 2);

   *((_BYTE *)v2 + 11) = 0;
   *((_BYTE *)v2 + 10) = 26;
   DrawLoadingScreen((class56 *)v2);
  }
 return true;
}




//----- (00443670) --------------------------------------------------------
void DrawLoadingScreen(struct class56 *_this)
{
  int v1; // edi@1
  int v4; // eax@10
  float v5; // ST2C_4@10

  v1 = (int)_this;
  pD3DRenderer->BeginScene();
  if (_this->uProgressBarType != 1 )
  {
    if ( *(_DWORD *)(v1 + 344) )
    {
      if ( pD3DRenderer->pRenderD3D3 )
      {
        if (!pD3DRenderer->bWindowMode)
          Render_sub_49FD3A((int)pD3DRenderer, v1);
      }
      Render_DrawIndexedTexture(pD3DRenderer, 80, 122, (cTexture *)(v1 + 296));
      v4 = (int)pIconFrameTable->GetImage(dword_50C984, 0);
      Render_DrawTransparentTexture(pD3DRenderer, 100, 146, (cTexture *)(&LODFile_Icons_LOD.aLODHeaders[(v4 + 30)]));
      v5 = (double)(113 * *(_BYTE *)(v1 + 11)) / (double)*(_BYTE *)(v1 + 10);
      compile_error;//Render_FillRect2(pD3DRenderer, 0, 174, 164, v5 + 6.755399441055744e15, 16, pD3DRenderer->uTargetRMask);

      pD3DRenderer->EndScene();
      pD3DRenderer->Present();
      return;
    }
    pD3DRenderer->EndScene();
    return;
  }
#ifndef OLD_CODE  
  Render_DrawRGBTexture_New(pD3DRenderer, 0, 0, _this->uTextureID_Loading);
#else
  Render_DrawRGBTexture(pD3DRenderer, 0, 0, _this->loading);
#endif
  Render_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  Render_Set2DClippingRect(pD3DRenderer, 172, 459,
    172 + 300 * ((float)(_this->uProgressCurrent) / (float)_this->uProgressMax),
    471);
#ifndef OLD_CODE 
  Render_DrawTransparentTexture(pD3DRenderer, 172, 459, &LODFile_Icons_LOD.aLODHeaders[_this->_addon_loadprog_id_in_Icons_LOD]);
#else
   Render_DrawTransparentTexture(pD3DRenderer, 172, 459, _this->loadprog);
#endif
  Render_Reset2DClippingRect(pD3DRenderer);
  pD3DRenderer->EndScene();
  pD3DRenderer->Present();
}


//----- (004435BB) --------------------------------------------------------
void LevelLoadingUI_Reset(struct class56 *_this, char a2)
{
 _this->byte_000009 = 0;
 _this->uProgressMax = a2;
 _this->uProgressCurrent = 0;
}