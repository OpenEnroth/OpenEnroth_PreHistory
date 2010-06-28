#include "GUI.h"

#include "defs.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "mm7DDrawRenderer.h"

#include "data.h"

#include "FrameTables.h"




//----- (00420EFF) --------------------------------------------------------
void GameUI_Update()
{
  int v1; // ebx@6
  int *v2; // edi@7
  unsigned int v4; // eax@19
  int v5; // ecx@19
  int v6; // eax@19
  char v7; // cl@19
  __int16 v8; // fps@23
  unsigned __int8 v9; // c0@23
  unsigned __int8 v10; // c3@23
  int v11; // esi@24
  int v12; // edx@25
  char *v13; // ecx@28
  unsigned int v14; // eax@41
  void *v15; // ecx@44
  int v16; // ecx@46
  int v17; // eax@49
  signed int v18; // eax@55
  signed int v19; // ecx@63
  int v20; // eax@69
  __int16 v21; // ax@70
  char *v22; // eax@72
  __int16 v23; // ax@75
  __int16 *v24; // ecx@75
  __int16 *v25; // esi@75
  int v26; // ecx@79
  int v27; // eax@82
  char *v28; // ecx@82
  const CHAR *v29; // esi@82
  int v30; // ecx@88
  int v31; // eax@91
  unsigned __int8 v33; // c0@109
  unsigned __int8 v34; // c3@109
  int v35; // esi@110
  int v36; // edx@111
  int v37; // edx@117
  int v38; // ecx@118
  int v39; // [sp-8h] [bp-E8h]@20
  int v40; // [sp-8h] [bp-E8h]@83
  int v41; // [sp-4h] [bp-E4h]@20
  char Str1; // [sp+Ch] [bp-D4h]@129
  int x; // [sp+D4h] [bp-Ch]@1
  int y; // [sp+D8h] [bp-8h]@1
  int v45; // [sp+DCh] [bp-4h]@21
 int i;
 struct GUIButton *pControl;

  pGame->pClass03->dword_000000 = 0;
  class03_GetMouseClickPos(pGame->pClass03, &x, &y);
  if (x < 0 || x > 639 ||
      y < 0 || y > 479)
    return;

  if ( !dword_4E28F8 )
  {
    if (x > 467 || y > 351)  //if pointer isn't inside game viewport
      goto _mouse_is_on_UI;

    if ( pD3DRenderer->dword_040088 )
    {
      v18 = sub_4C1BF1(pGame->class05_obj);
      if (x < class28_global.dword_000000 || x > class28_global.dword_000008 ||
          y < class28_global.dword_000004 || y > class28_global.dword_00000C)
        v18 = -1;
      if ( v18 == -1 )
        goto LABEL_61;
    }
    else
      v18 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]];

    pGame->pClass03->dword_000000 = (unsigned __int16)v18;
    v19 = (signed int)(unsigned __int16)v18 >> 3;
    if ( (v18 & 7) == 2 )
    {
      v30 = 112 * v19;
      if (pObjectDescriptionList->pDescriptions[array_665230[v19].uObjectDescriptionID].byte_000026 & 0x10)
        goto LABEL_73;
      if ( v18 >= 33554432 || dword_AD470C )
      {
        v22 = (char *)sub_456499((char *)&unk_665254 + v30);
LABEL_93:
        v26 = (int)v22;
        goto LABEL_87;
      }
      v31 = sub_456499((char *)&unk_665254 + v30);
      v29 = ExistingFileName;
      sprintfex(ExistingFileName, pGlobalTXT_LocalizationStrings[470], v31);
    }
    else
    {
      if ( (v18 & 7) != 3 )
      {
        if ( (v18 & 7) == 5 )
        {
          v24 = &array_6836D0[v19];
          v25 = v24;
          v23 = v24[11];
          if ( !v23 )
          {
            if ( sub_44C2F4(v24) )
             v26 = dword_722240[2 * (unsigned __int8)global_5E4C90.byte_000000[v25[14]]];
            else
              v26 = 84 * *v25 + pDecorationDescriptionList->pDescriptions + 32;
            goto LABEL_87;
          }
          v22 = sub_444732((void *)v23);
          if ( !v22 )
            goto LABEL_123;
          goto LABEL_93;
        }
        if ( (v18 & 7) == 6 )
        {
          if ( v18 < 33554432 )
          {
            if ( dword_6BE360 != 1 )
            {
              v21 = *(_WORD *)(*(_DWORD *)(188 * ((signed int)(unsigned __int16)v18 >> 9) + pClass51_global->pBModels + 84)
                             + 308 * (v19 & 0x3F)
                             + 292);
              goto LABEL_71;
            }
            v20 = dword_6BE644 + 96 * v19;
            if ( *(_BYTE *)(v20 + 47) & 6 )
            {
              v21 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v20 + 72) + 26);
LABEL_71:
              if ( !v21 || (v22 = sub_444732((void *)v21), !v22) )
                goto LABEL_73;
              goto LABEL_93;
            }
          }
LABEL_73:
          pGame->pClass03->dword_000000 = 0;
          goto LABEL_50;
        }
LABEL_61:
        pGame->pClass03->dword_000000 = 0;
        goto LABEL_123;
      }
      if ( v18 >= 335544320 )
        goto LABEL_61;
      v28 = (char *)pActors + 836 * v19;
      v29 = &ExistingFileName;
      v27 = *((_DWORD *)v28 + 205);
      if ( v27 )
        //v40 = dword_5D2958[v27];
        v40 = pMonsterStats->sPlacements.pSubstrings[v27 - 1];
      else
        v40 = pMonsterStats->pMonsterInfos[*((_WORD *)v28 + 48)].pName;
      strncpy((char *)&ExistingFileName, (const char *)v40, 0x7D0u);
    }
    v26 = (int)v29;
LABEL_87:
    sub_41C0B8((const char *)v26);
    goto LABEL_123;
  }
  v1 = uNumGUIWindows;

  if ( uNumGUIWindows <= 0 )
  {
LABEL_38:
    if ( dword_4E28F8 == 10 )
    {
      sub_42038D();
      goto LABEL_123;
    }
    if ( dword_4E28F8 == 13 )
    {
      if ( dword_F8B19C != 2
        || (v16 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]], v16 == 0)
        || v16 == -65536 )
        goto LABEL_123;
      v15 = (void *)(36 * (v16 + 12 * *(_DWORD *)(dword_507BC0 + 28)) + 11355920);
LABEL_49:
      v17 = sub_456499(v15);
      sub_41C0B8((const char *)v17);
LABEL_50:
      dword_506578 = 1;
LABEL_123:
      if (pGame->pClass03->dword_000000 == 0)
      {
        if ( dword_506578 != 0 )
        {
          pStatusBarString[0] = 0;
          dword_5C35BC = 1;
        }
      }
      dword_506578 = pGame->pClass03->dword_000000;
      return;
    }
    if ( y < 350 )
    {
      v14 = pD3DRenderer->pActiveZBuffer[x + dword_5059A8[y]];
      if ( v14 == 0 || v14 == -65536 || v14 >= 0x1388 )
        goto LABEL_123;
      v15 = *((char **)(&ptr_A750C4) + uMaybeSelectedCharacter) + 36 * v14 + 496;
      goto LABEL_49;
    }

_mouse_is_on_UI:
    if (x >= GUIWindow_List[0].uFrameX && x <= GUIWindow_List[0].uFrameZ &&
        y >= GUIWindow_List[0].uFrameY && y <= GUIWindow_List[0].uFrameW)
    {
      for ( pControl = GUIWindow_List[0].pControlsHead; pControl; pControl = pControl->pNext)
      {
        if (pControl->dword_000018 == 1 )
        {
          if (x >= pControl->uX && x <= pControl->uZ &&
              y >= pControl->uY && y <= pControl->uW)
          {
            v37 = pControl->dword_00001C;
            if ( v37 == 0 )
              goto LABEL_28;
            v38 = pControl->dword_000024;
            if ( dword_50CBD0[0] < 40 )
            {
              dword_50CBD0[3 * dword_50CBD0[0] + 1] = v37;
              dword_50CBD0[3 * dword_50CBD0[0] + 2] = v38;
              dword_50CBD0[3 * dword_50CBD0[0]++ + 3] = 0;
            }
            goto LABEL_131;
          }
        }
        else
        {
          if (pControl->dword_000018 == 2 )
          {
           v45 = x - pControl->uX;
            v45 = y - pControl->uY;
            if (pControl->uWidth)
            {
             if (pControl->uHeight)
              {
                if ( v33 | v34 )
                {
                  v35 = pControl->dword_00001C;
                  if ( v35 != 0 )
                  {
                    v36 = pControl->dword_000024;
                    if ( dword_50CBD0[0] < 40 )
                    {
                      dword_50CBD0[3 * dword_50CBD0[0] + 1] = v35;
                      dword_50CBD0[3 * dword_50CBD0[0] + 2] = v36;
                      dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
                      goto LABEL_27;
                    }
                  }
                  goto LABEL_28;
                }
              }
            }
          }
          else if (pControl->dword_000018 == 3 &&
                   x >= pControl->uX && x <= pControl->uZ &&
                   y >= pControl->uY && y <= pControl->uW)
            goto LABEL_19;
        }
      }
    }
    pGame->pClass03->dword_000000 = sub_46A99B();
    goto LABEL_123;
  }
  while ( 1 )
  {
    v2 = &GUIWindow_List[array_5075E0[v1] - 1];
    if ( x >= *v2 && x <= v2[4] && y >= v2[1] && y <= v2[5] )
    {
      for ( i = v2[19]; ; i = *(_DWORD *)(i + 52) )
      {
        if ( !i )
          break;
        if ( *(_DWORD *)(i + 24) == 1 )
        {
          if (x >= *(_DWORD *)i && x <= *(_DWORD *)(i + 16) &&
              y >= *(_DWORD *)(i + 4) && y <= *(_DWORD *)(i + 20))
          {
LABEL_24:
            v11 = *(_DWORD *)(i + 28);
            if ( v11 )
            {
              v12 = *(_DWORD *)(i + 36);
              if ( dword_50CBD0[0] < 40 )
              {
                dword_50CBD0[3 * dword_50CBD0[0] + 1] = v11;
                dword_50CBD0[3 * dword_50CBD0[0] + 2] = v12;
                dword_50CBD0[3 * dword_50CBD0[0] + 3] = 0;
LABEL_27:
                ++dword_50CBD0[0];
              }
            }
LABEL_28:
            v13 = (char *)(i + 85);
LABEL_130:
            sub_41C0B8(v13);
LABEL_131:
            dword_506578 = 1;
            return;
          }
        }
        else
        {
          if ( *(_DWORD *)(i + 24) == 2 )
          {
            v45 = x - *(_DWORD *)i;
            v45 = y - *(_DWORD *)(i + 4);
            if ( (double)*(signed int *)(i + 8) != 0.0 )
            {
              if ( (double)*(signed int *)(i + 12) != 0.0 )
              {
                UNDEF(v8);
                if ( v9 | v10 )
                  goto LABEL_24;
              }
            }
          }
          else
          {
            if (*(_DWORD *)(i + 24) == 3 &&
                x >= *(_DWORD *)i && x <= *(_DWORD *)(i + 16) &&
                y >= *(_DWORD *)(i + 4) && y <= *(_DWORD *)(i + 20))
            {
LABEL_19:
              v6 = (int)*(&ptr_A750C4 + uMaybeSelectedCharacter);
              v7 = *(_BYTE *)(v6 + 2 * *(_DWORD *)(i + 36) + 264);
              v4 = *(_DWORD *)(v6 + 6456);
              v5 = (v7 & 0x3F) + 1;
              if ( v4 < v5 )
              {
                v41 = v5 - v4;
                v39 = pGlobalTXT_LocalizationStrings[469];
              }
              else
              {
                v41 = v5;
                v39 = pGlobalTXT_LocalizationStrings[468];
              }
              sprintfex(&Str1, (const char *)v39, v41);
              v13 = &Str1;
              goto LABEL_130;
            }
          }
        }
      }
    }
    if ( v2[3] == 480 )
      break;
    --v1;
    if ( v1 <= 0 )
    {
      goto LABEL_38;
    }
  }
}

//----- (00441D38) --------------------------------------------------------
void GameUI_DrawMinimap(unsigned int uX, unsigned int uY, unsigned int uZ, unsigned int uW, unsigned int uMinimapZoom, int a6)
{
  int v6; // eax@4
  int v8; // eax@8
  int v9; // edx@9
  int v10; // edi@9
  int v11; // ebx@10
  __int16 v12; // cx@11
  int v13; // ecx@17
  int v14; // ecx@21
  int v15; // eax@23
  int v16; // ebx@23
  int v17; // ecx@28
  double v18; // st6@30
  __int16 v20; // di@30
  double v21; // st7@30
  int v24; // eax@37
  unsigned short *v25; // edx@37
  float v27; // ST3C_4@37
  double v28; // ST20_8@37
  double v29; // ST20_8@37
  signed int v30; // edi@40
  _UNKNOWN *v32; // ebx@43
  int v37; // eax@50
  signed int v38; // ecx@50
  int v44; // ebx@91
  int v45; // edi@91
  int v52; // ebx@114
  int v53; // ST64_4@114
  signed int v61; // [sp-4h] [bp-58h]@54
  int v71; // [sp+20h] [bp-34h]@23
  int v73; // [sp+24h] [bp-30h]@23
  signed int v74; // [sp+24h] [bp-30h]@37
  signed int v76; // [sp+28h] [bp-2Ch]@37
  int v77; // [sp+2Ch] [bp-28h]@30
  signed int v79; // [sp+34h] [bp-20h]@4
  signed int v82; // [sp+38h] [bp-1Ch]@37
  bool v84; // [sp+3Ch] [bp-18h]@2
  int v86; // [sp+40h] [bp-14h]@8
  signed int v93; // [sp+5Ch] [bp+8h]@7
  int i; // [sp+5Ch] [bp+8h]@27
  int v100; // [sp+60h] [bp+Ch]@23
  _UNKNOWN *v102; // [sp+60h] [bp+Ch]@37
  float v103; // [sp+60h] [bp+Ch]@37
  unsigned int v104; // [sp+60h] [bp+Ch]@95
  float v105; // [sp+64h] [bp+10h]@117

 unsigned int  x, y;
 unsigned int *pTargetSurface,
              *pSourceSurface;
 unsigned int  uMinimapCentreX,
               uMinimapCentreY;
 unsigned int  uMinimapWidth,
               uMinimapHeight;
 unsigned int *pMapPixels;
 unsigned int  uMinimapOffsetX,
               uMinimapOffsetY;


  uMinimapCentreX = (uX + uZ) / 2;
  uMinimapCentreY = (uY + uW) / 2;
  v84 = qword_ACD974 > 0;
  v79 = (unsigned __int16)word_ACD97E;
  LOBYTE(v6) = sub_476395((void *)0x26);
  if ( v6 )
  {
    v84 = 1;
    v79 = 2;
  }

 CD3DRenderer_sub_4A0E97(pD3DRenderer, uX, uY, uZ - 1, uW - 1);

 uMinimapWidth = uZ - uX;
 uMinimapHeight = uW - uY;

 if (dword_6BE360 != 1)
 {
  v20 = pClass17_Icons_LOD->aLODHeaders[uTextureID_LocationMap].word_00001C;
  v77 = (1 << (v20 + 16)) / uMinimapZoom;
  v21 = (double)(1 << (16 - (_BYTE)v20));

  //convert world-space xy to texture-space xy
  uMinimapOffsetX = pClass17_Icons_LOD->aLODHeaders[uTextureID_LocationMap].uTextureWidth * (32768 + pParty_global->sPartyPosX) / 65536;
  uMinimapOffsetY = pClass17_Icons_LOD->aLODHeaders[uTextureID_LocationMap].uTextureHeight * (32768 - pParty_global->sPartyPosY) / 65536;

  uMinimapOffsetX -= uMinimapWidth / (uMinimapZoom / 256);
  uMinimapOffsetY -= uMinimapHeight / (uMinimapZoom / 256);
             
  pMapPixels = pClass17_Icons_LOD->aLODHeaders[uTextureID_LocationMap].pTruecolorPixels;
  for (y = 0; y < uMinimapHeight; ++y)
  {
   pTargetSurface = pD3DRenderer->pTargetSurface + (uY + y) * pD3DRenderer->uTargetSurfacePitch + uX;
   pSourceSurface = pMapPixels + (uMinimapOffsetY + y) * pClass17_Icons_LOD->aLODHeaders[uTextureID_LocationMap].uTextureWidth + uMinimapOffsetX;
   for (x = 0; x < uMinimapWidth; ++x)
     *pTargetSurface++ = *pSourceSurface++;
  }
  dword_576D14 = 0;
 }
 else
 {
  sub_4A6D87(pD3DRenderer, uMinimapHeight, uX, uY, uMinimapWidth, uMinimapHeight, 15);
  dword_576D14 = 0;
  v93 = 0;
  if ( *(_DWORD *)dword_6BE670 > 0 )
  {
    v86 = 0;
    v8 = dword_6BE644;
    do
    {
      v10 = v86 + dword_6BE670 + 4;
      v9 = *(_DWORD *)(96 * *(_WORD *)(v86 + dword_6BE670 + 8) + v8 + 44);
      if ( BYTE1(v9) & 0x20
        || (v11 = *(_DWORD *)(96 * *(_WORD *)(v86 + dword_6BE670 + 10) + v8 + 44), BYTE1(v11) & 0x20) )
        goto LABEL_26;
      v12 = *(_WORD *)(v86 + dword_6BE670 + 14);
      if ( !(v12 & 1) )
      {
        if ( (_BYTE)v9 >= 0 && (_BYTE)v11 >= 0 )
          goto LABEL_26;
        *(_WORD *)(v86 + dword_6BE670 + 14) = v12 | 1;
        byte_6BE6EC[v93 >> 3] |= 1 << (7 - v93 % 8);
        v8 = dword_6BE644;
      }
      if ( v84
        && v79 >= 3
        && ((v13 = v8 + 96 * *(_WORD *)(v10 + 4), *(_DWORD *)(v13 + 44) & 0x2000000)
         || *(_DWORD *)(96 * *(_WORD *)(v10 + 6) + v8 + 44) & 0x2000000)
        && (*(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(v13 + 72) + 26)
         || *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(96 * *(_WORD *)(v10 + 6) + v8 + 72) + 26))
        && (v14 = dword_576D14, dword_576D14 < 49) )
      {
        word_576D80[dword_576D14] = v93;
        dword_576D14 = v14 + 1;
      }
      else
      {
        v73 = uMinimapCentreX
            + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v10)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosX) >> 16);
        v71 = uMinimapCentreY
            - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v10 + 2)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosY) >> 16);
        v100 = uMinimapCentreX
             + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v10 + 2))) >> 16) << 16)
                           - uMinimapZoom * pParty_global->sPartyPosX) >> 16);
        v16 = uMinimapCentreY
            - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                             * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v10 + 2) + 2)) >> 16) << 16)
                          - uMinimapZoom * pParty_global->sPartyPosY) >> 16);
        v15 = abs(*(_WORD *)(v10 + 8) - pParty_global->dword_0006BC) / 8;
        if ( v15 > 100 )
          v15 = 100;
        CD3DRenderer_FillRect(pD3DRenderer, v73, v71, v100, v16, *((_WORD *)&unk_5771E4 - v15));
        v8 = dword_6BE644;
      }
LABEL_26:
      ++v93;
      v86 += 12;
    }
    while ( v93 < *(_DWORD *)dword_6BE670 );
  }
  for ( i = 0; i < dword_576D14; ++i )
  {
    v17 = dword_6BE670 + 12 * (unsigned __int16)word_576D80[i] + 4;
    CD3DRenderer_FillRect(pD3DRenderer,
      uMinimapCentreX
    + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v17)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosX) >> 16),
      uMinimapCentreY
    - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom * *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)v17 + 2)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosY) >> 16),
      uMinimapCentreX
    + ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                     * *(_WORD *)(dword_6BE63C
                                                                + 6
                                                                * *(_WORD *)(dword_6BE670
                                                                           + 12 * (unsigned __int16)word_576D80[i]
                                                                           + 6))) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosX) >> 16),
      uMinimapCentreY
    - ((signed int)(((unsigned int)((unsigned __int64)(uMinimapZoom
                                                     * *(_WORD *)(dword_6BE63C
                                                                + 6
                                                                * *(_WORD *)(dword_6BE670
                                                                           + 12 * (unsigned __int16)word_576D80[i]
                                                                           + 6)
                                                                + 2)) >> 16) << 16)
                  - uMinimapZoom * pParty_global->sPartyPosY) >> 16),
      0xFF0000FF);
  }
 }


  v37 = pParty_global->dword_0006C0 & pClass59_global->dword_00186C;
  v38 = 0;
  if ( (pParty_global->dword_0006C0 & pClass59_global->dword_00186C) < 128 )
    goto LABEL_66;
  if ( v37 <= 384 )
  {
    v38 = 1;
    goto LABEL_66;
  }
  if ( v37 >= 640 )
  {
    if ( v37 > 896 )
    {
      if ( v37 >= 1152 )
      {
        if ( v37 > 1408 )
        {
          if ( v37 >= 1664 )
          {
            if ( v37 > 1920 )
              goto LABEL_66;
            v61 = 7;
          }
          else
          {
            v61 = 6;
          }
        }
        else
        {
          v61 = 5;
        }
      }
      else
      {
        v61 = 4;
      }
    }
    else
    {
      v61 = 3;
    }
  }
  else
  {
    v61 = 2;
  }
  v38 = v61;

LABEL_66:
 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uMinimapCentreX - 3, uMinimapCentreY - 3, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_MapDirs[v38]]);
 if (v84)
 {
  for (i = 0; i < uNumElementsIn665230; ++i)
  {
   if (!array_665230[i].word_000000 || !array_665230[i].uObjectDescriptionID || v79 == 1)
     continue;

   v44 = uMinimapCentreX + uMinimapZoom * (array_665230[i].sItemPosX - pParty_global->sPartyPosX) / 65535;
   v45 = uMinimapCentreY - uMinimapZoom * (array_665230[i].sItemPosY - pParty_global->sPartyPosY) / 65535;
   if (v44 < pD3DRenderer->dword_00001C || v44 > pD3DRenderer->dword_000024 ||
       v45 < pD3DRenderer->dword_000020 || v45 > pD3DRenderer->dword_000028)
     continue;

   if (pObjectDescriptionList->pDescriptions[array_665230[i].uObjectDescriptionID].byte_000026 & 0x10)
     CD3DRenderer_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFF0000FF);
   else
     CD3DRenderer_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFF0000FF);
  }


  for (i = 0; i < uNumActors; ++i)
  {
   if (pActors[i].word_0000B0 == 11  || pActors[i].word_0000B0 == 19)
     continue;

   if (pActors[i].word_0000B0 == 5 || *((char *)&pActors[i] + 37) & 0x80 )
   {
    v45 = uMinimapCentreX + uMinimapZoom * (pActors[i].sActorPosX - pParty_global->sPartyPosX) / 65535;
    v44 = uMinimapCentreY - uMinimapZoom * (pActors[i].sActorPosY - pParty_global->sPartyPosY) / 65535;

    if (v45 >= pD3DRenderer->dword_00001C && v45 <= pD3DRenderer->dword_000024 &&
        v44 >= pD3DRenderer->dword_000020 && v44 <= pD3DRenderer->dword_000028)
    {
     v104 = 0xFF00FF00;
     if (*((char *)&pActors[i] + 47) & 1 )
       v104 = 0xFFFF0000;
     if (pActors[i].word_0000B0 == 5 )
       v104 = 0xFFFFFF00;

     CD3DRenderer_FillRect(pD3DRenderer, v45 - 1, v44 - 1, v45 + 1, v44 + 1, v104);
    }
   }
  }
 }


 for (i = 0; i < dword_69ADD0; ++i)
   if (array_6836D0[i].word_000002 & 8 )
   {
    v44 = uMinimapCentreX + uMinimapZoom * (array_6836D0[i].dword_000004 - pParty_global->sPartyPosX) / 65536;
    v45 = uMinimapCentreY - uMinimapZoom * (array_6836D0[i].dword_000008 - pParty_global->sPartyPosY) / 65536;
    if (v44 >= pD3DRenderer->dword_00001C && v44 <= pD3DRenderer->dword_000024 &&
        v45 >= pD3DRenderer->dword_000020 && v45 <= pD3DRenderer->dword_000028)
    {
         CD3DRenderer_FillRect(pD3DRenderer, v44 - 1, v45 - 1, v44 + 1, v45 + 1, 0xFFFFFFFF);
    }
   }

 CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 468, 0, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_MinimapMask]);

 v105 = (double)pParty_global->dword_0006C0 * 0.1171875;

 CD3DRenderer_Set2DClippingRect(pD3DRenderer, 541, 0, 567, 480);
 CD3DRenderer_DrawIndexedTexture(pD3DRenderer, v105 + 285, 136, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_MinimapCompass]);
 CD3DRenderer_Reset2DClippingRect(pD3DRenderer);
}

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
 CD3DRenderer_Set2DClippingRect(pD3DRenderer, uWindowX, uWindowY, uWindowX + uWindowWidth, uWindowY + uWindowHeight);


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
  CD3DRenderer_Set2DClippingRect(pD3DRenderer, uWindowX + 32, uWindowY, uWindowX + uWindowWidth - 32, uWindowY + uWindowHeight);

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
  CD3DRenderer_Set2DClippingRect(pD3DRenderer, uWindowX, uWindowY + 32, uWindowX + uWindowWidth, uWindowY + uWindowHeight - 32);

  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX, uWindowY + 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeLeft]);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, uWindowX + uWindowWidth - 10, uWindowY + 32, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_EdgeRight]);
 }

 CD3DRenderer_Reset2DClippingRect(pD3DRenderer);
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
   if (!GUIWindow_List[i].bSlotUsed)
     break;
   ++v8;
  }

  v9 = &GUIWindow_List[v8];
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
      dword_507BC0 = &GUIWindow_List[v8];
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
      sub_469903(pGame->pClass03, "MICON2");
      sub_44C175(pGlobalTXT_LocalizationStrings[39], 2);
      return v9;
    }
    if ( a5 == 30 )
      goto LABEL_62;
    if ( a5 == 31 )
    {
      sub_469903(pGame->pClass03, "MICON2");
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
  int v5; // eax@3
 struct Font *pFont;

 pFont = class17_fn1(pClass17_Icons_LOD, pFontFile, 0);

 if (pFontPalette)
 {
  v5 = class17_LoadTexture(pClass17_Icons_LOD, pFontPalette, 2);
  if (v5 == -1)
  {
   wsprintfA(ExistingFileName, "Unable to open %s", pFontPalette);
   erroneous_printf(ExistingFileName);
  }

  pFont->pFontPalette = pClass17_Icons_LOD->aLODHeaders[v5].pPalette;
 }

 pFont->dword_000008 = 1;
 return pFont;
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
      sub_4A6D87(pD3DRenderer, 0, 174, 164, v5 + 6.755399441055744e15, 16, pD3DRenderer->uTargetRMask);

      CD3DRenderer_EndScene(pD3DRenderer);
      CD3DRenderer_Present(pD3DRenderer);
      return;
    }
    CD3DRenderer_EndScene(pD3DRenderer);
    return;
  }

  CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, v1 + 24);
  CD3DRenderer_sub_4A0E97(pD3DRenderer, 0, 0, 639, 479);
  CD3DRenderer_Set2DClippingRect(pD3DRenderer, 172, 459,
    172 + 300 * ((float)(_this->uProgressCurrent) / (float)_this->uProgressMax),
    471);
  CD3DRenderer_DrawTransparentTexture(pD3DRenderer, 172, 459, &pClass17_Icons_LOD->aLODHeaders[_this->_addon_loadprog_id_in_Icons_LOD]);
  CD3DRenderer_Reset2DClippingRect(pD3DRenderer);
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
      v10 = dword_507AFC; //colored or white text flag
      v11 = AlignText_Center(v3, v2, pFontLucida);
      FontDrawText(pGUIWindow0, pFontLucida, v11 + 11, 357, v2, 0xFFFFFFFF, 0, v0);
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
void GameUI_DrawFrames()
{
 CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 0, pTexture_TopFrame);
 CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 8, pTexture_LeftFrame);
 CD3DRenderer_DrawRGBTexture(pD3DRenderer, 468, 0, pTexture_RightFrame);
 CD3DRenderer_DrawRGBTexture(pD3DRenderer, 0, 352, pTexture_BottomFrame);

 GameUI_DrawFoodAndGold();

 sub_41AD6E();
}

//----- (0041AEBB) --------------------------------------------------------
void __cdecl GameUI_DrawFoodAndGold()
{
  __int16 v0; // bx@2
  char *v1; // ebp@2
  int v2; // esi@2

  if ( dword_6A0D48 != 9 )
  {
    v0 = dword_507AFC; //colored or white text
    v1 = *(char **)&dword_507AF8; //final param in DrawText
    v2 = sub_44100D() != 0 ? 381 : 322;
    wsprintfA(ExistingFileName, "\r087%lu", pParty_global->uNumFood);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, ExistingFileName, 0xFFFFFFFF, 0, 0);
    wsprintfA(ExistingFileName, "\r028%lu", pParty_global->uNumGold);
    FontDrawText(pGUIWindow0, pFontSmallnum, 0, v2, ExistingFileName, 0xFFFFFFFF, 0, 0);
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
  int v1;
  signed int v3; // esi@7
 struct class18 *v4; // eax@10
  int v6; // eax@14
  int v7; // eax@17
  //int v8; // eax@21
  int v9; // eax@27
  bool v10; // eax@33
  bool v11; // edi@40
  bool v12; // edx@43
  bool v13; // ecx@46
  int v14; // esi@54
  int v15; // edi@55
  int v16; // eax@57
  int v19; // eax@62
  void *v22; // [sp+14h] [bp-4h]@1
 int i, j;
 struct PlayerFrame *pPlayerFaceIcon;

  v22 = this;
  if ( qword_A750D8 )
  {
    qword_A750D8 -= pClass24_global2->int_00001C;
    if ( qword_A750D8 <= 0 )
    {
      if ( sub_492C0B(pPlayers[word_A750E2 - 1]) )
        sub_4948B1(pPlayers[word_A750E2 - 1], word_A750E0, 0);
      qword_A750D8 = 0i64;
    }
  }

  v1 = 0;

  for (i = 0; i < 4; ++i)
  {
   v3 = &pParty_global->pPlayers[i].qword_000070;

   if (pParty_global->pPlayers[i].qword_000070 || pParty_global->pPlayers[i].qword_000080)
   {
    if (pParty_global->pPlayers[i].qword_000070)
      v4 = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_PlayerFaceEradicated];
    else if (pParty_global->pPlayers[i].qword_000080)
      v4 = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_PlayerFaceDead];

LABEL_27:
      v9 = off_4ED748[i];
      if (qword_ACD8F4)
        sub_4A6E7E(pD3DRenderer, v9, 387, v4);
      else
        CD3DRenderer_DrawTransparentTexture(pD3DRenderer, v9 + 1, 388, v4);
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
        sub_441A4E(i);
      continue;
    }


    v7 = 1;
    for (j = 0; j < pPlayerFrameTable->uNumFrames; ++j)
      if (pPlayerFrameTable->pFrames[j].word_000000 == pParty_global->pPlayers[i].word_001A9C)
      {
       v7 = j;
       break;
      }

    if (pParty_global->pPlayers[i].word_001A9C == 21)
      pPlayerFaceIcon = sub_494B5E(pPlayerFrameTable,
                      &pParty_global->pPlayers[i].dword_001AA8,
                      &pParty_global->pPlayers[i].dword_001AA4,
                      pClass24_global2->int_00001C);
    else
      pPlayerFaceIcon = CPlayerFrameTable_GetFrame(pPlayerFrameTable, v7, pParty_global->pPlayers[i].word_001A9E);

    if (pParty_global->pPlayers[i].word_001AA2 != pPlayerFaceIcon->word_000002 - 1 || v22)
    {
     pParty_global->pPlayers[i].word_001AA2 = pPlayerFaceIcon->word_000002 - 1;
     v1 = 0;
     v4 = &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_PlayerFaces[i][pPlayerFaceIcon->word_000002 - 1]];
     goto LABEL_27;
    }
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

//----- (0044CE08) --------------------------------------------------------
char __fastcall FontDrawText(struct GUIWindow *_this, struct Font *pFont, unsigned int uX, unsigned int uY, const char *pString, unsigned int uTextMainColor, signed int a8, unsigned int uTextShadowColor)
{
  int v9; // ebx@1
  int v10; // edi@1
  char *v11; // eax@2
  int v12; // edx@9
  //int v13; // edi@9
  //int v14; // esi@9
  int v15; // eax@25
  int v16; // ecx@25
  int v17; // eax@27
  int v18; // edi@32
  int v19; // esi@38
  unsigned __int8 v20; // sf@39
  unsigned __int8 v21; // of@39
  char v23; // [sp-18h] [bp-50h]@2
  int v24; // [sp-14h] [bp-4Ch]@2
  int v25; // [sp-10h] [bp-48h]@2
  int v26; // [sp-Ch] [bp-44h]@2
  char Dest[8]; // [sp+Ch] [bp-2Ch]@32
  char v30; // [sp+Fh] [bp-29h]@32
  char v31; // [sp+11h] [bp-27h]@34
  char *v32; // [sp+20h] [bp-18h]@25
  int v33; // [sp+24h] [bp-14h]@25
  int v34; // [sp+28h] [bp-10h]@1
  size_t v35; // [sp+2Ch] [bp-Ch]@4
  int v36; // [sp+30h] [bp-8h]@1
  char *v37; // [sp+34h] [bp-4h]@7
  int v38; // [sp+4Ch] [bp+14h]@11
 unsigned char c;
 unsigned int uOutX,
              uOutY;

  v34 = 0;
  v10 = _this;
  v9 = pFont;
  v36 = _this;
  if (!pString)
  {
    sub_40E2C8(&v23, "Invalid string passed!", 0);
    LOBYTE(v11) = (unsigned int)sub_466D09(&a8, *(int *)&v23, v24, v25, v26, __FILE__, __LINE__);
    return (char)v11;
  }
  v11 = strcmp(pString, "null");
  if (!v11)
    return v11;

    v35 = strlen(pString);
    v11 = 0;
    if ( !uX )
      uX = 12;
    if ( a8 )
    {
      v37 = (char *)pString;
    }
    else
    {
      v11 = FitTextInAWindow(pString, pFont, _this, uX, 0);
      v37 = v11;
    }
    uOutX = uX + _this->uFrameX;
    uOutY = uY + _this->uFrameY;
    v12 = 0;
    v11 = uOutY + pFont->uFontHeight;
    if ( !a8 || (signed int)v11 <= a8)
    {
      v38 = 0;
      if ( (signed int)v35 > 0 )
      {
        do
        {
          c = v37[v12];
          if (c >= pFont->uFirstChar && c <= pFont->uLastChar
            || c == 12
            || c == '\r' || c == '\t' || c == '\n')
          {
            switch ( c )
            {
              case 9u: // number (3 digit always) after \t denotes tab amount (in pixels);  example:  "\t004skips 4 whitespaces before this string"
                strncpy(Dest, &v37[v12 + 1], 3);
                v30 = 0;
                v38 += 3;
                v34 = atoi(Dest);
                v19 = atoi(Dest);
                c = v36;
                uOutX = uX + _this->uFrameX + v19;
                break;
              case 0xAu:
                c = pFont->uFontHeight;
                uY = uY + pFont->uFontHeight - 3;
                uOutY = uY + _this->uFrameY;
                uOutX = uX + v34 + _this->uFrameX;
                if ( a8 )
                  goto LABEL_36;
                break;
              case 0xCu:
                runtime_warning(color option inside a string?);
               /*
                strncpy(&Dest, &v37[v12 + 1], 5u);
                v31 = 0;
                c = (char *)atoi(&Dest);
                v38 += 5;
                *(_DWORD *)&a5 = c;*/
                break;
              case 0xDu:
                strncpy(&Dest, &v37[v12 + 1], 3u);
                v30 = 0;
                v38 += 3;
                v18 = atoi(&Dest);
                c = (char *)sub_44C51E(v9, &v37[v38]);
                uOutX = *(_DWORD *)(v36 + 16) - (_DWORD)c - v18;
                uOutY = uY + *(_DWORD *)(v36 + 4);
                if ( a8 )
                {
                 c = pFont->uFontHeight;
LABEL_36:
                  c = pFont->uFontHeight + uOutY - 3;
                  if ( (signed int)c > a8 )
                    return (char)c;
                  break;
                }
                break;
              default:
                if (c == 34 )
                {
                  if ( v37[v12 + 1] == 34 )
                  {
                    ++v12;
                    v38 = v12;
                  }
                }
                v32 = &v37[v12];
                v15 = (unsigned __int8)v37[v12];
                v16 = pFont->dword_000020[v15][1];
                v33 = pFont->dword_000020[v15][2];
                if ( v12 > 0 )
                  uOutX += pFont->dword_000020[v15][0];
                v17 = pFont->array_000C20[v15] + &pFont->unk_001020;

                CD3DRenderer_DrawText(pD3DRenderer, uOutX, uOutY, v17,
                    v16,
                    pFont->uFontHeight, pFont->pFontPalette,
                    uTextMainColor,
                    uTextShadowColor);
                uOutX += pFont->dword_000020[v15][1];
                if ( v38 < (signed int)v35)
                {
                  uOutX += pFont->dword_000020[v15][2];
                }
                break;
            }
          }
          v12 = v38 + 1;
          //v21 = __SETO__(v38 + 1, v35);
          //v20 = (signed int)(v38++ + 1 - v35) < 0;
        }
        while ( ++v38 < v35);
      }
    }

  return (char)v11;
}


//----- (0044158F) --------------------------------------------------------
void GameUI_DrawCharacterSelectionFrame()
{
 if (uMaybeSelectedCharacter)
   CD3DRenderer_DrawTransparentTexture(pD3DRenderer, off_4ED748[uMaybeSelectedCharacter - 1] - 9, 380, &pClass17_Icons_LOD->aLODHeaders[uTextureIdx_CharacterSelectionFrame]);
}