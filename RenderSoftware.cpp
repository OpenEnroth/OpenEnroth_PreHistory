
#if 0



//----- (0045D3C7) --------------------------------------------------------
bool __stdcall sub_45D3C7(struct struct8 *_this)
{
 struct struct8 *v2; // ecx@2
 struct Span    *i; // edi@5

 if (!_this->ptr_000040)
   return false;

 if (_this->ptr_000040->pParent)
 {
  v2 = _this->ptr_000040->pParent;
  if (v2->ptr_000040)
  {
   for (i = _this->ptr_000040; ; i = i->pNext)
   {
    compile_error();
    //if (i->pParent->byte_000108)
    //   sub_45D426((int)i, _this->array_000060, _this->dword_0000B0, _this->array_0000B4, _this->dword_000104);
     if (_this->ptr_000044 == i)
       break;
   }
   return true;
  }
 }
 return false;
}


//----- (0045D426) --------------------------------------------------------
char __stdcall sub_45D426(int a1, struct Edge *a2, signed int a3, struct Edge *a4, signed int a5)
{
  signed int v5; // edi@1
  signed int v6; // ecx@3
  signed int v7; // ebx@3
  int v8; // esi@3
  double v9; // st7@4
  int v10; // edx@5
  double v11; // st7@11
  int v12; // edx@12
  int v13; // ebx@17
  int v14; // edi@17
  double v15; // st7@17
  float v16; // ST04_4@17
  float v17; // ST04_4@17
  double v18; // ST14_8@20
  double v19; // ST14_8@20
  double v20; // st7@20
  int v21; // ecx@20
  double v22; // st6@20
  double v23; // st7@23
  double v24; // st7@29
  char result; // al@33
  signed int v26; // [sp+18h] [bp-4h]@3
  float v27; // [sp+24h] [bp+8h]@20
  signed int v28; // [sp+24h] [bp+8h]@20
  float v29; // [sp+28h] [bp+Ch]@17
  float v30; // [sp+2Ch] [bp+10h]@17
  float v31; // [sp+34h] [bp+18h]@20
  float v32; // [sp+34h] [bp+18h]@20

  v5 = 0;
  if ( a5 && a3 )
  {
    v7 = -1;
    v6 = 0;
    v8 = a1;
    v26 = -1;
    if ( a3 > 0 )
    {
      v9 = (double)*(_WORD *)(a1 + 10);
      while ( 1 )
      {
        v10 = *(_DWORD *)(a2 + 4 * v6);
        if ( v9 >= *(float *)(v10 + 44) )
        {
          if ( v9 <= *(float *)(v10 + 48) )
            break;
        }
        ++v6;
        if ( v6 >= a3 )
          goto LABEL_10;
      }
      v26 = v6;
    }
LABEL_10:
    if ( a5 > 0 )
    {
      v11 = (double)*(_WORD *)(a1 + 10);
      while ( 1 )
      {
        v12 = *(_DWORD *)(LODWORD(a4) + 4 * v5);
        if ( v11 >= *(float *)(v12 + 44) )
        {
          if ( v11 <= *(float *)(v12 + 48) )
            break;
        }
        ++v5;
        if ( v5 >= a5 )
          goto LABEL_17;
      }
      v7 = v5;
    }
LABEL_17:
    v13 = *(_DWORD *)(LODWORD(a4) + 4 * v7);
    v14 = *(_DWORD *)(a2 + 4 * v26);
    v16 = (double)*(_WORD *)(a1 + 10);
    v30 = sub_45D643(*(_DWORD *)(a2 + 4 * v26), v16);
    v17 = (double)*(_WORD *)(a1 + 10);
    v15 = sub_45D643(v13, v17);
    v29 = v15;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 0x80 )
    {
      *(float *)(a1 + 20) = v15;
      *(_DWORD *)(a1 + 16) = LODWORD(v30);
    }
    else
    {
      v31 = ((double)*(_WORD *)(a1 + 10) - *(float *)(v14 + 44)) * *(float *)(v14 + 4) + *(float *)(v14 + 36) - 0.5;
      v18 = v31 + 6.755399441055744e15;
      v32 = (double)SLODWORD(v18);
      v27 = ((double)*(_WORD *)(a1 + 10) - *(float *)(v13 + 44)) * *(float *)(v13 + 4) + *(float *)(v13 + 36) + 0.5;
      v19 = v27 + 6.755399441055744e15;
      v20 = (double)SLODWORD(v19);
      v28 = *(_WORD *)(v8 + 8);
      v21 = *(_WORD *)(v8 + 12);
      v22 = -((v30 - v29) / (v20 - v32));
      *(float *)(v8 + 16) = ((double)v28 - v32) * v22 + v30;
      *(float *)(v8 + 20) = v29 - (v20 - (double)(v28 + v21)) * v22;
    }
    if ( *(float *)(v8 + 16) < 0.0 || *(float *)(v8 + 16) <= 1.0 )
    {
      if ( *(float *)(v8 + 16) >= 0.0 )
        v23 = *(float *)(v8 + 16);
      else
        v23 = 0.0;
    }
    else
    {
      v23 = 1.0;
    }
    *(float *)(v8 + 16) = v23;
    if ( *(float *)(v8 + 20) < 0.0 || *(float *)(v8 + 20) <= 1.0 )
    {
      if ( *(float *)(v8 + 20) >= 0.0 )
        v24 = *(float *)(v8 + 20);
      else
        v24 = 0.0;
    }
    else
    {
      v24 = 1.0;
    }
    *(float *)(v8 + 20) = v24;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00485E1F) --------------------------------------------------------
char *__fastcall sub_485E1F(int *a1, struct Span *pSpan, signed int a3, struct struct8 *a4, int a5, unsigned __int8 a6, char a7)
{
  char v10; // zf@1
  int v11; // eax@1
  char *v16; // eax@4
  signed int v17; // ST14_4@4
  char v18; // dl@4
  signed int v19; // ST10_4@4
  signed int v20; // ST14_4@5
  char v21; // dl@5
  int v22; // ST10_4@5
  signed int v24; // ST14_4@6
  char v25; // dl@6
  char v27; // [sp+16h] [bp-2h]@1
  char v28; // [sp+17h] [bp-1h]@1

  runtime_warning(suspicious decompilation)


  v10 = a1[0] == 0;
  v27 = a1[1] != 0;
  v28 = !v10;
  sub_47BEB1(a3, a4, a5, 0, (int)&a1[2], &a1[3], (char *)&v27, (char *)&v28);
  a1[9] = (int)sub_47C28C((int)a4, v28, a1[2], a1[3]);
  v11 = a4->byte_000108;
  a1[8] = v11;
  if ( v11 )
  {
    if ( a7 )
    {
      a1[4] = floorf(pSpan->flt_000010 * 31.0 + 0.5f) * 65536;
      a1[5] = floorf(pSpan->flt_000014 * 31.0 + 0.5f) * 65536;
      a1[6] = -((a1[4] - a1[5]) / pSpan->word_00000C);
    }
    v17 = a1[3];
    v18 = v28;
    v19 = a1[2];
    a1[7] = a6;
    v16 = (char *)sub_47C28C((int)a4, v18, v19, v17);
  }
  else
  {
    v20 = a1[3];
    v21 = v28;
    a1[4] = 0;
    a1[5] = 0;
    v22 = a1[2];
    a1[6] = 0;
    a1[7] = 0;
    v16 = sub_47C1CA(a4, v21, v22, v20);
  }
  v24 = a1[3];
  v25 = v28;
  a1[9] = (int)v16;
  return sub_47C1CA(a4, v25, a1[2], v24);
}


//----- (00484442) --------------------------------------------------------
signed int __thiscall sub_484442(int _this)
{
  signed int v1; // ecx@1
  int v2; // ebx@1
  int ebp0; // ebp@0
  int v4; // edi@1
  int v5; // esi@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // eax@1
  int v9; // edx@1
  int v10; // eax@1
  int v11; // ebx@1
  int v12; // eax@1
  int v13; // ecx@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // ecx@3
  signed int v17; // ebx@3
  signed __int64 v18; // qtt@3
  int v19; // ebx@3
  int v20; // eax@3
  int v21; // eax@3
  int v22; // eax@4
  int v23; // ecx@12
  int v24; // eax@12
  signed int v25; // eax@12
  int v26; // ecx@14
  int v27; // eax@14
  int v28; // esi@14
  signed int v29; // edi@14
  signed int v30; // eax@14
  signed int v32; // [sp+Ch] [bp-90h]@1
  int v33; // [sp+10h] [bp-8Ch]@1
  int v34; // [sp+14h] [bp-88h]@1
  char v35; // [sp+18h] [bp-84h]@14
  int v36; // [sp+40h] [bp-5Ch]@14
  int v37; // [sp+44h] [bp-58h]@14
  int v38; // [sp+48h] [bp-54h]@14
  int v39; // [sp+4Ch] [bp-50h]@14
  int v40; // [sp+50h] [bp-4Ch]@14
  int v41; // [sp+54h] [bp-48h]@13
  int v42; // [sp+58h] [bp-44h]@13
  int v43; // [sp+5Ch] [bp-40h]@13
  int v44; // [sp+60h] [bp-3Ch]@13
  int v45; // [sp+64h] [bp-38h]@3
  int v46; // [sp+68h] [bp-34h]@1
  int v47; // [sp+6Ch] [bp-30h]@12
  int v48; // [sp+70h] [bp-2Ch]@12
  char *v49; // [sp+74h] [bp-28h]@14
  int v50; // [sp+78h] [bp-24h]@3
  int v51; // [sp+7Ch] [bp-20h]@14
  int v52; // [sp+80h] [bp-1Ch]@14
  int v53; // [sp+84h] [bp-18h]@1
  int v54; // [sp+88h] [bp-14h]@1
  int v55; // [sp+8Ch] [bp-10h]@1
  int v56; // [sp+90h] [bp-Ch]@1
  int v57; // [sp+94h] [bp-8h]@1
  int v58; // [sp+98h] [bp-4h]@1

  v4 = _this;
  v5 = *(_DWORD *)(_this + 4);
  v6 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - *(_WORD *)(_this + 10));
  v7 = *(_DWORD *)(v5 + 56);
  v57 = v6;
  v56 = *(_DWORD *)(v7 + 20);
  v57 = (unsigned __int64)(v56 * v6) >> 16;
  v8 = *(_DWORD *)(v5 + 56);
  v9 = v57 + *(_DWORD *)(v8 + 12);
  v56 = *(_DWORD *)(v8 + 32);
  v53 = v9;
  v10 = ((unsigned __int64)(v56 * v6) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v57 = v6;
  v55 = v10;
  v56 = *(_DWORD *)(v5 + 32);
  v57 = (unsigned __int64)(v56 * v6) >> 16;
  v11 = v57 + *(_DWORD *)(v5 + 24);
  v33 = class59_SinCos(pClass59_global, pOldCamera->sRotationY - pClass59_global->uIntegerHalfPi);
  v12 = class59_SinCos(pClass59_global, pOldCamera->sRotationY);
  v13 = *(_WORD *)(v4 + 8);
  v34 = v12;
  v46 = *(_WORD *)(v4 + 12);
  v14 = pOldViewport->dword_000028 - v13;
  v15 = *(_DWORD *)(v5 + 36);
  v58 = pStruct9_global->dword_000018 * v14;
  v1 = -v15;
  v32 = v1;
  v2 = ((unsigned __int64)(pStruct9_global->dword_000018 * v14 * *(_DWORD *)(v5 + 28)) >> 16) + v11;
  v54 = v2;
  if ( !v2 || (v56 = abs(v1 >> 14), v56 > abs(v2)) )
    return 0;
  LODWORD(v18) = v32 << 16;
  HIDWORD(v18) = v32 >> 16;
  v57 = v18 / v54;
  v16 = v18 / v54;
  v19 = v58;
  HIWORD(v20) = (unsigned int)(v18 / v54) >> 16;
  LOWORD(v20) = 0;
  v45 = v20;
  v21 = v53 + ((unsigned __int64)(*(_DWORD *)(*(_DWORD *)(v5 + 56) + 16) * v58) >> 16);
  v58 = v19;
  v54 = v21;
  v53 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
  v58 = (unsigned __int64)(v53 * v19) >> 16;
  v55 += (unsigned __int64)(v53 * v19) >> 16;
  v17 = 2;
  v50 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  if ( v16 < dword_6BE0F0 << 16 )
  {
    v17 = 0;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 48);
LABEL_11:
    v50 = v22;
    goto LABEL_12;
  }
  if ( v16 < dword_6BE0F4 << 16 )
  {
    v17 = 1;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 52);
    goto LABEL_11;
  }
  if ( v16 < dword_6BE0F8 << 16 )
  {
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
    goto LABEL_11;
  }
  if ( !bUseLoResSprites )
  {
    v17 = 3;
    v22 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 60);
    goto LABEL_11;
  }
LABEL_12:
  v58 = (unsigned __int64)(v54 * v16) >> 16;
  v24 = *(_DWORD *)(v5 + 56);
  v58 = v16;
  v48 = ((unsigned __int64)(v54 * v16) >> 16) - *(_DWORD *)(v24 + 36);
  v25 = ((unsigned __int64)(v55 * v16) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
  v23 = (unsigned __int8)bUseLoResSprites + v17 + 2;
  v48 >>= v23;
  v55 = (unsigned __int8)bUseLoResSprites + v17 + 2;
  v47 = v25 >> v23;
  if ( byte_80AA10 )
  {
    v41 = dword_80AA20 >> v23;
    v42 = dword_80AA1C >> v23;
    v43 = dword_80AA18 >> v23;
    v44 = dword_80AA14 >> v23;
  }
  v55 = pStruct9_global->dword_000018;
  v56 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v57) >> 16) >> v23;
  v37 = (unsigned __int64)(v56 * v33) >> 16;
  v58 = (unsigned __int64)(v56 * v34) >> 16;
  v36 = (unsigned __int64)(v56 * v34) >> 16;
  v49 = sub_485E1F((int *)&v35, (Span *)v4, v57, (struct8 *)v5, dword_6BE0E0, 1u, 1);
  v26 = *(_WORD *)(v4 + 8);
  v27 = (int)(&pD3DRenderer->pActiveZBuffer[v26 + 640 * *(_WORD *)(v4 + 10)]);
  v52 = (int)(pD3DRenderer->pTargetSurface + (v26 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v4 + 10)));
  v51 = v27;
  v28 = *(_DWORD *)(v5 + 60);
  v29 = (signed int)*(_WORD *)(v28 + 24) >> v17;
  v30 = (signed int)*(_WORD *)(v28 + 26) >> v17;
  v40 = v17 - *(_WORD *)(v28 + 28) + 16;
  v39 = v29 - 1;
  v38 = (v30 << 16) - 65536;
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
  {
    if ( byte_80AA10 )
      sub_485D3E((int)&v36, (int)&v35);
    else
      sub_485C89((int)&v36, (int)&v35);
  }
  else
  {
    if ( byte_80AA10 )
      sub_4D72EC(ebp0);
    else
      sub_4D73DF(ebp0);
  }
  return 1;
}

//----- (00485C89) --------------------------------------------------------
int __fastcall sub_485C89(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // esi@2
  int v6; // esi@2
  int v7; // edi@4
  int v8; // esi@4
  int v9; // ecx@9
  int v10; // esi@11
  int v11; // ecx@14
  int v12; // esi@14
  int v13; // [sp+0h] [bp-4h]@2

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    v5 = *(_DWORD *)(result + 8) & *(_DWORD *)(result + 44);
    *(_DWORD *)(result + 40) = i - 1;
    v6 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50)) + (v5 >> *(_DWORD *)(result + 16));
    v4 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    v13 = *(_BYTE *)(v6 + *(_DWORD *)(result + 56));
    if ( *(_BYTE *)(v6 + *(_DWORD *)(result + 56)) )
    {
      if ( *(_DWORD *)(a2 + 32) )
      {
        v8 = *(_WORD *)(a2 + 18);
        v7 = v8;
        if ( v8 >= *(_DWORD *)(a2 + 12) )
          v7 = *(_DWORD *)(a2 + 12);
        if ( *(_DWORD *)(a2 + 8) - v7 <= 0 )
        {
          v9 = 0;
        }
        else
        {
          if ( v8 >= *(_DWORD *)(a2 + 12) )
            v8 = *(_DWORD *)(a2 + 12);
          v9 = *(_DWORD *)(a2 + 8) - v8;
        }
        v10 = *(_DWORD *)(a2 + 36);
        v4 = v13 + (v9 << 8);
      }
      else
      {
        v10 = *(_DWORD *)(result + 52);
      }
      **(_WORD **)(result + 64) = *(_WORD *)(v10 + 2 * v4);
    }
    v11 = *(_DWORD *)(result + 60);
    v12 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v11 = v12;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}


//----- (00485D3E) --------------------------------------------------------
int __fastcall sub_485D3E(int a1, int a2)
{
  int result; // eax@1
  int i; // ecx@1
  int v4; // ecx@2
  int v5; // ecx@4
  int v6; // ecx@6
  int v7; // ecx@8
  int v8; // ecx@10
  int v9; // esi@10
  int v10; // edi@12
  int v11; // esi@12
  int v12; // ecx@17
  int v13; // esi@19
  int v14; // ecx@22
  int v15; // esi@22
  int v16; // [sp+0h] [bp-4h]@10

  result = a1;
  for ( i = *(_DWORD *)(a1 + 40); i; i = *(_DWORD *)(result + 40) )
  {
    *(_DWORD *)(result + 40) = i - 1;
    v4 = *(_DWORD *)(result + 24);
    if ( *(_DWORD *)(result + 48) > v4 )
      *(_DWORD *)(result + 48) = v4;
    v5 = *(_DWORD *)(result + 32);
    if ( *(_DWORD *)(result + 44) > v5 )
      *(_DWORD *)(result + 44) = v5;
    v6 = *(_DWORD *)(result + 20);
    if ( *(_DWORD *)(result + 48) < v6 )
      *(_DWORD *)(result + 48) = v6;
    v7 = *(_DWORD *)(result + 28);
    if ( *(_DWORD *)(result + 44) < v7 )
      *(_DWORD *)(result + 44) = v7;
    v9 = (*(_DWORD *)(result + 12) & *(_WORD *)(result + 50))
       + ((*(_DWORD *)(result + 44) & *(_DWORD *)(result + 8)) >> *(_DWORD *)(result + 16));
    v8 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    v16 = *(_BYTE *)(v9 + *(_DWORD *)(result + 56));
    if ( *(_BYTE *)(v9 + *(_DWORD *)(result + 56)) )
    {
      if ( *(_DWORD *)(a2 + 32) )
      {
        v11 = *(_WORD *)(a2 + 18);
        v10 = v11;
        if ( v11 >= *(_DWORD *)(a2 + 12) )
          v10 = *(_DWORD *)(a2 + 12);
        if ( *(_DWORD *)(a2 + 8) - v10 <= 0 )
        {
          v12 = 0;
        }
        else
        {
          if ( v11 >= *(_DWORD *)(a2 + 12) )
            v11 = *(_DWORD *)(a2 + 12);
          v12 = *(_DWORD *)(a2 + 8) - v11;
        }
        v13 = *(_DWORD *)(a2 + 36);
        v8 = v16 + (v12 << 8);
      }
      else
      {
        v13 = *(_DWORD *)(result + 52);
      }
      **(_WORD **)(result + 64) = *(_WORD *)(v13 + 2 * v8);
    }
    v14 = *(_DWORD *)(result + 60);
    v15 = *(_DWORD *)(result + 36);
    *(_DWORD *)(result + 64) += 2;
    *(_DWORD *)v14 = v15;
    *(_DWORD *)(result + 60) += 4;
    *(_DWORD *)(a2 + 16) += *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 48) += *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 44) += *(_DWORD *)result;
  }
  --*(_DWORD *)(result + 40);
  return result;
}


//----- (00487389) --------------------------------------------------------
void sub_487389_DrawSpansAndAll()
{
 struct Span *pSpan; // edi@6
 struct struct8 * v4; // esi@9
  int v5; // ebp@10
  int v9; // edi@22
  int v13; // esi@33
  int v16; // eax@39
  int v17; // eax@39
  int v18; // ebp@51
  int v19; // eax@51
  unsigned int v22; // eax@57
  unsigned int v24; // eax@57
  signed int v28; // edx@79
  signed int v29; // ecx@79
  int v30; // eax@106
  int v41; // [sp+2Ch] [bp-30h]@26
  int v42; // [sp+2Ch] [bp-30h]@116

  //char v43; // [sp+30h] [bp-2Ch]@57
  struct class57 local_30;

 int i, j, k;
 struct struct8 *pStruct8Array;
 unsigned int    uNumStructs;


 if (pParty_global->dword_007778 & 2)
 {
  uNumStructs = pStruct9_global->dword_00002C;
  pStruct8Array = array_77EC08;
 }
 else
 {
  uNumStructs = uNumElementsIn80AA28;
  pStruct8Array = array_80AA28[0];
 }

 for (i = 0; i < uNumStructs; ++i)
 {
  if (pParty_global->dword_007778 & 2)
    pSpan = pStruct8Array[i].ptr_000040;
  else
    pSpan = array_80AA28[i]->ptr_000040;

  if (!pSpan)
    continue;

  v4 = pSpan->pParent;
  if (!pSpan->pParent)
    continue;

  v5 = (int)pSpan->pParent->ptr_00003C;
  if (!v5)
    continue;

  if (!(pSpan->word_000008 >= pOldViewport->uGameX || pSpan->word_00000C != pOldViewport->uGameX))
  {
   pSpan->word_00000E = data_6BE060.dword_6BE064;
   continue;
  }

  v4->word_000032 |= 0x0002;
  if (v4->word_000030 & 0x0010 && v4->byte_000059 != 5)
  {
   v16 = (v4->byte_00005C - 64) << 25;
   dword_80AA20 = v16;
   dword_80AA1C = v16 + 0x1FF0000;
   v17 = ((unsigned int)(v4->byte_00005D) << 25) + 0x7FFF0000;
   dword_80AA14 = v17;
   dword_80AA18 = v17 - 0x1FF0000;

   byte_80AA10 = ((unsigned int)class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(pClass51_global, v4->byte_00005C, v4->byte_00005D - 1) / 512) & 1;

   if (v4->word_000030 & 0x0002 || v4->word_000030 & 0x0100)
   {
    if (v4->word_000030 & 0x0002)
    {
     while (true)
     {
      if (dword_6BE0D4)
        sub_48408A((int)pSpan);
      else
        sub_485407((int)pSpan);

      pSpan->word_00000E = data_6BE060.dword_6BE064;
      if (pSpan == v4->ptr_000044)
        break;
      pSpan = pSpan->pNext;
     }
    }
    else
    {
     while (true)
     {
      v18 = (int)v4->ptr_00003C;
	  #ifndef OLD_CODE
      v19 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( L"wtrtyl"); // temporarely replace texture with a water tile
# endif
   #ifdef OLD_CODE
      v19 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "wtrtyl",0); // temporarely replace texture with a water tile
# endif
      v4->ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[v19];
      if (dword_6BE0D4)
        sub_48408A((int)pSpan);
      else
        sub_485407((int)pSpan);

      v4->ptr_00003C = (cTexture *)v18;
      dword_80AA20 = (v4->byte_00005C - 64) << 25;
      dword_80AA1C = dword_80AA20 + 33488896;
      dword_80AA14 = ((unsigned int)(v4->byte_00005D) << 25) + 2147418112;
      dword_80AA18 = dword_80AA14 - 33488896;
      byte_80AA10 = ((unsigned int)class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(
                                               pClass51_global,
                                               v4->byte_00005C,
                                               v4->byte_00005D - 1) >> 9) & 1;
      sub_484442((int)pSpan);
      pSpan->word_00000E = data_6BE060.dword_6BE064;
      if (pSpan == v4->ptr_000044)
        break;
      pSpan = pSpan->pNext;
     }
    }
   }
   else
   {
    while (sub_48408A((int)pSpan))
    {
     pSpan->word_00000E = data_6BE060.dword_6BE064;
     if (pSpan == v4->ptr_000044)
       break;
     pSpan = pSpan->pNext;
    }
   }
  }
  else
  {
   if (v4->byte_000059 != 5)
   {
    if (v4->word_000030 & 0x0002)
    {
     while (1)
     {
	 #ifndef OLD_CODE
      v30 = LODFile_Bitmaps_LOD.LODFile_LoadTexture_New( L"wtrtyla");
#endif	
#ifdef OLD_CODE
      v30 = LODFile_Bitmaps_LOD.LODFile_LoadTexture( "wtrtyla",2);
#endif
      v4->ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[v30];
      if (!sub_4847EB(pSpan))
        break;

      v4->ptr_00003C = (cTexture *)v5;
      if (!sub_484442((int)pSpan))
        break;

      pSpan->word_00000E = data_6BE060.dword_6BE064;
      if (pSpan == v4->ptr_000044)
        break;

      pSpan = pSpan->pNext;
      v5 = (int)v4->ptr_00003C;
     }
    }
    else
    {
     if (v4->byte_000059 == 1)
     {
      dword_80AA20 = (v4->byte_00005C - 64) << 25;
      dword_80AA1C = dword_80AA20 + 33488896;
      dword_80AA14 = ((unsigned int)(v4->byte_00005D) << 25) + 2147418112;
      dword_80AA18 = dword_80AA14 - 33488896;
      byte_80AA10 = ((unsigned int)class51_sub_47EDB3_ActuallyGetSomeOtherTileInfo(pClass51_global,
                                               v4->byte_00005C,
                                               v4->byte_00005D - 1) >> 9) & 1;

      while (true)
      {
       if (!sub_4847EB(pSpan))
         sub_48585C_MaybeDrawSpan(pSpan, (pD3DRenderer->pTargetSurface + (pSpan->word_000008 + 640 * pSpan->word_00000A)), 0);

       pSpan->word_00000E = data_6BE060.dword_6BE064;
       if (pSpan == v4->ptr_000044)
         break;
       pSpan = pSpan->pNext;
      }
     }
    } 
    continue;
   }

   v4->ptr_000038 = &local_30;
   struct8_sub_479295(v4);

   v24 = GetTickCount();
   v22 = v24 / 8;

   if (v4->word_000030 & 0x0400)
     v4->dword_00002C -= v22 & v4->ptr_00003C->word_000022;
   else if (v4->word_000030 & 0x0800)
     v4->dword_00002C += v22 & v4->ptr_00003C->word_000022;

   if (v4->word_000030 & 0x1000)
     v4->dword_000028 -= v22 & v4->ptr_00003C->word_000020;
   else if (v4->word_000030 & 0x2000)
     v4->dword_000028 += v22 & v4->ptr_00003C->word_000020;

   v4->word_000052 = 32;
   v4->byte_00005A = 5;

   if ((double)abs(v4->ptr_000038->dword_00000C) > 52428.800000000003)
   {
    v4->word_000052 = 8;
    v4->byte_00005A = 3;
   }

   //if ( !(v4->word_000032 & 0x1) )
   if (~v4->word_000032 & 0x0001)
   {
    //if ( !(v4->word_000030 & 0x0002) )
    if (~v4->word_000030 & 0x0002)
    {
     if (v4->ptr_000054->byte_00012F == 1)
     {
      v28 = v4->ptr_000054->array_000048[0];
      dword_80AA1C = v28;
      dword_80AA20 = v28;

      v29 = v4->ptr_000054->array_000070[0];
      dword_80AA14 = v29;
      dword_80AA18 = v29;
      
      for (k = 1; k < v4->ptr_000054->uNumVertices; ++k)
      {
       if (dword_80AA20 > v4->ptr_000054->array_000048[k])
         dword_80AA20 = v4->ptr_000054->array_000048[k];
       if (v28 < v4->ptr_000054->array_000048[k])
       {
        v28 = v4->ptr_000054->array_000048[k];
        dword_80AA1C = v4->ptr_000054->array_000048[k];
       }

       if (dword_80AA18 > v4->ptr_000054->array_000070[k])
         dword_80AA18 = v4->ptr_000054->array_000070[k];
       if ( v29 < v4->ptr_000054->array_000070[k])
       {
        v29 = v4->ptr_000054->array_000070[k];
        dword_80AA14 = v4->ptr_000054->array_000070[k];
       }
      }

      dword_80AA20 = (dword_80AA20 + v4->dword_000028) << 16;
      dword_80AA1C = ((v28 + v4->dword_000028) << 16) - 65536;
      dword_80AA18 = (dword_80AA18 + v4->dword_00002C) << 16;
      dword_80AA14 = ((v29 + v4->dword_00002C) << 16) - 65536;
     }

     while (true)
     {
      if (!sub_482E07(pSpan, pD3DRenderer->pTargetSurface))
        sub_48585C_MaybeDrawSpan(pSpan, (pD3DRenderer->pTargetSurface + (pSpan->word_000008 + 640 * pSpan->word_00000A)), 0);

      pSpan->word_00000E = data_6BE060.dword_6BE064;
      if (pSpan == v4->ptr_000044)
        break;
      pSpan = pSpan->pNext;
     }
     continue;
    }

    while (true)
    {
LABEL_74:
     if (!sub_4839BD((int)pSpan, (int)pD3DRenderer->pTargetSurface))
       sub_48585C_MaybeDrawSpan(pSpan, (pD3DRenderer->pTargetSurface + (pSpan->word_000008 + 640 * pSpan->word_00000A)), 0);

     pSpan->word_00000E = data_6BE060.dword_6BE064;
     if (pSpan == v4->ptr_000044)
       break;
     pSpan = pSpan->pNext;
    }
    continue;
   }

   if (v4->word_000030 & 0x0002)
     goto LABEL_74;

   while (true)
   {
    if (!sub_482A94((int)pSpan))
      sub_48585C_MaybeDrawSpan(pSpan, (pD3DRenderer->pTargetSurface + (pSpan->word_000008 + 640 * pSpan->word_00000A)), 0);

    pSpan->word_00000E = data_6BE060.dword_6BE064;
    if (pSpan == v4->ptr_000044)
      break;
    pSpan = pSpan->pNext;
   }
  }
 }


 if (pParty_global->dword_007778 & 2)
 {
  uNumElementsIn80AA28 = 0;
  for (i = 0; i < pStruct9_global->dword_00002C; ++i)
  {
   if (array_77EC08[i].word_000032 & 0x0002)
   {
    array_77EC08[i].word_000032 &= 0xFFFD;
    array_80AA28[uNumElementsIn80AA28++] = &array_77EC08[i];
   }
  }
 }

 data_6BE060.dword_6BE060 = pStruct9_global->uNumSpans;
 if ( pStruct9_global->dword_00002C >= 1999 )
   return;

 sub_48607B_MessWithStruct8(&array_77EC08[1999], pClass57_global);
 class57_sub_48694B(array_77EC08[1999].ptr_000038);

 if (pClass51_global->dword_0000EC == -1)
   return;
 array_77EC08[1999].ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[pClass51_global->dword_0000EC];

 array_77EC08[1999].byte_000058 = 23 - ((signed int)((unsigned __int64)(1310720i64
                                               * (signed int)((unsigned __int64)((signed __int64)(-pClass51_global->dword_000D38) << 16) >> 16)) >> 16) >> 16);
 if (array_77EC08[1999].byte_000058 > 20)
   array_77EC08[1999].byte_000058 = 20;

 array_77EC08[1999].dword_000018 = class59_SinCos(pClass59_global, pOldCamera->sRotationX - pClass59_global->uIntegerHalfPi);
 array_77EC08[1999].dword_00001C = 0;
 array_77EC08[1999].dword_000020 = class59_SinCos(pClass59_global, pOldCamera->sRotationX);
 array_77EC08[1999].dword_000024 = 2048 - pOldCamera->dword_000008 * 65536;

 v41 = (signed __int64)((double)(pOldCamera->dword_000008 * pStruct9_global->dword_000014) / ((double)pStruct9_global->dword_000014 + 8192.0) + (double)pOldViewport->dword_00002C);

  cos((double)pOldCamera->sRotationX * 0.003066406352445483);
  sin((double)pOldCamera->sRotationX * 0.003066406352445483);

 sub_48607B_MessWithStruct8(&array_77EC08[1999], pClass57_global);
 class57_sub_48694B(array_77EC08[1999].ptr_000038);


 if (pClass51_global->uSkyTextureID == -1)
    return;

 array_77EC08[1999].ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[pClass51_global->uSkyTextureID];
 array_77EC08[1999].byte_000058 = 0;


 array_77EC08[1999].dword_000018 = -class59_SinCos(pClass59_global, pOldCamera->sRotationX + 16 - pClass59_global->uIntegerHalfPi);
 array_77EC08[1999].dword_00001C = 0;
 array_77EC08[1999].dword_000020 = -class59_SinCos(pClass59_global, pOldCamera->sRotationX + 16);
 array_77EC08[1999].dword_000024 = 0x2000000;

 array_77EC08[1999].dword_000028 = 224 * cClock2.dword_000024;
 array_77EC08[1999].dword_00002C = 224 * cClock2.dword_000024;
 
 v9 = pStruct9_global->uNumSpans;
 if (!v9)
   return;

 if (dword_6BE030 & 1 && pParty_global->uCurrentHour >= 5 && pParty_global->uCurrentHour < 21 || byte_6BE3C4_MaybeDrowningFlag)
 {
    v42 = *(_WORD *)sub_47BE72(array_77EC08[1999].ptr_00003C->word_000026, 31, 1);

    while ( 1 )
    {
      pSpan = &pSpansBuf[v9 - 1];

      if (pSpan->word_00000E != data_6BE060.dword_6BE064 )
      {
        pOldViewport->uGameX;
        if (pSpan->word_000008 >= pOldViewport->uGameX )
          goto LABEL_124;

        if (pSpan->word_00000C == pOldViewport->uGameX )
        {
         pSpan->word_00000E = data_6BE060.dword_6BE064;
        }
        else
        {
         pSpan->word_000008 = pOldViewport->uGameX;
         pSpan->word_00000C -= pOldViewport->uGameX;
          if (pSpan->word_00000C >= 0 )
          {
LABEL_124:
            pSpan->pParent = &array_77EC08[1999];
            sub_452AF3(v42, (pD3DRenderer->pTargetSurface + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A)), pSpan->word_00000C);
            memset_dw(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A), -65536, pSpan->word_00000C);
            goto LABEL_125;
          }
          pSpan->word_00000E = data_6BE060.dword_6BE064;
        }
      }
LABEL_125:
      --v9;
      if ( !v9 )
        return;
    }
  }
 else
  {
    do
    {
      pSpan = &pSpansBuf[v9 - 1];
      if (pSpan->word_00000E != data_6BE060.dword_6BE064)
      {
       if (pSpan->word_000008 >= pOldViewport->uGameX )
          goto LABEL_109;
        if (pSpan->word_00000C != pOldViewport->uGameX )
        {
          pSpan->word_000008 = pOldViewport->uGameX;
          pSpan->word_00000C -= pOldViewport->uGameX;
          if (pSpan->word_00000C >= 0 )
          {
LABEL_109:
            if ( dword_6BE0C4 )
            {
              sub_482A90();
            }
            else
            {
             pSpan->pParent = &array_77EC08[1999];
              if ( !sub_485044(pSpan, &array_77EC08[1999], v41))
                memset_dw(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A), -65536, pSpan->word_00000C);
            }
          }
          pSpan->word_00000E = data_6BE060.dword_6BE064;
          goto LABEL_114;
        }
        pSpan->word_00000E = data_6BE060.dword_6BE064;
      }
LABEL_114:
      --v9;
    }
    while ( v9 );
  }
}


//----- (004847EB) --------------------------------------------------------
bool sub_4847EB(struct Span *pSpan)
{
  int v2;
  int v3;
  int ebp0; // ebp@0
  struct struct8 *v5; // esi@1
  signed int v6; // eax@3
  signed int v7; // ebx@3
  int v8; // edi@3
  int v11; // edx@3
  int v12; // eax@3
  int v13; // ebx@4
  signed int v14; // eax@5
  signed int v15; // ebx@5
  signed __int64 v16; // qtt@5
  int v18; // ecx@14
  signed int v21; // eax@14
  signed int v23; // eax@16
  int v24; // ebx@16
  int v25; // ebx@17
  int v26; // edi@17
  int v27; // edi@17
  int v28; // eax@17
  int v29; // eax@18
  int v30; // eax@19
  int v31; // ecx@19
  signed __int64 v32; // qtt@19
  signed int v34; // edi@21
  int v35; // ebx@21
  signed int v36; // edi@21
  signed __int64 v37; // qtt@21
  signed int v38; // ebx@21
  int v39; // ebx@29
  int v40; // eax@32
  int v41; // edi@32
  unsigned __int64 v42; // qax@32
  int v43; // eax@33
  int v44; // eax@34
  int v45; // ecx@34
  signed __int64 v46; // qtt@34
  signed int v48; // edi@36
  int v49; // eax@36
  int v50; // eax@47
  int v51; // edi@47
  unsigned __int64 v52; // qax@47
  int v53; // eax@48
  int v54; // eax@49
  int v55; // ecx@49
  signed __int64 v56; // qtt@49
  signed int v58; // edi@51
  int v59; // eax@51
  int v62; // [sp+10h] [bp-ACh]@3
  int v63; // [sp+14h] [bp-A8h]@3
  int v64; // [sp+18h] [bp-A4h]@3
  int v65; // [sp+1Ch] [bp-A0h]@3
  signed int v66; // [sp+20h] [bp-9Ch]@3
  signed int v67; // [sp+24h] [bp-98h]@3
  int v68; // [sp+28h] [bp-94h]@1
  char v69; // [sp+2Ch] [bp-90h]@1

  struct sub_485975_stru0 local_30;
  /*
  //local struct
 struct
 {
  int v70; // [sp+30h] [bp-8Ch]@21
  int v71; // [sp+34h] [bp-88h]@21
  int v72; // [sp+38h] [bp-84h]@16
  int v73; // [sp+3Ch] [bp-80h]@16
  int v74; // [sp+40h] [bp-7Ch]@16
  int v75; // [sp+44h] [bp-78h]@15
  int v76; // [sp+48h] [bp-74h]@15
  int v77; // [sp+4Ch] [bp-70h]@15
  int v78; // [sp+50h] [bp-6Ch]@15
  int v79; // [sp+54h] [bp-68h]@21
  int v80; // [sp+58h] [bp-64h]@21
  int v81; // [sp+5Ch] [bp-60h]@14
  int v82; // [sp+60h] [bp-5Ch]@14
  char *v83; // [sp+64h] [bp-58h]@14
  int v84; // [sp+68h] [bp-54h]@5
  int v85; // [sp+6Ch] [bp-50h]@1 depth buffer
  int v86; // [sp+70h] [bp-4Ch]@1 color buffer
 } v70;*/

  char v87[40]; // [sp+74h] [bp-48h]@14
  int v88; // [sp+9Ch] [bp-20h]@5
  int v89; // [sp+A0h] [bp-1Ch]@1
  int X; // [sp+A4h] [bp-18h]@3
  int v91; // [sp+A8h] [bp-14h]@21
  int v92; // [sp+ACh] [bp-10h]@1
  int v93; // [sp+B0h] [bp-Ch]@14
  int v94; // [sp+B4h] [bp-8h]@3
  int v95; // [sp+B8h] [bp-4h]@3

  v3 = pSpan->word_00000A;
  v2 = pSpan->word_000008;
  v5 = pSpan->pParent;
  v89 = 0;

  v92 = v2;

  local_30.pDepthBuffer = (unsigned int *)(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A));
  local_30.pColorBuffer = (unsigned int *)(pD3DRenderer->pTargetSurface + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A));
  v68 = dword_6BE050;
  v69 = dword_6BE054;
  if (pSpan->word_00000C >= dword_6BE050 )
    v89 = dword_6BE050 - (v2 & (dword_6BE050 - 1));
  v6 = pSpan->word_00000C - v89;
  v67 = v6 >> dword_6BE054;
  v62 = v6 - (v6 >> dword_6BE054 << dword_6BE054);
  v8 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v92);

  v95 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v92);
  v94 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3);
  v92 = v5->ptr_000038->dword_000014;
  v94 = ((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16;

  v11 = v94 + v5->ptr_000038->dword_00000C;
  v92 = v5->ptr_000038->dword_000020;
  v65 = v11;
  v12 = (((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16) + v5->ptr_000038->dword_000018;
  v94 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3);
  v64 = v12;
  v92 = v5->dword_000020;
  v94 = ((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16;
  v7 = -v5->dword_000024;
  v63 = v94 + v5->dword_000018;
  v66 = -v5->dword_000024;
  v94 = ((unsigned __int64)(v95) * v5->dword_00001C) >> 16;
  X = v94 + v63;
  if (!(v94 + v63))
    return false;
   
  v92 = v7 >> 14;
  v13 = abs(v7 >> 14);
  if (v13 > abs(X))
    return false;

  LODWORD(v16) = v66 << 16;
  HIDWORD(v16) = v66 >> 16;
  v88 = v16 / X;
  local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
  v14 = v16 / X;
  v15 = 2;
  if ( v14 >= dword_6BE0F0 << 16 )
  {
    if ( v14 >= dword_6BE0F4 << 16 )
    {
      if ( v14 >= dword_6BE0F8 << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_14;
        v15 = 3;
        local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal3;
      }
      else
      {
        local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
      }
    }
    else
    {
      v15 = 1;
      local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal1;
    }
  }
  else
  {
    v15 = 0;
    local_30.dword_000038 = (int)v5->ptr_00003C->pIndexedPixels;
  }

  v15 = 0;
  local_30.dword_000038 = (int)v5->ptr_00003C->pTruecolorPixels; // fuck lods and palettes


LABEL_14:
  local_30.dword_000034 = (int)sub_485E1F((int *)v87, pSpan, v14, pSpan->pParent, dword_6BE0E0, 1, 1);

  v93 = v65 + (((unsigned __int64)(v5->ptr_000038->dword_000010) * v8) >> 16);
  v95 = v64 + (((unsigned __int64)(v5->ptr_000038->dword_00001C) * v8) >> 16);

  local_30.dword_000030 = (((unsigned __int64)(v93) * v88) >> 16) - v5->ptr_000038->dword_000024;
  v21 = (((unsigned __int64)(v95) * v88) >> 16) - v5->ptr_000038->dword_000028;

  v18 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  local_30.dword_000030 >>= v18;
  v94 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  local_30.dword_00002C = v21 >> v18;
  if ( byte_80AA10 )
  {
    local_30.dword_000014 = dword_80AA20 >> v18;
    local_30.dword_000018 = dword_80AA1C >> v18;
    local_30.dword_00001C = dword_80AA18 >> v18;
    local_30.dword_000020 = dword_80AA14 >> v18;
  }

  v95 = (signed int)v5->ptr_00003C->uTextureWidth >> v15;
  v23 = (signed int)v5->ptr_00003C->uTextureHeight >> v15;
  v24 = v15 - v5->ptr_00003C->word_00001C + 16;
  local_30.dword_000008 = (v23 << 16) - 65536;
  local_30.dword_00000C = v95 - 1;
  local_30.dword_000010 = v24;
  if ( v89 )
  {
    v27 = v8 - v89 * pStruct9_global->dword_000018;
    v25 = v27;
    v93 = v5->dword_00001C;
    v95 = v27;
    v28 = ((unsigned __int64)(v93) * v27) >> 16;
    v26 = v28 + v63;
    X = v28 + v63;
    if ( !(v28 + v63))
      return false;

    v93 = abs(v92);
    v29 = abs(v26);
     if (v93 > v29)
      return 0;
    LODWORD(v32) = v66 << 16;
    HIDWORD(v32) = v66 >> 16;
    v93 = v32 / X;
    v31 = v32 / X;
    HIWORD(v30) = HIWORD(v88);
    if ( v88 <= v31 )
      HIWORD(v30) = HIWORD(v31);
    LOWORD(v30) = 0;
    v93 = v25;
    local_30.dword_000024 = v30;
    X = v5->ptr_000038->dword_000010;
    X = v65 + (((unsigned __int64)(X) * v25) >> 16);
    v93 = ((unsigned __int64)(X) * v31) >> 16;

    v93 = v25;
    v34 = (((unsigned __int64)(X) * v31) >> 16) - v5->ptr_000038->dword_000024;
    X = v5->ptr_000038->dword_00001C;
    X = v64 + (((unsigned __int64)(X) * v25) >> 16);
    v93 = ((unsigned __int64)(X) * v31) >> 16;
    v35 = (v93 - v5->ptr_000038->dword_000028) >> v94;
    X = v89 << 16;
    v36 = (v34 >> v94) - local_30.dword_000030;
    LODWORD(v37) = v36 << 16;
    HIDWORD(v37) = v36 >> 16;
    v38 = v35 - local_30.dword_00002C;
    local_30.dword_000004 = v37 / (v89 << 16);
    v91 = v89 << 16;
    LODWORD(v37) = v38 << 16;
    HIDWORD(v37) = v38 >> 16;
    v93 = v37 / (v89 << 16);
    local_30.dword_000000 = v37 / (v89 << 16);
    local_30.dword_000028 = v89;
    if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
    {
      if ( byte_80AA10 )
        sub_485A24(&local_30, (sub_485975_stru1 *)v87);
      else
        sub_485975(&local_30, (sub_485975_stru1 *)v87);
    }
    else
    {
      if ( byte_80AA10 )  //v70 here apperas to be passed on stack
        sub_4D705A((int)&local_30);
      else
        sub_4D6FB0((int)&local_30);
    }
    v39 = v95 - (pStruct9_global->dword_000018 << v69);
  }
  else
  {
    v95 = v8 - (pStruct9_global->dword_000018 << v69);
    v39 = v8 - (pStruct9_global->dword_000018 << v69);
  }


  local_30.dword_000028 = v68;
  while ( v67 > 0 )
  {
   v40 = v5->dword_00001C;
    --v67;
    v91 = v40;
    v42 = v40 * v39;
    v95 = v42 >> 16;
    LODWORD(v42) = v42 >> 16;
    v41 = v42 + v63;
    X = v42 + v63;
    if ( !((_DWORD)v42 + v63))
      return false;

    v91 = abs(v92);
    v43 = abs(v41);
    if (v91 > v43)

    LODWORD(v46) = v66 << 16;
    HIDWORD(v46) = v66 >> 16;
    v89 = v46 / X;
    v45 = v46 / X;
    HIWORD(v44) = HIWORD(v88);
    if ( v88 <= v45 )
      HIWORD(v44) = HIWORD(v45);
    LOWORD(v44) = 0;
    v95 = v39;
    local_30.dword_000024 = v44;
    v91 = v5->ptr_000038->dword_000010;
    v91 = v65 + (((unsigned __int64)(v91) * v39) >> 16);
    v95 = ((unsigned __int64)(v91) * v45) >> 16;

    v95 = v39;
    v48 = (((unsigned __int64)(v91) * v45) >> 16) - v5->ptr_000038->dword_000024;
    v91 = v5->ptr_000038->dword_00001C;
    v91 = v64 + (((unsigned __int64)(v91) * v39) >> 16);
    v95 = ((unsigned __int64)(v91) * v45) >> 16;
    v49 = (((v95 - v5->ptr_000038->dword_000028) >> v94) - local_30.dword_00002C) >> v69;
    local_30.dword_000004 = ((v48 >> v94) - local_30.dword_000030) >> v69;
    local_30.dword_000000 = v49;
    if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
    {
      if ( byte_80AA10 )
        sub_485A24(&local_30, (sub_485975_stru1 *)v87);
      else
        sub_485975(&local_30, (sub_485975_stru1 *)v87);
    }
    else
    {
      if ( byte_80AA10 )
        sub_4D705A((int)&local_30);
      else
        sub_4D6FB0((int)&local_30);
    }
    local_30.dword_000034 = (int)sub_485E1F((int *)v87, pSpan, v89, v5, dword_6BE0E0, 1u, 0);
    local_30.dword_000028 = v68;
    v39 -= pStruct9_global->dword_000018 << v69;
  }
  if ( !v62 )
    return true;

  v50 = v5->dword_00001C;
  v91 = v50;
  v52 = v50 * v39;
  v95 = v52 >> 16;
  LODWORD(v52) = v52 >> 16;
  v51 = v52 + v63;
  X = v52 + v63;
  if ( (_DWORD)v52 + v63 )
  {
    v91 = abs(v92);
    v53 = abs(v51);
    if ( v91 <= v53 )
    {
      LODWORD(v56) = v66 << 16;
      HIDWORD(v56) = v66 >> 16;
      v92 = v56 / X;
      v55 = v56 / X;
      HIWORD(v54) = HIWORD(v88);
      if ( v88 <= v55 )
        HIWORD(v54) = HIWORD(v55);
      LOWORD(v54) = 0;
      v92 = v39;
      local_30.dword_000024 = v54;
      v91 = v5->ptr_000038->dword_000010;
      v91 = v65 + (((unsigned __int64)(v91) * v39) >> 16);
      v92 = ((unsigned __int64)(v91) * v55) >> 16;

      v92 = v39;
      v58 = (((unsigned __int64)(v91) * v55) >> 16) - v5->ptr_000038->dword_000024;
      v91 = v5->ptr_000038->dword_00001C;
      v91 = v64 + (((unsigned __int64)(v91) * v39) >> 16);
      v92 = ((unsigned __int64)(v91) * v55) >> 16;
      v59 = (((v92 - v5->ptr_000038->dword_000028) >> v94) - local_30.dword_00002C) >> v69;
      local_30.dword_000004 = ((v58 >> v94) - local_30.dword_000030) >> v69;
      local_30.dword_000000 = v59;
      local_30.dword_000028 = v62;
      if (byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
      {
        if ( byte_80AA10 )
          sub_485A24(&local_30, (sub_485975_stru1 *)v87);
        else
          sub_485975(&local_30, (sub_485975_stru1 *)v87);
      }
      else
      {
        if ( byte_80AA10 )
          sub_4D705A((int)&local_30);
        else
          sub_4D6FB0((int)&local_30);
      }
      return true;
    }
  }
  return false;
}

//----- (00485044) --------------------------------------------------------
signed int __fastcall sub_485044(struct Span *pSpan, struct struct8 *a2, int a3)
{
  float v5; // ST2C_4@1
  signed int result; // eax@2
  int v7; // eax@3
  int v8; // edx@3
  int v9; // ecx@3
  int v10; // ebx@3
  int v11; // ST40_4@3
  int v13; // ST28_4@5
  int v14; // eax@5
  int v15; // eax@11
  int v16; // edi@11
  unsigned int v17; // esi@11
  signed __int64 v18; // qtt@11
  int v19; // ST28_4@11
  int v20; // eax@11
  signed int v21; // ecx@11
  int v22; // ST40_4@11
  int v23; // ST3C_4@11
  int v24; // ST30_4@11
  char *v25; // eax@11
  int v28; // ebx@12
  int v29; // edx@13
  __int16 v30; // cx@13
  int v31; // edx@14
  __int16 v32; // cx@14
  signed int v37; // [sp+18h] [bp-34h]@11
  signed int v39; // [sp+1Ch] [bp-30h]@11
  int v40; // [sp+20h] [bp-2Ch]@3
  short *v41;
  int v42; // [sp+24h] [bp-28h]@3
  int v43; // [sp+24h] [bp-28h]@11
  int v44; // [sp+28h] [bp-24h]@11
  int v45; // [sp+2Ch] [bp-20h]@3
  signed int v46; // [sp+30h] [bp-1Ch]@3
  int v47; // [sp+30h] [bp-1Ch]@11
  signed int v48; // [sp+34h] [bp-18h]@3
  int v49; // [sp+34h] [bp-18h]@11
  int v50; // [sp+38h] [bp-14h]@3
  int v51; // [sp+38h] [bp-14h]@11
  int v52; // [sp+3Ch] [bp-10h]@4
  int v53; // [sp+40h] [bp-Ch]@3
  int v54; // [sp+44h] [bp-8h]@3
  int v55; // [sp+48h] [bp-4h]@3
  int v56; // [sp+54h] [bp+8h]@11
  int v57; // [sp+54h] [bp+8h]@11

  v5 = (double)(pOldViewport->uGameZ - pOldViewport->uGameX) * 0.5 / tan(0.64577174186706543) + 0.5;
  if ((int)(floorf(v5 + 0.5f)))
  {
    v55 = 65536 / floorf(v5 + 0.5f);
    v11 = 65536 / floorf(v5 + 0.5f) * (a3 - pSpan->word_00000A);

    v42 = (((unsigned __int64)(a2->ptr_000038->dword_000014) * v11) / 65536) + a2->ptr_000038->dword_00000C;
    v40 = (((unsigned __int64)(a2->ptr_000038->dword_000020) * v11) / 65536) + a2->ptr_000038->dword_000018;
    v45 = pSpan->word_00000C;
    v10 = (((unsigned __int64)(a2->dword_000020) * v11) / 65536) + a2->dword_000018;
    v9 = 65536 / floorf(v5 + 0.5f) * (pOldViewport->dword_000028 - pSpan->word_000008);
    v48 = 0;
    v50 = 65536 / floorf(v5 + 0.5f) * (pOldViewport->dword_000028 - pSpan->word_000008);
    v46 = -a2->dword_000024;
    v8 = pSpan->word_00000A - 1;
    v54 = v8;
    v7 = 65536 / floorf(v5 + 0.5f) * (a3 - v8);
    v53 = 65536 / floorf(v5 + 0.5f) * (a3 - v8);
    while ( 1 )
    {
      v52 = v10;
      if ( v10 )
      {
        v13 = abs(v46 >> 14);
        v14 = abs(v10);
        v8 = v54;
        v9 = v50;
        if ( v13 <= v14 )
          break;
        v7 = v53;
      }
      if ( v8 <= pOldViewport->uGameY )
        break;
      v10 = (((unsigned __int64)(a2->dword_000020) * v7) / 65536) + a2->dword_000018;
      --v54;
      v53 += v55;
      v7 = v53;
      v8 = v54;
      v48 = 1;
    }

    if ( v48 )
     v52 = (((unsigned __int64)(a2->dword_000020) * v55 * (a3 + (signed int)pSpan->word_00000A - 2 * v8)) >> 16)
      + a2->dword_000018;
    LODWORD(v18) = v46 << 16;
    HIDWORD(v18) = v46 >> 16;
    v19 = v42 + (((unsigned __int64)(a2->ptr_000038->dword_000010) * v9) >> 16);
    v20 = v40 + (((unsigned __int64)(a2->ptr_000038->dword_00001C) * v9) >> 16);
    v21 = v18 / v52;
    //v43 = a2->ptr_00003C->dword_000030;
    v43 = (int)a2->ptr_00003C->pTruecolorPixels;
    v22 = a2->dword_000028 + ((signed int)(((unsigned __int64)(v19) * (signed int)(v18 / v52)) >> 16) >> 3);
    v57 = v18 / v52;
    v23 = a2->dword_00002C + ((signed int)(((unsigned __int64)(v20) * (signed int)(v18 / v52)) >> 16) >> 3);
    v24 = ((unsigned __int64)(v55) * v57) >> 16;
    v39 = (signed int)(((unsigned __int64)(v24) * pStruct9_global->camera_rotation_y_int_sine) >> 16) >> 3;
    v37 = (signed int)(((unsigned __int64)(v24) * pStruct9_global->camera_rotation_y_int_cosine) >> 16) >> 3;
    v25 = (char *)sub_47C178(v21, a2, 0, 1);

    v41 = (short *)v25;
    v47 = 16 - a2->ptr_00003C->word_00001C;
    v44 = a2->ptr_00003C->uTextureWidth - 1;
    v49 = ((unsigned int)(a2->ptr_00003C->uTextureHeight) << 16) - 65536;

    v51 = (int)(pD3DRenderer->pTargetSurface + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A));
    v56 = (int)(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A));

    v17 = v22;
    v16 = v23;
    v15 = v51;
    if ( !(v45 & 1) )
      goto LABEL_15;
    --v45;
    v15 = v51 - 2;
    v28 = v56;
    v56 += 4;
    while ( 1 )
    {
      *(_DWORD *)v28 = -65536;
      v31 = v44 & (v17 >> 16);
      v15 += 8;
      v17 += v39;
      v32 = v41[2 * *(_BYTE *)(v43 + v31 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      *(_DWORD *)(v15 - 4) = v32;
LABEL_15:
      //v34 = __SETO__(v45, 2);
      //v33 = v45 - 2 < 0;
      if (v45 < 2)
        break;
      v45 -= 2;
      v29 = v44 & (v17 >> 16);
      v17 += v39;
      v30 = v41[2 * *(_BYTE *)(v43 + v29 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      v28 = v56;
      *(_DWORD *)v15 = v30;
      v56 += 8;
      *(_DWORD *)(v28 + 4) = -65536;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (0048585C) --------------------------------------------------------
bool sub_48585C_MaybeDrawSpan(struct Span *pSpan, unsigned int *pRenderTarget, int a3)
{
  struct struct8 *v3; // edi@1
  int v5; // ebx@2
  signed int v6; // ecx@3
  signed __int64 v8; // qtt@3
  short *v10; // eax@5
  int v11; // ecx@5
  signed int v13; // [sp+10h] [bp-10h]@1
  int v14; // [sp+18h] [bp-8h]@1

  v3 = pSpan->pParent;
  v13 = -v3->dword_000024;
  v14 = (((unsigned __int64)(pStruct9_global->dword_000018) * v3->dword_00001C * (pOldViewport->dword_000028 - (signed int)pSpan->word_000008)) / 65536) +
        (((unsigned __int64)(pStruct9_global->dword_000018) * v3->dword_000020 * (pOldViewport->dword_00002C - (signed int)pSpan->word_00000A)) / 65536) + v3->dword_000018;

  v5 = abs(-v3->dword_000024 >> 14);
  if ( v14 && v5 <= abs(v14))
  {
    LODWORD(v8) = v13 << 16;
    HIDWORD(v8) = v13 >> 16;
    v6 = v8 / v14;
  }
  else
  {
    v6 = pStruct9_global->shading_dist_mist << 16;
  }
  v10 = sub_47C178(v6, v3, dword_6BE0E0, a3);

  sub_452AF3(v10[v3->ptr_00003C->uDecompressedSize], pRenderTarget, pSpan->word_00000C);
  HIWORD(v11) = HIWORD(v6);
  LOWORD(v11) = 0;
  memset_dw(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A), v11, pSpan->word_00000C);

  return true;
}


//----- (00485E1F) --------------------------------------------------------
char *__fastcall sub_485E1F(int *a1, struct Span *pSpan, signed int a3, struct struct8 *a4, int a5, unsigned __int8 a6, char a7)
{
  char v10; // zf@1
  int v11; // eax@1
  char *v16; // eax@4
  signed int v17; // ST14_4@4
  char v18; // dl@4
  signed int v19; // ST10_4@4
  signed int v20; // ST14_4@5
  char v21; // dl@5
  int v22; // ST10_4@5
  signed int v24; // ST14_4@6
  char v25; // dl@6
  char v27; // [sp+16h] [bp-2h]@1
  char v28; // [sp+17h] [bp-1h]@1

  runtime_warning(suspicious decompilation)


  v10 = a1[0] == 0;
  v27 = a1[1] != 0;
  v28 = !v10;
  sub_47BEB1(a3, a4, a5, 0, (int)&a1[2], &a1[3], (char *)&v27, (char *)&v28);
  a1[9] = (int)sub_47C28C((int)a4, v28, a1[2], a1[3]);
  v11 = a4->byte_000108;
  a1[8] = v11;
  if ( v11 )
  {
    if ( a7 )
    {
      a1[4] = floorf(pSpan->flt_000010 * 31.0 + 0.5f) * 65536;
      a1[5] = floorf(pSpan->flt_000014 * 31.0 + 0.5f) * 65536;
      a1[6] = -((a1[4] - a1[5]) / pSpan->word_00000C);
    }
    v17 = a1[3];
    v18 = v28;
    v19 = a1[2];
    a1[7] = a6;
    v16 = (char *)sub_47C28C((int)a4, v18, v19, v17);
  }
  else
  {
    v20 = a1[3];
    v21 = v28;
    a1[4] = 0;
    a1[5] = 0;
    v22 = a1[2];
    a1[6] = 0;
    a1[7] = 0;
    v16 = sub_47C1CA(a4, v21, v22, v20);
  }
  v24 = a1[3];
  v25 = v28;
  a1[9] = (int)v16;
  return sub_47C1CA(a4, v25, a1[2], v24);
}

//----- (00485407) --------------------------------------------------------
signed int __fastcall sub_485407(int a1)
{
  int v1; // ebx@1
  int ebp0; // ebp@0
  signed int v3; // edi@1
  int v4; // esi@1
  int v5; // eax@1
  int v6; // edx@1
  int v7; // edi@1
  int v8; // ecx@1
  int v9; // ecx@1
  int v10; // eax@1
  int v11; // eax@1
  int v12; // edx@1
  int v13; // eax@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // edi@2
  int v17; // eax@3
  signed int v18; // edi@3
  signed __int64 v19; // qtt@3
  int v20; // eax@3
  int v21; // eax@4
  int v22; // eax@6
  int v23; // eax@8
  int v24; // eax@10
  signed int v25; // ebx@13
  signed int v26; // edi@13
  int v27; // eax@13
  int v28; // eax@13
  signed int v29; // ebx@13
  int v30; // eax@13
  int v31; // esi@13
  signed int v32; // edx@13
  signed int v33; // eax@13
  int v34; // esi@13
  int v35; // eax@13
  unsigned __int64 v36; // qax@13
  int v37; // eax@13
  unsigned __int64 v38; // qax@13
  int v39; // ecx@14
  char v40; // zf@20
  char v42; // [sp+Ch] [bp-90h]@13
  int v43; // [sp+34h] [bp-68h]@13
  int v44; // [sp+38h] [bp-64h]@13
  int v45; // [sp+3Ch] [bp-60h]@13
  int v46; // [sp+40h] [bp-5Ch]@13
  int v47; // [sp+44h] [bp-58h]@13
  int v48; // [sp+58h] [bp-44h]@3
  int v49; // [sp+5Ch] [bp-40h]@13
  int v50; // [sp+60h] [bp-3Ch]@16
  int v51; // [sp+64h] [bp-38h]@16
  char *v52; // [sp+68h] [bp-34h]@13
  int v53; // [sp+6Ch] [bp-30h]@3
  int v54; // [sp+70h] [bp-2Ch]@1
  int v55; // [sp+74h] [bp-28h]@1
  int v56; // [sp+78h] [bp-24h]@1
  int v57; // [sp+7Ch] [bp-20h]@1
  int v58; // [sp+80h] [bp-1Ch]@1
  int v59; // [sp+84h] [bp-18h]@1
  int v60; // [sp+88h] [bp-14h]@1
  int v61; // [sp+8Ch] [bp-10h]@1
  int v62; // [sp+90h] [bp-Ch]@3
  int i; // [sp+94h] [bp-8h]@3
  int X; // [sp+98h] [bp-4h]@1

  v5 = *(_WORD *)(a1 + 10);
  v6 = *(_WORD *)(a1 + 8);
  v7 = v6 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(a1 + 10);
  v4 = *(_DWORD *)(a1 + 4);
  v56 = a1;
  v8 = *(_WORD *)(a1 + 12);
  v55 = (int)(pD3DRenderer->pTargetSurface + v7);
  v59 = v8;
  v1 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v6);
  v9 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v5);
  v54 = (int)(pD3DRenderer->pActiveZBuffer + (v6 + 640 * v5));
  v10 = *(_DWORD *)(v4 + 56);
  v60 = v1;
  X = v9;
  v61 = *(_DWORD *)(v10 + 20);
  X = (unsigned __int64)(v61 * v9) >> 16;
  v11 = *(_DWORD *)(v4 + 56);
  v12 = X + *(_DWORD *)(v11 + 12);
  v61 = *(_DWORD *)(v11 + 32);
  v57 = v12;
  v13 = ((unsigned __int64)(v61 * v9) >> 16) + *(_DWORD *)(*(_DWORD *)(v4 + 56) + 24);
  X = v9;
  v58 = v13;
  v61 = *(_DWORD *)(v4 + 32);
  X = (unsigned __int64)(v61 * v9) >> 16;
  v14 = *(_DWORD *)(v4 + 28);
  v15 = X + *(_DWORD *)(v4 + 24);
  v3 = -*(_DWORD *)(v4 + 36);
  v61 = -*(_DWORD *)(v4 + 36);
  X = ((unsigned __int64)(v1 * v14) >> 16) + v15;
  if ( !X || (v16 = abs(v3 >> 14), v16 > abs(X)) )
    return 0;
  LODWORD(v19) = v61 << 16;
  HIDWORD(v19) = v61 >> 16;
  i = v19 / X;
  v18 = v19 / X;
  HIWORD(v20) = (unsigned int)(v19 / X) >> 16;
  LOWORD(v20) = 0;
  v48 = v20;
  v17 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  v53 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  v62 = 2;
  if ( v18 >= dword_6BE0F0 << 16 )
  {
    if ( v18 >= dword_6BE0F4 << 16 )
    {
      if ( v18 >= dword_6BE0F8 << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v24 = *(_DWORD *)(v4 + 60);
        v62 = 3;
        v17 = *(_DWORD *)(v24 + 60);
      }
      else
      {
        v23 = *(_DWORD *)(v4 + 60);
        v62 = 2;
        v17 = *(_DWORD *)(v23 + 56);
      }
    }
    else
    {
      v22 = *(_DWORD *)(v4 + 60);
      v62 = 1;
      v17 = *(_DWORD *)(v22 + 52);
    }
  }
  else
  {
    v21 = *(_DWORD *)(v4 + 60);
    v62 = 0;
    v17 = *(_DWORD *)(v21 + 48);
  }
  v53 = v17;
LABEL_12:
  if ( !v17 )
    return 0;
  v52 = sub_485E1F((int *)&v42, (Span *)v56, v18, (struct8 *)v4, dword_6BE0E0, 1u, 1);
  v49 = 16;
  v56 = v59 >> 4;
  X = v1;
  v27 = *(_DWORD *)(v4 + 56);
  v61 = v59 - 16 * (v59 >> 4);
  v59 = *(_DWORD *)(v27 + 16);
  X = v1;
  v59 = v57 + ((unsigned __int64)(v59 * v1) >> 16);
  v57 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 28);
  v58 += (unsigned __int64)(v57 * v1) >> 16;
  X = (unsigned __int64)(v59 * v18) >> 16;
  v28 = *(_DWORD *)(v4 + 56);
  X = v18;
  v29 = ((unsigned __int64)(v59 * v18) >> 16) - *(_DWORD *)(v28 + 36);
  X = (unsigned __int64)(v58 * v18) >> 16;
  v30 = *(_DWORD *)(v4 + 56);
  v31 = *(_DWORD *)(v4 + 60);
  v57 = (unsigned __int8)bUseLoResSprites + v62 + 2;
  v25 = v29 >> v57;
  v26 = (signed int)(((unsigned __int64)(v58 * v18) >> 16) - *(_DWORD *)(v30 + 40)) >> v57;
  v32 = (signed int)*(_WORD *)(v31 + 24) >> v62;
  v33 = (signed int)*(_WORD *)(v31 + 26) >> v62;
  v34 = v62 - *(_WORD *)(v31 + 28);
  v45 = (v33 << 16) - 65536;
  X = 2 * cClock2.dword_000024;
  v58 = pStruct9_global->dword_000018;
  v47 = v34 + 16;
  v46 = v32 - 1;
  i = (unsigned __int64)(pStruct9_global->dword_000018 * i) >> 16;
  v60 = i >> v57;
  v35 = class59_SinCos(pClass59_global, pOldCamera->sRotationY - pClass59_global->uIntegerHalfPi);
  v36 = v60 * v35;
  i = v36 >> 16;
  v44 = v36 >> 16;
  v37 = class59_SinCos(pClass59_global, pOldCamera->sRotationY);
  v38 = v60 * v37;
  i = v38 >> 16;
  v43 = v38 >> 16;
  if ( v56 > 0 )
  {
    v60 = v56;
    v39 = 12 - v62;
    for ( i = 12 - v62; ; LOBYTE(v39) = i )
    {
      v51 = v25 + 4 * class59_SinCos(pClass59_global, X + (v26 >> v39));
      v50 = v26 + 4 * class59_SinCos(pClass59_global, X + (v25 >> i) - pClass59_global->uIntegerHalfPi);
      if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
        sub_485975((sub_485975_stru0 *)&v43, (sub_485975_stru1 *)&v42);
      else
        sub_4D6FB0(ebp0);
      v49 = 16;
      v25 += 16 * v44;
      v26 += 16 * v43;
      v40 = v60-- == 1;
      if ( v40 )
        break;
    }
  }
  if ( v61 )
  {
    i = 12 - v62;
    v51 = v25 + 4 * class59_SinCos(pClass59_global, X + (v26 >> (12 - v62)));
    v50 = v26 + 4 * class59_SinCos(pClass59_global, X + (v25 >> i) - pClass59_global->uIntegerHalfPi);
    v49 = v61;
    if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
      sub_485975((sub_485975_stru0 *)&v43, (sub_485975_stru1 *)&v42);
    else
      sub_4D6FB0(ebp0);
  }
  return 1;
}


//----- (00482E07) --------------------------------------------------------
bool sub_482E07(struct Span *pSpan, unsigned int *pRenderTarget)
{
  int v2; // eax@1
  int ebp0; // ebp@0
  struct struct8 *v5;
  int v4; // edi@1
  int v6; // edi@1
  int v7; // edi@1
  int v10; // edx@1
  int v11; // eax@1
  int v12; // eax@1
  unsigned __int64 v13; // qax@1
  signed __int64 v14; // qtt@3
  int v15; // ebx@4
  int v16; // eax@5
  signed __int64 v17; // qtt@5
  int v23; // ebx@17
  int v24; // ecx@17
  signed int v26; // edx@17
  signed int v27; // eax@17
  int v30; // eax@18
  int v33; // edi@21
  signed int v34; // ecx@22
  signed __int64 v35; // qtt@22
  int v36; // eax@24
  int v38; // edi@24
  int v39; // eax@24
  int v41; // edi@35
  signed __int64 v42; // qtt@36
  int v43; // edx@36
  int v45; // edi@36
  int v46; // eax@36
  int v50; // eax@44
  int v53; // edi@46
  signed int v54; // ecx@47
  signed __int64 v55; // qtt@47
  int v56; // eax@49
  int v58; // edi@49
  int v59; // eax@49
  int v61; // edi@60
  signed __int64 v62; // qtt@61
  int v63; // edx@61
  int v65; // edi@61
  int v66; // eax@61
  int v68; // [sp+Ch] [bp-B8h]@1
  int v69; // [sp+10h] [bp-B4h]@1
  int v70; // [sp+14h] [bp-B0h]@1
  int v71; // [sp+18h] [bp-ACh]@1
  int v72; // [sp+1Ch] [bp-A8h]@5
  int v73; // [sp+20h] [bp-A4h]@1
  signed int v74; // [sp+24h] [bp-A0h]@1

  struct sub_485975_stru1 local_28;
  //char v75; // [sp+28h] [bp-9Ch]@18

  int v76; // [sp+50h] [bp-74h]@17

  struct sub_485975_stru0 local_54;
  /*float v77; // [sp+54h] [bp-70h]@24
  int v78; // [sp+58h] [bp-6Ch]@24
  int v79; // [sp+5Ch] [bp-68h]@17
  int v80; // [sp+60h] [bp-64h]@17
  int v81; // [sp+64h] [bp-60h]@17
  int v82; // [sp+68h] [bp-5Ch]@18
  int v83; // [sp+6Ch] [bp-58h]@18
  int v84; // [sp+70h] [bp-54h]@18
  int v85; // [sp+74h] [bp-50h]@18
  int v86; // [sp+78h] [bp-4Ch]@5
  int v87; // [sp+7Ch] [bp-48h]@24
  int v88; // [sp+80h] [bp-44h]@18
  int v89; // [sp+84h] [bp-40h]@18
  char *v90; // [sp+88h] [bp-3Ch]@18
  int v91; // [sp+8Ch] [bp-38h]@7
  int v92; // [sp+90h] [bp-34h]@18
  int v93; // [sp+94h] [bp-30h]@18
  */
  int v95; // [sp+9Ch] [bp-28h]@1
  int v96; // [sp+A0h] [bp-24h]@17
  int v97; // [sp+A4h] [bp-20h]@3
  int v98; // [sp+A8h] [bp-1Ch]@3
  int v99; // [sp+ACh] [bp-18h]@1
  int X; // [sp+B0h] [bp-14h]@2
  int v101; // [sp+B4h] [bp-10h]@1
  int v102; // [sp+B8h] [bp-Ch]@1
  int v103; // [sp+BCh] [bp-8h]@1
  int v104; // [sp+C0h] [bp-4h]@18

  v103 = pSpan->word_00000C;
  v5 = pSpan->pParent;
  v6 = pOldViewport->dword_00002C - pSpan->word_00000A;
  v95 = (int)pRenderTarget;
  v7 = pStruct9_global->dword_000018 * v6;

  v101 = pSpan->pParent->ptr_000038->dword_000014;
  v99 = (unsigned __int64)(v101) * v7 / 65536;

  v10 = v99 + pSpan->pParent->ptr_000038->dword_00000C;
  v101 = pSpan->pParent->ptr_000038->dword_000020;
  v69 = v10;
  v11 = ((unsigned __int64)(v101) * v7 / 65536) + v5->ptr_000038->dword_000018;

  v73 = v11;
  v101 = pSpan->pParent->dword_000020;
  v99 = (unsigned __int64)(v101) * v7 / 65536;
  v70 = v5->dword_000028 << 16;
  v71 = v5->dword_00002C << 16;
  v74 = -v5->dword_000024;
  v4 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - pSpan->word_000008);
  v12 = v5->dword_00001C;
  v68 = v99 + v5->dword_000018;
  v101 = v4;
  v13 = v4 * v12;
  v99 = v13 >> 16;
  v2 = v68 + (v13 >> 16);
  v102 = v2;
  if (!v2)
    return false;

  X = v74 >> 15;
  v101 = abs(v2);
  if (abs(v74 >> 15) >= v101)
    return false;

  LODWORD(v14) = v74 << 16;
  HIDWORD(v14) = v74 >> 16;
  v97 = v14 / v102;
  v98 = v4 - v103 * pStruct9_global->dword_000018;
  v99 = (unsigned __int64)(v98) * v5->dword_00001C / 65536;
  v102 = v68 + v99;
  if (!(v68 + v99))
    return false;

  v15 = abs(v68 + v99);
  if (abs(X) >= v15)
    return false;

  LODWORD(v17) = v74 << 16;
  HIDWORD(v17) = v74 >> 16;
  v72 = v17 / v102;
  v16 = v17 / v102;
  local_54.dword_000024 = v97;
  if ( v97 >= v16 )
    local_54.dword_000024 = v16;
  local_54.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
  v102 = 2;
  if (local_54.dword_000024 >= dword_6BE0E4 << 16 )
  {
    if (local_54.dword_000024 >= dword_6BE0E8 << 16 )
    {
      if (local_54.dword_000024 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_16;
        v102 = 3;
        local_54.dword_000038 =  (int)v5->ptr_00003C->pLevelOfDetal3;
      }
      else
      {
        v102 = 2;
        local_54.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
      }
    }
    else
    {
      v102 = 1;
      local_54.dword_000038 = (int) v5->ptr_00003C->pLevelOfDetal1;
    }
  }
  else
  {
    v102 = 0;
    local_54.dword_000038 = (int)v5->ptr_00003C->pIndexedPixels;
  }

  v102 = 0;
  local_54.dword_000038 = (int)v5->ptr_00003C->pTruecolorPixels;


LABEL_16:
  if (!local_54.dword_000038)
    return false;

   v24 = v5->byte_00005A;
    v101 = v5->word_000052;

    v76 = v24;
    v96 = v103 >> v24;
    v26 = v5->ptr_00003C->uTextureWidth;
    v99 = v103 - (v103 >> v24 << v24);
    v27 = (signed int)v5->ptr_00003C->uTextureHeight >> v102;
    local_54.dword_000010 = v102 - v5->ptr_00003C->word_00001C + 16;
    v23 = v102 + (unsigned __int8)bUseLoResSprites;
    local_54.dword_000008 = (v27 << 16) - 65536;
    local_54.dword_00000C = (v26 >> v102) - 1;
    if ( v97 >= v72 )
    {
      local_54.dword_000034 = (int)sub_485E1F((int *)&local_28, pSpan, v72, v5, dword_6BE0DC, 0, 1);
      v97 = v98;

      v104 = v5->ptr_000038->dword_000010;
      v97 = v98;
      v102 = v69 + (((unsigned __int64)(v104) * v98) >> 16);
      v104 = v5->ptr_000038->dword_00001C;
      v104 = v73 + (((unsigned __int64)(v104) * v98) >> 16);
      v97 = ((unsigned __int64)(v102) * v72) >> 16;

      v97 = v72;
      local_54.dword_000030 = v70 + (((unsigned __int64)(v102) * v72) >> 16) - v5->ptr_000038->dword_000024;
      v97 = ((unsigned __int64)(v104) * v72) >> 16;
      v50 = (((unsigned __int64)(v104) * v72) >> 16) - v5->ptr_000038->dword_000028;
      local_54.dword_000030 >>= v23;
      local_54.dword_00002C = (v71 + v50) >> v23;
      local_54.dword_000014 = dword_80AA20 >> v23;
      local_54.dword_000018 = dword_80AA1C >> v23;
      local_54.dword_00001C = dword_80AA18 >> v23;

      local_54.dword_000020 = dword_80AA14 >> v23;

      local_54.pDepthBuffer = (unsigned int *)(pD3DRenderer->pActiveZBuffer + v103 + (pSpan->word_000008 + 640 * pSpan->word_00000A) - 1);
      local_54.pColorBuffer = (unsigned int *)(pRenderTarget + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A) - 1);
      v98 += pStruct9_global->dword_000018 << v76;
      if ( v96 > 0 )
      {
        do
        {
          v95 = v5->dword_00001C;
          v104 = ((unsigned __int64)(v95) * v98) >> 16;
          v102 = v68 + (((unsigned __int64)(v95) * v98) >> 16);
          if ( v68 + (unsigned int)(((unsigned __int64)(v95) * v98) >> 16)
            && (v53 = abs((int)(v68 + (((unsigned __int64)(v95) * v98) >> 16))), abs(X) < v53) )
          {
            LODWORD(v55) = v74 << 16;
            HIDWORD(v55) = v74 >> 16;
            v104 = v55 / v102;
            v54 = v55 / v102;
            v102 = v55 / v102;
          }
          else
          {
            v102 = 1073741824;
            v54 = 1073741824;
          }
          HIWORD(v56) = HIWORD(v54);
          LOWORD(v56) = 0;
          local_54.dword_000024 = v5->word_000050 | v56;
          v95 = v5->ptr_000038->dword_000010;
          v95 = v69 + (((unsigned __int64)(v95) * v98) >> 16);
          v104 = ((unsigned __int64)(v95) * v54) >> 16;

          v58 = (((unsigned __int64)(v95) * v54) >> 16) - v5->ptr_000038->dword_000024;
          v95 = v5->ptr_000038->dword_00001C;
          v95 = v73 + (((unsigned __int64)(v95) * v98) >> 16);
          v104 = ((unsigned __int64)(v95) * v54) >> 16;
          v59 = (((v71 + v104 - v5->ptr_000038->dword_000028) >> v23) - local_54.dword_00002C) >> v76;
          local_54.dword_000004 = (((v70 + v58) >> v23) - local_54.dword_000030) >> v76;
          local_54.dword_000000 = v59;
          local_54.dword_000028 = v101;
          if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
          {
           if (v5->ptr_000054->byte_00012F == 1)
              sub_485BAE((int)&local_54, (int)&local_28);
            else
              sub_485AFF((int)&local_54, (int)&local_28);
          }
          else
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_4D71F8(ebp0);
            else
              sub_4D714C(ebp0);
          }
          local_54.dword_000034 = (int)sub_485E1F((int *)&local_28, pSpan, v102, v5, dword_6BE0DC, 0, 0);
          v98 += pStruct9_global->dword_000018 << v76;
        }
        while ( v96-- != 1 );
      }
      if ( !v99 )
        return true;

      v101 = v5->dword_00001C;
      v104 = ((unsigned __int64)(v101) * v98) >> 16;
      v102 = v68 + (((unsigned __int64)(v101) * v98) >> 16);
      if ( v68 + (unsigned int)(((unsigned __int64)(v101) * v98) >> 16) )
      {
        v61 = abs((int)(v68 + (((unsigned __int64)(v101) * v98) >> 16)));
        if ( abs(X) < v61 )
        {
          LODWORD(v62) = v74 << 16;
          HIDWORD(v62) = v74 >> 16;
          v104 = v62 / v102;
          HIWORD(v63) = (unsigned int)(v62 / v102) >> 16;
          LOWORD(v63) = 0;
          local_54.dword_000024 = v63 | v5->word_000050;
          v101 = v5->ptr_000038->dword_000010;
          v101 = v69 + ((unsigned __int64)(v101 * v98) >> 16);
          v104 = ((unsigned __int64)(v101) * (signed int)(v62 / v102)) >> 16;

          v65 = (((unsigned __int64)(v101) * (signed int)(v62 / v102)) >> 16) - v5->ptr_000038->dword_000024;
          v101 = v5->ptr_000038->dword_00001C;
          v101 = v73 + (((unsigned __int64)(v101) * v98) >> 16);
          v104 = ((unsigned __int64)(v101) * (signed int)(v62 / v102)) >> 16;
          v66 = (((signed int)(v71
                             + (((unsigned __int64)(v101) * (signed int)(v62 / v102)) >> 16)
                             - v5->ptr_000038->dword_000028) >> v23)
               - local_54.dword_00002C) >> v76;
          local_54.dword_000004 = (((v70 + v65) >> v23) - local_54.dword_000030) >> v76;
          local_54.dword_000000 = v66;
          local_54.dword_000028 = v99;
          if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_485BAE((int)&local_54, (int)&local_28);
            else
              sub_485AFF((int)&local_54, (int)&local_28);
          }
          else
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_4D71F8(ebp0);
            else
              sub_4D714C(ebp0);
          }
          return 1;
        }
      }
    }
    else
    {
      local_54.dword_000034 = (int)sub_485E1F((int *)&local_28, pSpan, v97, v5, dword_6BE0DC, 1u, 1);

      v103 = v4;
      v104 = v5->ptr_000038->dword_000010;
      v103 = v4;
      v102 = v69 + (((unsigned __int64)(v104) * v4) >> 16);
      v104 = v5->ptr_000038->dword_00001C;
      v104 = v73 + (((unsigned __int64)(v104) * v4) >> 16);
      v103 = ((unsigned __int64)(v102) * v97) >> 16;

      v103 = v97;
      local_54.dword_000030 = v70 + (((unsigned __int64)(v102) * v97) >> 16) - v5->ptr_000038->dword_000024;
      v103 = ((unsigned __int64)(v104) * v97) >> 16;
      v30 = (((unsigned __int64)(v104) * v97) >> 16) - v5->ptr_000038->dword_000028;
      local_54.dword_000030 >>= v23;
      local_54.dword_00002C = (v71 + v30) >> v23;
      local_54.dword_000014 = dword_80AA20 >> v23;
      local_54.dword_000018 = dword_80AA1C >> v23;
      local_54.dword_00001C = dword_80AA18 >> v23;
      local_54.dword_000020 = dword_80AA14 >> v23;

      v104 = pSpan->word_000008;
      local_54.pColorBuffer = pRenderTarget + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A);
      local_54.pDepthBuffer = (unsigned int *)(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A));

      v98 = v4 - (pStruct9_global->dword_000018 << v76);
      if ( v96 > 0 )
      {
        v104 = v96;
        do
        {
          v96 = v5->dword_00001C;
          v103 = ((unsigned __int64)(v96) * v98) >> 16;
          v102 = v68 + (((unsigned __int64)(v96) * v98) >> 16);
          if ( v68 + (unsigned int)(((unsigned __int64)(v96) * v98) >> 16)
            && (v33 = abs((int)(v68 + (((unsigned __int64)(v96) * v98) >> 16))), abs(X) < v33) )
          {
            LODWORD(v35) = v74 << 16;
            HIDWORD(v35) = v74 >> 16;
            v103 = v35 / v102;
            v34 = v35 / v102;
            v102 = v35 / v102;
          }
          else
          {
            v102 = 1073741824;
            v34 = 1073741824;
          }
          HIWORD(v36) = HIWORD(v34);
          LOWORD(v36) = 0;
          local_54.dword_000024 = v5->word_000050 | v36;
          v96 = v5->ptr_000038->dword_000010;
          v96 = v69 + (((unsigned __int64)(v96) * v98) >> 16);
          v103 = ((unsigned __int64)(v96) * v34) >> 16;

          v38 = (((unsigned __int64)(v96) * v34) >> 16) - v5->ptr_000038->dword_000024;
          v96 = v5->ptr_000038->dword_00001C;
          v96 = v73 + (((unsigned __int64)(v96) * v98) >> 16);
          v103 = ((unsigned __int64)(v96) * v34) >> 16;
          v39 = (((v71 + v103 - v5->ptr_000038->dword_000028) >> v23) - local_54.dword_00002C) >> v76;
          local_54.dword_000004 = (((v70 + v38) >> v23) - local_54.dword_000030) >> v76;
          local_54.dword_000000 = v39;
          local_54.dword_000028 = v101;
          if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_485A24(&local_54, &local_28);
            else
              sub_485975((sub_485975_stru0 *)&local_54, (sub_485975_stru1 *)&local_28);
          }
          else
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_4D705A((int)&local_54);
            else
              sub_4D6FB0((int)&local_54);
          }
          local_54.dword_000034 = (int)sub_485E1F((int *)&local_28, pSpan, v102, v5, dword_6BE0DC, 1u, 0);
          v98 -= pStruct9_global->dword_000018 << v76;
        }
        while ( v104-- != 1 );
      }
      if ( !v99 )
        return true;

      v101 = v5->dword_00001C;
      v102 = v68 + (((unsigned __int64)(v101) * v98) >> 16);
      if ( v68 + (unsigned int)(((unsigned __int64)(v101) * v98) >> 16) )
      {
        v41 = abs((int)(v68 + (((unsigned __int64)(v101) * v98) >> 16)));
        if ( abs(X) < v41 )
        {
          LODWORD(v42) = v74 << 16;
          HIDWORD(v42) = v74 >> 16;
          X = v42 / v102;
          HIWORD(v43) = (unsigned int)(v42 / v102) >> 16;
          LOWORD(v43) = 0;
          local_54.dword_000024 = v43 | v5->word_000050;
          v101 = v5->ptr_000038->dword_000010;
          v101 = v69 + (((unsigned __int64)(v101) * v98) >> 16);
          X = ((unsigned __int64)(v101) * (signed int)(v42 / v102)) >> 16;

          v45 = (((unsigned __int64)(v101) * (signed int)(v42 / v102)) >> 16) - v5->ptr_000038->dword_000024;
          v101 = v5->ptr_000038->dword_00001C;
          v101 = v73 + (((unsigned __int64)(v101) * v98) >> 16);
          X = ((unsigned __int64)(v101) * (signed int)(v42 / v102)) >> 16;
          v46 = (((signed int)(v71
                             + (((unsigned __int64)(v101) * (signed int)(v42 / v102)) >> 16)
                             - v5->ptr_000038->dword_000028) >> v23)
               - local_54.dword_00002C) >> v76;
          local_54.dword_000004 = (((v70 + v45) >> v23) - local_54.dword_000030) >> v76;
          local_54.dword_000000 = v46;
          local_54.dword_000028 = v99;
          if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_485A24(&local_54, &local_28);
            else
              sub_485975((sub_485975_stru0 *)&local_54, (sub_485975_stru1 *)&local_28);
          }
          else
          {
            if (v5->ptr_000054->byte_00012F == 1)
              sub_4D705A((int)&local_54);
            else
              sub_4D6FB0((int)&local_54);
          }
          return true;
        }
      }
    }

  return false;
}


//----- (004847EB) --------------------------------------------------------
bool sub_4847EB(struct Span *pSpan)
{
  int v2;
  int v3;
  int ebp0; // ebp@0
  struct struct8 *v5; // esi@1
  signed int v6; // eax@3
  signed int v7; // ebx@3
  int v8; // edi@3
  int v11; // edx@3
  int v12; // eax@3
  int v13; // ebx@4
  signed int v14; // eax@5
  signed int v15; // ebx@5
  signed __int64 v16; // qtt@5
  int v18; // ecx@14
  signed int v21; // eax@14
  signed int v23; // eax@16
  int v24; // ebx@16
  int v25; // ebx@17
  int v26; // edi@17
  int v27; // edi@17
  int v28; // eax@17
  int v29; // eax@18
  int v30; // eax@19
  int v31; // ecx@19
  signed __int64 v32; // qtt@19
  signed int v34; // edi@21
  int v35; // ebx@21
  signed int v36; // edi@21
  signed __int64 v37; // qtt@21
  signed int v38; // ebx@21
  int v39; // ebx@29
  int v40; // eax@32
  int v41; // edi@32
  unsigned __int64 v42; // qax@32
  int v43; // eax@33
  int v44; // eax@34
  int v45; // ecx@34
  signed __int64 v46; // qtt@34
  signed int v48; // edi@36
  int v49; // eax@36
  int v50; // eax@47
  int v51; // edi@47
  unsigned __int64 v52; // qax@47
  int v53; // eax@48
  int v54; // eax@49
  int v55; // ecx@49
  signed __int64 v56; // qtt@49
  signed int v58; // edi@51
  int v59; // eax@51
  int v62; // [sp+10h] [bp-ACh]@3
  int v63; // [sp+14h] [bp-A8h]@3
  int v64; // [sp+18h] [bp-A4h]@3
  int v65; // [sp+1Ch] [bp-A0h]@3
  signed int v66; // [sp+20h] [bp-9Ch]@3
  signed int v67; // [sp+24h] [bp-98h]@3
  int v68; // [sp+28h] [bp-94h]@1
  char v69; // [sp+2Ch] [bp-90h]@1

  struct sub_485975_stru0 local_30;
  /*
  //local struct
 struct
 {
  int v70; // [sp+30h] [bp-8Ch]@21
  int v71; // [sp+34h] [bp-88h]@21
  int v72; // [sp+38h] [bp-84h]@16
  int v73; // [sp+3Ch] [bp-80h]@16
  int v74; // [sp+40h] [bp-7Ch]@16
  int v75; // [sp+44h] [bp-78h]@15
  int v76; // [sp+48h] [bp-74h]@15
  int v77; // [sp+4Ch] [bp-70h]@15
  int v78; // [sp+50h] [bp-6Ch]@15
  int v79; // [sp+54h] [bp-68h]@21
  int v80; // [sp+58h] [bp-64h]@21
  int v81; // [sp+5Ch] [bp-60h]@14
  int v82; // [sp+60h] [bp-5Ch]@14
  char *v83; // [sp+64h] [bp-58h]@14
  int v84; // [sp+68h] [bp-54h]@5
  int v85; // [sp+6Ch] [bp-50h]@1 depth buffer
  int v86; // [sp+70h] [bp-4Ch]@1 color buffer
 } v70;*/

  char v87[40]; // [sp+74h] [bp-48h]@14
  int v88; // [sp+9Ch] [bp-20h]@5
  int v89; // [sp+A0h] [bp-1Ch]@1
  int X; // [sp+A4h] [bp-18h]@3
  int v91; // [sp+A8h] [bp-14h]@21
  int v92; // [sp+ACh] [bp-10h]@1
  int v93; // [sp+B0h] [bp-Ch]@14
  int v94; // [sp+B4h] [bp-8h]@3
  int v95; // [sp+B8h] [bp-4h]@3

  v3 = pSpan->word_00000A;
  v2 = pSpan->word_000008;
  v5 = pSpan->pParent;
  v89 = 0;

  v92 = v2;

  local_30.pDepthBuffer = (unsigned int *)(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A));
  local_30.pColorBuffer = (unsigned int *)(pD3DRenderer->pTargetSurface + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A));
  v68 = dword_6BE050;
  v69 = dword_6BE054;
  if (pSpan->word_00000C >= dword_6BE050 )
    v89 = dword_6BE050 - (v2 & (dword_6BE050 - 1));
  v6 = pSpan->word_00000C - v89;
  v67 = v6 >> dword_6BE054;
  v62 = v6 - (v6 >> dword_6BE054 << dword_6BE054);
  v8 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v92);

  v95 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v92);
  v94 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3);
  v92 = v5->ptr_000038->dword_000014;
  v94 = ((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16;

  v11 = v94 + v5->ptr_000038->dword_00000C;
  v92 = v5->ptr_000038->dword_000020;
  v65 = v11;
  v12 = (((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16) + v5->ptr_000038->dword_000018;
  v94 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3);
  v64 = v12;
  v92 = v5->dword_000020;
  v94 = ((unsigned __int64)(v92) * pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v3)) >> 16;
  v7 = -v5->dword_000024;
  v63 = v94 + v5->dword_000018;
  v66 = -v5->dword_000024;
  v94 = ((unsigned __int64)(v95) * v5->dword_00001C) >> 16;
  X = v94 + v63;
  if (!(v94 + v63))
    return false;
   
  v92 = v7 >> 14;
  v13 = abs(v7 >> 14);
  if (v13 > abs(X))
    return false;

  LODWORD(v16) = v66 << 16;
  HIDWORD(v16) = v66 >> 16;
  v88 = v16 / X;
  local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
  v14 = v16 / X;
  v15 = 2;
  if ( v14 >= dword_6BE0F0 << 16 )
  {
    if ( v14 >= dword_6BE0F4 << 16 )
    {
      if ( v14 >= dword_6BE0F8 << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_14;
        v15 = 3;
        local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal3;
      }
      else
      {
        local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal2;
      }
    }
    else
    {
      v15 = 1;
      local_30.dword_000038 = (int)v5->ptr_00003C->pLevelOfDetal1;
    }
  }
  else
  {
    v15 = 0;
    local_30.dword_000038 = (int)v5->ptr_00003C->pIndexedPixels;
  }

  v15 = 0;
  local_30.dword_000038 = (int)v5->ptr_00003C->pTruecolorPixels; // fuck lods and palettes


LABEL_14:
  local_30.dword_000034 = (int)sub_485E1F((int *)v87, pSpan, v14, pSpan->pParent, dword_6BE0E0, 1, 1);

  v93 = v65 + (((unsigned __int64)(v5->ptr_000038->dword_000010) * v8) >> 16);
  v95 = v64 + (((unsigned __int64)(v5->ptr_000038->dword_00001C) * v8) >> 16);

  local_30.dword_000030 = (((unsigned __int64)(v93) * v88) >> 16) - v5->ptr_000038->dword_000024;
  v21 = (((unsigned __int64)(v95) * v88) >> 16) - v5->ptr_000038->dword_000028;

  v18 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  local_30.dword_000030 >>= v18;
  v94 = (unsigned __int8)bUseLoResSprites + v15 + 2;
  local_30.dword_00002C = v21 >> v18;
  if ( byte_80AA10 )
  {
    local_30.dword_000014 = dword_80AA20 >> v18;
    local_30.dword_000018 = dword_80AA1C >> v18;
    local_30.dword_00001C = dword_80AA18 >> v18;
    local_30.dword_000020 = dword_80AA14 >> v18;
  }

  v95 = (signed int)v5->ptr_00003C->uTextureWidth >> v15;
  v23 = (signed int)v5->ptr_00003C->uTextureHeight >> v15;
  v24 = v15 - v5->ptr_00003C->word_00001C + 16;
  local_30.dword_000008 = (v23 << 16) - 65536;
  local_30.dword_00000C = v95 - 1;
  local_30.dword_000010 = v24;
  if ( v89 )
  {
    v27 = v8 - v89 * pStruct9_global->dword_000018;
    v25 = v27;
    v93 = v5->dword_00001C;
    v95 = v27;
    v28 = ((unsigned __int64)(v93) * v27) >> 16;
    v26 = v28 + v63;
    X = v28 + v63;
    if ( !(v28 + v63))
      return false;

    v93 = abs(v92);
    v29 = abs(v26);
     if (v93 > v29)
      return 0;
    LODWORD(v32) = v66 << 16;
    HIDWORD(v32) = v66 >> 16;
    v93 = v32 / X;
    v31 = v32 / X;
    HIWORD(v30) = HIWORD(v88);
    if ( v88 <= v31 )
      HIWORD(v30) = HIWORD(v31);
    LOWORD(v30) = 0;
    v93 = v25;
    local_30.dword_000024 = v30;
    X = v5->ptr_000038->dword_000010;
    X = v65 + (((unsigned __int64)(X) * v25) >> 16);
    v93 = ((unsigned __int64)(X) * v31) >> 16;

    v93 = v25;
    v34 = (((unsigned __int64)(X) * v31) >> 16) - v5->ptr_000038->dword_000024;
    X = v5->ptr_000038->dword_00001C;
    X = v64 + (((unsigned __int64)(X) * v25) >> 16);
    v93 = ((unsigned __int64)(X) * v31) >> 16;
    v35 = (v93 - v5->ptr_000038->dword_000028) >> v94;
    X = v89 << 16;
    v36 = (v34 >> v94) - local_30.dword_000030;
    LODWORD(v37) = v36 << 16;
    HIDWORD(v37) = v36 >> 16;
    v38 = v35 - local_30.dword_00002C;
    local_30.dword_000004 = v37 / (v89 << 16);
    v91 = v89 << 16;
    LODWORD(v37) = v38 << 16;
    HIDWORD(v37) = v38 >> 16;
    v93 = v37 / (v89 << 16);
    local_30.dword_000000 = v37 / (v89 << 16);
    local_30.dword_000028 = v89;
    if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
    {
      if ( byte_80AA10 )
        sub_485A24(&local_30, (sub_485975_stru1 *)v87);
      else
        sub_485975(&local_30, (sub_485975_stru1 *)v87);
    }
    else
    {
      if ( byte_80AA10 )  //v70 here apperas to be passed on stack
        sub_4D705A((int)&local_30);
      else
        sub_4D6FB0((int)&local_30);
    }
    v39 = v95 - (pStruct9_global->dword_000018 << v69);
  }
  else
  {
    v95 = v8 - (pStruct9_global->dword_000018 << v69);
    v39 = v8 - (pStruct9_global->dword_000018 << v69);
  }


  local_30.dword_000028 = v68;
  while ( v67 > 0 )
  {
   v40 = v5->dword_00001C;
    --v67;
    v91 = v40;
    v42 = v40 * v39;
    v95 = v42 >> 16;
    LODWORD(v42) = v42 >> 16;
    v41 = v42 + v63;
    X = v42 + v63;
    if ( !((_DWORD)v42 + v63))
      return false;

    v91 = abs(v92);
    v43 = abs(v41);
    if (v91 > v43)

    LODWORD(v46) = v66 << 16;
    HIDWORD(v46) = v66 >> 16;
    v89 = v46 / X;
    v45 = v46 / X;
    HIWORD(v44) = HIWORD(v88);
    if ( v88 <= v45 )
      HIWORD(v44) = HIWORD(v45);
    LOWORD(v44) = 0;
    v95 = v39;
    local_30.dword_000024 = v44;
    v91 = v5->ptr_000038->dword_000010;
    v91 = v65 + (((unsigned __int64)(v91) * v39) >> 16);
    v95 = ((unsigned __int64)(v91) * v45) >> 16;

    v95 = v39;
    v48 = (((unsigned __int64)(v91) * v45) >> 16) - v5->ptr_000038->dword_000024;
    v91 = v5->ptr_000038->dword_00001C;
    v91 = v64 + (((unsigned __int64)(v91) * v39) >> 16);
    v95 = ((unsigned __int64)(v91) * v45) >> 16;
    v49 = (((v95 - v5->ptr_000038->dword_000028) >> v94) - local_30.dword_00002C) >> v69;
    local_30.dword_000004 = ((v48 >> v94) - local_30.dword_000030) >> v69;
    local_30.dword_000000 = v49;
    if ( byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
    {
      if ( byte_80AA10 )
        sub_485A24(&local_30, (sub_485975_stru1 *)v87);
      else
        sub_485975(&local_30, (sub_485975_stru1 *)v87);
    }
    else
    {
      if ( byte_80AA10 )
        sub_4D705A((int)&local_30);
      else
        sub_4D6FB0((int)&local_30);
    }
    local_30.dword_000034 = (int)sub_485E1F((int *)v87, pSpan, v89, v5, dword_6BE0E0, 1u, 0);
    local_30.dword_000028 = v68;
    v39 -= pStruct9_global->dword_000018 << v69;
  }
  if ( !v62 )
    return true;

  v50 = v5->dword_00001C;
  v91 = v50;
  v52 = v50 * v39;
  v95 = v52 >> 16;
  LODWORD(v52) = v52 >> 16;
  v51 = v52 + v63;
  X = v52 + v63;
  if ( (_DWORD)v52 + v63 )
  {
    v91 = abs(v92);
    v53 = abs(v51);
    if ( v91 <= v53 )
    {
      LODWORD(v56) = v66 << 16;
      HIDWORD(v56) = v66 >> 16;
      v92 = v56 / X;
      v55 = v56 / X;
      HIWORD(v54) = HIWORD(v88);
      if ( v88 <= v55 )
        HIWORD(v54) = HIWORD(v55);
      LOWORD(v54) = 0;
      v92 = v39;
      local_30.dword_000024 = v54;
      v91 = v5->ptr_000038->dword_000010;
      v91 = v65 + (((unsigned __int64)(v91) * v39) >> 16);
      v92 = ((unsigned __int64)(v91) * v55) >> 16;

      v92 = v39;
      v58 = (((unsigned __int64)(v91) * v55) >> 16) - v5->ptr_000038->dword_000024;
      v91 = v5->ptr_000038->dword_00001C;
      v91 = v64 + (((unsigned __int64)(v91) * v39) >> 16);
      v92 = ((unsigned __int64)(v91) * v55) >> 16;
      v59 = (((v92 - v5->ptr_000038->dword_000028) >> v94) - local_30.dword_00002C) >> v69;
      local_30.dword_000004 = ((v58 >> v94) - local_30.dword_000030) >> v69;
      local_30.dword_000000 = v59;
      local_30.dword_000028 = v62;
      if (byte_4D8410[572] && pGame->uSomeFlags & 0x0800)
      {
        if ( byte_80AA10 )
          sub_485A24(&local_30, (sub_485975_stru1 *)v87);
        else
          sub_485975(&local_30, (sub_485975_stru1 *)v87);
      }
      else
      {
        if ( byte_80AA10 )
          sub_4D705A((int)&local_30);
        else
          sub_4D6FB0((int)&local_30);
      }
      return true;
    }
  }
  return false;
}

//----- (004D6FB0) --------------------------------------------------------
function_error;//int __usercall sub_4D6FB0<eax>(int a1<ebp>)
int sub_4D6FB0(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  int v7; // ebx@3
  __int16 v8; // cx@3
  int v9; // edx@4
  __int16 v10; // cx@4
  unsigned __int8 v11; // sf@5
  unsigned __int8 v12; // of@5

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_5;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v9 = *(_DWORD *)(v2 + 12) & (v4 >> 16);
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    v10 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                   + 2 * *(_BYTE *)(*(_DWORD *)(v2 + 56) + v9 + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result - 2) = v10;
LABEL_5:
    compile_error();//v12 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v11 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v11 ^ v12 )
      break;
    v7 = *(_BYTE *)(*(_DWORD *)(v2 + 56)
                  + (*(_DWORD *)(v2 + 12) & (v4 >> 16))
                  + ((*(_DWORD *)(v2 + 8) & v3) >> *(_BYTE *)(v2 + 16)));
    v4 += *(_DWORD *)(v2 + 4);
    v8 = *(_WORD *)(*(_DWORD *)(v2 + 52) + 2 * v7);
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v8;
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}


//----- (0048408A) --------------------------------------------------------
signed int __thiscall sub_48408A(int _this)
{
  signed int v1; // ecx@1
  int v2; // ebx@1
  int ebp0; // ebp@0
  int v4; // edi@1
  int v5; // esi@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // eax@1
  int v9; // edx@1
  int v10; // eax@1
  int v11; // ebx@1
  int v12; // eax@1
  int v13; // ecx@1
  int v14; // eax@1
  int v15; // ecx@1
  int v16; // eax@1
  int v17; // ebx@3
  signed __int64 v18; // qtt@3
  int v19; // eax@3
  int v20; // eax@4
  int v21; // eax@4
  int v22; // eax@6
  int v23; // ecx@8
  int v24; // eax@10
  int v25; // ecx@12
  int v26; // eax@12
  signed int v27; // eax@12
  int v28; // eax@14
  int v29; // edx@14
  int v30; // ecx@14
  int v31; // esi@14
  int v32; // edx@14
  int v33; // eax@14
  int v35; // [sp+Ch] [bp-8Ch]@1
  int v36; // [sp+10h] [bp-88h]@1
  char v37; // [sp+14h] [bp-84h]@14
  int v38; // [sp+3Ch] [bp-5Ch]@14
  int v39; // [sp+40h] [bp-58h]@14
  int v40; // [sp+44h] [bp-54h]@14
  int v41; // [sp+48h] [bp-50h]@14
  int v42; // [sp+4Ch] [bp-4Ch]@14
  int v43; // [sp+50h] [bp-48h]@13
  int v44; // [sp+54h] [bp-44h]@13
  int v45; // [sp+58h] [bp-40h]@13
  int v46; // [sp+5Ch] [bp-3Ch]@13
  int v47; // [sp+60h] [bp-38h]@14
  int v48; // [sp+64h] [bp-34h]@1
  int v49; // [sp+68h] [bp-30h]@12
  int v50; // [sp+6Ch] [bp-2Ch]@12
  char *v51; // [sp+70h] [bp-28h]@14
  int v52; // [sp+74h] [bp-24h]@3
  int v53; // [sp+78h] [bp-20h]@14
  int v54; // [sp+7Ch] [bp-1Ch]@14
  int v55; // [sp+80h] [bp-18h]@1
  int v56; // [sp+84h] [bp-14h]@1
  int v57; // [sp+88h] [bp-10h]@1
  int v58; // [sp+8Ch] [bp-Ch]@1
  int v59; // [sp+90h] [bp-8h]@2
  int v60; // [sp+94h] [bp-4h]@1

  v4 = _this;
  v5 = *(_DWORD *)(_this + 4);
  v6 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - *(_WORD *)(_this + 10));
  v7 = *(_DWORD *)(v5 + 56);
  v60 = v6;
  v58 = *(_DWORD *)(v7 + 20);
  v60 = (unsigned __int64)(v58 * v6) >> 16;
  v8 = *(_DWORD *)(v5 + 56);
  v9 = v60 + *(_DWORD *)(v8 + 12);
  v58 = *(_DWORD *)(v8 + 32);
  v55 = v9;
  v10 = ((unsigned __int64)(v58 * v6) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v60 = v6;
  v57 = v10;
  v58 = *(_DWORD *)(v5 + 32);
  v60 = (unsigned __int64)(v58 * v6) >> 16;
  v11 = v60 + *(_DWORD *)(v5 + 24);
  v35 = class59_SinCos(pClass59_global, pOldCamera->sRotationY - pClass59_global->uIntegerHalfPi);
  v12 = class59_SinCos(pClass59_global, pOldCamera->sRotationY);
  v13 = *(_WORD *)(v4 + 8);
  v36 = v12;
  v48 = *(_WORD *)(v4 + 12);
  v14 = pOldViewport->dword_000028 - v13;
  v15 = *(_DWORD *)(v5 + 36);
  v58 = pStruct9_global->dword_000018 * v14;
  v16 = *(_DWORD *)(v5 + 28);
  v1 = -v15;
  v56 = v1;
  v2 = ((unsigned __int64)(v58 * v16) >> 16) + v11;
  v60 = v2;
  if ( !v2 || (v59 = abs(v1 >> 14), v59 > abs(v2)) )
    return 0;
  LODWORD(v18) = v56 << 16;
  HIDWORD(v18) = v56 >> 16;
  v59 = v18 / v60;
  v19 = *(_DWORD *)(v5 + 56);
  v60 = v58;
  v56 = *(_DWORD *)(v19 + 16);
  v60 = v58;
  v56 = v55 + ((unsigned __int64)(v56 * v58) >> 16);
  v55 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
  v60 = (unsigned __int64)(v55 * v58) >> 16;
  v17 = v59;
  v57 += (unsigned __int64)(v55 * v58) >> 16;
  v52 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v60 = 2;
  if ( v59 < dword_6BE0F0 << 16 )
  {
    v21 = *(_DWORD *)(v5 + 60);
    v60 = 0;
    v20 = *(_DWORD *)(v21 + 48);
LABEL_11:
    v52 = v20;
    goto LABEL_12;
  }
  if ( v59 < dword_6BE0F4 << 16 )
  {
    v22 = *(_DWORD *)(v5 + 60);
    v60 = 1;
    v20 = *(_DWORD *)(v22 + 52);
    goto LABEL_11;
  }
  if ( v59 >= dword_6BE0F8 << 16 )
  {
    if ( !bUseLoResSprites )
    {
      v24 = *(_DWORD *)(v5 + 60);
      v60 = 3;
      v20 = *(_DWORD *)(v24 + 60);
      goto LABEL_11;
    }
  }
  else
  {
    v23 = *(_DWORD *)(v5 + 60);
    v60 = 2;
    v52 = *(_DWORD *)(v23 + 56);
  }
LABEL_12:
  v59 = (unsigned __int64)(v56 * v59) >> 16;
  v26 = *(_DWORD *)(v5 + 56);
  v59 = v17;
  v50 = ((unsigned __int64)(v56 * v17) >> 16) - *(_DWORD *)(v26 + 36);
  v59 = (unsigned __int64)(v57 * v17) >> 16;
  v27 = ((unsigned __int64)(v57 * v17) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
  v25 = (unsigned __int8)bUseLoResSprites + v60 + 2;
  v50 >>= v25;
  v57 = (unsigned __int8)bUseLoResSprites + v60 + 2;
  v49 = v27 >> v25;
  if ( byte_80AA10 )
  {
    v43 = dword_80AA20 >> v25;
    v44 = dword_80AA1C >> v25;
    v45 = dword_80AA18 >> v25;
    v46 = dword_80AA14 >> v25;
  }
  v57 = pStruct9_global->dword_000018;
  v58 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v17) >> 16) >> v25;
  v39 = (unsigned __int64)(v58 * v35) >> 16;
  v59 = (unsigned __int64)(v58 * v36) >> 16;
  v38 = (unsigned __int64)(v58 * v36) >> 16;
  v51 = sub_485E1F((int *)&v37, (Span *)v4, v17, (struct8 *)v5, dword_6BE0E0, 1u, 1);
  LOWORD(v17) = 0;
  v28 = *(_WORD *)(v4 + 10);
  v29 = *(_WORD *)(v4 + 10);
  v47 = v17;
  v30 = *(_WORD *)(v4 + 8);
  v54 = (int)(pD3DRenderer->pTargetSurface + (v30 + pD3DRenderer->uTargetSurfacePitch * v29));
  v53 = (int)(&pD3DRenderer->pActiveZBuffer[v30 + 640 * v28]);
  v31 = *(_DWORD *)(v5 + 60);
  v32 = ((signed int)*(_WORD *)(v31 + 24) >> v60) - 1;
  v33 = ((signed int)*(_WORD *)(v31 + 26) >> v60 << 16) - 65536;
  v42 = v60 - *(_WORD *)(v31 + 28) + 16;
  v41 = v32;
  v40 = v33;
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
  {
    if ( byte_80AA10 )
      sub_485A24((sub_485975_stru0 *)&v38, (sub_485975_stru1 *)&v37);
    else
      sub_485975((sub_485975_stru0 *)&v38, (sub_485975_stru1 *)&v37);
  }
  else
  {
    if ( byte_80AA10 )
      sub_4D705A(ebp0);
    else
      sub_4D6FB0(ebp0);
  }
  return 1;
}

//----- (004D705A) --------------------------------------------------------
function_error;//int __usercall sub_4D705A<eax>(int a1<ebp>)
int sub_4D705A(int a1)
{
  int result; // eax@1
  int v2; // ebp@1
  unsigned int v3; // edi@1
  unsigned int v4; // esi@1
  int v5; // edx@2
  int v6; // ebx@2
  unsigned int v7; // edx@3
  unsigned int v8; // ebx@3
  __int16 v9; // cx@11
  unsigned int v10; // edx@12
  unsigned int v11; // ebx@12
  unsigned __int8 v12; // sf@21
  unsigned __int8 v13; // of@21

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 48);
  v3 = *(_DWORD *)(v2 + 44);
  result = *(_DWORD *)(v2 + 64);
  if ( !(*(_DWORD *)(v2 + 40) & 1) )
    goto LABEL_21;
  --*(_DWORD *)(v2 + 40);
  result -= 2;
  v6 = *(_DWORD *)(v2 + 60);
  v5 = *(_DWORD *)(v2 + 36);
  *(_DWORD *)(v2 + 60) += 4;
  while ( 1 )
  {
    *(_DWORD *)v6 = v5;
    v11 = v3;
    v10 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v10 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v11 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v10 > *(_DWORD *)(v2 + 24) )
      v10 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v11 > *(_DWORD *)(v2 + 32) )
      v11 = *(_DWORD *)(v2 + 32);
    result += 4;
    v4 += *(_DWORD *)(v2 + 4);
    v3 += *(_DWORD *)v2;
    *(_WORD *)(result - 2) = *(_WORD *)(*(_DWORD *)(v2 + 52)
                                      + 2
                                      * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                                                 + (*(_DWORD *)(v2 + 12) & (v10 >> 16))
                                                 + ((*(_DWORD *)(v2 + 8) & v11) >> *(_BYTE *)(v2 + 16))));
LABEL_21:
    compile_error();//v13 = __SETO__(*(_DWORD *)(v2 + 40), 2);
    v12 = *(_DWORD *)(v2 + 40) - 2 < 0;
    *(_DWORD *)(v2 + 40) -= 2;
    if ( v12 ^ v13 )
      break;
    v8 = v3;
    v7 = v4;
    if ( (signed int)v4 < *(_DWORD *)(v2 + 20) )
      v7 = *(_DWORD *)(v2 + 20);
    if ( (signed int)v3 < *(_DWORD *)(v2 + 28) )
      v8 = *(_DWORD *)(v2 + 28);
    if ( (signed int)v7 > *(_DWORD *)(v2 + 24) )
      v7 = *(_DWORD *)(v2 + 24);
    if ( (signed int)v8 > *(_DWORD *)(v2 + 32) )
      v8 = *(_DWORD *)(v2 + 32);
    v4 += *(_DWORD *)(v2 + 4);
    v9 = *(_WORD *)(*(_DWORD *)(v2 + 52)
                  + 2
                  * *(_BYTE *)(*(_DWORD *)(v2 + 56)
                             + (*(_DWORD *)(v2 + 12) & (v7 >> 16))
                             + ((*(_DWORD *)(v2 + 8) & v8) >> *(_BYTE *)(v2 + 16))));
    v3 += *(_DWORD *)v2;
    v6 = *(_DWORD *)(v2 + 60);
    v5 = *(_DWORD *)(v2 + 36);
    *(_WORD *)result = v9;
    *(_DWORD *)(v2 + 60) += 8;
    *(_DWORD *)(v6 + 4) = v5;
  }
  *(_DWORD *)(v2 + 64) = result;
  *(_DWORD *)(v2 + 48) = v4;
  *(_DWORD *)(v2 + 44) = v3;
  return result;
}

//----- (00485044) --------------------------------------------------------
signed int __fastcall sub_485044(struct Span *pSpan, struct struct8 *a2, int a3)
{
  float v5; // ST2C_4@1
  signed int result; // eax@2
  int v7; // eax@3
  int v8; // edx@3
  int v9; // ecx@3
  int v10; // ebx@3
  int v11; // ST40_4@3
  int v13; // ST28_4@5
  int v14; // eax@5
  int v15; // eax@11
  int v16; // edi@11
  unsigned int v17; // esi@11
  signed __int64 v18; // qtt@11
  int v19; // ST28_4@11
  int v20; // eax@11
  signed int v21; // ecx@11
  int v22; // ST40_4@11
  int v23; // ST3C_4@11
  int v24; // ST30_4@11
  char *v25; // eax@11
  int v28; // ebx@12
  int v29; // edx@13
  __int16 v30; // cx@13
  int v31; // edx@14
  __int16 v32; // cx@14
  signed int v37; // [sp+18h] [bp-34h]@11
  signed int v39; // [sp+1Ch] [bp-30h]@11
  int v40; // [sp+20h] [bp-2Ch]@3
  short *v41;
  int v42; // [sp+24h] [bp-28h]@3
  int v43; // [sp+24h] [bp-28h]@11
  int v44; // [sp+28h] [bp-24h]@11
  int v45; // [sp+2Ch] [bp-20h]@3
  signed int v46; // [sp+30h] [bp-1Ch]@3
  int v47; // [sp+30h] [bp-1Ch]@11
  signed int v48; // [sp+34h] [bp-18h]@3
  int v49; // [sp+34h] [bp-18h]@11
  int v50; // [sp+38h] [bp-14h]@3
  int v51; // [sp+38h] [bp-14h]@11
  int v52; // [sp+3Ch] [bp-10h]@4
  int v53; // [sp+40h] [bp-Ch]@3
  int v54; // [sp+44h] [bp-8h]@3
  int v55; // [sp+48h] [bp-4h]@3
  int v56; // [sp+54h] [bp+8h]@11
  int v57; // [sp+54h] [bp+8h]@11

  v5 = (double)(pOldViewport->uGameZ - pOldViewport->uGameX) * 0.5 / tan(0.64577174186706543) + 0.5;
  if ((int)(floorf(v5 + 0.5f)))
  {
    v55 = 65536 / floorf(v5 + 0.5f);
    v11 = 65536 / floorf(v5 + 0.5f) * (a3 - pSpan->word_00000A);

    v42 = (((unsigned __int64)(a2->ptr_000038->dword_000014) * v11) / 65536) + a2->ptr_000038->dword_00000C;
    v40 = (((unsigned __int64)(a2->ptr_000038->dword_000020) * v11) / 65536) + a2->ptr_000038->dword_000018;
    v45 = pSpan->word_00000C;
    v10 = (((unsigned __int64)(a2->dword_000020) * v11) / 65536) + a2->dword_000018;
    v9 = 65536 / floorf(v5 + 0.5f) * (pOldViewport->dword_000028 - pSpan->word_000008);
    v48 = 0;
    v50 = 65536 / floorf(v5 + 0.5f) * (pOldViewport->dword_000028 - pSpan->word_000008);
    v46 = -a2->dword_000024;
    v8 = pSpan->word_00000A - 1;
    v54 = v8;
    v7 = 65536 / floorf(v5 + 0.5f) * (a3 - v8);
    v53 = 65536 / floorf(v5 + 0.5f) * (a3 - v8);
    while ( 1 )
    {
      v52 = v10;
      if ( v10 )
      {
        v13 = abs(v46 >> 14);
        v14 = abs(v10);
        v8 = v54;
        v9 = v50;
        if ( v13 <= v14 )
          break;
        v7 = v53;
      }
      if ( v8 <= pOldViewport->uGameY )
        break;
      v10 = (((unsigned __int64)(a2->dword_000020) * v7) / 65536) + a2->dword_000018;
      --v54;
      v53 += v55;
      v7 = v53;
      v8 = v54;
      v48 = 1;
    }

    if ( v48 )
     v52 = (((unsigned __int64)(a2->dword_000020) * v55 * (a3 + (signed int)pSpan->word_00000A - 2 * v8)) >> 16)
      + a2->dword_000018;
    LODWORD(v18) = v46 << 16;
    HIDWORD(v18) = v46 >> 16;
    v19 = v42 + (((unsigned __int64)(a2->ptr_000038->dword_000010) * v9) >> 16);
    v20 = v40 + (((unsigned __int64)(a2->ptr_000038->dword_00001C) * v9) >> 16);
    v21 = v18 / v52;
    //v43 = a2->ptr_00003C->dword_000030;
    v43 = (int)a2->ptr_00003C->pTruecolorPixels;
    v22 = a2->dword_000028 + ((signed int)(((unsigned __int64)(v19) * (signed int)(v18 / v52)) >> 16) >> 3);
    v57 = v18 / v52;
    v23 = a2->dword_00002C + ((signed int)(((unsigned __int64)(v20) * (signed int)(v18 / v52)) >> 16) >> 3);
    v24 = ((unsigned __int64)(v55) * v57) >> 16;
    v39 = (signed int)(((unsigned __int64)(v24) * pStruct9_global->camera_rotation_y_int_sine) >> 16) >> 3;
    v37 = (signed int)(((unsigned __int64)(v24) * pStruct9_global->camera_rotation_y_int_cosine) >> 16) >> 3;
    v25 = (char *)sub_47C178(v21, a2, 0, 1);

    v41 = (short *)v25;
    v47 = 16 - a2->ptr_00003C->word_00001C;
    v44 = a2->ptr_00003C->uTextureWidth - 1;
    v49 = ((unsigned int)(a2->ptr_00003C->uTextureHeight) << 16) - 65536;

    v51 = (int)(pD3DRenderer->pTargetSurface + (pSpan->word_000008 + pD3DRenderer->uTargetSurfacePitch * pSpan->word_00000A));
    v56 = (int)(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A));

    v17 = v22;
    v16 = v23;
    v15 = v51;
    if ( !(v45 & 1) )
      goto LABEL_15;
    --v45;
    v15 = v51 - 2;
    v28 = v56;
    v56 += 4;
    while ( 1 )
    {
      *(_DWORD *)v28 = -65536;
      v31 = v44 & (v17 >> 16);
      v15 += 8;
      v17 += v39;
      v32 = v41[2 * *(_BYTE *)(v43 + v31 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      *(_DWORD *)(v15 - 4) = v32;
LABEL_15:
      //v34 = __SETO__(v45, 2);
      //v33 = v45 - 2 < 0;
      if (v45 < 2)
        break;
      v45 -= 2;
      v29 = v44 & (v17 >> 16);
      v17 += v39;
      v30 = v41[2 * *(_BYTE *)(v43 + v29 + ((v49 & (unsigned int)v16) >> v47))];
      v16 += v37;
      v28 = v56;
      *(_DWORD *)v15 = v30;
      v56 += 8;
      *(_DWORD *)(v28 + 4) = -65536;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


//----- (0048585C) --------------------------------------------------------
bool sub_48585C_MaybeDrawSpan(struct Span *pSpan, unsigned int *pRenderTarget, int a3)
{
  struct struct8 *v3; // edi@1
  int v5; // ebx@2
  signed int v6; // ecx@3
  signed __int64 v8; // qtt@3
  short *v10; // eax@5
  int v11; // ecx@5
  signed int v13; // [sp+10h] [bp-10h]@1
  int v14; // [sp+18h] [bp-8h]@1

  v3 = pSpan->pParent;
  v13 = -v3->dword_000024;
  v14 = (((unsigned __int64)(pStruct9_global->dword_000018) * v3->dword_00001C * (pOldViewport->dword_000028 - (signed int)pSpan->word_000008)) / 65536) +
        (((unsigned __int64)(pStruct9_global->dword_000018) * v3->dword_000020 * (pOldViewport->dword_00002C - (signed int)pSpan->word_00000A)) / 65536) + v3->dword_000018;

  v5 = abs(-v3->dword_000024 >> 14);
  if ( v14 && v5 <= abs(v14))
  {
    LODWORD(v8) = v13 << 16;
    HIDWORD(v8) = v13 >> 16;
    v6 = v8 / v14;
  }
  else
  {
    v6 = pStruct9_global->shading_dist_mist << 16;
  }
  v10 = sub_47C178(v6, v3, dword_6BE0E0, a3);

  sub_452AF3(v10[v3->ptr_00003C->uDecompressedSize], pRenderTarget, pSpan->word_00000C);
  HIWORD(v11) = HIWORD(v6);
  LOWORD(v11) = 0;
  memset_dw(pD3DRenderer->pActiveZBuffer + (pSpan->word_000008 + 640 * pSpan->word_00000A), v11, pSpan->word_00000C);

  return true;
}














//----- (00487355) --------------------------------------------------------
void __cdecl sub_487355()
{
 int i;
 for (i = 0; i < pStruct9_global->dword_00002C; ++i)
   sub_45D3C7(&array_77EC08[i]);
}

//----- (00486F92) --------------------------------------------------------
void __cdecl sub_486F92_MessWithEdgesAndSpans()
{
  struct Edge *v2; // edx@3
  struct Edge *v3; // ecx@3
  struct Edge *v4; // esi@6
  struct Edge *v5; // eax@7
  struct Edge *v6; // ecx@8
  struct Surf *v7; // esi@11
  struct Surf *v8; // edi@13
  double v9; // st6@13
  double v10; // st7@13
  double v11; // st7@14
  short v12; // qax@14
  struct struct8 *v13; // eax@15
  double v15; // st7@28
  struct Edge *v20; // ecx@43
  struct Edge *v23; // edx@48
  float v25; // [sp+14h] [bp-Ch]@3
  signed int v27; // [sp+1Ch] [bp-4h]@1
 struct Span *pNewSpan;
 struct Edge *pEdge;

 pNewSpan = pSpansBuf;

 someEdge1.flt_000000 = pOldViewport->uGameZ;
 someEdge1.dword_000008 = 0;
 someEdge1.pSurf = &someSurf;
 someEdge1.pNext = 0;
 someEdge1.pPrev = &someEdge2;

 someSurf.flt_000000 = -999999.0;
 someSurf.flt_000004 = 0.0;
 someSurf.flt_000008 = 0.0;
 someSurf.pNext = &someSurf;
 someSurf.pPrev = &someSurf;
  
 someEdge2.flt_000000 = pOldViewport->uGameX;
 someEdge2.dword_000008 = 1;
 someEdge2.pSurf = &someSurf;
 someEdge2.pNext = &someEdge1;
 someEdge2.pPrev = 0;

  v27 = pOldViewport->uGameY;

  if (pOldViewport->uGameY > pOldViewport->uGameW)
  {
LABEL_51:
   pNewSpan->word_000008 = -1; 
  }
  else
  {
    while ( 1 )
    {
      v3 = pNewEdgesBuf[v27].pNext;
      v2 = &someEdge2;
      v25 = (double)v27;
      if (v3 != &defaultEdge)
      {
        do
        {
          while ( 1 )
          {
            v4 = v2->pNext;
            if (v3->flt_000000 <= v4->flt_000000)
              break;
            v2 = v2->pNext;
          }
          v5 = v3->pNext;
          v3->pNext = v4;
          v3->pPrev = v2;
          v2->pNext->pPrev = v3;
          v2->pNext = v3;
          v2 = v3;
          v3 = v5;
        }
        while ( v5 != &defaultEdge );
      }
      someSurf.word_000020 = 0;
      someSurf.word_000022 = 1;
      v6 = someEdge2.pNext;
      if ( v6 )
      {
        while ( 1 )
        {
         v7 = v6->pSurf;
          if (v6->dword_000008)
          {
           ++v7->word_000022;
            if ( v7->word_000022 == 1 )
            {
             v10 = v6->flt_000000 + 2.0;
              v8 = someSurf.pNext;
              v9 = (v10 - v7->flt_00000C) * v7->flt_000004 + (v25 - v7->flt_000010) * v7->flt_000008
                 + v7->flt_000000;
              if (v9 <= (v10 - someSurf.pNext->flt_00000C) * someSurf.pNext->flt_000004 +
                (v25 - someSurf.pNext->flt_000010) * someSurf.pNext->flt_000008 +
                 someSurf.pNext->flt_000000)
              {
                do
                  v8 = v8->pNext;
                while ( v9 <= (v10 - v8->flt_00000C) * v8->flt_000004 +
                              (v25 - v8->flt_000010) * v8->flt_000008 + v8->flt_000000);
                v7->pNext = v8;
                v7->pPrev = v8->pPrev;
                v8->pPrev->pNext = v7;
                v8->pPrev = v7;
              }
              else
              {
               v11 = v6->flt_000000 + 0.5;
                v12 = v11 - (double)someSurf.pNext->word_000020;
                pNewSpan->word_00000C = v12;
                if (v12 > 0)
                {
                 pNewSpan->word_00000A = v27;
                 pNewSpan->word_000008 = v8->word_000020;
                  v13 = v8->ptr_00001C;
                 pNewSpan->pParent = v13;
                  if (v13)
                  {
                    if (v13->ptr_000040)
                    {
                      if (!v13->ptr_000044)
                        return;
                      v13->ptr_000044->pNext = pNewSpan;
                    }
                    else
                      v13->ptr_000040 = pNewSpan;
                    v13->ptr_000044 = pNewSpan;
                  }
                  if ( pStruct9_global->uNumSpans >= 12499 )
                    return;
                  ++pNewSpan;
                  ++pStruct9_global->uNumSpans;
                }
                v7->word_000020 = (signed __int64)v11;

                v7->pNext = v8;
                v8->pPrev = v7;

                someSurf.pNext = v7;
                v7->pPrev = &someSurf;
              }
            }
          }
          else
          {
            --v7->word_000022;
            if (!v7->word_000022)
            {
              if (someSurf.pNext == v7)
              {
                v15 = v6->flt_000000 + 0.5;
                pNewSpan->word_00000C = v15 - (double)v7->word_000020;
                if (pNewSpan->word_00000C > 0)
                {
                 pNewSpan->word_00000A = v27;
                 pNewSpan->word_000008 = v7->word_000020;

                 pNewSpan->pParent = v7->ptr_00001C;
                  if (pNewSpan->pParent)
                  {
                   if (pNewSpan->pParent->ptr_000040)
                    {
                      if (!pNewSpan->pParent->ptr_000044)
                        return;
                      pNewSpan->pParent->ptr_000040 = pNewSpan;
                    }
                    else
                      pNewSpan->pParent->ptr_000040 = pNewSpan;

                    pNewSpan->pParent->ptr_000044 = pNewSpan;
                  }
                  if (pStruct9_global->uNumSpans >= 12499)
                    return;
                  ++pNewSpan;
                  ++pStruct9_global->uNumSpans;
                }
                v7->pNext->word_000020 = (signed __int64)v15;
              }
              v7->pNext->pPrev = v7->pPrev;
              v7->pPrev->pNext = v7->pNext;
            }
          }
          if (!v6->pNext)
            break;
          v6 = v6->pNext;
        }
      }
      for (pEdge = ptr_80CA10[v27]; pEdge; pEdge = pEdge->ptr_000018)
      {
       pEdge->pPrev->pNext = pEdge->pNext;
       pEdge->pNext->pPrev = pEdge->pPrev;
      }
      v20 = someEdge2.pNext;
      if (someEdge2.pNext != &someEdge1)
        break;
LABEL_50:
      ++v27;

      if ( v27 > pOldViewport->uGameW )
        goto LABEL_51;
    }

    while (true)
    {
     if (!v20->pNext)
       break;

     v20->flt_000000 += v20->flt_000004;
     if (v20->flt_000000 < someEdge2.flt_000000)
       v20->flt_000000 = someEdge2.flt_000000 + 0.0000001000000011686097;

     while (true)
     {
      v23 = v20->pPrev;
      if (v20->flt_000000 >= v20->pPrev->flt_000000)
        break;
      v20->pPrev->pNext = v20->pNext;
      v20->pNext->pPrev = v23;
      v23->pPrev->pNext = v20;
      v20->pPrev = v23->pPrev;
      v20->pNext = v23;
      v23->pPrev = v20;
      }
      v20 = v20->pNext;
      if (v20->pNext == &someEdge1)
        goto LABEL_50;
    }
  }
}


//----- (004789DE) --------------------------------------------------------
void sub_4789DE_RenderBuildingsSoftware()
{
  int v1; // ebx@2
  struct class51_stru2 *v3; // edi@4
  int v7; // ecx@6
  int v8; // ecx@6
  double v10; // st7@7
  struct class51_stru3 *v11; // eax@9
  int v14; // ebx@19
  struct struct8 *p14;
  double v15; // st7@21
  int v18; // eax@27
  int v22; // ecx@30
  int v23; // eax@31
  int v24; // eax@31
  int v35; // ecx@45
  int v37; // eax@50
  int v38; // eax@53
  signed int v39; // esi@53
  int v40; // eax@54
  int v45; // eax@60
  signed int v46; // esi@60
  int v47; // eax@61
  int v52; // eax@66
  float v57; // [sp+44h] [bp-7Ch]@50
  float v58; // [sp+48h] [bp-78h]@50
  float v59; // [sp+4Ch] [bp-74h]@50
  int v73; // [sp+84h] [bp-3Ch]@23
  int v76; // [sp+90h] [bp-30h]@6
  int v77; // [sp+94h] [bp-2Ch]@6
  int v83;
  int v84; // [sp+B0h] [bp-10h]@6
  int v85; // [sp+B4h] [bp-Ch]@6
  signed int v86; // [sp+B8h] [bp-8h]@7
  int v87; // [sp+BCh] [bp-4h]@1

 struct class51_BModel *pModel;
 int i, j, k;


 if (!pClass51_global->uNumBModels)
   return;

  v87 = 0;

 for (i = 0; i < pClass51_global->uNumBModels; ++i)
 {
  v1 = (int)&pClass51_global->pBModels[i].dword_00004C;
  pModel = &pClass51_global->pBModels[i];

  if (!sub_479089(i, &v87))
    continue;

  pClass51_global->pBModels[i].dword_000040 |= 0x0001;
  for (j = 0; j < pClass51_global->pBModels[i].dword_00004C; ++j)
  {
   v3 = &pClass51_global->pBModels[i].ptr_000054[j];
 
      if ( !(pClass51_global->pBModels[i].ptr_000054[j].byte_000010[13] & 0x20))
      {
        v7 = pClass51_global->pBModels[i].ptr_000054[j].array_000020[0];
        v8 = pClass51_global->pBModels[i].ptr_000048[v7].y + 4;
        v84 = 0;
        v76 = 0;
        v77 = 0;

        v10 = (double)v8;
        
        for (k = 0; k < pClass51_global->pBModels[i].ptr_000054[j].uNumVertices; ++k)
        {
         v11 = &pModel->ptr_000048[v3->array_000020[k]];

         array_73D150[k].x = v11->x + 4.0;
         array_73D150[k].z = v11->z + 4.0;
         array_73D150[k].y = v11->y + 4.0;
         if (v10 == v11->y + 4.0)
           ++v84;

         sub_436523(&array_73D150[k], 1);
         if (array_73D150[k].flt_00000C < 8.0 ||
             array_73D150[k].flt_00000C > pStruct9_global->shading_dist_mist)
         {
          if (array_73D150[k].flt_00000C >= 8.0 )
            v77 = 1;
          else
            v76 = 1;
         }
         else
           class08_sub_436BB7(pGame->class08_obj, &array_73D150[k], 1, 0);
        }


        v14 = (int)&array_77EC08[pStruct9_global->dword_00002C];
        p14 = (struct8 *)v14;
        p14->word_000030 = 0;
        if ( v84 == pClass51_global->pBModels[i].ptr_000054[j].uNumVertices)
          p14->word_000030 = 65536;

        p14->ptr_000054 = v3;
        p14->uNumVertices = pClass51_global->pBModels[i].ptr_000054[j].uNumVertices;
        p14->byte_000059 = 5;
        v85 = (unsigned __int64)(v3->dword_000000) * -pClass51_global->dword_000D30 / 65536;
        v84 = (unsigned __int64)(v3->dword_000004) * -pClass51_global->dword_000D34 / 65536;
        v83 = (unsigned __int64)(v3->dword_000008) * -pClass51_global->dword_000D38 / 65536;
        v86 = v85 + v84 + v83;
        v15 = (double)v86 / 65536.0;
        if ( v15 < 0.0 )
          v15 = 0.0;

        *(float *)&v86 = v15 * 31.0;
        v73 = floorf(v15 * 31 + 0.5f);

        p14->byte_000058 = 31 - (char)v73;
        if (p14->byte_000058 < 0)
           p14->byte_000058 = 0;
        if (p14->byte_000058 > 31)
           p14->byte_000058 = 31;

        if (v3->byte_000010[13] & 0x40)
          v18 = TextureFrameTable_GetFrame(pTextureFrameTable, v3->uTextureID, cClock1.dword_000024);
        else v18 = v3->uTextureID;

        if (v18 == -1)
          p14->ptr_00003C = 0;
        else
          p14->ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[v18];

        if (pStruct9_global->dword_00002C > 1999)
          return;

        ++pStruct9_global->dword_00002C;
        ++pStruct9_global->dword_000044;
        if (!sub_482170(pClass51_global->pBModels[i].ptr_000054, array_73D150, p14))
        {
LABEL_71:
          --pStruct9_global->dword_00002C;
          --pStruct9_global->dword_000044;
          continue;
        }
        LOBYTE(v22) = j;
        v23 = i;

        v3->byte_000131 = 1;

        p14->byte_00005E = i;
        p14->byte_00005F = j;

        LOWORD(v22) = (unsigned __int8)v22;
        v24 = 8 * (v22 | (v23 << 6));
        LOBYTE(v24) = v24 | 6;
        p14->uTextureID = v24;
        if (v3->byte_000010[12] & 0x10)
          p14->word_000030 |= 0x02;
        if (v3->byte_000010[14] & 0x40)
          p14->word_000030 |= 0x0400;

        if (v3->byte_000010[12] & 0x04)
          p14->word_000030 |= 0x0400;
        else if (v3->byte_000010[12] & 0x20)
          p14->word_000030 |= 0x0800;

        if (v3->byte_000010[13] & 0x08)
          p14->word_000030 |= 0x2000;
        else if (v3->byte_000010[12] & 0x40)
          p14->word_000030 |= 0x1000;

        for (k = 0; k < pClass51_global->pBModels[i].ptr_000054[j].uNumVertices; ++k)
        {
            //memcpy((char *)&unk_50AC10 + v32, &array_73D150[v32 / 48], 0x30u);
         memcpy(&array_50AC10[k], &array_73D150[k], sizeof(struct RenderVertex));

            //*(float *)(v32 + 0x50AC00) = v34;
         array_50AC10[k].flt_000020 = 1.0 / (array_73D150[k].flt_00000C + 0.0000001000000011686097);

         //          v33 = v3 + 0x70;
            //v86 = *(_DWORD *)(v14 + 40) + *(_WORD *)(v33 - 40);
            //*(float *)(v32 + 5286916) = (double)v86 * v30;
            //v35 = *(_DWORD *)(v14 + 44) + *(_WORD *)v33;
         v86 = p14->dword_000028 + (signed int)v3->array_000048[k];
         v35 = p14->dword_00002C + (signed int)v3->array_000070[k];

            //*(float *)(v32 + 0x50AC04) = (double)v86 * v30;
         array_50AC10[k].u = v86 * (1.0 / p14->ptr_00003C->uTextureWidth);
           
            //*(float *)(v32 + 0x50AC08) = (double)v35 * v29;
         array_50AC10[k].v = v35 * (1.0 / p14->ptr_00003C->uTextureHeight);
        }


        if ( !(byte_73C830 & 1) )
        {
          byte_73C830 |= 1u;
          sub_49B001(&unk_73C818);
          atexit(loc_47907F);
        }
        sub_45CDB7(v3, pGame->class04_obj);
        if ( dword_F8ADD4 <= 0 )
           p14->byte_000108 = 0;
        else
        {
          v37 = v1 - 8;
          p14->byte_000108 = 1;
          sub_49B04D(&unk_73C818, (int)v3, v37);
          v57 = flt_73C81C;
          v58 = flt_73C820;
          v59 = flt_73C824;
          sub_45CA88(pGame->class04_obj, (int)&dword_F8AD28, (int)array_50AC10, pClass51_global->pBModels[i].ptr_000054[j].uNumVertices, (int)&v57);
        }
        if (v76)
        {
          v38 = sub_4250FE(pClass51_global->pBModels[i].ptr_000054[j].uNumVertices);
          v39 = v38;
          if ( !v38)
            goto LABEL_71;

          sub_481E55(v38);
          v40 = sub_4254D2(v39);
          p14->uNumVertices = v40;
          if (!v40)
            goto LABEL_71;


          sub_48276F((struct8 *)v14);
          for (k = 0; k < p14->uNumVertices; ++k)
          {
              dword_50B638[k] = floorf(array_508690[k].flt_000018 + 0.5f);
              dword_50B570[k] = floorf(array_508690[k].flt_00001C + 0.5f);
          }
        }
        else
        {
          if (v77)
          {
            v45 = sub_4252E8(pClass51_global->pBModels[i].ptr_000054[j].uNumVertices);
            v46 = v45;

            if ( !v45)
              goto LABEL_71;

            sub_481E55(v45);
            v47 = sub_4254D2(v46);
            p14->uNumVertices = v47;
            if (!v47)
              goto LABEL_71;

            sub_48276F((struct8 *)v14);
            
            for (k = 0; k < p14->uNumVertices; ++k)
            {
             dword_50B638[k] = floorf(array_508690[k].flt_000018 + 0.5f);
             dword_50B570[k] = floorf(array_508690[k].flt_00001C + 0.5f);
            }
          }
          else
          {
            v52 = sub_4254D2(pClass51_global->pBModels[i].ptr_000054[j].uNumVertices);
            p14->uNumVertices = v52;
            if (!v52)
              goto LABEL_71;

            sub_4829B9(&array_73D150[v3->byte_00012A], &array_73D150[v3->byte_00012B], &array_73D150[v3->byte_00012C],
                       p14, 0);

            for (k = 0; k < p14->uNumVertices; ++k)
            {
             dword_50B638[k] = floorf(array_508690[k].flt_000018 + 0.5f);
             dword_50B570[k] = floorf(array_508690[k].flt_00001C + 0.5f);
            }
          }
        }
        sub_486B4E(array_508690, dword_50B638, dword_50B570, (struct8 *)v14);
      }
    }
   }
}


//----- (0045CA88) --------------------------------------------------------
int __thiscall sub_45CA88(void *_this, int a2, int a3, int a4, int a5)
{
  int result; // eax@1
  int v6; // ecx@2
  int v7; // ebx@2
  double v8; // st7@2
  double v9; // st6@2
  int v10; // eax@3
  double v11; // st7@5
  float v12; // ST2C_4@5
  float v13; // ST30_4@5
  float v14; // edx@5
  float v15; // eax@5
  float v16; // ST10_4@5
  double v17; // st7@5
  int v18; // [sp+2Ch] [bp-1Ch]@1
  float v19; // [sp+30h] [bp-18h]@1
  float v20; // [sp+34h] [bp-14h]@1
  void *v21; // [sp+38h] [bp-10h]@1
  int v22; // [sp+3Ch] [bp-Ch]@1
  int j; // [sp+40h] [bp-8h]@3
  int i; // [sp+44h] [bp-4h]@1
  float v25; // [sp+58h] [bp+10h]@2

  *(float *)&v18 = 0.0;
  v19 = 0.0;
  v21 = _this;
  v20 = 0.0;
  result = sub_45CBD4(a3, a4, (int)dword_69B010, (int)&v22);
  for ( i = 0; i < v22; result = i )
  {
    v6 = a2;
    LODWORD(v25) = 0;
    v7 = a3 + 48 * dword_69B010[i];
    v8 = *(float *)(v7 + 8);
    v9 = *(float *)(v7 + 4);
    *(float *)&v18 = *(float *)v7;
    v19 = v9;
    v20 = v8;
    *(float *)(v7 + 44) = 0.0;
    if ( *(_DWORD *)(a2 + 172) > 0 )
    {
      v10 = a2 + 416;
      for ( j = a2 + 416; ; v10 = j )
      {
        v11 = (double)*(signed int *)(v10 - 240);
        LODWORD(v12) = *(_DWORD *)(v10 - 80);
        LODWORD(v13) = *(_DWORD *)v10;
        LODWORD(v14) = *(_DWORD *)(v10 + 240);
        v15 = v25;
        LOBYTE(v15) = *(_BYTE *)(v6 + LODWORD(v25) + 976);
        v16 = v11;
        compile_error();//v17 = sub_45CC0C(v12, v13, v14, 1.0, v16, a5, COERCE_FLOAT(&v18), v15) + *(float *)(v7 + 44);
        ++LODWORD(v25);
        j += 4;
        *(float *)(v7 + 44) = v17;
        if (LODWORD(v25) >= *(_DWORD *)(a2 + 172) )
          break;
        v6 = a2;
      }
    }
    ++i;
  }
  return result;
}


//----- (0048276F) --------------------------------------------------------
void __thiscall sub_48276F(struct struct8 *_this)
{
  double v3; // st7@2
  int v8; // ecx@13
  int i; // eax@16
  int v10; // edx@20
  int v11; // edx@22
  int v12; // ecx@22
  float *v13; // esi@22
  int v14; // ebx@26
  float *v15; // ebx@27
  double v16; // st4@28
  double v17; // st5@28
  double v18; // st6@28

  int v23;
  int v24;
  int v25;
  int v29;
  struct
  {
   int v19; // [sp+4h] [bp-2Ch]@20
   int v20; // [sp+8h] [bp-28h]@22
   int v21; // [sp+Ch] [bp-24h]@22
   int v22; // [sp+10h] [bp-20h]@1
   int v23; // [sp+14h] [bp-1Ch]@11

   float v24; // [sp+18h] [bp-18h]@7
   float v25; // [sp+1Ch] [bp-14h]@5
   float v26; // [sp+20h] [bp-10h]@2
   float v27; // [sp+24h] [bp-Ch]@2
   float v28; // [sp+28h] [bp-8h]@2
   float v29; // [sp+2Ch] [bp-4h]@9

   float uncharted_stack[16*array_size_unknown]; //[sp+2C+edx*4]
  } v19;
  int uncharted_stack[16*array_size_unknown];

  v19.v22 = (int)_this;
  if (_this->uNumVertices < 3)
    return;

    v19.v26 = 10000.0;
    v19.v28 = 10000.0;
    v3 = -10000.0;
    v19.v27 = -10000.0;

      for (i = 0; i < _this->uNumVertices; ++i)
      {
        if (array_508690[i].flt_000018 < (double)v19.v26 )
        {
          v25 = i;
          v19.v26 = array_508690[i].flt_000018;
        }
        if (array_508690[i].flt_000018 > (double)v19.v27 )
        {
          v24 = i;
          v19.v27 = array_508690[i].flt_000018;
        }

        if (array_508690[i].flt_00001C < (double)v19.v28 )
        {
          v29 = i;
          v19.v28 = array_508690[i].flt_00001C;
        }
        if (array_508690[i].flt_00001C > v3)
        {
          v23 = i;
          v3 = array_508690[i].flt_00001C;
        }
      }

    v8 = v29;
    if (v29 == v25 || v29 == v24)
      v8 = v23;
    v29 = 0;

    for (i = 0; i < _this->uNumVertices; ++i)
    {
      if (i == v25 || i == v24 || i == v8)
      {
        v10 = v29;
        uncharted_stack[v29++] = i;
      }
    }
    //v12 = (int)&flt_508690[12 * v19.v19];
    //v11 = (int)&flt_508690[12 * v19.v20];
    //v13 = &flt_508690[12 * v19.v21];
    v12 = (int)&array_508690[uncharted_stack[0]];
    v11 = (int)&array_508690[uncharted_stack[1]];
    v13 = (float *)&array_508690[uncharted_stack[2]];

    if (v29 != 3)
    {
      v13 = (float *)&array_508690[_this->uNumVertices - 1];
      v12 = (int)&array_508690[0];
      v11 = (int)&array_508690[1];

      v19.v28 = array_508690[1].x - array_508690[0].x;
      v19.v27 = array_508690[1].z - array_508690[0].z;
      v19.v29 = array_508690[1].y - array_508690[0].y;
      v19.v26 = array_508690[_this->uNumVertices - 1].x - array_508690[0].x;
      v19.v25 = array_508690[_this->uNumVertices - 1].z - array_508690[0].z;
      v19.v24 = array_508690[_this->uNumVertices - 1].y - array_508690[0].y;
      if ( v19.v24 * v19.v27 - v19.v25 * v19.v29 == 0.0 )
      {
        if ( v19.v26 * v19.v29 - v19.v24 * v19.v28 == 0.0 )
        {
          if ( v19.v25 * v19.v28 - v19.v26 * v19.v27 == 0.0 )
          {
            v14 = _this->uNumVertices - 2;
            LODWORD(v19.v26) = v14;
            if ( v14 >= 2 )
            {
              v15 = (float *)&array_508690[v14];
              do
              {
               v18 = *v15 - array_508690[0].x;
               v17 = v15[1] - array_508690[0].z;
               v16 = v15[2] - array_508690[0].y;
                v13 = v15;
                if ( v19.v27 * v16 - v17 * v19.v29 != 0.0 )
                  break;
                if ( v18 * v19.v29 - v16 * v19.v28 != 0.0 )
                  break;
                if ( v19.v28 * v17 - v18 * v19.v27 != 0.0 )
                  break;
                --LODWORD(v19.v26);
                v15 -= 12;
              }
              while (LODWORD(v19.v26) >= 2 );
            }
          }
        }
      }
    }
    //sub_4829B9(v12, v11, (int)v13, &v19.v22, 1);
 sub_4829B9((RenderVertex *)v12, (RenderVertex *)v11, (RenderVertex *)v13, _this, 1);
}


//----- (004254D2) --------------------------------------------------------
int sub_4254D2(signed int a1)
{
  bool v5; // edi@12
  double v11; // st7@16
  double v12; // st7@17
  bool v25; // esi@29
  bool v29; // ecx@32
  double v32; // st7@34
  double v33; // st7@35
  bool v45; // edi@47
  bool v49; // ecx@49
  double v52; // st6@51
  double v53; // st6@52
  void *v63; // edi@61
  bool v65; // edi@64
  bool v69; // ecx@66
  double v72; // st6@68
  int v97; // eax@97
  int v98; // edx@97
  int v99; // edi@97
  int v100; // esi@97
  int v101; // eax@104
  float v105; // [sp+5Ch] [bp-7Ch]@1
  float v106; // [sp+60h] [bp-78h]@1
  float v107; // [sp+64h] [bp-74h]@1
  float v109; // [sp+A8h] [bp-30h]@1
  signed int v110; // [sp+A8h] [bp-30h]@96
  bool v111; // [sp+ACh] [bp-2Ch]@14
  bool v112; // [sp+ACh] [bp-2Ch]@32
  bool v113; // [sp+ACh] [bp-2Ch]@49
  bool v114; // [sp+ACh] [bp-2Ch]@66
  signed int v115; // [sp+B0h] [bp-28h]@12
  signed int v120; // [sp+BCh] [bp-1Ch]@29
  signed int v121; // [sp+BCh] [bp-1Ch]@64
  struct RenderVertex *v127; // [sp+C4h] [bp-14h]@30
  signed int v128; // [sp+C4h] [bp-14h]@47
  signed int v132; // [sp+CCh] [bp-Ch]@2
  struct RenderVertex *v133;
  struct RenderVertex *v134; // [sp+CCh] [bp-Ch]@30
  struct RenderVertex *v139; // [sp+D0h] [bp-8h]@48
  struct RenderVertex *v140; // [sp+D0h] [bp-8h]@65
  signed int v141; // [sp+D4h] [bp-4h]@1
 int i;

 v106 = pOldViewport->uGameX;
 v109 = pOldViewport->uGameY;
 v105 = pOldViewport->uGameZ;
 v107 = pOldViewport->uGameW + 1;

 if (a1 <= 0)
   return a1;

  v132 = a1;
  
 v141 = 1;
 memcpy(array_508690, array_50AC10, a1 * sizeof(struct RenderVertex));
 for (i = 0; i < a1; ++i)
 {
  if (array_50AC10[i].flt_000018 < pOldViewport->uGameX || array_50AC10[i].flt_000018 > pOldViewport->uGameZ)
    v141 = 0;
  if (array_50AC10[i].flt_00001C < pOldViewport->uGameY || array_50AC10[i].flt_00001C > pOldViewport->uGameW + 1)
    v141 = 0;
 }

 if (v141)
   return a1;

 v115 = 0;
 memcpy(&array_50AC10[a1], array_50AC10, sizeof(struct RenderVertex));

 v5 = (int)(floorf(array_50AC10[0].flt_000018 + 0.5f)) >= pOldViewport->uGameX;
 if (a1 < 1)
   return 0;

 v133 = array_50A2B0;
 for (i = 0; i < a1; ++i)
 {
  v111 = (int)(floorf(array_50AC10[i + 1].flt_000018 + 0.5f)) >= pOldViewport->uGameX;

  if (v5 == v111)
    goto LABEL_25;

  if (v111)
  {
   v11 = (pOldViewport->uGameX - array_50AC10[i].flt_000018) /
         (array_50AC10[i + 1].flt_000018 - array_50AC10[i].flt_000018);

   v133->flt_00001C = (array_50AC10[i + 1].flt_00001C - array_50AC10[i].flt_00001C) * v11 + array_50AC10[i].flt_00001C;
   v133->flt_000020 = (array_50AC10[i + 1].flt_000020 - array_50AC10[i].flt_000020) * v11 + array_50AC10[i].flt_000020;
   v133->flt_00002C = (array_50AC10[i + 1].flt_00002C - array_50AC10[i].flt_00002C) * v11 + array_50AC10[i].flt_00002C;
  }
  else
  {
   v12 = (pOldViewport->uGameX - array_50AC10[i + 1].flt_000018) /
         (array_50AC10[i].flt_000018 - array_50AC10[i + 1].flt_000018);

   v133->flt_00001C = (array_50AC10[i].flt_00001C - array_50AC10[i + 1].flt_00001C) * v12 + array_50AC10[i + 1].flt_00001C;
   v133->flt_000020 = (array_50AC10[i].flt_000020 - array_50AC10[i + 1].flt_000020) * v12 + array_50AC10[i + 1].flt_000020;
   v133->flt_00002C = (array_50AC10[i].flt_00002C - array_50AC10[i + 1].flt_00002C) * v12 + array_50AC10[i + 1].flt_00002C;
  }

  v133->flt_000018 = pOldViewport->uGameX;
  if (v5)
  {
   if (floorf(v133->flt_00001C + 0.5f) == floorf(array_50AC10[i].flt_00001C + 0.5f) &&
       floorf(v133->flt_000018 + 0.5f) == floorf(array_50AC10[i].flt_000018 + 0.5f))
      goto LABEL_25;
  }
  else
  {
   if (floorf(v133->flt_00001C + 0.5f) == floorf(array_50AC10[i + 1].flt_00001C + 0.5f) &&
       floorf(v133->flt_000018 + 0.5f) == floorf(array_50AC10[i + 1].flt_000018 + 0.5f))
      goto LABEL_25;
  }
  v133++;
  v115++;

LABEL_25:
  if (v111)
  {
   v115++;
   memcpy(v133++, &array_50AC10[i + 1], sizeof(struct RenderVertex));
  }

  v5 = v111;
 }
  
 v120 = 0;
 if ( v115 < 3)
   return 0;

 memcpy(&array_50A2B0[v115], array_50A2B0, sizeof(struct RenderVertex));
 if (v115 < 1)
   return 0;

  
 v25 = (int)(floorf(array_50A2B0[0].flt_000018 + 0.5f)) <= pOldViewport->uGameZ;
 
 v134 = array_50A2B0;
 v127 = array_509950;

 for (i = 0; i < v115; ++i)
 {
  v29 = (int)(floorf(array_50A2B0[i + 1].flt_000018 + 0.5f)) <= pOldViewport->uGameZ;
  v112 = (int)(floorf(array_50A2B0[i + 1].flt_000018 + 0.5f)) <= pOldViewport->uGameZ;
  if (v25 == v29)
    goto LABEL_43;

  if (v29)
  {
   v32 = (pOldViewport->uGameZ - array_50A2B0[i].flt_000018) /
         (array_50A2B0[i + 1].flt_000018 - array_50A2B0[i].flt_000018);

   v127->flt_00001C = (array_50A2B0[i + 1].flt_00001C - array_50A2B0[i].flt_00001C) * v32 + array_50A2B0[i].flt_00001C;
   v127->flt_000020 = (array_50A2B0[i + 1].flt_000020 - array_50A2B0[i].flt_000020) * v32 + array_50A2B0[i].flt_000020;
   v127->flt_00002C = (array_50A2B0[i + 1].flt_00002C - array_50A2B0[i].flt_00002C) * v32 + array_50A2B0[i].flt_00002C;
  }
  else
  {
   v33 = (pOldViewport->uGameZ - array_50A2B0[i + 1].flt_000018) /
         (array_50A2B0[i].flt_000018 - array_50A2B0[i + 1].flt_000018);

   v127->flt_00001C = (array_50A2B0[i].flt_00001C - array_50A2B0[i + 1].flt_00001C) * v33 + array_50A2B0[i + 1].flt_00001C;
   v127->flt_000020 = (array_50A2B0[i].flt_000020 - array_50A2B0[i + 1].flt_000020) * v33 + array_50A2B0[i + 1].flt_000020;
   v127->flt_00002C = (array_50A2B0[i].flt_00002C - array_50A2B0[i + 1].flt_00002C) * v33 + array_50A2B0[i + 1].flt_00002C;
  }

  v127->flt_000018 = pOldViewport->uGameZ;
  if (v25)
  {
   if (floorf(v127->flt_00001C + 0.5f) != floorf(array_50A2B0[i].flt_00001C + 0.5f) ||
       floorf(v127->flt_000018 + 0.5f) != floorf(array_50A2B0[i].flt_000018 + 0.5f))
     goto LABEL_42;
   goto LABEL_43;
  }
  else
  {
   if (floorf(v134->flt_00001C + 0.5f) != floorf(array_50A2B0[i + 1].flt_00001C + 0.5f) ||
       floorf(v134->flt_000018 + 0.5f) != floorf(array_50A2B0[i + 1].flt_000018 + 0.5f))
     goto LABEL_42;
   goto LABEL_43;
  }

LABEL_42:
  v134++;
  v127++;
  v120++;


LABEL_43:
  if (v29)
  {
   ++v120;
   v134++;
   memcpy(v127++, &array_50A2B0[i + 1], sizeof(struct RenderVertex));
  }

  v25 = v112;
 }


 if (v120 < 3)
   return 0;

 v128 = 0;
 memcpy(&array_509950[v120], array_509950, sizeof(struct RenderVertex));

 v45 = (int)(floorf(array_509950[0].flt_00001C + 0.5f)) >= pOldViewport->uGameY;
 if (v120 < 1)
   return 0;

  
 v139 = array_508FF0;
 for (i = 0; i < v120; ++i)
 {
  v49 = (int)(floorf(array_509950[i + 1].flt_00001C + 0.5f)) >= pOldViewport->uGameY;
  v113 = (int)(floorf(array_509950[i + 1].flt_00001C + 0.5f)) >= pOldViewport->uGameY;

  if (v45 != v49)
  {
   if (floorf(array_509950[i + 1].flt_00001C + 0.5f) >= pOldViewport->uGameY)
   {
    v52 = (pOldViewport->uGameY - array_509950[i].flt_00001C) / (array_509950[i + 1].flt_00001C - array_509950[i].flt_00001C);
    v139->flt_000018 = (array_509950[i].flt_000018 - array_509950[i].flt_000018) * v52 + array_509950[i].flt_000018;
    v139->flt_000020 = (array_509950[i + 1].flt_000020 - array_509950[i].flt_000020) * v52 + array_509950[i].flt_000020;
    v139->flt_00002C = (array_509950[i + 1].flt_00002C - array_509950[i].flt_00002C) * v52 + array_509950[i].flt_00002C;
   }
   else
   {
    v53 = (pOldViewport->uGameY - array_509950[i + 1].flt_00001C) / (array_509950[i].flt_00001C - array_509950[i + 1].flt_00001C);
    v139->flt_000018 = (array_509950[i].flt_000018 - array_509950[i + 1].flt_000018) * v53 + array_509950[i + 1].flt_000018;
    v139->flt_000020 = (array_509950[i].flt_000020 - array_509950[i + 1].flt_000020) * v53 + array_509950[i + 1].flt_000020;
    v139->flt_00002C = (array_509950[i].flt_00002C - array_509950[i + 1].flt_00002C) * v53 + array_509950[i + 1].flt_00002C;
   }

   v139->flt_00001C = pOldViewport->uGameY;
   if (v45)
   {
    if (floorf(pOldViewport->uGameY) != floorf(array_509950[i].flt_00001C + 0.5f) ||
        floorf(v139->flt_000018 + 0.5f) != floorf(array_509950[i].flt_000018 + 0.5f))
    {
     v139++;
     ++v128;
    }
   }
   else if (floorf(pOldViewport->uGameY) != floorf(array_509950[i + 1].flt_00001C + 0.5f) ||
            floorf(v139->flt_000018 + 0.5f) != floorf(array_509950[i + 1].flt_000018 + 0.5f))
   {
    v139++;
    ++v128;
   }
  }

  if (v49)
  {
   ++v128;
   memcpy(v139++, &array_509950[i + 1], sizeof(struct RenderVertex));
  }

  v45 = v113;
 }


 if (v128 < 3)
   return 0;

 v121 = 0,
 memcpy(&array_508FF0[v128], array_508FF0, sizeof(struct RenderVertex));
 v65 = (int)(floorf(array_508FF0[0].flt_00001C + 0.5f)) <= pOldViewport->uGameW;

 if (v128 < 1)
   return 0;


 v140 = array_508690;
 for (i = 0; i < v128; ++i)
 {
  v69 = floorf(array_508FF0[i + 1].flt_00001C + 0.5f) <= pOldViewport->uGameW;
  v114 = floorf(array_508FF0[i + 1].flt_00001C + 0.5f) <= pOldViewport->uGameW;
  if (v65 != v69)
  {
   if (floorf(array_508FF0[i + 1].flt_00001C + 0.5f) <= pOldViewport->uGameW )
   {
    v72 = (v107 - array_508FF0[i].flt_00001C) / (array_508FF0[i + 1].flt_00001C - array_508FF0[i].flt_00001C);
    v140->flt_000018 = (array_508FF0[i + 1].flt_000018 - array_508FF0[i].flt_000018) * v72 + array_508FF0[i].flt_000018;
    v140->flt_000020 = (array_508FF0[i + 1].flt_000020 - array_508FF0[i].flt_000020) * v72 + array_508FF0[i].flt_000020;
    v140->flt_00002C = (array_508FF0[i + 1].flt_00002C - array_508FF0[i].flt_00002C) * v72 + array_508FF0[i].flt_00002C;
   }
   else
   {
    v72 = (v107 - array_508FF0[i + 1].flt_00001C) / (array_508FF0[i].flt_00001C - array_508FF0[i + 1].flt_00001C);
    v140->flt_000018 = (array_508FF0[i].flt_000018 - array_508FF0[i + 1].flt_000018) * v72 + array_508FF0[i + 1].flt_000018;
    v140->flt_000020 = (array_508FF0[i].flt_000020 - array_508FF0[i + 1].flt_000020) * v72 + array_508FF0[i + 1].flt_000020;
    v140->flt_00002C = (array_508FF0[i].flt_00002C - array_508FF0[i + 1].flt_00002C) * v72 + array_508FF0[i + 1].flt_00002C;
   }

   v140->flt_00001C = v107;
   if (v65)
   {
    if (floorf(v107 + 0.5f) != floorf(array_508FF0[i].flt_00001C + 0.5f) ||
        floorf(v140->flt_000018 + 0.5f) != floorf(array_508FF0[i].flt_000018))
    {
     v140++;
     ++v121;
    }
   }
   else if (floorf(v107 + 0.5f) != floorf(array_508FF0[i + 1].flt_00001C) ||
            floorf(v140->flt_000018 + 0.5f) != floorf(array_508FF0[i + 1].flt_000018 + 0.5f))
   {
    v140++;
    ++v121;
   }
  }

  if (v69)
  {
   ++v121;
   memcpy(v140++, &array_508FF0[i + 1], sizeof(struct RenderVertex));
  }

  v65 = v114;
 }

 if (v121 < 3)
   return 0;

 memcpy(&array_508690[v121], array_508690, sizeof(struct RenderVertex));

 for (i = 0; i < v121; ++i)
 {
  array_508690[i].flt_00000C = 1.0 / array_508690[i].flt_000020;

  if (floorf(array_508690[i].flt_000018 + 0.5f) < pOldViewport->uGameX)
    array_508690[i].flt_000018 = v106;
  else if (floorf(array_508690[i].flt_000018 + 0.5f) > pOldViewport->uGameZ)
    array_508690[i].flt_000018 = v105;

  if (floorf(array_508690[i].flt_00001C + 0.5f) > pOldViewport->uGameW)
    array_508690[i].flt_00001C = v107;
  else if (floorf(array_508690[i].flt_00001C + 0.5f) < pOldViewport->uGameY)
    array_508690[i].flt_00001C = v109;
 }

 if (v121 > 3)
 {
  memcpy(&array_508690[v121 + 1], &array_508690[1], sizeof(struct RenderVertex));

  v110 = 1;
  do
  {
   v98 = v110;
   v100 = v110 - 1;
   v99 = v110 + 1;
   v97 = v110 + 1;

   if (v110 - 1 >= v121)
     v100 -= v121;
   if (v110 >= v121)
     v98 = v110 - v121;
   if (v99 >= v121)
     v97 = v99 - v121;

   if ((array_508690[v98].flt_000018 - array_508690[v100].flt_000018) * (array_508690[v97].flt_00001C - array_508690[v100].flt_00001C) -
       (array_508690[v97].flt_000018 - array_508690[v100].flt_000018) * (array_508690[v98].flt_00001C - array_508690[v100].flt_00001C) < 0)
     ++v110;
   else
   {
    v101 = v110;
    if (v110 < v121 || (v101 = v110 - v121, v110 - v121 < v121))
      memcpy(&array_508690[v101], &array_508690[v101 + 1], (v121 - v101) * sizeof(struct RenderVertex));
          --v121;
   }
  }
  while ( v110 - 1 < v121);
 }

 if (v121 >= 3)
   return v121;
 else
   return 0;
}


//----- (004829B9) --------------------------------------------------------
void sub_4829B9(struct RenderVertex *a1, struct RenderVertex *a2, struct RenderVertex *a3, struct struct8 *a4, int a5)
{
  double v6; // st6@1
  double v7; // st7@1
  double v9; // st6@3
  double v10; // st5@3
  float v11; // ST0C_4@3
  float v12; // ST04_4@3
  double v13; // st4@3
  float v14; // [sp+8h] [bp-Ch]@1
  float v15; // [sp+10h] [bp-4h]@1
  float v16; // [sp+1Ch] [bp+8h]@1
  float v17; // [sp+1Ch] [bp+8h]@3

 v7 = a2->flt_000018 - a1->flt_000018;
 v16 = a3->flt_00001C - a1->flt_00001C;
 v15 = a2->flt_00001C - a1->flt_00001C;
 v14 = a3->flt_000018 - a1->flt_000018;
 v6 = v16 * v7 - v14 * v15;
 if ( v6 == 0.0 )
   v6 = 0.0000001000000011686097;
 v9 = 1.0 / v6;

 v10 = 1.0 / a1->flt_00000C;
 v11 = 1.0 / a2->flt_00000C - v10;
 v12 = 1.0 / a3->flt_00000C - v10;
 v13 = (v11 * v16 - v12 * v15) * v9;
 v17 = (v11 * v14 - v12 * v7) * -v9;

 a4->flt_00000C = a1->flt_000018;
 a4->flt_000010 = a1->flt_00001C;

 a4->flt_000000 = v10;
 a4->flt_000004 = v13;
 a4->flt_000008 = v17;
}


//----- (00481DB2) --------------------------------------------------------
void __fastcall sub_481DB2(struct RenderVertex *a1, signed int a2, struct struct8 *a3)
{
  char result; // al@5
 int i;

  if (a2 < 3)
    return;

    a3->ptr_000038 = pClass57_global;
    a3->ptr_00003C = &LODFile_Bitmaps_LOD.aLODHeaders[a3->uTextureID];

    for (i = 0; i < a3->uNumVertices; ++i)
    {
     dword_50B638[i] = floorf(array_508690[i].flt_000018 + 0.5f);
     dword_50B570[i] = floorf(array_508690[i].flt_00001C + 0.5f);
    }
 sub_486B4E(a1, dword_50B638, dword_50B570, a3);
}

//----- (00486B4E) --------------------------------------------------------
void __fastcall sub_486B4E(struct RenderVertex *a1, int *a2, int *a3, struct struct8 *a4)
{
 int v0;
  float v4;
  float v5;
  int v10; // ebx@8
  int v11; // eax@10
  int i; // edx@20
  char v31; // [sp-18h] [bp-98h]@2
  int v32; // [sp-14h] [bp-94h]@2
  int v33; // [sp-10h] [bp-90h]@2
  int v34; // [sp-Ch] [bp-8Ch]@2
  const char *v35; // [sp-8h] [bp-88h]@2
  int v36; // [sp-4h] [bp-84h]@2
  int v45; // [sp+40h] [bp-40h]@28
  int v46; // [sp+44h] [bp-3Ch]@20
  int v52; // [sp+5Ch] [bp-24h]@14
  int v53; // [sp+60h] [bp-20h]@6
  int v54; // [sp+64h] [bp-1Ch]@6
  char *v61; // [sp+8Ch] [bp+Ch]@2
 struct Edge *pEdge;


  if (a4->word_000030 & 0x4000)
  {
    v61 = &v31;
    Game_sub_40E2C8(&v31, "The Texture Frame Table is not a supported feature.", (int)((char *)&a4 + 3));
    sub_466D09(&v31, *(int *)&v31, v32, v33, v34, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Odspan.cpp", __LINE__);
  }

 v0 = a4->byte_000108;
 a4->byte_000108 = 0;

 if (a4->uNumVertices <= 0)
   return;

 if (pStruct9_global->uNumSurfs >= 1999 || pStruct9_global->uNumEdges >= 5979)
   return;

 a4->dword_0000B0 = 0;
 a4->dword_000104= 0;

 v54 = -1;
 v53 = 10000;

 sub_45CB89(a1, a4->uNumVertices);


 for (i = 0; i < a4->uNumVertices; ++i)
 {
  ++pStruct9_global->uNumEdges;

  v10 = i + 1;
  if (v10 >= a4->uNumVertices)
    v10 = 0;

  v11 = a3[i];

  if (a3[i] > v54)
    v54 = a3[i];

  if (a3[i] < v53)
    v53 = a3[i];

  v52 = floorf(a3[v10] - a3[i] + 0.5f);
  if (!v52)
    continue;

  if (v52 >= 0)
  {
   v4 = a3[i];
   v5 = a3[v10];

   ptr_80C978->dword_000008 = 1;

   ptr_80C978->flt_000004 = (double)(a2[v10] - a2[i]) / (double)(a3[v10] - a3[i]);
   ptr_80C978->flt_000000 = (a3[i] - a3[i]) * ptr_80C978->flt_000004 + a2[i];

   if (v0)
   {
    ptr_80C978->flt_00001C = a1[i].flt_00002C;
    ptr_80C978->flt_000020 = a1[v10].flt_00002C;
    ptr_80C978->flt_000024 = a2[i];
    ptr_80C978->flt_000028 = a2[v10];
    ptr_80C978->flt_00002C = a3[i];
    ptr_80C978->flt_000030 = a3[v10];
    a4->array_000060[a4->dword_0000B0++] = ptr_80C978;
   }
  }
  else
  {
   v4 = a3[v10];
   v5 = a3[i];

   ptr_80C978->dword_000008 = 0;
   
   ptr_80C978->flt_000004 = (double)(a2[i] - a2[v10]) / (double)(a3[i] - a3[v10]);
   ptr_80C978->flt_000000 = (a3[v10] - a3[v10]) * ptr_80C978->flt_000004 + a2[v10];

   if (v0)
   {
    ptr_80C978->flt_00001C = a1[v10].flt_00002C;
    ptr_80C978->flt_000020 = a1[i].flt_00002C;
    ptr_80C978->flt_000024 = (double)a2[v10];
    ptr_80C978->flt_000028 = (double)a2[i];
    ptr_80C978->flt_00002C = (double)a3[v10];
    ptr_80C978->flt_000030 = (double)a3[i];
    a4->array_0000B4[a4->dword_000104++] = ptr_80C978;
   }
  }

  v46 = floorf(v4 + 0.5f);
  for (pEdge = &pNewEdgesBuf[v46]; pEdge->pNext->flt_000000 < ptr_80C978->flt_000000; pEdge = pEdge->pNext)
    ;

  if (pEdge->flt_000000 != ptr_80C978->flt_000000 || pEdge->dword_000008 || ptr_80C978->dword_000008 != 1 )
  {
   ptr_80C978->pNext = pEdge->pNext;
   pEdge->pNext = ptr_80C978;
  }
  else
  {
   ptr_80C978->pNext = pEdge;
   pEdge->pPrev->pNext = ptr_80C978;
  }

  v45 = floorf(v5 - 1.0 + 0.5f); 
  ptr_80C978->ptr_000018 = ptr_80CA10[v45];
  ptr_80CA10[v45] = ptr_80C978;

  ptr_80C978->pSurf = ptr_80C97C;
  if (ptr_80C978 < &pEdgesBuf[5999])
    ptr_80C978++;
 }



 if (a4->uNumVertices > 0)
 {
  a4->ptr_000048 = 0;

  ptr_80C97C->flt_000000 = a4->flt_000000;
  ptr_80C97C->flt_000004 = a4->flt_000004;
  ptr_80C97C->flt_000008 = a4->flt_000008;
  ptr_80C97C->flt_00000C = a4->flt_00000C;
  ptr_80C97C->flt_000010 = a4->flt_000010;

  ptr_80C97C->ptr_00001C = a4;

  ptr_80C97C->word_000022 = 0;

  if (ptr_80C97C < &pSurfsBuf[1999])
  {
   ptr_80C97C++;
   pStruct9_global->uNumSurfs++;
  }

  if (v0)
    a4->byte_000108 = 1;
 }
}

//----- (00482A94) --------------------------------------------------------
signed int __thiscall sub_482A94(int _this)
{
  signed int v1; // ebx@1
  int ebp0; // ebp@0
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@1
  int v6; // eax@1
  int v7; // eax@1
  int v8; // edx@1
  int v9; // eax@1
  int v10; // ecx@1
  int v11; // edx@1
  int v12; // ebx@1
  int v13; // eax@1
  int v14; // ebx@2
  signed int v15; // ebx@3
  signed __int64 v16; // qtt@3
  int v17; // eax@3
  int v18; // eax@14
  int v19; // eax@15
  int v20; // eax@21
  signed int v21; // eax@21
  int v22; // ecx@21
  int v23; // eax@21
  int v24; // edx@21
  int v25; // eax@21
  signed int v27; // [sp-4h] [bp-A4h]@8
  int v28; // [sp+Ch] [bp-94h]@1
  int v29; // [sp+10h] [bp-90h]@1
  char v30; // [sp+14h] [bp-8Ch]@21
  int v31; // [sp+3Ch] [bp-64h]@21
  int v32; // [sp+40h] [bp-60h]@21
  int v33; // [sp+44h] [bp-5Ch]@21
  int v34; // [sp+48h] [bp-58h]@21
  int v35; // [sp+4Ch] [bp-54h]@21
  int v36; // [sp+60h] [bp-40h]@21
  int v37; // [sp+64h] [bp-3Ch]@1
  int v38; // [sp+68h] [bp-38h]@21
  int v39; // [sp+6Ch] [bp-34h]@21
  char *v40; // [sp+70h] [bp-30h]@21
  int v41; // [sp+74h] [bp-2Ch]@3
  int v42; // [sp+78h] [bp-28h]@21
  int v43; // [sp+7Ch] [bp-24h]@21
  int v44; // [sp+80h] [bp-20h]@1
  int v45; // [sp+84h] [bp-1Ch]@1
  int v46; // [sp+88h] [bp-18h]@1
  int v47; // [sp+8Ch] [bp-14h]@1
  int v48; // [sp+90h] [bp-10h]@1
  int v49; // [sp+94h] [bp-Ch]@1
  int v50; // [sp+98h] [bp-8h]@1
  int X; // [sp+9Ch] [bp-4h]@1

  v3 = _this;
  v4 = *(_DWORD *)(_this + 4);
  v5 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - *(_WORD *)(_this + 10));
  v6 = *(_DWORD *)(v4 + 56);
  v50 = v5;
  v49 = *(_DWORD *)(v6 + 20);
  v50 = (unsigned __int64)(v49 * v5) >> 16;
  v7 = *(_DWORD *)(v4 + 56);
  v8 = v50 + *(_DWORD *)(v7 + 12);
  v49 = *(_DWORD *)(v7 + 32);
  v45 = v8;
  v9 = ((unsigned __int64)(v49 * v5) >> 16) + *(_DWORD *)(*(_DWORD *)(v4 + 56) + 24);
  v50 = v5;
  v46 = v9;
  v49 = *(_DWORD *)(v4 + 32);
  v50 = (unsigned __int64)(v49 * v5) >> 16;
  v10 = *(_DWORD *)(v4 + 24);
  v28 = *(_DWORD *)(v4 + 40) << 16;
  v47 = *(_DWORD *)(v4 + 44) << 16;
  v11 = *(_WORD *)(v3 + 8);
  v29 = pStruct9_global->camera_rotation_y_int_sine;
  v44 = pStruct9_global->camera_rotation_y_int_cosine;
  v37 = *(_WORD *)(v3 + 12);
  v12 = *(_DWORD *)(v4 + 36);
  v49 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v11);
  v13 = *(_DWORD *)(v4 + 28);
  v1 = -v12;
  v48 = v1;
  X = ((unsigned __int64)(v49 * v13) >> 16) + v50 + v10;
  if ( !X || (v14 = abs(v1 >> 14), v14 > abs(X)) )
    return 0;
  LODWORD(v16) = v48 << 16;
  HIDWORD(v16) = v48 >> 16;
  v50 = v16 / X;
  v17 = *(_DWORD *)(v4 + 56);
  X = v49;
  v48 = *(_DWORD *)(v17 + 16);
  X = v49;
  v48 = v45 + ((unsigned __int64)(v48 * v49) >> 16);
  v45 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 28);
  X = (unsigned __int64)(v45 * v49) >> 16;
  v46 += (unsigned __int64)(v45 * v49) >> 16;
  v15 = 2;
  v41 = *(_DWORD *)(*(_DWORD *)(v4 + 60) + 56);
  if ( v50 >= dword_6BE0E4 << 16 )
  {
    if ( v50 >= dword_6BE0E8 << 16 )
    {
      if ( v50 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v27 = 3;
      }
      else
      {
        v27 = 2;
      }
      v15 = v27;
      goto LABEL_12;
    }
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
LABEL_12:
  if ( v15 < *(_DWORD *)(v4 + 72) )
    v15 = *(_DWORD *)(v4 + 72);
  v18 = *(_DWORD *)(v4 + 60);
  if ( v15 )
  {
    if ( v15 == 1 )
    {
      v19 = *(_DWORD *)(v18 + 52);
    }
    else
    {
      if ( v15 == 2 )
        v19 = *(_DWORD *)(v18 + 56);
      else
        v19 = *(_DWORD *)(v18 + 60);
    }
  }
  else
  {
    v19 = *(_DWORD *)(v18 + 48);
  }
  v41 = v19;
  X = (unsigned __int64)(v48 * v50) >> 16;
  v20 = *(_DWORD *)(v4 + 56);
  X = v50;
  v39 = v28 + ((unsigned __int64)(v48 * v50) >> 16) - *(_DWORD *)(v20 + 36);
  X = (unsigned __int64)(v46 * v50) >> 16;
  v21 = X - *(_DWORD *)(*(_DWORD *)(v4 + 56) + 40) - v47;
  v22 = v15 + (unsigned __int8)bUseLoResSprites;
  v39 >>= v22;
  v38 = v21 >> v22;
  v47 = pStruct9_global->dword_000018;
  v49 = (signed int)((unsigned __int64)(pStruct9_global->dword_000018 * v50) >> 16) >> v22;
  v32 = (unsigned __int64)(v49 * v29) >> 16;
  X = (unsigned __int64)(v49 * v44) >> 16;
  v31 = -(signed int)((unsigned __int64)(v49 * v44) >> 16);
  v23 = *(_WORD *)(v3 + 10);
  v43 = (int)(pD3DRenderer->pTargetSurface + (*(_WORD *)(v3 + 8) + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(v3 + 10)));
  HIWORD(v22) = HIWORD(v50);
  v42 = (int)(&pD3DRenderer->pActiveZBuffer[(*(_WORD *)(v3 + 8) + 640 * v23)]);
  LOWORD(v22) = 0;
  v36 = v22 | *(_WORD *)(v4 + 80);
  v24 = *(_DWORD *)(v4 + 60);
  v44 = (signed int)*(_WORD *)(v24 + 24) >> v15;
  v25 = ((signed int)*(_WORD *)(v24 + 26) >> v15 << 16) - 65536;
  v35 = v15 - *(_WORD *)(v24 + 28) + 16;
  v34 = v44 - 1;
  v33 = v25;
  v40 = sub_485E1F((int *)&v30, (Span *)v3, v50, (struct8 *)v4, dword_6BE0DC, 1u, 1);
  if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
    sub_485975((sub_485975_stru0 *)&v31, (sub_485975_stru1 *)&v30);
  else
    sub_4D6FB0(ebp0);
  return 1;
}

//----- (004839BD) --------------------------------------------------------
signed int __fastcall sub_4839BD(int a1, int a2)
{
  int v2; // ebx@1
  int ebp0; // ebp@0
  signed int v4; // edi@1
  int v5; // esi@1
  int v6; // eax@1
  int v7; // edi@1
  int v8; // ebx@1
  int v9; // ecx@1
  int v10; // ecx@1
  int v11; // eax@1
  int v12; // eax@1
  int v13; // edx@1
  int v14; // eax@1
  int v15; // edi@1
  int v16; // ecx@1
  int v17; // eax@1
  int v18; // edi@2
  int v19; // eax@3
  signed int v20; // edi@3
  signed __int64 v21; // qtt@3
  int v22; // eax@4
  int v23; // eax@6
  int v24; // eax@8
  int v25; // eax@10
  signed int v26; // edx@13
  int v27; // edi@13
  int v28; // eax@13
  int v29; // edi@13
  signed int v30; // edx@13
  int v31; // ebx@13
  signed int v32; // eax@13
  signed int v33; // eax@13
  int v34; // ebx@13
  int v35; // ebx@15
  int v36; // eax@15
  int v37; // eax@16
  int v38; // ecx@17
  signed __int64 v39; // qtt@17
  int v40; // eax@19
  int v41; // ebx@21
  int v42; // eax@21
  int v43; // ebx@21
  int v44; // eax@21
  char v45; // zf@25
  int v46; // ebx@28
  int v47; // eax@28
  int v48; // eax@28
  int v49; // eax@29
  int v50; // eax@30
  int v51; // ecx@30
  signed __int64 v52; // qtt@30
  int v53; // edx@31
  int v54; // eax@33
  int v55; // ebx@33
  signed int v56; // ebx@33
  int v57; // eax@33
  unsigned __int64 v58; // qax@33
  int v60; // [sp+Ch] [bp-BCh]@1
  int v61; // [sp+10h] [bp-B8h]@1
  int v62; // [sp+14h] [bp-B4h]@2
  int v63; // [sp+18h] [bp-B0h]@1
  int v64; // [sp+1Ch] [bp-ACh]@21
  int v65; // [sp+20h] [bp-A8h]@21
  int v66; // [sp+24h] [bp-A4h]@13
  int v67; // [sp+28h] [bp-A0h]@13
  int v68; // [sp+2Ch] [bp-9Ch]@13
  int v69; // [sp+40h] [bp-88h]@21
  int v70; // [sp+44h] [bp-84h]@13
  int v71; // [sp+48h] [bp-80h]@21
  int v72; // [sp+4Ch] [bp-7Ch]@21
  char *v73; // [sp+50h] [bp-78h]@13
  int v74; // [sp+54h] [bp-74h]@3
  int v75; // [sp+58h] [bp-70h]@1
  int v76; // [sp+5Ch] [bp-6Ch]@1
  char v77; // [sp+60h] [bp-68h]@13
  int v78; // [sp+88h] [bp-40h]@13
  int v79; // [sp+8Ch] [bp-3Ch]@1
  int v80; // [sp+90h] [bp-38h]@13
  int v81; // [sp+94h] [bp-34h]@3
  int v82; // [sp+98h] [bp-30h]@1
  int v83; // [sp+9Ch] [bp-2Ch]@1
  int v84; // [sp+A0h] [bp-28h]@1
  int v85; // [sp+A4h] [bp-24h]@13
  int v86; // [sp+A8h] [bp-20h]@1
  int v87; // [sp+ACh] [bp-1Ch]@3
  int v88; // [sp+B0h] [bp-18h]@1
  int v89; // [sp+B4h] [bp-14h]@1
  int X; // [sp+B8h] [bp-10h]@1
  int v91; // [sp+BCh] [bp-Ch]@21
  int v92; // [sp+C0h] [bp-8h]@13
  int v93; // [sp+C4h] [bp-4h]@1

  v6 = *(_WORD *)(a1 + 10);
  v7 = *(_WORD *)(a1 + 8);
  v5 = *(_DWORD *)(a1 + 4);
  v8 = v7 + pD3DRenderer->uTargetSurfacePitch * *(_WORD *)(a1 + 10);
  v61 = a1;
  v9 = *(_WORD *)(a1 + 12);
  v76 = a2 + 2 * v8;
  v86 = v9;
  v75 = (int)(&pD3DRenderer->pActiveZBuffer[v7 + 640 * v6]);
  v2 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v7);
  v10 = pStruct9_global->dword_000018 * (pOldViewport->dword_00002C - v6);
  v11 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 20);
  v88 = pStruct9_global->dword_000018 * (pOldViewport->dword_000028 - v7);
  v84 = v11;
  v93 = (unsigned __int64)(v11 * v10) >> 16;
  v12 = *(_DWORD *)(v5 + 56);
  v13 = v93 + *(_DWORD *)(v12 + 12);
  v84 = *(_DWORD *)(v12 + 32);
  v79 = v13;
  v14 = ((unsigned __int64)(v84 * v10) >> 16) + *(_DWORD *)(*(_DWORD *)(v5 + 56) + 24);
  v93 = v10;
  v82 = v14;
  v84 = *(_DWORD *)(v5 + 32);
  v93 = (unsigned __int64)(v84 * v10) >> 16;
  v15 = *(_DWORD *)(v5 + 36);
  v16 = v93 + *(_DWORD *)(v5 + 24);
  v83 = *(_DWORD *)(v5 + 40) << 16;
  v63 = *(_DWORD *)(v5 + 44) << 16;
  v17 = *(_DWORD *)(v5 + 28);
  v4 = -v15;
  v60 = v16;
  v89 = v4;
  v93 = (unsigned __int64)(v88 * v17) >> 16;
  X = v93 + v16;
  if ( !(v93 + v16) || (v62 = v4 >> 14, v18 = abs(v4 >> 14), v18 > abs(X)) )
    return 0;
  LODWORD(v21) = v89 << 16;
  HIDWORD(v21) = v89 >> 16;
  v81 = v21 / X;
  v20 = v21 / X;
  v19 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v74 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 56);
  v87 = 2;
  if ( v20 >= dword_6BE0E4 << 16 )
  {
    if ( v20 >= dword_6BE0E8 << 16 )
    {
      if ( v20 >= dword_6BE0EC << 16 )
      {
        if ( bUseLoResSprites )
          goto LABEL_12;
        v25 = *(_DWORD *)(v5 + 60);
        v87 = 3;
        v19 = *(_DWORD *)(v25 + 60);
      }
      else
      {
        v24 = *(_DWORD *)(v5 + 60);
        v87 = 2;
        v19 = *(_DWORD *)(v24 + 56);
      }
    }
    else
    {
      v23 = *(_DWORD *)(v5 + 60);
      v87 = 1;
      v19 = *(_DWORD *)(v23 + 52);
    }
  }
  else
  {
    v22 = *(_DWORD *)(v5 + 60);
    v87 = 0;
    v19 = *(_DWORD *)(v22 + 48);
  }
  v74 = v19;
LABEL_12:
  if ( v19 )
  {
    v73 = sub_485E1F((int *)&v77, (Span *)v61, v20, (struct8 *)v5, dword_6BE0DC, 1u, 1);
    v70 = 16;
    v78 = v86 >> 4;
    v93 = v2;
    v28 = *(_DWORD *)(v5 + 56);
    v84 = v86 - 16 * (v86 >> 4);
    v88 = *(_DWORD *)(v28 + 16);
    v93 = v2;
    v86 = v79 + ((unsigned __int64)(v88 * v2) >> 16);
    v88 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 28);
    v88 = v82 + ((unsigned __int64)(v88 * v2) >> 16);
    v93 = (unsigned __int64)(v86 * v20) >> 16;
    v29 = ((unsigned __int64)(v86 * v20) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 36);
    v93 = (unsigned __int64)(v88 * v81) >> 16;
    v30 = v63 + ((unsigned __int64)(v88 * v81) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40);
    v88 = v87 + (unsigned __int8)bUseLoResSprites;
    v85 = v2 - 16 * pStruct9_global->dword_000018;
    v31 = *(_DWORD *)(v5 + 60);
    v27 = (v83 + v29) >> v88;
    v26 = v30 >> v88;
    v32 = (signed int)*(_WORD *)(v31 + 24) >> v87;
    v86 = (signed __int16)v87;
    v80 = v26;
    v92 = v32;
    v33 = (signed int)*(_WORD *)(v31 + 26) >> v87;
    v34 = v87 - *(_WORD *)(v31 + 28);
    v66 = (v33 << 16) - 65536;
    v93 = 2 * cClock2.dword_000024;
    v68 = v34 + 16;
    v67 = v92 - 1;
    if ( v78 > 0 )
    {
      v86 = v78;
      v78 = 12 - v87;
      do
      {
        v92 = *(_DWORD *)(v5 + 28);
        v36 = (unsigned __int64)(v92 * v85) >> 16;
        v35 = v36 + v60;
        X = v36 + v60;
        if ( v36 + v60 && (v92 = abs(v62), v37 = abs(v35), v92 <= v37) )
        {
          LODWORD(v39) = v89 << 16;
          HIDWORD(v39) = v89 >> 16;
          v92 = v39 / X;
          v38 = v39 / X;
          X = v39 / X;
        }
        else
        {
          X = 1073741824;
          v38 = 1073741824;
        }
        HIWORD(v40) = HIWORD(v38);
        if ( v38 <= v81 )
          HIWORD(v40) = HIWORD(v81);
        LOWORD(v40) = 0;
        v69 = *(_WORD *)(v5 + 80) | v40;
        v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
        v91 = v79 + ((unsigned __int64)(v91 * v85) >> 16);
        v92 = (unsigned __int64)(v91 * v38) >> 16;
        v42 = *(_DWORD *)(v5 + 56);
        v43 = ((unsigned __int64)(v91 * v38) >> 16) - *(_DWORD *)(v42 + 36);
        v91 = *(_DWORD *)(v42 + 28);
        v91 = v82 + ((unsigned __int64)(v91 * v85) >> 16);
        v92 = (unsigned __int64)(v91 * v38) >> 16;
        v41 = (v83 + v43) >> v88;
        v91 = (signed int)(v63 + ((unsigned __int64)(v91 * v38) >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v88;
        v65 = (v41 - v27) >> 4;
        v64 = (v91 - v80) >> 4;
        v72 = v27 + 4 * class59_SinCos(pClass59_global, v93 + (v80 >> v78));
        v44 = class59_SinCos(pClass59_global, v93 + (v27 >> v78) - pClass59_global->uIntegerHalfPi);
        v71 = v80 + 4 * v44;
        if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          sub_485975((sub_485975_stru0 *)&v64, (sub_485975_stru1 *)&v77);
        else
          sub_4D6FB0(ebp0);
        v73 = sub_485E1F((int *)&v77, (Span *)v61, X, (struct8 *)v5, dword_6BE0DC, 1u, 0);
        v85 -= 16 * pStruct9_global->dword_000018;
        v45 = v86-- == 1;
        v70 = 16;
        v27 = v41;
        v80 = v91;
      }
      while ( !v45 );
      v26 = v91;
    }
    if ( !v84 )
      return 1;
    v78 = 12 - v87;
    v72 = v27 + 4 * class59_SinCos(pClass59_global, v93 + (v26 >> (12 - v87)));
    v47 = class59_SinCos(pClass59_global, v93 + (v27 >> v78) - pClass59_global->uIntegerHalfPi);
    v71 = v80 + 4 * v47;
    v91 = *(_DWORD *)(v5 + 28);
    v92 = (unsigned __int64)(v91 * v85) >> 16;
    v48 = (unsigned __int64)(v91 * v85) >> 16;
    v46 = v48 + v60;
    X = v48 + v60;
    if ( v48 + v60 )
    {
      v91 = abs(v62);
      v49 = abs(v46);
      if ( v91 <= v49 )
      {
        LODWORD(v52) = v89 << 16;
        HIDWORD(v52) = v89 >> 16;
        v89 = v52 / X;
        v51 = v52 / X;
        HIWORD(v50) = HIWORD(v81);
        if ( v51 <= v81 )
        {
          LOWORD(v50) = 0;
          v69 = v50 | *(_WORD *)(v5 + 80);
        }
        else
        {
          HIWORD(v53) = HIWORD(v51);
          LOWORD(v53) = 0;
          v69 = v53 | *(_WORD *)(v5 + 80);
        }
        v91 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + 16);
        v89 = (unsigned __int64)(v91 * v85) >> 16;
        v91 = v79 + ((unsigned __int64)(v91 * v85) >> 16);
        v79 = (unsigned __int64)(v91 * v51) >> 16;
        v54 = *(_DWORD *)(v5 + 56);
        v55 = v79 - *(_DWORD *)(v54 + 36);
        v91 = *(_DWORD *)(v54 + 28);
        v56 = v83 + v55;
        v83 = (unsigned __int64)(v91 * v85) >> 16;
        v57 = v82 + ((unsigned __int64)(v91 * v85) >> 16);
        v91 = v57;
        v58 = v57 * v51;
        v82 = v58 >> 16;
        LODWORD(v58) = (signed int)(v63 + (v58 >> 16) - *(_DWORD *)(*(_DWORD *)(v5 + 56) + 40)) >> v88;
        v65 = ((v56 >> v88) - v27) >> 4;
        v64 = ((_DWORD)v58 - v80) >> 4;
        v70 = v84;
        if ( byte_4D8410[572] && *(_BYTE *)(LODWORD(pGame) + 3617) & 8 )
          sub_485975((sub_485975_stru0 *)&v64, (sub_485975_stru1 *)&v77);
        else
          sub_4D6FB0(ebp0);
        return 1;
      }
    }
  }
  return 0;
}


//----- (00481212) --------------------------------------------------------
void __fastcall sub_481212(int a1, int a2, int a3)
{
  int v3; // edi@1
  int v4; // esi@1
  int v5; // ecx@1
  int v6; // ST10_4@1
  int v7; // ebx@2
  int v8; // eax@2
  struct RenderVertex *v10; // edi@3
  struct RenderVertex *v11; // ecx@4
  struct RenderVertex *v12; // ebx@4
  struct struct8 *v16; // ebx@12
  __int16 v17; // ax@12
  int v18; // eax@13
  int v20; // ecx@13
  double v24; // st7@18
  double v25; // st5@24
  double v26; // st5@24
  double v27; // st5@24
  double v28; // st5@24
  float v29; // eax@25
  int v30; // edi@29
  double v31; // st7@31
  int v32; // esi@35
  int v33; // edx@36
  int v34; // ecx@36
  signed int v35; // eax@39
  int v36; // esi@40
  struct struct8 *v37; // ebx@43
  int v39; // eax@44
  int v40; // eax@44
  int v41; // ecx@44
  int v42; // eax@44
  int v43; // eax@44
  int v44; // eax@44
  double v46; // st7@49
  double v47; // st5@57
  double v48; // st5@57
  double v49; // st5@57
  float v50; // eax@58
  int v51; // edi@62
  double v52; // st7@63
  int v53; // esi@66
  int v54; // eax@69
  signed int v55; // esi@71
  int v57; // eax@76
  int v58; // eax@76
  struct Vec3 *pNormal; // eax@77
  double v60; // st7@80
  double v61; // st5@88
  double v62; // st5@88
  double v63; // st5@88
  float v64; // eax@89
  double v65; // st7@94
  int v68; // [sp-Ch] [bp-C4h]@36
  int v69; // [sp-8h] [bp-C0h]@36
  int v70; // [sp-4h] [bp-BCh]@36
  char v71; // [sp+Ch] [bp-ACh]@88
  double v73; // [sp+18h] [bp-A0h]@82
  double v75; // [sp+28h] [bp-90h]@51
  char v79; // [sp+48h] [bp-70h]@57
  int v82; // [sp+54h] [bp-64h]@1
  int v83; // [sp+58h] [bp-60h]@6
  int v84; // [sp+5Ch] [bp-5Ch]@82
  int v85; // [sp+60h] [bp-58h]@20
  int v86; // [sp+64h] [bp-54h]@1
  int v87; // [sp+68h] [bp-50h]@1
  int v88; // [sp+6Ch] [bp-4Ch]@51
  float v89; // [sp+70h] [bp-48h]@51
  int v90; // [sp+74h] [bp-44h]@6
  int v91; // [sp+78h] [bp-40h]@1
  char v92; // [sp+7Ch] [bp-3Ch]@24
  int v93; // [sp+80h] [bp-38h]@2
  float v94; // [sp+84h] [bp-34h]@44
  int v95; // [sp+88h] [bp-30h]@6
  float v96; // [sp+8Ch] [bp-2Ch]@1
  float v97; // [sp+90h] [bp-28h]@1
  float v98; // [sp+94h] [bp-24h]@1
  int X; // [sp+98h] [bp-20h]@1
  float v100; // [sp+9Ch] [bp-1Ch]@6
  int v101; // [sp+A0h] [bp-18h]@6
  int v102; // [sp+A4h] [bp-14h]@6
  struct RenderVertex *v105; // [sp+B0h] [bp-8h]@6
  float v107; // [sp+C0h] [bp+8h]@6
  float v108; // [sp+C0h] [bp+8h]@6

  v4 = a1;
  v5 = *(_WORD *)(a3 + 4);
  v6 = *(_WORD *)(a3 + 6);
  v86 = a2;
  v87 = v5;
  X = abs(v6);
  v3 = 0;
  v91 = 0;
  v82 = v4 - 1;
  v96 = pClass51_global->dword_000D30 / 65536.0;
  v97 = pClass51_global->dword_000D34 / 65536.0;
  v98 = pClass51_global->dword_000D38 / 65536.0;
  if ( v4 - 1 > 0 )
  {
    while ( 1 )
    {
      v7 = abs(X);
      v8 = abs(v87);
      --X;
      v93 = (int)(4 * ((v7 * 128) + v8) + byte_76E5C8);

      if ( !byte_76E5C8[4 * ((v7 * 128) + v8)])
        goto LABEL_105;

      v10 = &array_806210[v3];
      if (!v86)
      {
       v12 = &array_801A10[v3];
       v11 = &array_806210[v3 + 1];
      }
      else
      {
       v12 = &array_806210[v3 + 1];
       v11 = &array_801A10[v3];
      }
      v105 = &array_801A10[v3 + 1];

      v102 = floorf(v10->x + 0.5);
      v101 = floorf(v10->z + 0.5);

      v107 = (v11->x + v10->x) / 2;
      v90 = floorf(v107 + 0.5f);
      v95 = WorldPosToGridCellX(v90);

      v108 = (v12->z + v10->z) / 2;
      v83 = floorf(v108 + 0.5f);
      LODWORD(v100) = WorldPosToGridCellZ(v83);

      WorldPosToGridCellX(v102);
      WorldPosToGridCellZ(v101);

      if ((!byte_4D8410[572] || !(pGame->uSomeFlags & 0x80)) && !sub_481EFA(v10, v12, v11, v105, 1))
        goto LABEL_105;

      if (v10->y != v12->y ||
          v12->y != v105->y ||
          v105->y != v11->y)
        break;

      v16 = &array_77EC08[pStruct9_global->dword_00002C];
      v17 = class51_GetTileTexture(pClass51_global, v102, v101);
      array_77EC08[pStruct9_global->dword_00002C].uTextureID = v17;
      if ( v17 != -1 )
      {
        v20 = LODWORD(v100);
        array_77EC08[pStruct9_global->dword_00002C].word_000030 = 0x8010 | class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v102, v101);
        array_77EC08[pStruct9_global->dword_00002C].byte_000059 = 1;
        array_77EC08[pStruct9_global->dword_00002C].byte_00005C = v95;
        array_77EC08[pStruct9_global->dword_00002C].byte_00005D = v20;
        array_77EC08[pStruct9_global->dword_00002C].dword_000034 = *(_WORD *)(v93 + 2);
        v18 = (unsigned __int16)pClass51_global->pTerrainNormalIndices[2 * (v20 + (v95 * 128)) + 1];
        if (v18 < 0 || v18 > pClass51_global->uNumTerrainNormals - 1)
          pNormal = 0;
        else
          pNormal = pClass51_global->pTerrainNormals + v18;

        if (pNormal)
        {
         v24 = -(v98 * pNormal->y + v97 * pNormal->z + v96 * pNormal->x);
          if ( v24 < 0.0 )
            v24 = 0.0;
          v100 = v24 * 31.0;
          v85 = floorf(v100 + 0.5f);
          array_77EC08[pStruct9_global->dword_00002C].byte_000058 = 31 - (char)(v85);
        }
        else
          array_77EC08[pStruct9_global->dword_00002C].byte_000058 = 0;

        if ( pStruct9_global->dword_00002C >= 1999 )
          return;
        ++pStruct9_global->dword_00002C;
        if ( !sub_481FC9(v10, v12, v11, v16) )
          goto LABEL_104;

        v25 = 1.0 / (v10->flt_00000C + 0.0000001000000011686097);
        memcpy(&array_50AC10[0], v10, sizeof(struct RenderVertex));
        array_50AC10[0].flt_000020 = v25;
        array_50AC10[0].u = 0.0;
        array_50AC10[0].v = 0.0;

        v26 = v12->flt_00000C + 0.0000001000000011686097;
        memcpy(&array_50AC10[1], v12, sizeof(struct RenderVertex));
        array_50AC10[1].flt_000020 = 1.0 / v26;
        array_50AC10[1].u = 0.0;
        array_50AC10[1].v = 1.0;

        v27 = v105->flt_00000C + 0.0000001000000011686097;
        memcpy(&array_50AC10[2], v105, sizeof(struct RenderVertex));
        array_50AC10[2].flt_000020 = 1.0 / v27;
        array_50AC10[2].u = 1.0;
        array_50AC10[2].v = 1.0;

        v28 = v11->flt_00000C + 0.0000001000000011686097;
        memcpy(&array_50AC10[3], v11, sizeof(struct RenderVertex));
        array_50AC10[3].flt_000020 = 1.0 / v28;
        array_50AC10[3].u = 1.0;
        array_50AC10[3].v = 0.0;

        sub_45D036(pNormal, (int)&v92, array_50AC10, 4, 1);
        if ( dword_F8ADD4 <= 0 )
        {
          v16->byte_000108 = 0;
        }
        else
        {
          v29 = *(float *)&pGame;
          v16->byte_000108 = 1;
          sub_45CA88(*(void **)(LODWORD(v29) + 3656), (int)&dword_F8AD28, (int)array_50AC10, 4, (int)pNormal);
        }
        if (v10->flt_00000C < 8.0
          || v12->flt_00000C < 8.0
          || (v30 = (int)v11, v11->flt_00000C < 8.0)
          || v105->flt_00000C < 8.0 )
        {
          v35 = sub_4250FE(4);
        }
        else
        {
          v31 = (double)pStruct9_global->shading_dist_mist;
          if (v31 >= v10->flt_00000C &&
              v31 >= v12->flt_00000C &&
              v31 >= v11->flt_00000C &&
              v31 >= v105->flt_00000C)
          {
            v32 = sub_4254D2(4);
            v16->uNumVertices = v32;
            if ( !v32 )
              goto LABEL_104;
            v33 = (int)v12;
            v34 = (int)v10;
            v70 = 0;
            v69 = (int)v16;
            v68 = v30;
            goto LABEL_37;
          }
          v35 = sub_4252E8(4);
        }
        v36 = v35;
        if ( !v35 )
          goto LABEL_104;
LABEL_41:
        sub_481E55(v36);
LABEL_102:
        v32 = sub_4254D2(v36);
        v16->uNumVertices = v32;
        if ( !v32 )
          goto LABEL_104;
        sub_48276F((struct8 *)v16);
        goto LABEL_38;
      }
LABEL_105:
      v3 = v91 + 1;
      //v67 = __SETO__(v91 + 1, v82);
      //v66 = v91++ + 1 - v82 < 0;
      if (++v91 >= v82)
        return;
    }
    v37 = &array_77EC08[pStruct9_global->dword_00002C];
    array_77EC08[pStruct9_global->dword_00002C].uTextureID = class51_GetTileTexture(pClass51_global, v102, v101);
    if (array_77EC08[pStruct9_global->dword_00002C].uTextureID == -1)
      goto LABEL_105;
    v40 = 0x80 | class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v102, v101);

    v41 = LODWORD(v100);
    array_77EC08[pStruct9_global->dword_00002C].word_000030 = v40;
    v42 = v93;
    v37->byte_000059 = 1;
    v37->byte_00005D = v41;
    v37->dword_000034 = *(_WORD *)(v42 + 2);
    v43 = v95;
    v37->byte_00005C = v95;
    v44 = 4 * (v41 + (v43 << 7));
    LODWORD(v94) = v44;
    v39 = *(unsigned __int16 *)((char *)pClass51_global->pTerrainNormalIndices + v44 + 2);
    if ( v39 < 0 || v39 > pClass51_global->uNumTerrainNormals - 1 )
      pNormal = 0;
    else
      pNormal = pClass51_global->pTerrainNormals + v39;

    if (pNormal)
    {
      v46 = -(v98 * pNormal->y + v97 * pNormal->z + v96 * pNormal->x);
      if ( v46 < 0.0 )
        v46 = 0.0;
      v89 = v46 * 31.0;
      v75 = v89 + 6.755399441055744e15;
      v88 = LODWORD(v75);
      v37->byte_000058 = 31 - LOBYTE(v75);
    }
    else
    {
     v37->byte_000058 = 0;
    }
    if (v37->byte_000058 < 0 )
      v37->byte_000058 = 0;
    if ( pStruct9_global->dword_00002C >= 1999 )
      return;
    ++pStruct9_global->dword_00002C;
    if ( !sub_481FC9(v12, v105, v10, v37) )
      goto LABEL_74;

    v47 = 1.0 / (v10->flt_00000C + 0.0000001000000011686097);
    memcpy(&array_50AC10[0], v10, sizeof(struct RenderVertex));
    array_50AC10[0].flt_000020 = v47;
    array_50AC10[0].u = 0.0;
    array_50AC10[0].v = 0.0;

    v48 = v12->flt_00000C + 0.0000001000000011686097;
    memcpy(&array_50AC10[1], v12, sizeof(struct RenderVertex));
    array_50AC10[1].flt_000020 = 1.0 / v48;
    array_50AC10[1].u = 0.0;
    array_50AC10[1].v = 1.0;

    v49 = v105->flt_00000C + 0.0000001000000011686097;
    memcpy(&array_50AC10[2], v105, sizeof(struct RenderVertex));
    array_50AC10[2].flt_000020 = 1.0 / v49;
    array_50AC10[2].u = 1.0;
    array_50AC10[2].v = 1.0;

    sub_45D036(pNormal, (int)&v79, array_50AC10, 3, 0);
    if ( dword_F8ADD4 <= 0 )
    {
     v37->byte_000108 = 0;
    }
    else
    {
      v50 = *(float *)&pGame;
      v37->byte_000108 = 1;
      sub_45CA88(*(void **)(LODWORD(v50) + 3656), (int)&dword_F8AD28, (int)array_50AC10, 3, (int)pNormal);
    }
    if (v10->flt_00000C < 8.0 || v12->flt_00000C < 8.0 || (v51 = (int)v105, v105->flt_00000C < 8.0) )
    {
      v54 = sub_4250FE(3);
    }
    else
    {
      v52 = (double)pStruct9_global->shading_dist_mist;
      if (v52 >= v10->flt_00000C && v52 >= v12->flt_00000C && v52 >= v105->flt_00000C)
      {
        v53 = sub_4254D2(3);
        v37->uNumVertices = v53;
        if ( v53 )
        {
          sub_4829B9(v12, (RenderVertex *)v51, v10, v37, 0);
LABEL_68:
          sub_481DB2(array_508690, v53, v37);
LABEL_75:
          v16 = &array_77EC08[pStruct9_global->dword_00002C];
          v16->uTextureID = class51_GetTileTexture(pClass51_global, v102, v101);
          if (v16->uTextureID == -1)
            goto LABEL_105;
          v16->word_000030 = class51_sub_488EB1_GetSomeOtherTileInfo(pClass51_global, v102, v101);
          v16->word_000032 = 0;
          v58 = v93;
          v16->byte_000059 = 1;
          v16->dword_000034 = *(_WORD *)(v58 + 2);
          v16->byte_00005C = v95;
          v16->byte_00005D = LOBYTE(v100);
          v57 = *(unsigned __int16 *)((char *)pClass51_global->pTerrainNormalIndices + LODWORD(v94));
          if ( v57 > pClass51_global->uNumTerrainNormals - 1 )
             pNormal = 0;
          else
             pNormal = pClass51_global->pTerrainNormals + v57;
          if ( pNormal )
          {
           v60 = -(v98 * pNormal->y + v97 * pNormal->z + v96 * pNormal->x);
            if ( v60 < 0.0 )
              v60 = 0.0;
            v94 = v60 * 31.0;
            v73 = v94 + 6.755399441055744e15;
            v84 = LODWORD(v73);
            v16->byte_000058 = 31 - LOBYTE(v73);
          }
          else
          {
            v16->byte_000058 = 0;
          }
          if (v16->byte_000058 < 0 )
            v16->byte_000058 = 0;
          if ( pStruct9_global->dword_00002C >= 1999 )
            return;
          ++pStruct9_global->dword_00002C;
          if ( !sub_481FC9(v11, v10, v105, v16) )
          {
LABEL_104:
            --pStruct9_global->dword_00002C;
            goto LABEL_105;
          }

          v61 = 1.0 / (v10->flt_00000C + 0.0000001000000011686097);
          memcpy(&array_50AC10[0], v10, sizeof(struct RenderVertex));
          array_50AC10[0].flt_000020 = v61;
          array_50AC10[0].u = 0.0;
          array_50AC10[0].v = 0.0;

          v62 = v105->flt_00000C + 0.0000001000000011686097;
          memcpy(&array_50AC10[1], v105, sizeof(struct RenderVertex));
          array_50AC10[1].flt_000020 = 1.0 / v62;
          array_50AC10[1].u = 1.0;
          array_50AC10[1].v = 1.0;

          v63 = v11->flt_00000C + 0.0000001000000011686097;
          memcpy(&array_50AC10[2], v11, sizeof(struct RenderVertex));
          array_50AC10[2].flt_000020 = 1.0 / v63;
          array_50AC10[2].u = 1.0;
          array_50AC10[2].v = 0.0;

          sub_45D036(pNormal, (int)&v71, array_50AC10, 3, 1);
          if ( dword_F8ADD4 <= 0 )
          {
           v16->byte_000108 = 0;
          }
          else
          {
            v64 = *(float *)&pGame;
            v16->byte_000108 = 1;
            sub_45CA88(*(void **)(LODWORD(v64) + 3656), (int)&dword_F8AD28, (int)array_50AC10, 3, (int)pNormal);
          }
          if (v10->flt_00000C < 8.0 || v105->flt_00000C < 8.0 || v11->flt_00000C < 8.0 )
          {
            v36 = sub_4250FE(3);
            sub_481E55(v36);
            if ( !v36 )
              goto LABEL_104;
            goto LABEL_102;
          }
          v65 = (double)pStruct9_global->shading_dist_mist;
          if ( v65 < v10->flt_00000C || v65 < v105->flt_00000C || v65 < v11->flt_00000C)
          {
            v36 = sub_4252E8(3);
            if ( !v36 )
              goto LABEL_105;
            goto LABEL_41;
          }
          v32 = sub_4254D2(3);
          v16->uNumVertices = v32;
          if ( !v32 )
            goto LABEL_104;
          v33 = (int)v10;
          v34 = (int)v11;
          v70 = 0;
          v69 = (int)v16;
          v68 = (int)v105;
LABEL_37:
          sub_4829B9((RenderVertex *)v34, (RenderVertex *)v33, (RenderVertex *)v68, (struct8 *)v69, v70);
LABEL_38:
          sub_481DB2(array_508690, v32, v16);
          goto LABEL_105;
        }
        goto LABEL_74;
      }
      v54 = sub_4252E8(3);
    }
    v55 = v54;
    if ( v54 )
    {
      sub_481E55(v54);
      v53 = sub_4254D2(v55);
      v37->uNumVertices = v53;
      if ( v53 )
      {
        sub_48276F(v37);
        goto LABEL_68;
      }
    }
LABEL_74:
    --pStruct9_global->dword_00002C;
    goto LABEL_75;
  }
}


#endif