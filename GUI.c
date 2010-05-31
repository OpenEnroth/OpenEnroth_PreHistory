#include "GUI.h"

#include "defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "mm7DDrawRenderer.h"

#include "data.h"

#include "FrameTables.h"




//----- (004151D9) --------------------------------------------------------
void __fastcall DrawWindow(unsigned int uWindowX, unsigned int uWindowY, unsigned int uWindowWidth, unsigned int uWindowHeight)
{
  //int v10; // ebx@14
  //int v11; // [sp+10h] [bp-28h]@5
  //signed int v12; // [sp+18h] [bp-20h]@1
  //int v13; // [sp+1Ch] [bp-1Ch]@7
  //int v14; // [sp+20h] [bp-18h]@1
  unsigned int uNumYTiles;//int v15; // [sp+24h] [bp-14h]@5
  //int v16; // [sp+24h] [bp-14h]@11
  //int v17; // [sp+28h] [bp-10h]@1
  unsigned int uNumXTiles;//int v18; // [sp+2Ch] [bp-Ch]@3
  //int v19; // [sp+2Ch] [bp-Ch]@6
  //int v20; // [sp+2Ch] [bp-Ch]@11
  //int v21; // [sp+30h] [bp-8h]@1
  //int v22; // [sp+34h] [bp-4h]@5
  //int v23; // [sp+34h] [bp-4h]@11
 int x, y;

 struct class18 *pClass18Parchment;

 //v17 = uWindowX + uWindowWidth;
 sub_4A5B81(pD3DRenderer, uWindowX, uWindowY, uWindowX + uWindowWidth, uWindowY + uWindowHeight);


 pClass18Parchment = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_Parchment];

 uNumXTiles = uWindowWidth / pClass18Parchment->uTextureWidth;
 if (uWindowWidth % pClass18Parchment->uTextureWidth)
   ++uNumXTiles;

 uNumYTiles = uWindowHeight / pClass18Parchment->uTextureHeight;
 if (uWindowHeight % pClass18Parchment->uTextureHeight)
   ++uNumYTiles;


 for (y = 0; y < uNumYTiles; ++y)
   for (x = 0; x < uNumXTiles; ++x)
     CD3DRenderer_DrawIndexedTexture(pD3DRenderer,
                uWindowX + x * pClass18Parchment->uTextureWidth,
                uWindowY + y * pClass18Parchment->uTextureHeight,
                pClass18Parchment);



 //v16 = uWindowY + uWindowHeight - 32;

 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_CornerUpperLeft]);
 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY + uWindowHeight - 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_CornerLowerLeft]);
 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 32, uWindowY, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_CornerUpperRight]);
 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 32, uWindowY + uWindowHeight - 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_CornerLowerRight]);

 
  //v20 = uWindowX + 32;
  //v23 = uWindowY + uWindowHeight - 10;
 if (uWindowWidth > 64)
 {
  sub_4A5B81(pD3DRenderer, uWindowX + 32, uWindowY, uWindowX + uWindowWidth - 32, uWindowY + uWindowHeight);

  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + 32, uWindowY, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeTop]);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + 32, uWindowY + uWindowHeight - 10, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeBottom]);

  if (uWindowWidth > 512)
  {
   CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + 544, uWindowY, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeTop]);
   CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + 544, uWindowY + uWindowHeight - 10, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeBottom]);
  }
 }

  //v10 = uWindowY + 32;
 if (uWindowHeight > 64)
 {
  sub_4A5B81(pD3DRenderer, uWindowX, uWindowY + 32, uWindowX + uWindowWidth, uWindowY + uWindowHeight - 32);

  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY + 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeLeft]);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 10, uWindowY + 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeRight]);
 }

 CD3DRenderer_sub_4A5BB6(pD3DRenderer);
}

//----- (0041CD3B) --------------------------------------------------------
struct GUIButton *GUIWindow_GetChild(struct GUIWindow *_this, int uID)
{
 struct GUIButton *v1;
 int               i;

 v1 = _this->pControlsHead;
 for (i = 0; i < uID; ++i)
   v1 = v1->pNext;

 return v1;
}

//----- (00466C40) --------------------------------------------------------
void SetCurrentMenu(unsigned int uMenuID)
{
  if ( uCurrentMenuID == -1 )
  {
    if ( uMenuID != -1 )
    {
      if (pGame->class14_obj->dword_000004 & 0xFF)
      {
        if (dword_69B00C)
          Keyboard_suspend(dword_69B00C);
      }
    }
  }
  else
  {
    if ( uMenuID == -1)
    {
      if (pGame->class14_obj->dword_000004 & 0xFF)
      {
        if (dword_69B00C)
          Keyboard_resume(dword_69B00C);
      }
    }
  }
  uCurrentMenuID = uMenuID;
}

//----- (0041D12F) --------------------------------------------------------
struct GUIButton *__fastcall GUIButtonCreate(struct GUIWindow *pParentWindow,
                                             unsigned int uX, unsigned int uY,
                                             unsigned int uWidth, unsigned int uHeight,
                                             int a6, int a7, unsigned int uControlID, int a9, char a10, const char *pName, unsigned int uTextureID)
{
  int *v19; // edx@5
  struct class18 **v20; // ecx@5
 struct GUIButton *pButton;

 pButton = class23_AllocatedNamedBuffer(class23_instance, 0, sizeof(struct GUIButton), "BUTTON");

 pButton->uX = uX + pParentWindow->uFrameX;
 pButton->uY = uY + pParentWindow->uFrameY;
 pButton->uWidth = uWidth;
 pButton->uHeight = uHeight;
 if (a6 == 2 && !uHeight)
   pButton->uHeight = uWidth;

 pButton->uZ = uX + pParentWindow->uFrameX + uWidth - 1;
 pButton->uW = uY + pParentWindow->uFrameY + uHeight - 1;
 pButton->dword_000018 = a6;
 pButton->dword_00001C = a7;
 pButton->dword_000020 = uControlID;
 pButton->dword_000024 = a9;
 pButton->dword_00002C = 0;
 pButton->pParentWindow = pParentWindow;

 pButton->byte_000054 = a10;
 strcpy(pButton->pButtonName, pName);

 pButton->dword_000050 = 0;
 //if (pTexture)
 //{
  pButton->dword_00003C = uTextureID;
  pButton->dword_000040 = 0xFEAFEAFE;
  pButton->dword_000044 = 0xFEAFEAFE;
  pButton->dword_000048 = 0xFEAFEAFE;
  pButton->dword_00004C = 0xFEAFEAFE;
  pButton->dword_000050 = 1;
  /*
  v20 = &pTexture;
  v19 = &pButton->dword_00003C;
  do
  {
   *v19++ = *v20++;
   pButton->dword_000050++;
  }
  while (*v20);*/
 //}

 if (pParentWindow->pControlsTail)
   pParentWindow->pControlsTail->pNext = pButton;
 else
   pParentWindow->pControlsHead = pButton;

 pButton->pPrev = pParentWindow->pControlsTail;
 pButton->pNext = 0;

 pParentWindow->pControlsTail = pButton;
 pParentWindow->uNumControls++;

 return pButton;
}


//----- (0041C432) --------------------------------------------------------
struct GUIWindow *__fastcall GUIWindowCreate(unsigned int uFrameX, unsigned int uFrameY,
                                             unsigned int uFrameWidth, unsigned int uFrameHeight,
                                             signed int a5, int a6, int a7)
{
  signed int v7; // eax@1
  int v8; // ebp@1
  //int *v9; // esi@4
  struct GUIWindow *v9;
  int v11; // ebx@15
  char *v12; // ebp@15
  void *v13; // ecx@18
  bool v14; // eax@20
  void *v15; // ecx@23
  bool v16; // eax@25
  void *v17; // ecx@28
  bool v18; // eax@30
  void *v19; // ecx@33
  bool v20; // eax@35
  void *v21; // ecx@38
  bool v22; // eax@40
  void *v23; // ecx@43
  bool v24; // eax@45
  int v25; // eax@65
  int v26; // ebx@65
  int v27; // eax@71
  int v29; // [sp-8h] [bp-18h]@68
  int v30; // [sp-4h] [bp-14h]@68
  char *v31; // [sp+14h] [bp+4h]@15
  int v32; // [sp+14h] [bp+4h]@66
  int v33; // [sp+20h] [bp+10h]@15
 int i;

  v8 = 0;
  for (i = 0; i < 20; ++i)
  {
   if (!array_506F50[i].bSlotUsed)
     break;
   ++v8;
  }

  v9 = &array_506F50[v8];
  v9->uFrameX = uFrameX;
  v9->uFrameY = uFrameY;
  v9->uFrameWidth = uFrameWidth;
  v9->uFrameHeight = uFrameHeight;
  v9->uFrameZ = uFrameX + uFrameWidth - 1;
  v9->uFrameW = uFrameY + uFrameHeight - 1;
  v9->bSlotUsed = a5;
  v9->dword_00001C = a6;
  v9->dword_000044 = 0;
  v9->dword_000048 = a7;

  v9->dword_00003C = ++uNumGUIWindows;
  array_5075E0[uNumGUIWindows] = v8 + 1;

  if ( a5 <= 20 )
  {
    if ( a5 != 20 )
    {
      switch ( a5 )
      {
        case 9:
          sub_411BFC((void *)v9);
          break;
        case 10:
          dword_506978 = dword_4E28F8;
          dword_4E28F8 = 4;
          dword_5076F4 = GUIButtonCreate(
                           v9,
                           471,
                           445,
                           169,
                           35,
                           1,
                           0,
                           113,
                           0,
                           0,
                           pGlobalTXT_LocalizationStrings[79],
                           dword_506438 != -1 ? 72 * dword_506438 + 0x6D084C : 0);
          if ( *(_DWORD *)(v9 + 28) != 1 )
          {
            v33 = 0;
            v11 = pFontArrus->uFontHeight - 3;
            v12 = sub_4459F9(dword_591090);
            v31 = v12;
            if ( sub_445C8B(dword_591090) == 1 )
            {
              if ( *((_DWORD *)v31 + 8) )
              {
                GUIButtonCreate(v9, 480, 130, 140, v11, 1, 0, 136, 13, 0, "", 0);
                v33 = 1;
              }
              v13 = (void *)*((_DWORD *)v31 + 10);
              if ( v13 )
              {
                if ( v33 < 4 )
                {
                  v14 = sub_4466C4(v13);
                  if ( v14 == 1 || v14 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 19, 0, "", 0);
                }
              }
              v15 = (void *)*((_DWORD *)v31 + 11);
              if ( v15 )
              {
                if ( v33 < 4 )
                {
                  v16 = sub_4466C4(v15);
                  if ( v16 == 1 || v16 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 20, 0, "", 0);
                }
              }
              v17 = (void *)*((_DWORD *)v31 + 12);
              if ( v17 )
              {
                if ( v33 < 4 )
                {
                  v18 = sub_4466C4(v17);
                  if ( v18 == 1 || v18 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 21, 0, "", 0);
                }
              }
              v19 = (void *)*((_DWORD *)v31 + 13);
              if ( v19 )
              {
                if ( v33 < 4 )
                {
                  v20 = sub_4466C4(v19);
                  if ( v20 == 1 || v20 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 22, 0, "", 0);
                }
              }
              v21 = (void *)*((_DWORD *)v31 + 14);
              if ( v21 )
              {
                if ( v33 < 4 )
                {
                  v22 = sub_4466C4(v21);
                  if ( v22 == 1 || v22 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 23, 0, "", 0);
                }
              }
              v23 = (void *)*((_DWORD *)v31 + 15);
              if ( v23 )
              {
                if ( v33 < 4 )
                {
                  v24 = sub_4466C4(v23);
                  if ( v24 == 1 || v24 == 2 )
                    GUIButtonCreate(v9, 480, v33++ * v11 + 130, 140, v11, 1, 0, 136, 24, 0, "", 0);
                }
              }
            }
            else
            {
              if ( *((_DWORD *)v12 + 8) )
              {
                GUIButtonCreate(v9, 480, 130, 140, v11, 1, 0, 136, 77, 0, pGlobalTXT_LocalizationStrings[407], 0);
                if ( v31[8] & 0x80 )
                {
                  sprintfex(&ExistingFileName, pGlobalTXT_LocalizationStrings[408], *(_DWORD *)v31);
                  GUIButtonCreate(v9, 480, v11 + 130, 140, v11, 1, 0, 136, 76, 0, &ExistingFileName, 0);
                }
                else
                {
                  GUIButtonCreate(v9, 480, v11 + 130, 140, v11, 1, 0, 136, 76, 0, pGlobalTXT_LocalizationStrings[406], 0);
                }
                v33 = 2;
              }
            }
            sub_41D08F(v9, v33, 1, 0, 1);
          }
          break;
        case 17:
          dword_506978 = dword_4E28F8;
          dword_4E28F8 = 17;
          dword_5076F4 = GUIButtonCreate(
                           v9,
                           566,
                           445,
                           75,
                           33,
                           1,
                           0,
                           91,
                           0,
                           78,
                           pGlobalTXT_LocalizationStrings[156],
                           uTextureIdx_BtnEsc2 + 1 != 0 ? 72 * (_DWORD)uTextureIdx_BtnEsc2 + 0x6D084C : 0);
          dword_5076FC = GUIButtonCreate(
                           v9,
                           486,
                           445,
                           75,
                           33,
                           1,
                           0,
                           90,
                           0,
                           89,
                           *(const char **)(v9 + 72),
                           uTextureIdx_BtnYes2 != -1 ? 72 * uTextureIdx_BtnYes2 + 0x6D084C : 0);
          GUIButtonCreate(v9, dword_4E5E50, dword_4E5EE0, 63, 73, 1, 0, 90, 1, 32, *(const char **)(v9 + 72), 0);
          GUIButtonCreate(v9, 8, 8, 460, 344, 1, 0, 90, 1, 0, *(const char **)(v9 + 72), 0);
          break;
        case 18:
          sub_41192C();
          sub_411621((void *)v9);
          break;
        case 19:
          dword_506978 = dword_4E28F8;
          sub_459E5A((int)&dword_69AE00, 0, 15, v9);
          dword_4E28F8 = 19;
          break;
      }
      return v9;
    }
LABEL_62:
    GUIButtonCreate(v9, 61, 424, 31, 0, 2, 94, 110, 1, 49, "", 0);
    GUIButtonCreate(v9, 177, 424, 31, 0, 2, 94, 110, 2, 50, "", 0);
    GUIButtonCreate(v9, 292, 424, 31, 0, 2, 94, 110, 3, 51, "", 0);
    GUIButtonCreate(v9, 407, 424, 31, 0, 2, 94, 110, 4, 52, "", 0);
    GUIButtonCreate(v9, 0, 0, 0, 0, 1, 0, 176, 0, 9, "", 0);
    return v9;
  }
  if ( a5 == 25 )
  {
    dword_4E28F8 = 13;
    dword_5076F4 = GUIButtonCreate(
                     v9,
                     471,
                     445,
                     169,
                     35,
                     1,
                     0,
                     113,
                     0,
                     0,
                     pGlobalTXT_LocalizationStrings[80],
                     dword_506438 != -1 ? 72 * dword_506438 + 7145548 : 0);
    v25 = dword_591424;
    v26 = 0;
    if ( dword_591424 > 0 )
    {
      do
      {
        v32 = v26 + 1;
        if ( v26 + 1 == v25 && dword_5C35D0 )
        {
          v30 = pMapStats->pMapInfos[dword_5C35D0].pLocationName;
          v29 = pGlobalTXT_LocalizationStrings[411];
        }
        else
        {
          if ( v26 || !dword_591080 )
            v27 = *(_DWORD *)dword_5913D8[v26 - (dword_591080 != 0)];
          else
            v27 = dword_591440[13 * a6];
          v30 = v27;
          v29 = pGlobalTXT_LocalizationStrings[435];
        }
        sprintfex(&byte_591180[100 * v26], (const char *)v29, v30);
        dword_5913F4[v26] = GUIButtonCreate(
                              v9,
                              *(&dword_4E5E50 + v26 + 6 * dword_591424 - 6),
                              *(&dword_4E5EE0 + v26 + 6 * dword_591424 - 6),
                              63,
                              73,
                              1,
                              0,
                              410,
                              v26,
                              0,
                              &byte_591180[100 * v26],
                              0);
        v26 = v32;
        v25 = dword_591424;
      }
      while ( v32 < dword_591424 );
    }
    if ( v25 == 1 )
    {
      dword_507BC0 = &array_506F50[v8];
      sub_4B4224(0);
    }
  }
  else
  {
    if ( a5 == 26 )
    {
      dword_506978 = dword_4E28F8;
      dword_4E28F8 = 18;
      dword_5076F4 = GUIButtonCreate(
                       v9,
                       566,
                       445,
                       75,
                       33,
                       1,
                       0,
                       412,
                       0,
                       78,
                       pGlobalTXT_LocalizationStrings[34],
                       uTextureIdx_BtnEsc2 + 1 != 0 ? 72 * (_DWORD)uTextureIdx_BtnEsc2 + 7145548 : 0);
      dword_5076FC = GUIButtonCreate(
                       v9,
                       486,
                       445,
                       75,
                       33,
                       1,
                       0,
                       411,
                       0,
                       89,
                       *(const char **)(v9 + 72),
                       uTextureIdx_BtnYes2 != -1 ? 72 * uTextureIdx_BtnYes2 + 7145548 : 0);
      GUIButtonCreate(v9, dword_4E5E50, dword_4E5EE0, 63, 73, 1, 0, 411, 1, 32, *(const char **)(v9 + 72), 0);
      GUIButtonCreate(v9, 8, 8, 460, 344, 1, 0, 411, 1, 0, *(const char **)(v9 + 72), 0);
      return v9;
    }
    if ( a5 == 27 )
    {
      class24_fn1(pClass24_global);
      AudioPlayer_sub_4AB71F(pAudioPlayer, -1, -1);
      sub_469903(pClass03_global, "MICON2");
      sub_44C175(pGlobalTXT_LocalizationStrings[39], 2);
      return v9;
    }
    if ( a5 == 30 )
      goto LABEL_62;
    if ( a5 == 31 )
    {
      sub_469903(pClass03_global, "MICON2");
      dword_5076F4 = GUIButtonCreate(
                       v9,
                       392,
                       318,
                       75,
                       33,
                       1,
                       0,
                       113,
                       0,
                       0,
                       pGlobalTXT_LocalizationStrings[34],
                       uTextureIdx_BtnEsc2 + 1 != 0 ? 72 * (_DWORD)uTextureIdx_BtnEsc2 + 7145548 : 0);
      sub_44C175(pGlobalTXT_LocalizationStrings[39], 2);
      ++pClass17_Icons_LOD->dword_011B9C;
      dword_506F48 = 103;
      dword_4E28F8 = 23;
      if ( !pClass17_Icons_LOD->dword_011B98 )
        pClass17_Icons_LOD->dword_011B98 = pClass17_Icons_LOD->uNumLoadedFiles;
    }
  }
  return v9;
}





//----- (0041C26A) --------------------------------------------------------
void GUIWindowDelete(int this)
{
  int v1; // esi@1
  signed int v2; // eax@2
  int v3; // eax@5
  int v4; // eax@6
  int v5; // eax@14
  int v6; // eax@15
  int i; // edi@20
  int v8; // eax@26
  int v9; // edi@27
  int v10; // ecx@28
  int v11; // esi@28
  int v12; // edx@29

  v1 = this;
  if ( this )
  {
    v2 = *(_DWORD *)(this + 24);
    if ( v2 > 18 )
    {
      v5 = v2 - 19;
      if ( !v5 )
      {
        sub_40F9C5(pClass17_Icons_LOD);
        dword_4E28F8 = dword_506978;
        sub_459ED1(&dword_69AE00, 3);
        goto LABEL_26;
      }
      v6 = v5 - 6;
      if ( !v6 )
      {
        for ( i = 0; i < dword_591424; ++i )
          sub_40F77C(dword_59140C[i]);
        sub_40F77C(dword_591430);
        sub_40F9C5(pClass17_Icons_LOD);
        dword_591424 = 0;
        sub_4114F2(pClass17_Icons_LOD);
        dword_5C35D4 = 0;
        if ( dword_6BE380 )
        {
          pClass55_global->dword_000018 = (pClass59_global->dword_001868 - 1) & (pClass59_global->dword_001860 + pClass55_global->dword_000018);
          pParty_global->dword_0006C0 = pClass55_global->dword_000018;
        }
        pParty_global->dword_007778 |= 2;
        goto LABEL_26;
      }
      if ( v6 == 1 )
      {
        CVideoPlayer_UnloadAll(pVideoPlayer);
        goto LABEL_18;
      }
    }
    else
    {
      if ( v2 == 18 )
      {
        sub_41140B();
        sub_411473();
      }
      else
      {
        if ( !v2 )
          return;
        v3 = v2 - 9;
        if ( v3 )
        {
          v4 = v3 - 1;
          if ( !v4 )
          {
            if ( !dword_591084 )
              sub_40F77C(dword_59140C[0]);
            sub_40F77C(dword_591430);
            sub_40F9C5(pClass17_Icons_LOD);
            dword_591424 = 0;
            goto LABEL_19;
          }
          if ( v4 != 7 )
            goto LABEL_26;
LABEL_18:
          sub_40F77C(dword_59142C);
          sub_40F77C(dword_591430);
          sub_40F9C5(pClass17_Icons_LOD);
LABEL_19:
          dword_4E28F8 = dword_506978;
          goto LABEL_26;
        }
        sub_411597();
      }
    }
LABEL_26:
    v8 = *(_DWORD *)(v1 + 76);
    if ( v8 )
    {
      do
      {
        v9 = *(_DWORD *)(v8 + 52);
        class23_DeleteBuffer(class23_instance, v8);
        v8 = v9;
      }
      while ( v9 );
    }
    *(_DWORD *)(v1 + 76) = 0;
    *(_DWORD *)(v1 + 80) = 0;
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 24) = 0;
    v11 = *(_DWORD *)(v1 + 60);
    v10 = uNumGUIWindows;
    while ( v11 < v10 )
    {
      v12 = array_5075E0[v11 + 1];
      array_5075E0[v11] = v12;
      --*((_DWORD *)pRGBTexture_Menu->word_000018 + 21 * v12);
      ++v11;
    }
    array_5075E0[v10] = 0;
    uNumGUIWindows = v10 - 1;
  }
}



//----- (0044C448) --------------------------------------------------------
struct Font *__cdecl LoadFont(const char *pFontFile, const char *pFontPalette)
{
  int result; // eax@1
  int v5; // eax@3
  int v8; // [sp+8h] [bp-8h]@1
  int **v9; // [sp+Ch] [bp-4h]@2

 result = class17_fn1(pClass17_Icons_LOD, pFontFile, 0);
 v8 = 0;
 if (pFontPalette)
 {
  v9 = result + 12;

   v5 = class17_LoadTexture(pClass17_Icons_LOD, pFontPalette, 2);
   if (v5 == -1)
   {
    sprintfex(&ExistingFileName, "Unable to open %s", pFontPalette);
    erroneous_printf(&ExistingFileName);
   }
   ++v8;
   *v9++ = pClass17_Icons_LOD->aLODHeaders[v5].pPalette;
 }

 *(_DWORD *)(result + 8) = v8;
 return result;
}


//----- (0049750E) --------------------------------------------------------
void __cdecl DeleteFontCChar()
{
  class23_DeleteBuffer(class23_instance, pFontCChar);
  pFontCChar = 0;
}


//----- (0049695A) --------------------------------------------------------
void __cdecl PlayerCreationUI_Initialize()
{
  int v1; // ebx@5
  int v2; // eax@6
  signed int v3; // ecx@6
  int v4; // eax@8
  signed int v5; // ecx@8
  int result; // eax@19
  //signed int v7; // [sp+10h] [bp-Ch]@7
  int v8; // [sp+10h] [bp-Ch]@9
  int v9; // [sp+10h] [bp-Ch]@11
  int v10; // [sp+10h] [bp-Ch]@13
  int v11; // [sp+10h] [bp-Ch]@15
  //signed int v12; // [sp+14h] [bp-8h]@5
  int v13; // [sp+14h] [bp-8h]@9
  int v14; // [sp+14h] [bp-8h]@11
  int v15; // [sp+14h] [bp-8h]@13
  signed int v16; // [sp+14h] [bp-8h]@16

 int i;
 wchar_t pFilename[256];
  if ( dword_50CBD0[0] )
    dword_50CBD0[0] = dword_50CBDC != 0;

  AudioPlayer_SetVolume(pAudioPlayer, aMusicVolumeLevels[byte_6BE371] * 64.0);

  ++pClass17_Icons_LOD->dword_011B9C;
  if ( !pClass17_Icons_LOD->dword_011B98 )
    pClass17_Icons_LOD->dword_011B98 = pClass17_Icons_LOD->uNumLoadedFiles;

  dword_4E28F8 = 21;
  dword_A74CD4 = 0;
  dword_A74CCC = 0;
  uPlayerCreationUI_SelectedCharacter = 0;
  v1 = pFontCreate->uFontHeight - 2;

  pPlayerCreationUI_ClassIcons[0] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_KNIGHT")];
  pPlayerCreationUI_ClassIcons[1] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_THIEF")];
  pPlayerCreationUI_ClassIcons[2] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_MONK")];
  pPlayerCreationUI_ClassIcons[3] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_PALADIN")];
  pPlayerCreationUI_ClassIcons[4] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_ARCHER")];
  pPlayerCreationUI_ClassIcons[5] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_RANGER")];
  pPlayerCreationUI_ClassIcons[6] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_CLERIC")];
  pPlayerCreationUI_ClassIcons[7] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_DRUID")];
  pPlayerCreationUI_ClassIcons[8] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"IC_SORCERER")];

  pPlayerCreationUI_Sky = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAKESKY")];
  pPlayerCreationUI_Top = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"MAKETOP")];

  for (i = 0; i < 22; ++i)
  {
   wsprintfW(pFilename, L"pc%02u-01", i + 1);
   pPlayerCreationUI_PCPortraits[i] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilename)];
  }

  uTextureID_PlayerCreationUI_FaceMask = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"FACEMASK")];

  uTextureID_PlayerCreationUI_BtnLeft = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"presleft");
  uTextureID_PlayerCreationUI_BtnRight = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"presrigh");
  uTextureID_PlayerCreationUI_BtnMinus = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"buttminu");
  uTextureID_PlayerCreationUI_BtnPlus = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"buttplus");

  for (i = 1; i < 20; ++i)
  {
   wsprintfW(pFilename, L"ArrowL%02u", i);
   pPlayerCreationUI_ArrowL[i] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilename)];

   wsprintfW(pFilename, L"ArrowR%02u", i);
   pPlayerCreationUI_ArrowR[i] = &pClass17_Icons_LOD->aLODHeaders[class17_LoadTextureFromCBM(pClass17_Icons_LOD, pFilename)];
  }

  pGUIWindow_PlayerCreation = GUIWindowCreate(0, 0, 640, 480, 1, 0, 0);
  v8 = 0;
  v13 = 8;
  do
  {
    GUIButtonCreate(pGUIWindow_PlayerCreation, v13, 120, 145, 25, 1, 0, 60, v8, 0, "", 0);
    v13 += 158;
    ++v8;
  }
  while ( v13 < 640 );

  array_A74CAC[0] = GUIButtonCreate(pGUIWindow_PlayerCreation, 10, 32, 11, 13, 1, 0, 171, 0, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74CAC[1] = GUIButtonCreate(pGUIWindow_PlayerCreation, 169, 32, 11, 13, 1, 0, 171, 1, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74CAC[2] = GUIButtonCreate(pGUIWindow_PlayerCreation, 327, 32, 11, 13, 1, 0, 171, 2, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74CAC[3] = GUIButtonCreate(pGUIWindow_PlayerCreation, 486, 32, 11, 13, 1, 0, 171, 3, 0, "", uTextureID_PlayerCreationUI_BtnLeft);

  array_A74CBC[0] = GUIButtonCreate(pGUIWindow_PlayerCreation, 74, 32, 11, 13, 1, 0, 172, 0, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74CBC[1] = GUIButtonCreate(pGUIWindow_PlayerCreation, 233, 32, 11, 13, 1, 0, 172, 1, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74CBC[2] = GUIButtonCreate(pGUIWindow_PlayerCreation, 391, 32, 11, 13, 1, 0, 172, 2, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74CBC[3] = GUIButtonCreate(pGUIWindow_PlayerCreation, 549, 32, 11, 13, 1, 0, 172, 3, 0, "", uTextureID_PlayerCreationUI_BtnRight);

  array_A74C9C[0] = GUIButtonCreate(pGUIWindow_PlayerCreation, 10, 103, 11, 13, 1, 0, 144, 0, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74C9C[1] = GUIButtonCreate(pGUIWindow_PlayerCreation, 169, 103, 11, 13, 1, 0, 144, 1, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74C9C[2] = GUIButtonCreate(pGUIWindow_PlayerCreation, 327, 103, 11, 13, 1, 0, 144, 2, 0, "", uTextureID_PlayerCreationUI_BtnLeft);
  array_A74C9C[3] = GUIButtonCreate(pGUIWindow_PlayerCreation, 486, 103, 11, 13, 1, 0, 144, 3, 0, "", uTextureID_PlayerCreationUI_BtnLeft);

  array_A74C8C[0] = GUIButtonCreate(pGUIWindow_PlayerCreation, 74, 103, 11, 13, 1, 0, 145, 0, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74C8C[1] = GUIButtonCreate(pGUIWindow_PlayerCreation, 233, 103, 11, 13, 1, 0, 145, 1, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74C8C[2] = GUIButtonCreate(pGUIWindow_PlayerCreation, 391, 103, 11, 13, 1, 0, 145, 2, 0, "", uTextureID_PlayerCreationUI_BtnRight);
  array_A74C8C[3] = GUIButtonCreate(pGUIWindow_PlayerCreation, 549, 103, 11, 13, 1, 0, 145, 3, 0, "", uTextureID_PlayerCreationUI_BtnRight);

  v9 = 0;
  v14 = 8;
  do
  {
    GUIButtonCreate(pGUIWindow_PlayerCreation, v14, 308, 150, v1, 1, 0, 72, v9, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v14, v1 + 308, 150, v1, 1, 0, 73, v9, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v14, 2 * v1 + 308, 150, v1, 1, 0, 74, v9, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v14, 3 * v1 + 308, 150, v1, 1, 0, 75, v9, 0, "", 0);
    v14 += 158;
    ++v9;
  }
  while ( v14 < 640 );

  GUIButtonCreate(pGUIWindow_PlayerCreation, 5, 21, 153, 365, 1, 0, 118, 0, 49, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 163, 21, 153, 365, 1, 0, 118, 1, 50, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 321, 21, 153, 365, 1, 0, 118, 2, 51, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 479, 21, 153, 365, 1, 0, 118, 3, 52, "", 0);
  v15 = 23;
  v10 = 2;
  do
  {
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 169, 120, 20, 1, 0, 0, v10 - 2, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, v1 + 169, 120, 20, 1, 0, 0, v10 - 1, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 2 * v1 + 169, 120, 20, 1, 0, 0, v10, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 3 * v1 + 169, 120, 20, 1, 0, 0, v10 + 1, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 4 * v1 + 169, 120, 20, 1, 0, 0, v10 + 2, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 5 * v1 + 169, 120, 20, 1, 0, 0, v10 + 3, 0, "", 0);
    GUIButtonCreate(pGUIWindow_PlayerCreation, v15, 6 * v1 + 169, 120, 20, 1, 0, 0, v10 + 4, 0, "", 0);
    v10 += 7;
    v15 += 158;
  }
  while ( v10 < 30 );

  sub_41D08F(pGUIWindow_PlayerCreation, 28, 0, 7, 40);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 323, 417, 65, v1, 1, 0, 65, 0, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 323, v1 + 417, 65, v1, 1, 0, 65, 12, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 323, 2 * v1 + 417, 65, v1, 1, 0, 65, 20, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 388, 417, 65, v1, 1, 0, 65, 24, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 388, v1 + 417, 65, v1, 1, 0, 65, 28, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 388, 2 * v1 + 417, 65, v1, 1, 0, 65, 32, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 453, 417, 65, v1, 1, 0, 65, 16, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 453, v1 + 417, 65, v1, 1, 0, 65, 8, 0, "", 0);
  GUIButtonCreate(pGUIWindow_PlayerCreation, 453, 2 * v1 + 417, 65, v1, 1, 0, 65, 4, 0, "", 0);

  v11 = 0;
  do
  {
    v16 = -5;
    if ( v11 <= 3 )
      v16 = 0;
    GUIButtonCreate(pGUIWindow_PlayerCreation, 100 * v11 / 3 + v16 + 17, v1 * v11 % 3 + 417, 100, v1, 1, 0, 64, v11, 0, "", 0);
    ++v11;
  }
  while ( v11 < 9 );

  __asm nop
  pPlayerCreationUI_BtnOK = GUIButtonCreate(pGUIWindow_PlayerCreation,
                                            580, 431,
                                            51,
                                            39,
                                            1,
                                            0,
                                            66,
                                            0,
                                            13,
                                            "OK",
                                            uTextureIdx_BtnMake);

  pPlayerCreationUI_BtnReset = GUIButtonCreate(pGUIWindow_PlayerCreation,
                                               527, 431,
                                               51,
                                               39,
                                               1,
                                               0,
                                               67,
                                               0,
                                               67,
                                               "Reset",
                                               uTextureIdx_BtnMake2);

  pPlayerCreationUI_BtnMinus = GUIButtonCreate(pGUIWindow_PlayerCreation, 523, 393, 20, 35, 1, 0, 63, 0, 45, "BtnMinus", uTextureID_PlayerCreationUI_BtnMinus);
  pPlayerCreationUI_BtnPlus = GUIButtonCreate(pGUIWindow_PlayerCreation, 613, 393, 20, 35, 1, 0, 62, 1, 43, "BtnPlus", uTextureID_PlayerCreationUI_BtnPlus);

  pFontCChar = LoadFont("cchar.fnt", "FONTPAL");
}



//----- (0044C768) --------------------------------------------------------
unsigned char *__fastcall FitTextInAWindow(const char *pString, struct Font *pFont, struct GUIWindow *pParent, unsigned int uX, int a5)
{
  const char *v5; // edi@1
  unsigned char *v6; // esi@1
  int v8; // eax@3
  int v9; // edi@3
  int *v12; // ecx@10
  int v16; // edx@15
  int v17; // ecx@15
  int v18; // esi@15
  int v19; // ebx@16
  int v20; // edi@16
  unsigned __int8 v24; // dl@17
  int v27; // edi@39
  int v28; // eax@42
  char v29; // [sp-18h] [bp-40h]@2
  int v30; // [sp-14h] [bp-3Ch]@2
  int v31; // [sp-10h] [bp-38h]@2
  int v32; // [sp-Ch] [bp-34h]@2
  const char *v35; // [sp+Ch] [bp-1Ch]@1
  char Dest[3+256+array_size_unknown];
  char v37; // [sp+13h] [bp-15h]@42
  size_t v38; // [sp+14h] [bp-14h]@3
  int v39; // [sp+18h] [bp-10h]@3
  int v40; // [sp+1Ch] [bp-Ch]@1
  int v41; // [sp+20h] [bp-8h]@3
  int v42; // [sp+24h] [bp-4h]@3
 unsigned char c;

 v5 = pString;
 v35 = pString;
 v6 = pFont;
 v40 = pFont;
 if (!pString)
 {
   *(_DWORD *)&uX = &v29;
   sub_40E2C8(&v29, "Invalid string passed !", (int)(&uX + 3));
   sub_466D09(&pParent, *(int *)&v29, v30, v31, v32, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Font.cpp", 445);
   return 0;
 }

 strcpy(byte_5C45B0, pString);
 v8 = uX;
 v9 = 0;
 v41 = 0;
 v39 = uX;
 v42 = 0;

 v38 = strlen(pString);
 if (!v38)
   return byte_5C45B0;

 while (true)
 {
  c = byte_5C45B0[v9];
  if ((c < v6[0] || c > v6[1]) && c != '\f' && c != '\r' && c != '\n' && c != '\t')
    goto LABEL_34;

  v12 = pFont->dword_000020[c];
  if (c == '\t')
  {
   strncpy(Dest, &byte_5C45B0[v9 + 1], 3);
   v28 = atoi(Dest);
   v37 = 0;
   v8 = uX + v28;
   v27 = v9 + 3;
   v39 = v8;
   v42 = v27;
   goto LABEL_34;
  }
  else if (c == '\n')
    break;
  else if (c == '\f')
  {
   v27 = v9 + 5;
   v42 = v27;
   goto LABEL_34;
  }
  else if (c != '\r')
  {
   if (c != ' ')
   {
    v17 = v12[0];
    v16 = v12[1];
    v18 = v12[2];

    if ((unsigned int)(v8 + v18 + v17 + v16) < pParent->uFrameWidth)
    {
     if ( v42 > v41 )
       v8 += v17;
     v8 += v16;
     if (v42 < (signed int)v38)
       v8 += v18;
     v6 = v40;
    }
    else
    {
     v19 = v41;
     v8 = v39;
     v6 = v40;
     byte_5C45B0[v41] = '\n';
     v20 = v19;

     //compile_error;//v23 = __SETO__(v41, v42);
     //v21 = v41 == v42;
     //v22 = v41 - v42 < 0;
     //if ( (unsigned __int8)(v22 ^ v23) | v21 )
     if (v41 <= v42)
     {
      do
      {
       v24 = byte_5C45B0[v20];
       if (v24 >= v6[0] && v24 <= v6[1] || v24 == '\f' || v24 == '\r' || v24 == '\n' || v24 ==  '\t')
       {
        if ( v20 > v19 )
          v8 += *(_DWORD *)(v6 + 12 * v24 + 32);
        v8 += *(_DWORD *)(v6 + 4 * (3 * v24 + 9));
        if ( v20 < v42 )
          v8 += *(_DWORD *)(v6 + 12 * v24 + 40);
       }
       ++v20;
      }
      while ( v20 <= v42 );
     }
    }
    goto LABEL_34;
   }
   v8 += *(_DWORD *)(v12 + 4);
   goto LABEL_41;
  }
  if (!a5)
    return (char *)v35;

LABEL_34:
  v9 = v42 + 1;
  v42++;
  //compile_error;//v26 = __SETO__(v42, v38);
  //v25 = (signed int)(v42 - v38) < 0;
  if (v42 >= v38)//if ( !(v25 ^ v26) )
    return byte_5C45B0;
 }
 v8 = v39;

LABEL_41:
 v41 = v9;
 goto LABEL_34;
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
 int i;

  v2 = _this;
  if ( dword_720010)
    Mouse_suspend(dword_720010);

  if (uProgressBarType)
    _this->uProgressBarType = uProgressBarType;

  if (_this->uProgressBarType == 1)
  {
    v5 = 0;
    for (i = 1; i < 6; ++i)
      if (_this->array_000010[i] == 1)
        ++v5;

    v6 = (int)((char *)v2 + 16);

    if (v5 == 5 )
      memset(_this->array_000010, 0, 8);

    v7 = rand() % 5 + 1;
    if ( *((_BYTE *)v2 + v7 + 16) == 1 )
    {
      do
        v7 = rand() % 5 + 1;
      while ( *(_BYTE *)(v6 + v7) == 1 );
    }
    wsprintfA(Str1, "loading%d", v7);
    RGBTexture_Load(&_this->loading, Str1, 2);
    _this->_addon_loadprog_id_in_Icons_LOD = class17_LoadTextureFromCBM(pClass17_Icons_LOD, L"loadprog");

    _this->uX = 122;
    _this->uY = 151;
    _this->uWidth = 449;
    _this->uHeight = 56;

    _this->uProgressMax = 26;
    _this->uProgressCurrent = 0;

    DrawLoadingScreen(v2);
  }
  else
  {
   if (pParty_global->uAlignment == 0)
     sub_410522(pClass17_Icons_LOD, (char *)v2 + 296, "bardata-b", 2);
   else if (pParty_global->uAlignment == 1)
     sub_410522(pClass17_Icons_LOD, (char *)v2 + 296, "bardata", 2);
   else
     sub_410522(pClass17_Icons_LOD, (char *)v2 + 296, "bardata-C", 2);

   *((_BYTE *)v2 + 11) = 0;
   *((_BYTE *)v2 + 10) = 26;
   DrawLoadingScreen(v2);
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
  CD3DRenderer_BeginScene(pD3DRenderer);
  if (_this->uProgressBarType != 1 )
  {
    if ( *(_DWORD *)(v1 + 344) )
    {
      if ( pD3DRenderer->dword_040088 )
      {
        if ( !pD3DRenderer->dword_040058 )
          sub_49FD3A(pD3DRenderer, v1);
      }
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 80, 122, v1 + 296);
      v4 = CIconFrameTable_GetFrame(pIconFrameTable, dword_50C984, 0);
      CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 100, 146, 72 * *(_WORD *)(v4 + 30) + 7145548);
      v5 = (double)(113 * *(_BYTE *)(v1 + 11)) / (double)*(_BYTE *)(v1 + 10);
      sub_4A6D87(pD3DRenderer, 0, 174, 164, v5 + 6.755399441055744e15, 16, pD3DRenderer->dword_0400D8);

      CD3DRenderer_EndScene(pD3DRenderer);
      CD3DRenderer_Present(pD3DRenderer);
      return;
    }
    CD3DRenderer_EndScene(pD3DRenderer);
    return;
  }

  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, v1 + 24);
  CD3DRenderer_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  sub_4A5B81(pD3DRenderer,
    172,
    459,
    172 + 300 * ((float)(_this->uProgressCurrent) / (float)_this->uProgressMax),
    471);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 172, 459, &pClass17_Icons_LOD->aLODHeaders[_this->_addon_loadprog_id_in_Icons_LOD]);
  CD3DRenderer_sub_4A5BB6(pD3DRenderer);
  CD3DRenderer_EndScene(pD3DRenderer);
  CD3DRenderer_Present(pD3DRenderer);
}


//----- (004435BB) --------------------------------------------------------
void LevelLoadingUI_Reset(struct class56 *_this, char a2)
{
 _this->byte_000009 = 0;
 _this->uProgressMax = a2;
 _this->uProgressCurrent = 0;
}

//----- (0041C179) --------------------------------------------------------
void __cdecl GameUI_DrawStatusBar()
{
  char *v0; // ebp@1
  int v1; // eax@5
  char *v2; // edi@5
  int v3; // esi@5
  size_t v4; // eax@6
  int v5; // ecx@6
  int v6; // eax@9
  size_t v7; // eax@10
  int v8; // ecx@10
  char v9; // zf@12
  __int16 v10; // ST08_2@13
  int v11; // eax@13

  v0 = *(char **)&dword_507AF8;
  if ( pStatusBarString[0] || dword_5C35B8 || dword_5C35BC )
  {
    CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 352, pTexture_StatusBar);
    if ( dword_5C35B8 )
    {
      v2 = &byte_5C3428;
      v1 = sub_44C51E(pFontLucida, &byte_5C3428);
      v3 = 450;
      while ( v1 > 450 )
      {
        v4 = strlen(&byte_5C3428);
        v5 = pFontLucida;
        byte_5C3427[v4] = 0;
        v1 = sub_44C51E(v5, &byte_5C3428);
      }
    }
    else
    {
      v2 = pStatusBarString;
      v6 = sub_44C51E(pFontLucida, pStatusBarString);
      v3 = 450;
      while ( v6 > 450 )
      {
        v7 = strlen(pStatusBarString);
        v8 = pFontLucida;
        byte_5C34EF[v7] = 0;
        v6 = sub_44C51E(v8, pStatusBarString);
      }
    }
    v9 = *v2 == 0;
    dword_5C35BC = 0;
    if ( !v9 )
    {
      v10 = dword_507AFC;
      v11 = AlignText_Center(v3, v2, pFontLucida);
      FontDrawText(pGUIWindow0, pFontLucida, v11 + 11, 357, v10, v2, 0, 0, v0);
    }
  }
}

//----- (0044C502) --------------------------------------------------------
int __fastcall AlignText_Center(int a1, const char *pString, struct Font *pFont)
{
  int v3; // esi@1
  int result; // eax@2

  v3 = (a1 - sub_44C51E(pFont, pString)) / 2;
  if ( v3 >= 0 )
    result = v3;
  else
    result = 0;
  return result;
}

//----- (0044C51E) --------------------------------------------------------
bool __fastcall sub_44C4DE(unsigned __int8 a1, int a2);
int __fastcall sub_44C51E(struct Font *_this, const char *pString)
{
  signed int i; // ebx@3
  size_t v5; // ebp@3
  int v6; // esi@3
  const char *v8; // [sp+0h] [bp-4h]@1
 unsigned char c;

 if (!pString)
   return 0;

 v8 = pString;
 v5 = strlen(pString);
 v6 = 0;
 for ( i = 0; i < v5; ++i )
 {
  c = pString[i];
  if (sub_44C4DE(c, _this))
  {
   if (c == '\n' || c == '\r')
     return v6;
   if (c != '\f')
   {
    if (i > 0)
      v6 += _this->dword_000020[c][0];
    v6 += _this->dword_000020[c][1];
    if (i < v5)
      v6 += _this->dword_000020[c][2];
   }
   else
     i += 5;
  }
 }
 return v6;
}

//----- (0041B3E2) --------------------------------------------------------
int __cdecl GameUI_DrawFrames()
{
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, pTexture_TopFrame);
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 8, pTexture_LeftFrame);
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 468, 0, pTexture_RightFrame);
  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 352, pTexture_BottomFrame);

  GameUI_DrawFoodAndGold();

  runtime_warning;
  //return sub_41AD6E();
}

//----- (0041AEBB) --------------------------------------------------------
void __cdecl GameUI_DrawFoodAndGold()
{
  __int16 v0; // bx@2
  char *v1; // ebp@2
  int v2; // esi@2

  if ( dword_6A0D48 != 9 )
  {
    v0 = dword_507AFC;
    v1 = *(char **)&dword_507AF8;
    v2 = sub_44100D() != 0 ? 381 : 322;
    wsprintfA(ExistingFileName, "\r087%lu", pParty_global->uNumFood);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, v0, ExistingFileName, 0, 0, v1);
    wsprintfA(ExistingFileName, "\r028%lu", pParty_global->uNumGold);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, v0, ExistingFileName, 0, 0, v1);
  }
}

//----- (0044162D) --------------------------------------------------------
void __cdecl GameUI_DrawPartySpells()
{
  signed int v0; // ebp@1
  int v2; // eax@2
  int v3; // ecx@5
  signed int v4; // ebx@25
  int v5; // edi@26
  signed int v6; // [sp-4h] [bp-1Ch]@11
  int v7; // [sp-4h] [bp-1Ch]@12
  signed int v8; // [sp-4h] [bp-1Ch]@20
  int v9; // [sp-4h] [bp-1Ch]@21
 int i;

  v0 = (signed __int64)((double)GetTickCount() * 0.05000000074505806);

 for (i = 0; i < 14; ++i)
  {
    v2 = 16 * (unsigned __int8)byte_4E5DD8[i];
    if ( *(int *)((char *)&dword_ACD848 + v2) >= 0 )
    {
      if ( *(int *)((char *)&dword_ACD848 + v2) > 0 || *(unsigned int *)(pParty_global->array_00088C + (unsigned __int8)byte_4E5DD8[i]) > 0 )
      {
        v3 = uTextureIdx_SpellEffecIcons[i];
        sub_4A65CC(
          pD3DRenderer,
          dword_4E5D68[2 * i],
          dword_4E5D6C[2 * i],
          v3 != -1 ? 72 * v3 + 7145548 : 0,
          v3 != -1 ? 72 * v3 + 7145548 : 0,
          v0 + 20 * (unsigned __int8)byte_4E5DE8[i],
          0,
          63);
      }
    }
  }

  if ( !dword_4E28F8 || dword_4E28F8 == 4 )
  {
    if ( qword_ACD8B4 > 0 )
    {
      if ( dword_ACD6BC )
        v6 = v0;
      else
        v6 = 0;
      v7 = &pClass17_Icons_LOD->aLODHeaders[CIconFrameTable_GetFrame(pIconFrameTable, uIconIdx_Spell21, v6)->uTextureIdx];
      if ( pD3DRenderer->dword_040088 )
        CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 8, 8, v7);
      else
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 8, 8, v7);
    }
    if ( HIDWORD(qword_ACD964) >= 0 )
    {
      if ( HIDWORD(qword_ACD964) > 0 || (_DWORD)qword_ACD964 )
      {
        if ( pParty_global->dword_007778 & 0x80 )
          v8 = v0;
        else
          v8 = 0;
        v9 = 72 * *(_WORD *)(CIconFrameTable_GetFrame(pIconFrameTable, uIconIdx_Spell27, v8) + 30) + 7145548;
        if ( pD3DRenderer->dword_040088 )
          CD3DRenderer_DrawIndexedTexture(pD3DRenderer, 396, 8, v9);
        else
          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 396, 8, v9);
      }
    }
  }

  v4 = (signed int)&off_4ED748;

  for (i = 0; i < 4; ++i)
  {
    v5 = pPlayers[i];
    if ( *(_QWORD *)(v5 + 6144) > 0i64 )
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, *(_WORD *)v4 + 72, 427, &pClass17_Icons_LOD->aLODHeaders[dword_507964]);
    if ( *(_QWORD *)(v5 + 6064) > 0i64 )
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, *(_WORD *)v4 + 72, 393, &pClass17_Icons_LOD->aLODHeaders[dword_50796C]);
    if ( *(_QWORD *)(v5 + 6224) > 0i64 )
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, *(_WORD *)v4 + 72, 410, &pClass17_Icons_LOD->aLODHeaders[dword_507968]);
    if ( *(_QWORD *)(v5 + 6208) > 0i64 )
      CD3DRenderer_DrawIndexedTexture(pD3DRenderer, *(_WORD *)v4 + 72, 444, &pClass17_Icons_LOD->aLODHeaders[dword_507960]);
    v4 += 2;
  }
}


//----- (004435E2) --------------------------------------------------------
void LevelLoadingUI_Release(struct class56 *_this)
{
  void *v1; // esi@1
  int v6; // eax@8
  int v7; // eax@9

  v1 = _this;
 if (dword_720010)
   sub_46B105(dword_720010);

 if (_this->uProgressBarType == 1 )
 {
  if (_this->loading.pPixels)
    return;

  if (_this->uProgressCurrent != _this->uProgressMax)
  {
   _this->uProgressCurrent = _this->uProgressMax - 1;
    LevelLoadingUI_UpdateAndDrawProgressBar(_this);
  }
  call_delete(0, _this->loading.pPixels);
  _this->loading.pPixels = 0;

  operator_delete(0, _this->loading.pPixels);
  _this->loading.pPixels = 0;
 }
 else
 {
    v6 = *((_DWORD *)v1 + 86);
    if ( !v6 )
      return;
    v7 = operator_delete(v6, *((_DWORD *)v1 + 86));
    operator_delete(v7, *((_DWORD *)v1 + 90));
    *((_DWORD *)v1 + 86) = 0;
    *(_DWORD *)(int)((char *)v1 + 360) = 0;
  }
}


//----- (004921C1) --------------------------------------------------------
void GameUI_DrawPortraits(void *this)
{
  signed int v1; // ebx@2
  void *v2; // ebp@7
  signed int v3; // esi@7
  int v4; // eax@10
  int v5; // edx@13
  int v6; // eax@14
  int v7; // eax@17
  int v8; // eax@21
  int v9; // eax@27
  bool v10; // eax@33
  bool v11; // edi@40
  bool v12; // edx@43
  bool v13; // ecx@46
  int v14; // esi@54
  int v15; // edi@55
  int v16; // eax@57
  int v19; // eax@62
  int v20; // [sp-4h] [bp-1Ch]@27
  signed int v21; // [sp+10h] [bp-8h]@7
  void *v22; // [sp+14h] [bp-4h]@1
 int i;

  v22 = this;
  if ( qword_A750D8 )
  {
    qword_A750D8 -= pClass24_global2->dword_00001C;
    v1 = 0;
    if ( qword_A750D8 <= 0 )
    {
      if ( sub_492C0B(pPlayers[word_A750E2 - 1]) )
        sub_4948B1(pPlayers[word_A750E2 - 1], word_A750E0, 0);
      qword_A750D8 = 0i64;
    }
  }
  else
  {
    v1 = 0;
  }
  v2 = 0;
  v21 = v1;
  v3 = (signed int)&dword_ACD9F4;
  while ( 1 )
  {
    if ( *(_QWORD *)(v3 + 16) )
    {
      v4 = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_PlayerFaceDead];
LABEL_27:
      v20 = v4;
      v9 = off_4ED748[(_DWORD)v2];
      if ( qword_ACD8F4 )
        sub_4A6E7E(pD3DRenderer, v9, 387, v20);
      else
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v9 + 1, 388, v20);
      v10 = *(_DWORD *)(v3 + 6164) >= v1 && (*(_DWORD *)(v3 + 6164) > v1 || *(_DWORD *)(v3 + 6160) > (unsigned int)v1);
      if ( *(_DWORD *)(v3 + 5956) >= v1 )
      {
        if ( *(_DWORD *)(v3 + 5956) > v1 || *(_DWORD *)(v3 + 5952) > (unsigned int)v1 )
          v1 = 1;
      }
      v11 = *(_QWORD *)(v3 + 6064) > 0i64;
      v12 = *(_QWORD *)(v3 + 6048) > 0i64;
      v13 = *(_QWORD *)(v3 + 6144) > 0i64;
      if ( v13 | v12 | v11 | v1 | v10 )
        sub_441A4E(v2);
      goto LABEL_50;
    }
    if ( *(_QWORD *)v3 )
    {
      v4 = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_PlayerFaceEradicated];
      goto LABEL_27;
    }
    v5 = 0;
    if ( pPlayerFrameTable->uNumFrames <= v1 )
    {
LABEL_17:
      v7 = 0;
    }
    else
    {
     v6 = pPlayerFrameTable->pFrames;
      while ( *(_WORD *)v6 != *(_WORD *)(v3 + 6700) )
      {
        ++v5;
        v6 += 10;
        if ( v5 >= pPlayerFrameTable->uNumFrames )
          goto LABEL_17;
      }
      v7 = v5;
    }
    if ( v7 == v1 )
      v7 = 1;
    if ( *(_WORD *)(v3 + 6700) == 21 )
     v8 = sub_494B5E(pPlayerFrameTable, v3 + 6712, v3 + 6708, pClass24_global2->dword_00001C);
    else
      v8 = sub_494B10(pPlayerFrameTable, v7, *(_WORD *)(v3 + 6702));
    if ( *(_WORD *)(v3 + 6706) != *(_WORD *)(v8 + 2) - 1 || v22 )
    {
      *(_WORD *)(v3 + 6706) = *(_WORD *)(v8 + 2) - 1;
      v1 = 0;
      v4 = &pClass17_Icons_LOD->aLODHeaders[dword_A74CEC[v21 + *(_WORD *)(v8 + 2)]];
      goto LABEL_27;
    }
LABEL_50:
    v21 += 56;
    v3 += 6972;
    v2 = (char *)v2 + 1;
    if ( v3 >= (signed int)&unk_AD46E4 )
      break;
    v1 = 0;
  }
  if ( dword_ACD834 == 1 )
  {
    if ( dword_4F885C != 1 )
    {
      if ( (dword_4F8878[0] & 7) == 4 )
      {
        v14 = 0;
        if ( dword_4F8864 > 0 )
        {
          v15 = (int)dword_4F8878;
          do
          {
            if ( (*(_BYTE *)v15 & 7) != 4 )
              break;
            v16 = uTextureIdx_SensorGreen;
            if ( pParty_global->dword_007778 & 0x10 )
            {
              v16 = dword_5079CC;
            }
            else
            {
              if ( pParty_global->dword_007778 & 0x20 )
                v16 = dword_5079C8;
            }
            CD3DRenderer_DrawTransparentTexture(pD3DRenderer, off_4ED748[*(_DWORD *)v15 >> 3] - 4, 385, v16 != -1 ? 72 * v16 + 7145548 : 0);
            ++v14;
            v15 += 16;
          }
          while ( v14 < dword_4F8864 );
        }
      }
    }
  }
  else
  {
    for (i = 0; i < 4; ++i)
    {
      if ( sub_492C0B(&pParty_global->pPlayers[i]) )
      {
        if ( !pParty_global->pPlayers[i].word_001934)
        {
          v19 = uTextureIdx_SensorGreen;
          if ( pParty_global->dword_007778 & 0x10 )
            v19 = dword_5079CC;
          else if ( pParty_global->dword_007778 & 0x20 )
              v19 = dword_5079C8;
          CD3DRenderer_DrawTransparentTexture(pD3DRenderer, off_4ED748[i] - 4, 385, &pClass17_Icons_LOD->aLODHeaders[v19]);
        }
      }
    }
  }
}