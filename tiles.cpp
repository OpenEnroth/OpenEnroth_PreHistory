#include "defs.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"
#include "_lod.h"
#include "tiles.h"




void CTileTable_ctor(struct CTileTable *_this)
{
 memset(_this, 0, sizeof(struct CTileTable));
}


//----- (00488000) --------------------------------------------------------
void CTileTable_Initialize(struct CTileTable *_this, unsigned char *pSrc)
{
 _this->uNumTiles = *(int *)(pSrc);
 //_this->pTiles = (TileDesc *)mem_mng.AllocatedNamedBuffer(_this->pTiles, _this->uNumTiles * sizeof(struct TileDesc), "Tile Descrip");
 _this->pTiles = NamedMemAlloc(TileDesc, _this->uNumTiles, "Tile Descrip");
 memcpy(_this->pTiles, pSrc + 4, _this->uNumTiles * sizeof(struct TileDesc));
}

//----- (00487ED6) --------------------------------------------------------
int sub_487ED6(struct CTileTable *_this, int a2, int a3)
{
  int v5; // edx@3
  int v6; // edx@11

 if (a2 > 8)
   return sub_487F84(_this, a2, 0);

 v5 = rand() % 50;
 if (a3 || v5 < 20)
   return sub_487F84(_this, a2, 0);
 else if (v5 < 30)
   return sub_487F84(_this, a2, 1);
 else if (v5 < 40)
   return sub_487F84(_this, a2, 2);
 else if (v5 < 48)
   return sub_487F84(_this, a2, 3);

 v6 = rand() % 8;
 return sub_487F84(_this, a2, 4 + v6);
}

//----- (00487E3B) --------------------------------------------------------
struct TileDesc *TileTable_GetTile(struct CTileTable *_this, unsigned int uTileID)
{
 if (uTileID < 0 || uTileID > _this->uNumTiles - 1)
   return _this->pTiles;
 else
   return &_this->pTiles[uTileID];
}

//----- (00487F84) --------------------------------------------------------
int sub_487F84(struct CTileTable *_this, int a2, int a3)
{
 int i;

 if (!_this->uNumTiles)
   return 0;

 i = 0;
 while (_this->pTiles[i].uTerrainType != a2 || _this->pTiles[i].uSection != a3 )
 {
  ++i;
  if (i >= _this->uNumTiles)
    return 0;
 }
 return i;
}

//----- (00487E58) --------------------------------------------------------
void CTileTable_LoadSomeTiles(struct CTileTable *_this, int a2)
{
 for (unsigned int i = 0; i < _this->uNumTiles; ++i)
 {
  if (_this->pTiles[i].uTerrainType == a2)
  {
   if (_this->pTiles[i].sTileName[0])
   {
#ifndef OLD_CODE
    wchar_t pFilename[256];
    wsprintfW(pFilename, L"%S", _this->pTiles[i].sTileName);
    _this->pTiles[i].uBitmapID = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New(pFilename);
#else
    _this->pTiles[i].uBitmapID = LODFile_Bitmaps_LOD.LODFile_LoadTexture((const char*)_this->pTiles[i].sTileName,0);
#endif
    if (_this->pTiles[i].uBitmapID != -1)
      LODFile_Bitmaps_LOD.aLODHeaders[_this->pTiles[i].uBitmapID].word_000026 = class35_sub_48A3BC_MessWithPalettes(&class35_obj, LODFile_Bitmaps_LOD.aLODHeaders[_this->pTiles[i].uBitmapID].word_000026);
   }
  }
 }
}


//----- (00488047) --------------------------------------------------------
signed int __thiscall sub_488047(int _this, const char *a2)
{
  FILE *v2; // eax@1
  int v3; // ebp@1
  int v4; // ebx@3
  int v5; // eax@9
  char *v6; // esi@14
  const char *v7; // ST14_4@14
  int v8; // eax@17
  int v9; // eax@20
  int v10; // eax@22
  int v11; // eax@24
  int v12; // eax@26
  int v13; // eax@28
  int v14; // eax@30
  int v15; // eax@32
  int v16; // eax@34
  int v17; // eax@36
  int v18; // eax@38
  int v19; // eax@40
  int v20; // eax@42
  int v21; // eax@44
  int v22; // eax@46
  int v23; // eax@48
  int v24; // eax@50
  int v25; // eax@52
  int v26; // eax@54
  int v27; // eax@56
  int v28; // eax@58
  int v29; // eax@60
  int v30; // eax@62
  int v31; // eax@64
  int v32; // eax@66
  const char *v33; // esi@67
  int v34; // eax@70
  int v35; // eax@73
  int v36; // eax@75
  int v37; // eax@77
  int v38; // eax@79
  int v39; // eax@81
  int v40; // eax@83
  int v41; // eax@85
  int v42; // eax@87
  int v43; // eax@89
  int v44; // eax@91
  int v45; // eax@93
  int v46; // eax@108
  int v47; // eax@110
  int v48; // eax@112
  int v49; // eax@114
  int v50; // eax@116
  int v51; // eax@118
  int v52; // eax@120
  int v53; // eax@122
  int v54; // eax@124
  int v55; // eax@126
  int v56; // eax@128
  int v57; // eax@130
  int v58; // eax@132
  int v59; // eax@134
  int v60; // eax@136
  int v61; // eax@138
  int v62; // eax@140
  int v63; // eax@142
  int v64; // eax@144
  int v65; // eax@146
  int v66; // eax@148
  int v67; // eax@150
  int v68; // eax@151
  signed int j; // edi@152
  const char *v70; // esi@153
  int v71; // eax@154
  int v72; // eax@156
  int v73; // eax@160
  int v74; // eax@162
  int v75; // eax@164
  int v76; // eax@166
  int v77; // eax@168
  int v78; // eax@170
  FILE *i; // [sp-10h] [bp-304h]@3
  FILE *v81; // [sp+4h] [bp-2F0h]@1
  int v82; // [sp+8h] [bp-2ECh]@4
  char *Source; // [sp+Ch] [bp-2E8h]@5
  char *Str; // [sp+10h] [bp-2E4h]@14
  const char *v85; // [sp+14h] [bp-2E0h]@14
  char *Str1; // [sp+18h] [bp-2DCh]@14
  const char *v87; // [sp+1Ch] [bp-2D8h]@67
  StringSplitter v88; // [sp+84h] [bp-270h]@4
  char Buf; // [sp+100h] [bp-1F4h]@4

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(a2, "r");
  v81 = v2;
  //if ( !v2 )
 //   sub_466BE5("TileTable::load - Unable to open file: %s.");
  v4 = 0;
  for ( i = v2; fgets((char*)&Buf, 490, i); i = v81 )
  {
    *strchr((char*)&Buf, '\n') = 0;
    memcpy(&v82, sub_4BE3BF((unsigned char*)&Buf, &v88), 0x7Cu);
    if ( v82 )
    {
      if ( *Source != 47 )
        ++v4;
    }
  }
  *(_DWORD *)v3 = v4;
 // v5 = sub_426755(&unk_702B28, *(_DWORD *)(v3 + 4), 26 * v4, "Tile Descrip");
  *(_DWORD *)(v3 + 4) = v5;
 // if ( !v5 )
 //   err_printf("TileTable::Load - Out of Memory!");
  memset((void *)v5, 0, 26 * *(_DWORD *)v3);
  *(_DWORD *)v3 = 0;
  fseek(v81, 0, 0);
  while ( fgets(&Buf, 490, v81) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v82, sub_4BE3BF((unsigned char*)&Buf, &v88), 0x7Cu);
    if ( !v82 || *Source == 47 )
      continue;
    strcpy((char *)(*(_DWORD *)(v3 + 4) + 26 * *(_DWORD *)v3), Source);
    v7 = v85;
    *(_WORD *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 16) = atoi(Str);
    v6 = Str1;
    *(_WORD *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 18) = atoi(v7);
    *(_WORD *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20) = 0;
    if ( _strcmpi(v6, "TTtype_NULL") )
    {
      if ( _strcmpi(v6, "TTtype_Start") )
      {
        if ( _strcmpi(v6, "TTtype_Grass") )
        {
          if ( _strcmpi(v6, "TTtype_Cracked") )
          {
            if ( _strcmpi(v6, "TTtype_Snow") )
            {
              if ( _strcmpi(v6, "TTtype_Sand") )
              {
                if ( _strcmpi(v6, "TTtype_Volcano") )
                {
                  if ( _strcmpi(v6, "TTtype_Dirt") )
                  {
                    if ( _strcmpi(v6, "TTtype_Water") )
                    {
                      if ( _strcmpi(v6, "TTtype_Tropical") )
                      {
                        if ( _strcmpi(v6, "TTtype_Swamp") )
                        {
                          if ( _strcmpi(v6, "TTtype_City") )
                          {
                            if ( _strcmpi(v6, "TTtype_RoadGrassCobble") )
                            {
                              if ( _strcmpi(v6, "TTtype_RoadGrassDirt") )
                              {
                                if ( _strcmpi(v6, "TTtype_RoadCrackedCobble") )
                                {
                                  if ( _strcmpi(v6, "TTtype_RoadCrackedDirt") )
                                  {
                                    if ( _strcmpi(v6, "TTtype_RoadSandCobble") )
                                    {
                                      if ( _strcmpi(v6, "TTtype_RoadSandDirt") )
                                      {
                                        if ( _strcmpi(v6, "TTtype_RoadVolcanoCobble") )
                                        {
                                          if ( _strcmpi(v6, "TTtype_RoadVolcanoDirt") )
                                          {
                                            if ( _strcmpi(v6, "TTtype_RoadSwampCobble") )
                                            {
                                              if ( _strcmpi(v6, "TTtype_RoadSwampDirt") )
                                              {
                                                if ( _strcmpi(v6, "TTtype_RoadTropicalCobble") )
                                                {
                                                  if ( _strcmpi(v6, "TTtype_RoadTropicalDirt") )
                                                  {
                                                    if ( _strcmpi(v6, "TTtype_RoadSnowCobble") )
                                                    {
                                                      if ( _strcmpi(v6, "TTtype_RoadSnowDirt") )
                                                      {
                                                        if ( !_strcmpi(v6, "TTtype_RoadCityStone") )
                                                        {
                                                          v32 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                          *(_BYTE *)v32 |= 0x1Cu;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v31 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                        *(_BYTE *)v31 |= 0xDu;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v30 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                      *(_BYTE *)v30 |= 0xCu;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v29 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                    *(_BYTE *)v29 |= 0x1Bu;
                                                  }
                                                }
                                                else
                                                {
                                                  v28 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                  *(_BYTE *)v28 |= 0x1Au;
                                                }
                                              }
                                              else
                                              {
                                                v27 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                                *(_BYTE *)v27 |= 0x19u;
                                              }
                                            }
                                            else
                                            {
                                              v26 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                              *(_BYTE *)v26 |= 0x18u;
                                            }
                                          }
                                          else
                                          {
                                            v25 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                            *(_BYTE *)v25 |= 0x11u;
                                          }
                                        }
                                        else
                                        {
                                          v24 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                          *(_BYTE *)v24 |= 0x10u;
                                        }
                                      }
                                      else
                                      {
                                        v23 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                        *(_BYTE *)v23 |= 0xFu;
                                      }
                                    }
                                    else
                                    {
                                      v22 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                      *(_BYTE *)v22 |= 0xEu;
                                    }
                                  }
                                  else
                                  {
                                    v21 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                    *(_BYTE *)v21 |= 0x17u;
                                  }
                                }
                                else
                                {
                                  v20 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                  *(_BYTE *)v20 |= 0x16u;
                                }
                              }
                              else
                              {
                                v19 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                                *(_BYTE *)v19 |= 0xBu;
                              }
                            }
                            else
                            {
                              v18 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                              *(_BYTE *)v18 |= 0xAu;
                            }
                          }
                          else
                          {
                            v17 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                            *(_BYTE *)v17 |= 9u;
                          }
                        }
                        else
                        {
                          v16 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                          *(_BYTE *)v16 |= 7u;
                        }
                      }
                      else
                      {
                        v15 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                        *(_BYTE *)v15 |= 8u;
                      }
                    }
                    else
                    {
                      v14 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                      *(_BYTE *)v14 |= 5u;
                    }
                  }
                  else
                  {
                    v13 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                    *(_BYTE *)v13 |= 4u;
                  }
                }
                else
                {
                  v12 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                  *(_BYTE *)v12 |= 3u;
                }
              }
              else
              {
                v11 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
                *(_BYTE *)v11 |= 2u;
              }
            }
            else
            {
              v10 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
              *(_BYTE *)v10 |= 1u;
            }
          }
          else
          {
            v9 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20;
            *(_BYTE *)v9 |= 6u;
          }
        }
      }
      else
      {
        v8 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
        *(_BYTE *)v8 |= 0xFEu;
      }
    }
    else
    {
      *(_BYTE *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 20) = -1;
    }
    v33 = v87;
    *(_WORD *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22) = 0;
    *(_WORD *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24) = 0;
    if ( _strcmpi(v33, "TTsect_NULL") )
    {
      if ( _strcmpi(v33, "TTsect_Start") )
      {
        if ( _strcmpi(v33, "TTsect_Base1") )
        {
          if ( _strcmpi(v33, "TTsect_Base2") )
          {
            if ( _strcmpi(v33, "TTsect_Base3") )
            {
              if ( _strcmpi(v33, "TTsect_Base4") )
              {
                if ( _strcmpi(v33, "TTsect_Special1") )
                {
                  if ( _strcmpi(v33, "TTsect_Special2") )
                  {
                    if ( _strcmpi(v33, "TTsect_Special3") )
                    {
                      if ( _strcmpi(v33, "TTsect_Special4") )
                      {
                        if ( _strcmpi(v33, "TTsect_Special5") )
                        {
                          if ( _strcmpi(v33, "TTsect_Special6") )
                          {
                            if ( _strcmpi(v33, "TTsect_Special7") )
                            {
                              if ( _strcmpi(v33, "TTsect_Special8") )
                              {
                                if ( !_strcmpi(v33, "TTsect_NE1") )
                                  goto LABEL_130;
                                if ( !_strcmpi(v33, "TTsect_NW1") )
                                  goto LABEL_134;
                                if ( !_strcmpi(v33, "TTsect_SE1") )
                                  goto LABEL_130;
                                if ( !_strcmpi(v33, "TTsect_SW1") )
                                {
LABEL_134:
                                  v59 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v59 |= 0xEu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_E1") )
                                  goto LABEL_138;
                                if ( !_strcmpi(v33, "TTsect_W1") )
                                {
LABEL_140:
                                  v62 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v62 |= 0x11u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_N1") )
                                  goto LABEL_142;
                                if ( !_strcmpi(v33, "TTsect_S1") )
                                {
LABEL_144:
                                  v64 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v64 |= 0x13u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_XNE1") )
                                  goto LABEL_146;
                                if ( !_strcmpi(v33, "TTsect_XNW1") )
                                  goto LABEL_150;
                                if ( !_strcmpi(v33, "TTsect_XSE1") )
                                  goto LABEL_146;
                                if ( !_strcmpi(v33, "TTsect_XSW1") )
                                {
LABEL_150:
                                  v67 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v67 |= 0x16u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_CROS") )
                                  goto LABEL_151;
                                if ( !_strcmpi(v33, "TTsect_NS") )
                                {
                                  v46 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v46 |= 1u;
LABEL_151:
                                  v68 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                                  *(_WORD *)v68 |= 0x200u;
                                  goto LABEL_152;
                                }
                                if ( !_strcmpi(v33, "TTsect_EW") )
                                {
                                  v47 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v47 |= 2u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_N_E") )
                                {
                                  v48 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v48 |= 3u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_N_W") )
                                {
                                  v49 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v49 |= 4u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_S_E") )
                                {
                                  v50 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v50 |= 5u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_S_W") )
                                {
                                  v51 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v51 |= 6u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_NS_E") )
                                {
                                  v52 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v52 |= 7u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_NS_W") )
                                {
                                  v53 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v53 |= 8u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_EW_N") )
                                {
                                  v54 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v54 |= 9u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_EW_S") )
                                {
                                  v55 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v55 |= 0xAu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_NCAP") )
                                {
                                  v56 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v56 |= 0xBu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_ECAP") )
                                {
LABEL_130:
                                  v57 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v57 |= 0xCu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_SCAP") )
                                {
                                  v58 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v58 |= 0xDu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_WCAP") )
                                  goto LABEL_134;
                                if ( !_strcmpi(v33, "TTsect_DN") )
                                {
                                  v60 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v60 |= 0xFu;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_DS") )
                                {
LABEL_138:
                                  v61 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v61 |= 0x10u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_DW") )
                                  goto LABEL_140;
                                if ( !_strcmpi(v33, "TTsect_DE") )
                                {
LABEL_142:
                                  v63 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v63 |= 0x12u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_DSW") )
                                  goto LABEL_144;
                                if ( !_strcmpi(v33, "TTsect_DNE") )
                                {
LABEL_146:
                                  v65 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v65 |= 0x14u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_DSE") )
                                {
                                  v66 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                  *(_BYTE *)v66 |= 0x15u;
                                  goto LABEL_151;
                                }
                                if ( !_strcmpi(v33, "TTsect_DNW") )
                                  goto LABEL_150;
                              }
                              else
                              {
                                v45 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                                *(_BYTE *)v45 |= 0xBu;
                              }
                            }
                            else
                            {
                              v44 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                              *(_BYTE *)v44 |= 0xAu;
                            }
                          }
                          else
                          {
                            v43 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                            *(_BYTE *)v43 |= 9u;
                          }
                        }
                        else
                        {
                          v42 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                          *(_BYTE *)v42 |= 8u;
                        }
                      }
                      else
                      {
                        v41 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                        *(_BYTE *)v41 |= 7u;
                      }
                    }
                    else
                    {
                      v40 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                      *(_BYTE *)v40 |= 6u;
                    }
                  }
                  else
                  {
                    v39 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                    *(_BYTE *)v39 |= 5u;
                  }
                }
                else
                {
                  v38 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                  *(_BYTE *)v38 |= 4u;
                }
              }
              else
              {
                v37 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
                *(_BYTE *)v37 |= 3u;
              }
            }
            else
            {
              v36 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
              *(_BYTE *)v36 |= 2u;
            }
          }
          else
          {
            v35 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
            *(_BYTE *)v35 |= 1u;
          }
        }
      }
      else
      {
        v34 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22;
        *(_BYTE *)v34 |= 0xFEu;
      }
    }
    else
    {
      *(_BYTE *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 22) = -1;
    }
LABEL_152:
    for ( j = 5; j < v82; ++j )
    {
      v70 = (&Source)[4 * j];
      if ( _strcmpi((&Source)[4 * j], "TTattr_Burn") )
      {
        if ( _strcmpi(v70, "TTattr_Water") )
        {
          if ( _strcmpi(v70, "TTattr_Water2") )
          {
            if ( _strcmpi(v70, "TTattr_Block") )
            {
              if ( _strcmpi(v70, "TTattr_Repulse") )
              {
                if ( _strcmpi(v70, "TTattr_Flat") )
                {
                  if ( _strcmpi(v70, "TTattr_Wave") )
                  {
                    if ( _strcmpi(v70, "TTattr_NoDraw") )
                    {
                      if ( !_strcmpi(v70, "TTattr_Transition") )
                      {
                        v78 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                        *(_WORD *)v78 |= 0x200u;
                      }
                    }
                    else
                    {
                      v77 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                      *(_BYTE *)v77 |= 0x40u;
                    }
                  }
                  else
                  {
                    v76 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                    *(_BYTE *)v76 |= 0x20u;
                  }
                }
                else
                {
                  v75 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                  *(_BYTE *)v75 |= 0x10u;
                }
              }
              else
              {
                v74 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
                *(_BYTE *)v74 |= 8u;
              }
            }
            else
            {
              v73 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
              *(_BYTE *)v73 |= 4u;
            }
          }
          else
          {
            *(_BYTE *)(26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 25) |= 1u;
          }
        }
        else
        {
          v72 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
          *(_BYTE *)v72 |= 2u;
        }
      }
      else
      {
        v71 = 26 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24;
        *(_BYTE *)v71 |= 1u;
      }
    }
    ++*(_DWORD *)v3;
  }
  fclose(v81);
  return 1;
}
