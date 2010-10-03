#include "FrameTables.h"
#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"
#include "_audio.h"
#include "data.h"

//----- (0044E1EC) --------------------------------------------------------
int CTextureFrameTable_InitializeFromTXT(struct CTextureFrameTable *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  int v5; // ST0C_4@10
  int v6; // eax@10
  char *i; // eax@12
  FILE *v8; // ST0C_4@12
  signed int v9; // esi@15
  int v10; // eax@17
  int v11; // edx@22
  int v12; // ecx@23
  int v13; // eax@24
  int j; // eax@27
  int v15; // edx@28
  int v16; // esi@28
  int k; // ecx@29
  char Buf; // [sp+Ch] [bp-2F8h]@3
  char v20; // [sp+200h] [bp-104h]@4
  int v21; // [sp+27Ch] [bp-88h]@4
  char *Str1; // [sp+280h] [bp-84h]@5
  char *Str; // [sp+284h] [bp-80h]@15
  int v24; // [sp+2F8h] [bp-Ch]@3
  int v25; // [sp+2FCh] [bp-8h]@3
  FILE *File; // [sp+300h] [bp-4h]@1
  int v27; // [sp+30Ch] [bp+8h]@28

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(pSourceFile, L"r");
  File = v2;
  if ( !v2 )
    erroneous_printf("CTextureFrameTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v24 = 0;
  v25 = 1;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v21, sub_4BE3BF(&Buf, &v20), 0x7Cu);
      if ( v21 )
      {
        if ( *Str1 != 47 )
        {
          if ( v21 < 2 )
            erroneous_printf("CTextureFrameTable::load, too few arguments, %s line %i.", pSourceFile, v25);
          ++v24;
        }
      }
      ++v25;
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v24;
  }
  v5 = *(_DWORD *)(v3 + 4);
  *(_DWORD *)v3 = v4;
  v6 = class23_AllocatedNamedBuffer(class23_instance, v5, 20 * v4, "Txt Frames");
  *(_DWORD *)(v3 + 4) = v6;
  if ( !v6 )
    erroneous_printf("CTextureFrameTable::load - Out of Memory!");
  v8 = File;
  *(_DWORD *)v3 = 0;
  fseek(v8, 0, 0);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v21, sub_4BE3BF(&Buf, &v20), 0x7Cu);
    if ( v21 )
    {
      if ( *Str1 != 47 )
      {
        strcpy((char *)(*(_DWORD *)(v3 + 4) + 20 * *(_DWORD *)v3), Str1);
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 20 * *(_DWORD *)v3 + 14) = atoi(Str);
        v9 = 2;
        for ( *(_WORD *)(*(_DWORD *)(v3 + 4) + 20 * *(_DWORD *)v3 + 18) = 0; v9 < v21; ++v9 )
        {
          if ( !_strcmpi((&Str1)[4 * v9], "New") )
          {
            v10 = *(_DWORD *)(v3 + 4) + 20 * *(_DWORD *)v3 + 18;
            *(_BYTE *)v10 |= 2;
          }
        }
        ++*(_DWORD *)v3;
      }
    }
  }
  fclose(File);
  v11 = 0;
  if ( *(_DWORD *)v3 - 1 > 0 )
  {
    v12 = 0;
    do
    {
      v13 = v12 + *(_DWORD *)(v3 + 4);
      if ( !(*(_BYTE *)(v13 + 38) & 2) )
        *(_BYTE *)(v13 + 18) |= 1u;
      ++v11;
      v12 += 20;
    }
    while ( v11 < *(_DWORD *)v3 - 1 );
  }
  for ( j = 0; j < *(_DWORD *)v3; *(_WORD *)(v27 + 16) = v16 )
  {
    v15 = *(_DWORD *)(v3 + 4);
    v27 = v15 + 20 * j;
    v16 = *(_WORD *)(v27 + 14);
    if ( *(_BYTE *)(v27 + 18) & 1 )
    {
      ++j;
      for ( k = v15 + 20 * j; *(_BYTE *)(k + 18) & 1; k += 20 )
      {
        v16 += *(_WORD *)(k + 14);
        ++j;
      }
      v16 += *(_WORD *)(v15 + 20 * j + 14);
    }
    ++j;
  }
  return 1;
}








//----- (0049500A) --------------------------------------------------------
int CIconFrameTable_SaveToBIN(struct CIconFrameTable *_this)
{
 FILE *f;

 f = fopen("data\\dift.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dift.bin!");
 locked_fwrite(&_this->uNumIcons, 4, 1, f);
 locked_fwrite(_this->pIcons, sizeof(struct IconFrame), _this->uNumIcons, f);
 return fclose(f);
}

//----- (0049509D) --------------------------------------------------------
int CIconFrameTable_InitializeFromTXT(struct CIconFrameTable *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  int v5; // eax@10
  signed int result; // eax@11
  char *i; // eax@12
  FILE *v8; // ST0C_4@12
  char *v9; // ST00_4@15
  int v10; // eax@16
  int v11; // edx@20
  int v12; // ecx@21
  int v13; // eax@22
  int j; // edx@25
  int v15; // ecx@26
  int v16; // esi@26
  int k; // eax@27
  char Buf; // [sp+Ch] [bp-2F8h]@3
  char v19; // [sp+200h] [bp-104h]@4
  int v20; // [sp+27Ch] [bp-88h]@4
  char *Source; // [sp+280h] [bp-84h]@5
  const char *v22; // [sp+284h] [bp-80h]@15
  char *Str1; // [sp+288h] [bp-7Ch]@15
  char *Str; // [sp+28Ch] [bp-78h]@17
  int v25; // [sp+2F8h] [bp-Ch]@3
  int v26; // [sp+2FCh] [bp-8h]@3
  FILE *File; // [sp+300h] [bp-4h]@1
  int v28; // [sp+30Ch] [bp+8h]@26

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(pSourceFile, L"r");
  File = v2;
  if ( !v2 )
    erroneous_printf("IconFrameTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v25 = 0;
  v26 = 1;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v20, sub_4BE485(&Buf, &v19), 0x7Cu);
      if ( v20 )
      {
        if ( *Source != 47 )
        {
          if ( v20 < 3 )
            erroneous_printf("IconFrameTable::loadText, too few arguments, %s line %i.", pSourceFile, v26);
          ++v25;
        }
      }
      ++v26;
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v25;
  }
  *(_DWORD *)v3 = v4;
  v5 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v3 + 4), 32 * v4, "I Frames");
  *(_DWORD *)(v3 + 4) = v5;
  if ( v5 )
  {
    v8 = File;
    *(_DWORD *)v3 = 0;
    fseek(v8, 0, 0);
    for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v20, sub_4BE485(&Buf, &v19), 0x7Cu);
      if ( v20 )
      {
        if ( *Source != 47 )
        {
          strcpy((char *)(*(_DWORD *)(v3 + 4) + 32 * *(_DWORD *)v3), Source);
          strcpy((char *)(32 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 12), v22);
          v9 = Str1;
          *(_WORD *)(32 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 28) = 0;
          if ( !_strcmpi(v9, "new") )
          {
            v10 = 32 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 28;
            *(_BYTE *)v10 |= 4u;
          }
          *(_WORD *)(32 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 24) = atoi(Str);
          *(_WORD *)(32 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 26) = 0;
          *(_WORD *)(32 * *(_DWORD *)v3++ + *(_DWORD *)(v3 + 4) + 30) = 0;
        }
      }
    }
    fclose(File);
    v11 = 0;
    if ( *(_DWORD *)v3 - 1 > 0 )
    {
      v12 = 0;
      do
      {
        v13 = v12 + *(_DWORD *)(v3 + 4);
        if ( !(*(_BYTE *)(v13 + 60) & 4) )
          *(_BYTE *)(v13 + 28) |= 1u;
        ++v11;
        v12 += 32;
      }
      while ( v11 < *(_DWORD *)v3 - 1 );
    }
    for ( j = 0; j < *(_DWORD *)v3; *(_WORD *)(v28 + 26) = v16 )
    {
      v15 = *(_DWORD *)(v3 + 4);
      v28 = v15 + 32 * j;
      v16 = *(_WORD *)(v28 + 24);
      if ( *(_BYTE *)(v28 + 28) & 1 )
      {
        ++j;
        for ( k = v15 + 32 * j; *(_BYTE *)(k + 28) & 1; k += 32 )
        {
          v16 += *(_WORD *)(k + 24);
          ++j;
        }
        v16 += *(_WORD *)(32 * j + v15 + 24);
      }
      ++j;
    }
    result = 1;
  }
  else
  {
    fclose(File);
    result = 0;
  }
  return result;
}





//----- (MM7.exe::0044D96D) --------------------------------------------------------
int CSpriteFrameTable_SaveToBIN(struct CSpriteFrameTable *_this)
{
 FILE *f;

 f = fopen("data\\dsft.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dsft.bin!");

 locked_fwrite(&_this->uNumSpriteFrames, 4, 1, f);
 locked_fwrite((char *)_this + 4, 4, 1, f);
 locked_fwrite(*((const void **)_this + 3), 0x3C, *(_DWORD *)_this, f);
 locked_fwrite(*((const void **)_this + 5), 2, *((_DWORD *)_this + 1), f);
 return fclose(f);
}

//----- (MM7.exe::0044DA92) --------------------------------------------------------
int CSpriteFrameTable_LoadFromTXT(struct CSpriteFrameTable *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  signed int result; // eax@10
  char *i; // eax@11
  FILE *v7; // ST18_4@11
  int v8; // eax@14
  char *v9; // ST20_4@14
  char *v10; // ST0C_4@14
  double v11; // st7@14
  const char *v12; // ST04_4@14
  const char *v13; // ST00_4@14
  int v14; // eax@17
  int v15; // eax@23
  int v16; // eax@24
  int v17; // eax@25
  int v18; // eax@28
  int v19; // eax@29
  signed int j; // edi@30
  const char *v21; // esi@31
  int v22; // eax@32
  int v23; // edx@53
  int v24; // ecx@54
  int v25; // eax@55
  int k; // edx@58
  int v27; // ecx@59
  int v28; // esi@59
  int l; // eax@60
  signed int v30; // eax@65
  int v31; // edi@66
  int v32; // esi@66
  int v33; // eax@69
  int v34; // ecx@69
  int v35; // edx@69
  int v36; // eax@69
  int v37; // ecx@69
  char Buf; // [sp+Ch] [bp-2F0h]@3
  char v39; // [sp+200h] [bp-FCh]@4
  int v40; // [sp+27Ch] [bp-80h]@4
  char *Source; // [sp+280h] [bp-7Ch]@5
  const char *v42; // [sp+284h] [bp-78h]@14
  char *Str1; // [sp+288h] [bp-74h]@16
  char *Str; // [sp+28Ch] [bp-70h]@14
  char *String; // [sp+290h] [bp-6Ch]@14
  const char *v46; // [sp+294h] [bp-68h]@14
  const char *v47; // [sp+298h] [bp-64h]@14
  const char *v48; // [sp+29Ch] [bp-60h]@24
  const char *v49; // [sp+2A8h] [bp-54h]@18
  const char *v50; // [sp+2ACh] [bp-50h]@20
  const char *v51; // [sp+2B0h] [bp-4Ch]@22
  FILE *File; // [sp+2F8h] [bp-4h]@1
  int v53; // [sp+304h] [bp+8h]@3
  int v54; // [sp+304h] [bp+8h]@59
  FILE *v55; // [sp+304h] [bp+8h]@67

  v3 = _this;
  CSpriteFrameTable_sub_44D4D8(_this);
  v2 = fopen(pSourceFile, L"r");
  File = v2;
  if ( !v2 )
    erroneous_printf("CSpriteFrameTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v53 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v40, sub_4BE485(&Buf, &v39), 0x7Cu);
      if ( v40 )
      {
        if ( *Source != 47 )
          ++v53;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v53;
  }
  *(_DWORD *)v3 = v4;
  *(_DWORD *)(v3 + 12) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 12), 60 * v4, "S Frames");
  *(_DWORD *)(v3 + 20) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 20), 2 * *(_DWORD *)v3, "E Frames");
  *(_DWORD *)(v3 + 16) = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 16), 4 * *(_DWORD *)v3, "P Frames");
  if ( *(_DWORD *)(v3 + 12) )
  {
    v7 = File;
    *(_DWORD *)v3 = 0;
    fseek(v7, 0, 0);
    for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v40, sub_4BE485(&Buf, &v39), 0x7Cu);
      if ( v40 )
      {
        if ( *Source != 47 )
        {
          v9 = Source;
          *(_DWORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44) = 0;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 52) = 0;
          strcpy((char *)(*(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3), v9);
          strcpy((char *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 12), v42);
          v10 = String;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 50) = atoi(Str);
          v11 = atof(v10) * 65536.0;
          v12 = v46;
          *(_DWORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 40) = abs((signed __int64)v11);
          v13 = v47;
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 48) = atoi(v12);
          *(_WORD *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 54) = atoi(v13);
          v8 = *(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3;
          if ( *(_WORD *)(v8 + 48) )
            *(_DWORD *)(v8 + 44) |= 2u;
          if ( !_strcmpi(Str1, "new") )
          {
            v14 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v14 |= 4u;
            *(_DWORD *)(*(_DWORD *)(v3 + 16) + 4 * *(_DWORD *)(v3 + 4)) = *(_DWORD *)(v3 + 12) + 60 * *(_DWORD *)v3;
            compile_error;//*(_WORD *)(*(_DWORD *)(v3 + 20) + 2 * *(_DWORD *)(v3 + 4)++) = *(_WORD *)v3;
          }
          if ( !_strcmpi(v49, L"1") )
            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 46) |= 4u;
          if ( !_strcmpi(v50, L"1") )
            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 46) |= 2u;
          if ( !_strcmpi(v51, L"1") )
          {
            v15 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v15 |= 0x20u;
          }
          v16 = atoi(v48) - 1;
          if ( v16 )
          {
            v17 = v16 - 2;
            if ( v17 )
            {
              if ( v17 == 2 )
                *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0xE0u;
            }
            else
            {
              v18 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
              *(_DWORD *)v18 |= 0x1E000u;
            }
          }
          else
          {
            v19 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
            *(_DWORD *)v19 |= 0x10u;
          }
          for ( j = 13; j < v40; ++j )
          {
            v21 = (&Source)[4 * j];
            if ( _strcmpi((&Source)[4 * j], "Luminous") )
            {
              if ( _strcmpi(v21, "Mirror0") )
              {
                if ( _strcmpi(v21, "Mirror1") )
                {
                  if ( _strcmpi(v21, "Mirror2") )
                  {
                    if ( _strcmpi(v21, "Mirror3") )
                    {
                      if ( _strcmpi(v21, "Mirror4") )
                      {
                        if ( _strcmpi(v21, "Mirror5") )
                        {
                          if ( _strcmpi(v21, "Mirror6") )
                          {
                            if ( !_strcmpi(v21, "Mirror7") )
                              *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x80u;
                          }
                          else
                          {
                            *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x40u;
                          }
                        }
                        else
                        {
                          *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x20u;
                        }
                      }
                      else
                      {
                        *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 0x10u;
                      }
                    }
                    else
                    {
                      *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 8u;
                    }
                  }
                  else
                  {
                    *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 4u;
                  }
                }
                else
                {
                  *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 2u;
                }
              }
              else
              {
                *(_BYTE *)(60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 45) |= 1u;
              }
            }
            else
            {
              v22 = 60 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 12) + 44;
              *(_DWORD *)v22 |= 2u;
            }
          }
          ++*(_DWORD *)v3;
        }
      }
    }
    fclose(File);
    v23 = 0;
    if ( *(_DWORD *)v3 - 1 > 0 )
    {
      v24 = 0;
      do
      {
        v25 = v24 + *(_DWORD *)(v3 + 12);
        if ( !(*(_BYTE *)(v25 + 104) & 4) )
          *(_DWORD *)(v25 + 44) |= 1u;
        ++v23;
        v24 += 60;
      }
      while ( v23 < *(_DWORD *)v3 - 1 );
    }
    for ( k = 0; k < *(_DWORD *)v3; *(_WORD *)(v54 + 56) = v28 )
    {
      v27 = *(_DWORD *)(v3 + 12);
      v54 = v27 + 60 * k;
      v28 = *(_WORD *)(v54 + 54);
      if ( *(_BYTE *)(v54 + 44) & 1 )
      {
        ++k;
        for ( l = v27 + 60 * k; *(_BYTE *)(l + 44) & 1; l += 60 )
        {
          v28 += *(_WORD *)(l + 54);
          ++k;
        }
        v28 += *(_WORD *)(60 * k + v27 + 54);
      }
      ++k;
    }
    v30 = *(_DWORD *)(v3 + 4);
    if ( v30 > 0 )
    {
      v31 = 0;
      v32 = 0;
      File = (FILE *)1;
      do
      {
        v55 = File;
        if ( (signed int)File < v30 )
        {
          do
          {
            if ( _strcmpi(
                   *(const char **)(*(_DWORD *)(v3 + 16) + 4 * (_DWORD)v55),
                   *(const char **)(*(_DWORD *)(v3 + 16) + v32)) < 0 )
            {
              v33 = *(_DWORD *)(v3 + 16);
              v34 = v33 + 4 * (_DWORD)v55;
              v35 = *(_DWORD *)v34;
              *(_DWORD *)v34 = *(_DWORD *)(v33 + v32);
              *(_DWORD *)(v32 + *(_DWORD *)(v3 + 16)) = v35;
              v36 = *(_DWORD *)(v3 + 20);
              v37 = v36 + 2 * (_DWORD)v55;
              LOWORD(v35) = *(_WORD *)v37;
              *(_WORD *)v37 = *(_WORD *)(v36 + v31);
              *(_WORD *)(v31 + *(_DWORD *)(v3 + 20)) = v35;
            }
            v55 = (FILE *)((char *)v55 + 1);
          }
          while ( (signed int)v55 < *(_DWORD *)(v3 + 4) );
        }
        File = (FILE *)((char *)File + 1);
        v30 = *(_DWORD *)(v3 + 4);
        v32 += 4;
        v31 += 2;
      }
      while ( (signed int)((char *)File - 1) < v30 );
    }
    result = 1;
  }
  else
  {
    sub_4BE386("CSpriteFrameTable::load - Out of Memory!");
    fclose(File);
    result = 0;
  }
  return result;
}






//----- (00488047) --------------------------------------------------------
int CTileTable_InitializeFromTXT(struct CTileTable *_this, const char *pSourceFile)
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
  char v88; // [sp+84h] [bp-270h]@4
  char Buf; // [sp+100h] [bp-1F4h]@4

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(pSourceFile, "r");
  v81 = v2;
  if ( !v2 )
    erroneous_printf("TileTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  for ( i = v2; fgets(&Buf, 490, i); i = v81 )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v82, sub_4BE3BF(&Buf, &v88), 0x7Cu);
    if ( v82 )
    {
      if ( *Source != 47 )
        ++v4;
    }
  }
  *(_DWORD *)v3 = v4;
  v5 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v3 + 4), 26 * v4, "Tile Descrip");
  *(_DWORD *)(v3 + 4) = v5;
  if ( !v5 )
    erroneous_printf("TileTable::Load - Out of Memory!");
  memset((void *)v5, 0, 26 * *(_DWORD *)v3);
  *(_DWORD *)v3 = 0;
  fseek(v81, 0, 0);
  while ( fgets(&Buf, 490, v81) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v82, sub_4BE3BF(&Buf, &v88), 0x7Cu);
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
                *(_BYTE *)v11 |= 2;
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
                                  *(_BYTE *)v47 |= 2;
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
              *(_BYTE *)v36 |= 2;
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
          *(_BYTE *)v72 |= 2;
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

//----- (00487FB4) --------------------------------------------------------
int CTileTable_SaveToBIN(struct CTileTable *_this)
{
 FILE *f;

 f = fopen("data\\dtile.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dtile.bin!");

 locked_fwrite(&_this->uNumTiles, 4, 1, f);
 locked_fwrite(_this->pTiles, sizeof(struct TileDesc), _this->uNumTiles, f);
 return fclose(f);
}










//----- (00494BC3) --------------------------------------------------------
int CPlayerFrameTable_SaveToBIN(struct CPlayerFrameTable *_this)
{
 FILE *f;

 f = fopen("data\\dpft.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dpft.bin!");

 locked_fwrite(&_this->uNumFrames, 4, 1, f);
 locked_fwrite(_this->pFrames, sizeof(struct PlayerFrame), _this->uNumFrames, f);
 return fclose(f);
}

//----- (00494C5A) --------------------------------------------------------
int CPlayerFrameTable_InitializeFromTXT(struct CPlayerFrameTable *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  int v5; // eax@10
  char *i; // eax@12
  FILE *v7; // ST0C_4@12
  signed int j; // esi@15
  const char *v9; // ST10_4@15
  const char *v10; // ST0C_4@15
  int v11; // eax@17
  int v12; // edx@22
  int v13; // ecx@23
  int v14; // eax@24
  int k; // eax@27
  int v16; // edx@28
  int v17; // esi@28
  int l; // ecx@29
  char Buf; // [sp+Ch] [bp-2F8h]@3
  char v21; // [sp+200h] [bp-104h]@4
  int v22; // [sp+27Ch] [bp-88h]@4
  char *Str1; // [sp+280h] [bp-84h]@5
  const char *v24; // [sp+284h] [bp-80h]@15
  const char *v25; // [sp+288h] [bp-7Ch]@15
  int v26; // [sp+2F8h] [bp-Ch]@3
  int v27; // [sp+2FCh] [bp-8h]@3
  FILE *File; // [sp+300h] [bp-4h]@1
  int v29; // [sp+30Ch] [bp+8h]@28

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(pSourceFile, L"r");
  File = v2;
  if ( !v2 )
    erroneous_printf("PlayerFrameTable::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v26 = 0;
  v27 = 1;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v22, sub_4BE3BF(&Buf, &v21), 0x7Cu);
      if ( v22 )
      {
        if ( *Str1 != 47 )
        {
          if ( v22 < 3 )
            erroneous_printf("PlayerFrameTable::load, too few arguments, %s line %i.", pSourceFile, v27);
          ++v26;
        }
      }
      ++v27;
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v26;
  }
  *(_DWORD *)v3 = v4;
  v5 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v3 + 4), 10 * v4, "P Frames");
  *(_DWORD *)(v3 + 4) = v5;
  if ( !v5 )
    erroneous_printf("PlayerFrameTable::load - Out of Memory!");
  v7 = File;
  *(_DWORD *)v3 = 0;
  fseek(v7, 0, 0);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v22, sub_4BE3BF(&Buf, &v21), 0x7Cu);
    if ( v22 )
    {
      if ( *Str1 != 47 )
      {
        v9 = v24;
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3) = atoi(Str1);
        v10 = v25;
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3 + 2) = atoi(v9);
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3 + 4) = atoi(v10);
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3 + 6) = 0;
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3 + 8) = 0;
        for ( j = 3; j < v22; ++j )
        {
          if ( !_strcmpi((&Str1)[4 * j], "New") )
          {
            v11 = *(_DWORD *)(v3 + 4) + 10 * *(_DWORD *)v3 + 8;
            *(_BYTE *)v11 |= 4u;
          }
        }
        ++*(_DWORD *)v3;
      }
    }
  }
  fclose(File);
  v12 = 0;
  if ( *(_DWORD *)v3 - 1 > 0 )
  {
    v13 = 0;
    do
    {
      v14 = v13 + *(_DWORD *)(v3 + 4);
      if ( !(*(_BYTE *)(v14 + 18) & 4) )
        *(_BYTE *)(v14 + 8) |= 1u;
      ++v12;
      v13 += 10;
    }
    while ( v12 < *(_DWORD *)v3 - 1 );
  }
  for ( k = 0; k < *(_DWORD *)v3; *(_WORD *)(v29 + 6) = v17 )
  {
    v16 = *(_DWORD *)(v3 + 4);
    v29 = v16 + 10 * k;
    v17 = *(_WORD *)(v29 + 4);
    if ( *(_BYTE *)(v29 + 8) & 1 )
    {
      ++k;
      for ( l = v16 + 10 * k; *(_BYTE *)(l + 8) & 1; l += 10 )
      {
        v17 += *(_WORD *)(l + 4);
        ++k;
      }
      v17 += *(_WORD *)(v16 + 10 * k + 4);
    }
    ++k;
  }
  return 1;
}









//----- (004586B0) --------------------------------------------------------
int CDecorationDescriptionList_InitializeFromTXT(struct CDecorationDescriptionList *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  int v4; // esi@3
  int v5; // eax@10
  char *i; // eax@12
  FILE *v7; // ST18_4@12
  __int16 v8; // ax@16
  const char *v9; // ST20_4@16
  char *v10; // ST18_4@16
  const char *v11; // ST14_4@16
  const char *v12; // ST10_4@16
  const char *v13; // ST0C_4@16
  const char *v14; // ST08_4@16
  const char *v15; // ST04_4@16
  const char *v16; // ST00_4@16
  unsigned __int8 v17; // zf@16
  char v18; // sf@16
  unsigned __int8 v19; // of@16
  int j; // edi@17
  const char *v21; // esi@18
  int v22; // eax@19
  int v23; // eax@21
  int v24; // eax@23
  int v25; // eax@25
  int v26; // eax@27
  int v27; // eax@29
  int v28; // eax@31
  int v29; // eax@33
  char v31; // [sp+Ch] [bp-460h]@17
  char v32; // [sp+88h] [bp-3E4h]@13
  char Dest; // [sp+104h] [bp-368h]@17
  char Buf; // [sp+17Ch] [bp-2F0h]@3
  int v35; // [sp+370h] [bp-FCh]@4
  char Str1[120]; // [sp+374h] [bp-F8h]@18
  int v37; // [sp+3ECh] [bp-80h]@4
  int v38; // [sp+3F0h] [bp-7Ch]@5
  char *Source; // [sp+3F4h] [bp-78h]@16
  const char *v40; // [sp+3F8h] [bp-74h]@16
  char *Str; // [sp+3FCh] [bp-70h]@16
  const char *v42; // [sp+400h] [bp-6Ch]@16
  const char *v43; // [sp+404h] [bp-68h]@16
  const char *v44; // [sp+408h] [bp-64h]@16
  const char *v45; // [sp+40Ch] [bp-60h]@16
  const char *v46; // [sp+410h] [bp-5Ch]@16
  const char *v47; // [sp+414h] [bp-58h]@16
  const char *v48; // [sp+418h] [bp-54h]@17
  FILE *File; // [sp+468h] [bp-4h]@1
  int v50; // [sp+474h] [bp+8h]@3

  v3 = _this;
  sub_487E1D(_this);
  v2 = fopen(pSourceFile, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("DecorationDescriptionList::load - Unable to open file: %s.", pSourceFile);
  v4 = 0;
  v50 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v37, sub_4BE485(&Buf, &v35), 0x7Cu);
      if ( v37 )
      {
        if ( *(_BYTE *)v38 != 47 )
        {
          if ( v37 >= 3 )
            ++v50;
        }
      }
    }
    while ( fgets(&Buf, 490, File) );
    v4 = v50;
  }
  *(_DWORD *)v3 = v4;
  v5 = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 4), 84 * v4, "Dec Descrip");
  *(_DWORD *)(v3 + 4) = v5;
  if ( !v5 )
    erroneous_printf("DecorationDescriptionList::load - Out of Memory!");
  v7 = File;
  *(_DWORD *)v3 = 0;
  fseek(v7, 0, 0);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v37, sub_4BE485(&Buf, &v32), 0x7Cu);
    if ( v37 )
    {
      if ( *(_BYTE *)v38 != 47 )
      {
        if ( v37 >= 3 )
        {
          strcpy((char *)(*(_DWORD *)(v3 + 4) + 84 * *(_DWORD *)v3), Source);
          v8 = CSpriteFrameTable_FastFindSprite(pSpriteFrameTable, (const char *)(*(_DWORD *)(v3 + 4) + 84 * *(_DWORD *)v3));
          v9 = v40;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 72) = v8;
          strcpy((char *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 32), v9);
          v10 = Str;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 64) = 0;
          v11 = v42;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 68) = atoi(v10);
          v12 = v43;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 66) = atoi(v11);
          v13 = v44;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 70) = atoi(v12);
          v14 = v45;
          *(_BYTE *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 80) = atoi(v13);
          v15 = v46;
          *(_BYTE *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 81) = atoi(v14);
          v16 = v47;
          *(_BYTE *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 82) = atoi(v15);
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 76) = atoi(v16);
          compile_error;//v19 = __SETO__(v37, 10);
          v17 = v37 == 10;
          v18 = v37 - 10 < 0;
          *(_WORD *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74) = 0;
          if ( !((unsigned __int8)(v18 ^ v19) | v17) )
          {
            strcpy(&Dest, v48);
            memcpy(&v35, sub_4BE485(&Dest, &v31), 0x7Cu);
            for ( j = 0; j < v35; ++j )
            {
              v21 = *(const char **)&Str1[4 * j];
              if ( _strcmpi(*(const char **)&Str1[4 * j], "NBM") )
              {
                if ( _strcmpi(v21, "Invisible") )
                {
                  if ( _strcmpi(v21, "FS") )
                  {
                    if ( _strcmpi(v21, "FM") )
                    {
                      if ( _strcmpi(v21, "FF") )
                      {
                        if ( _strcmpi(v21, "Marker") )
                        {
                          if ( _strcmpi(v21, "LoopSlow") )
                          {
                            if ( _strcmpi(v21, "EmitFire") )
                            {
                              if ( _strcmpi(v21, "Dawn") )
                              {
                                if ( !_strcmpi(v21, "Dusk") )
                                  *(_BYTE *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 75) |= 2;
                              }
                              else
                              {
                                *(_BYTE *)(84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 75) |= 1u;
                              }
                            }
                            else
                            {
                              v29 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                              *(_BYTE *)v29 |= 0x80u;
                            }
                          }
                          else
                          {
                            v28 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                            *(_BYTE *)v28 |= 0x40u;
                          }
                        }
                        else
                        {
                          v27 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                          *(_BYTE *)v27 |= 0x20u;
                        }
                      }
                      else
                      {
                        v26 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                        *(_BYTE *)v26 |= 0x10u;
                      }
                    }
                    else
                    {
                      v25 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                      *(_BYTE *)v25 |= 8u;
                    }
                  }
                  else
                  {
                    v24 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                    *(_BYTE *)v24 |= 4u;
                  }
                }
                else
                {
                  v23 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                  *(_BYTE *)v23 |= 2;
                }
              }
              else
              {
                v22 = 84 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 74;
                *(_BYTE *)v22 |= 1u;
              }
            }
          }
          ++*(_DWORD *)v3;
        }
      }
    }
  }
  fclose(File);
  return 1;
}


//----- (00458600) --------------------------------------------------------
int CDecorationDescriptionList_SaveToBIN(struct CDecorationDescriptionList *_this)
{
 FILE *f;

 f = fopen("data\\ddeclist.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save ddeclist.bin!");

 locked_fwrite(&_this->uNumLevelDecorations, 4, 1, f);
 locked_fwrite(_this->pDescriptions, sizeof(struct DecorationDescription), _this->uNumLevelDecorations, f);
 return fclose(f);
}








//----- (00459090) --------------------------------------------------------
int CObjectDescriptionList_SaveToBIN(struct CObjectDescriptionList *_this)
{
 FILE *f;

 f = fopen("data\\dobjlist.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dobjlist.bin!");

 locked_fwrite(&_this->uNumObjects, 4, 1, f);
 locked_fwrite(_this->pDescriptions, sizeof(struct ObjectDescription), _this->uNumObjects, f);
 return fclose(f);
}

//----- (00459123) --------------------------------------------------------
int CObjectDescriptionList_InitializeFromTXT(struct CObjectDescriptionList *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  __int32 v4; // edi@1
  int v5; // esi@3
  int v6; // eax@9
  char *i; // eax@11
  FILE *v8; // ST0C_4@11
  __int16 v9; // ax@14
  char *v10; // ST20_4@14
  const char *v11; // ST1C_4@14
  const char *v12; // ST18_4@14
  const char *v13; // ST14_4@14
  const char *v14; // ST10_4@14
  const char *v15; // ST0C_4@14
  const char *v16; // edi@16
  int v17; // esi@16
  int v18; // eax@17
  int v19; // eax@19
  int v20; // eax@21
  int v21; // eax@21
  int v22; // eax@21
  int v23; // eax@23
  int v24; // eax@25
  int v25; // eax@27
  int v26; // eax@29
  const char *v27; // edi@30
  const char *v28; // ST20_4@35
  int v29; // eax@35
  const char *v30; // ST1C_4@35
  const char *v31; // ST18_4@35
  char v33; // [sp+8h] [bp-460h]@14
  char v34; // [sp+84h] [bp-3E4h]@12
  char Dest; // [sp+100h] [bp-368h]@14
  char Buf; // [sp+178h] [bp-2F0h]@3
  int v37; // [sp+36Ch] [bp-FCh]@4
  char *Str1; // [sp+370h] [bp-F8h]@16
  int v39; // [sp+374h] [bp-F4h]@35
  int v40; // [sp+378h] [bp-F0h]@35
  int v41; // [sp+37Ch] [bp-ECh]@35
  int v42; // [sp+3E8h] [bp-80h]@4
  char *Source; // [sp+3ECh] [bp-7Ch]@5
  const char *v44; // [sp+3F0h] [bp-78h]@14
  char *Str; // [sp+3F4h] [bp-74h]@14
  const char *v46; // [sp+3F8h] [bp-70h]@14
  const char *v47; // [sp+3FCh] [bp-6Ch]@14
  const char *v48; // [sp+400h] [bp-68h]@14
  const char *v49; // [sp+404h] [bp-64h]@14
  const char *v50; // [sp+408h] [bp-60h]@14
  FILE *File; // [sp+464h] [bp-4h]@1
  int v52; // [sp+470h] [bp+8h]@3
  int j; // [sp+470h] [bp+8h]@15

  v3 = _this;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(_this + 4));
  v4 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)v3 = 0;
  v2 = fopen(pSourceFile, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("ObjectDescriptionList::load - Unable to open file: %s.", pSourceFile);
  v5 = 0;
  v52 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v42, sub_4BE485(&Buf, &v37), 0x7Cu);
      if ( v42 )
      {
        if ( *Source != 47 )
          ++v52;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v5 = v52;
    v4 = 0;
  }
  *(_DWORD *)v3 = v5;
  v6 = class23_AllocatedNamedBuffer(class23_instance, *(_DWORD *)(v3 + 4), 56 * v5, "Obj Descrip");
  *(_DWORD *)(v3 + 4) = v6;
  if ( v6 == v4 )
    erroneous_printf("ObjectDescriptionList::load - Out of Memory!");
  memset((void *)v6, v4, 56 * *(_DWORD *)v3);
  v8 = File;
  *(_DWORD *)v3 = v4;
  fseek(v8, v4, v4);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v42, sub_4BE485(&Buf, &v34), 0x7Cu);
    if ( v42 )
    {
      if ( *Source != 47 )
      {
        strcpy((char *)(*(_DWORD *)(v3 + 4) + 56 * *(_DWORD *)v3), Source);
        v9 = CSpriteFrameTable_FastFindSprite(pSpriteFrameTable, v44);
        v10 = Str;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 40) = v9;
        v11 = v46;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 32) = atoi(v10);
        v12 = v47;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 34) = atoi(v11);
        v13 = v48;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 36) = atoi(v12);
        v14 = v49;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 42) = atoi(v13);
        v15 = v50;
        *(_WORD *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 48) = atoi(v14);
        strcpy(&Dest, v15);
        memcpy(&v37, sub_4BE485(&Dest, &v33), 0x7Cu);
        if ( v42 > 7 )
        {
          for ( j = 0; j < v37; ++j )
          {
            v17 = 4 * j;
            v16 = (&Str1)[4 * j];
            if ( !_strcmpi((&Str1)[4 * j], "NoDraw") )
            {
              v18 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v18 |= 1u;
            }
            if ( !_strcmpi(v16, "Lifetime") )
            {
              v19 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v19 |= 4u;
            }
            if ( !_strcmpi(v16, "FTLifetime") )
            {
              v20 = *(_DWORD *)(v3 + 4) + 56 * *(_DWORD *)v3;
              //*(_WORD *)(v20 + 42) = 8 * *(_WORD *)(60 * *(_WORD *)(v20 + 40) + dword_5C6DCC + 56);
              *(_WORD *)(v20 + 42) = 8 * *(_WORD *)(60 * *(_WORD *)(v20 + 40) + (unsigned int)(pSpriteFrameTable->pSpriteSFrames) + 56);
              v21 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v21 |= 8u;
              v22 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v22 |= 4u;
            }
            if ( !_strcmpi(v16, "NoPickup") )
            {
              v23 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v23 |= 0x10u;
            }
            if ( !_strcmpi(v16, "NoGravity") )
            {
              v24 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v24 |= 0x20u;
            }
            if ( !_strcmpi(v16, "FlagOnIntercept") )
            {
              v25 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v25 |= 0x40u;
            }
            if ( !_strcmpi(v16, "Bounce") )
            {
              v26 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)v26 |= 0x80u;
            }
            v27 = (&Source)[v17];
            if ( !_strcmpi((&Source)[v17], "Fire") )
              *(_BYTE *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 39) |= 2;
            if ( !_strcmpi(v27, "Lines") )
              *(_BYTE *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 39) |= 4u;
            if ( !_strcmpi((&Str1)[v17], "bits") )
            {
              v28 = *(const char **)((char *)&v39 + v17);
              v29 = 56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 38;
              *(_BYTE *)(v29 + 1) |= 1u;
              v30 = *(const char **)((char *)&v40 + v17);
              *(_BYTE *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 50) = atoi(v28);
              v31 = *(const char **)((char *)&v41 + v17);
              *(_BYTE *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 51) = atoi(v30);
              *(_BYTE *)(56 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 52) = atoi(v31);
            }
          }
        }
        ++*(_DWORD *)v3;
      }
    }
  }
  fclose(File);
  return 1;
}





//----- (00458DBC) --------------------------------------------------------
int COverlayDescriptionList_SaveToBIN(struct COverlayDescriptionList *_this)
{
 FILE *f;

 f = fopen("data\\doverlay.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save doverlay.bin!");

 locked_fwrite(&_this->uNumOverlays, 4, 1, f);
 locked_fwrite(_this->pDescriptions, sizeof(struct OverlayDescription), _this->uNumOverlays, f);
 return fclose(f);
}

//----- (00458E4F) --------------------------------------------------------
int COverlayDescriptionList_InitializeFromTXT(struct COverlayDescriptionList *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  __int32 v4; // edi@1
  int v5; // esi@3
  int v6; // eax@9
  int v7; // ST18_4@9
  char *i; // eax@11
  FILE *v9; // ST0C_4@11
  char *v10; // ST1C_4@14
  int v11; // eax@16
  int v12; // ecx@16
  int v13; // eax@16
  char v14; // zf@16
  char Buf; // [sp+10h] [bp-2F0h]@3
  char v17; // [sp+204h] [bp-FCh]@4
  int v18; // [sp+280h] [bp-80h]@4
  char *Str2; // [sp+284h] [bp-7Ch]@5
  char *Str1; // [sp+288h] [bp-78h]@14
  const char *v21; // [sp+28Ch] [bp-74h]@19
  FILE *File; // [sp+2FCh] [bp-4h]@1
  int v23; // [sp+308h] [bp+8h]@3

  v3 = _this;
  class23_DeleteBuffer(class23_instance, *(_DWORD *)(_this + 4));
  v4 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)v3 = 0;
  v2 = fopen(pSourceFile, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("ObjectDescriptionList::load - Unable to open file: %s.", pSourceFile);
  v5 = 0;
  v23 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v18, sub_4BE3BF(&Buf, &v17), 0x7Cu);
      if ( v18 )
      {
        if ( *Str2 != 47 )
          ++v23;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v5 = v23;
    v4 = 0;
  }
  v7 = *(_DWORD *)(v3 + 4);
  *(_DWORD *)v3 = v5;
  v6 = class23_AllocatedNamedBuffer(class23_instance, v7, 8 * v5, "Ovl Des.");
  *(_DWORD *)(v3 + 4) = v6;
  if ( v6 == v4 )
    erroneous_printf("OverlayDescriptionList::load - Out of Memory!");
  memset((void *)v6, v4, 8 * *(_DWORD *)v3);
  v9 = File;
  *(_DWORD *)v3 = v4;
  fseek(v9, v4, v4);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v18, sub_4BE3BF(&Buf, &v17), 0x7Cu);
    if ( v18 )
    {
      if ( *Str2 != 47 )
      {
        v10 = Str1;
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 8 * *(_DWORD *)v3) = atoi(Str2);
        if ( _strcmpi(v10, "center") )
        {
          v13 = _strcmpi(Str1, "transparent");
          v12 = *(_DWORD *)(v3 + 4);
          v14 = v13 == 0;
          v11 = *(_DWORD *)v3;
          if ( v14 )
            *(_WORD *)(v12 + 8 * v11 + 2) = 2;
          else
            *(_WORD *)(v12 + 8 * v11 + 2) = 1;
        }
        else
        {
          *(_WORD *)(*(_DWORD *)(v3 + 4) + 8 * *(_DWORD *)v3 + 2) = 0;
        }
        *(_WORD *)(*(_DWORD *)(v3 + 4) + 8 * *(_DWORD *)v3++ + 4) = CSpriteFrameTable_FastFindSprite(pSpriteFrameTable, v21);
      }
    }
  }
  fclose(File);
  return 1;
}





//----- (004A9E3D) --------------------------------------------------------
int CSoundList_SaveToBIN(struct CSoundList *_this)
{
 FILE *f;

 f = fopen("data\\dsounds.bin", "wb");
 if (!f)
   erroneous_printf("Unable to save dsounds.bin!");

 locked_fwrite(&_this->uNumSounds, 4, 1, f);
 locked_fwrite(_this->pDescriptions, sizeof(struct SoundDescription), _this->uNumSounds, f);
 return fclose(f);
}

//----- (004A9ED0) --------------------------------------------------------
int CSoundList_InitializeFromTXT(struct CSoundList *_this, const char *pSourceFile)
{
  FILE *v2; // eax@1
  int v3; // ebx@1
  __int32 v4; // edi@1
  int v5; // esi@3
  int v6; // eax@9
  char *i; // eax@11
  FILE *v8; // ST0C_4@11
  char *v9; // ST0C_4@14
  int v10; // eax@18
  int v11; // ecx@18
  int v12; // eax@18
  char v13; // zf@18
  int v14; // eax@23
  char Buf; // [sp+Ch] [bp-2F0h]@3
  char v17; // [sp+200h] [bp-FCh]@4
  int v18; // [sp+27Ch] [bp-80h]@4
  int v19; // [sp+280h] [bp-7Ch]@5
  char *Str; // [sp+284h] [bp-78h]@14
  char *Str1; // [sp+288h] [bp-74h]@14
  const char *v22; // [sp+28Ch] [bp-70h]@22
  FILE *File; // [sp+2F8h] [bp-4h]@1
  int v24; // [sp+304h] [bp+8h]@3

  v3 = _this;
  class23_DeleteBuffer((int)&class23_instance, *(_DWORD *)(_this + 4));
  v4 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)v3 = 0;
  v2 = fopen(pSourceFile, "r");
  File = v2;
  if ( !v2 )
    erroneous_printf("SoundListClass::load - Unable to open file: %s.", pSourceFile);
  v5 = 0;
  v24 = 0;
  if ( fgets(&Buf, 490, v2) )
  {
    do
    {
      *strchr(&Buf, 10) = 0;
      memcpy(&v18, sub_4BE3BF(&Buf, &v17), 0x7Cu);
      if ( v18 )
      {
        if ( *(_BYTE *)v19 != 47 )
          ++v24;
      }
    }
    while ( fgets(&Buf, 490, File) );
    v5 = v24;
    v4 = 0;
  }
  *(_DWORD *)v3 = v5;
  v6 = class23_AllocatedNamedBuffer(&class23_instance, *(_DWORD *)(v3 + 4), 120 * v5, "Snd Des.");
  *(_DWORD *)(v3 + 4) = v6;
  if ( v6 == v4 )
    erroneous_printf("SoundListClass::load - Out of Memory!");
  memset((void *)v6, v4, 120 * *(_DWORD *)v3);
  v8 = File;
  *(_DWORD *)v3 = v4;
  fseek(v8, v4, v4);
  for ( i = fgets(&Buf, 490, File); i; i = fgets(&Buf, 490, File) )
  {
    *strchr(&Buf, 10) = 0;
    memcpy(&v18, sub_4BE3BF(&Buf, &v17), 0x7Cu);
    if ( v18 )
    {
      if ( *(_BYTE *)v19 != 47 )
      {
        sprintfex(*(_DWORD *)(v3 + 4) + 120 * *(_DWORD *)v3, "%s", v19);
        v9 = Str1;
        *(_DWORD *)(120 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 32) = atoi(Str);
        if ( _strcmpi(v9, "system") )
        {
          if ( _strcmpi(Str1, "swap") )
          {
            v12 = _strcmpi(Str1, "lock");
            v11 = *(_DWORD *)(v3 + 4);
            v13 = v12 == 0;
            v10 = *(_DWORD *)v3;
            if ( v13 )
              *(_DWORD *)(120 * v10 + v11 + 36) = 4;
            else
              *(_DWORD *)(120 * v10 + v11 + 36) = 0;
          }
          else
          {
            *(_DWORD *)(120 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 36) = 2;
          }
        }
        else
        {
          *(_DWORD *)(120 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 36) = 1;
        }
        if ( v18 >= 4 )
        {
          if ( !_strcmpi(v22, "3D") )
          {
            v14 = 120 * *(_DWORD *)v3 + *(_DWORD *)(v3 + 4) + 40;
            *(_DWORD *)v14 |= 2;
          }
        }
        ++*(_DWORD *)v3;
      }
    }
  }
  fclose(File);
  return 1;
}