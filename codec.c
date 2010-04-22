#include "codec.h"
#include "classes.h"


//----- (004C2FC0) --------------------------------------------------------
void __fastcall MemUnzip(void *pDest, unsigned int *pDecompressedSize, void *pSrc, int uCompressedSize)
{
  signed int result; // eax@1
  int *v5; // esi@1
  int v6; // eax@1
  signed int v7; // edi@2

  struct class19 class19_obj;

  
  v5 = pDecompressedSize;
  v6 = *pDecompressedSize;

  class19_obj.pCompressedData = pSrc;
  class19_obj.uCompressedDataSize = uCompressedSize;
  class19_obj.pDecompressedData = pDest;
  class19_obj.uDecompressedDataSize = *pDecompressedSize;
  class19_obj.pFunction1 = 0;
  class19_obj.pFunction2 = 0;


  result = class19_fn0(&class19_obj, 15, "1.1.3", 56);
  if ( !result )
  {
    v7 = class19_fn3(&class19_obj, 4);
    if ( v7 == 1 )
    {
     *v5 = class19_obj.dword_000014;
     result = class19_fn1(&class19_obj);
    }
    else
    {
     class19_fn1(&class19_obj);
     result = -5;
     if (v7)
       result = v7;
    }
  }
  return result;
}


//----- (004C57C0) --------------------------------------------------------
int __fastcall sub_4C57C0_MaybeCalcHash(unsigned int a1, unsigned char *pData, unsigned int uSize)
{
  unsigned int v3; // ecx@1
  unsigned char *v4; // edi@1
  unsigned int v5; // esi@1
  int result; // eax@2
  unsigned int i; // ebx@3
  unsigned int v8; // eax@4
  unsigned int v9; // ebp@7
  int v10; // edx@8
  int v11; // esi@8
  int v12; // ecx@8
  int v13; // esi@8
  int v14; // ecx@8
  int v15; // esi@8
  int v16; // ecx@8
  int v17; // esi@8
  int v18; // ecx@8
  int v19; // esi@8
  int v20; // ecx@8
  int v21; // esi@8
  int v22; // ecx@8
  int v23; // esi@8
  int v24; // ecx@8
  int v25; // esi@8
  int v26; // ecx@8
  int v27; // esi@8
  int v28; // ecx@8
  int v29; // esi@8
  int v30; // ecx@8
  int v31; // esi@8
  int v32; // ecx@8
  int v33; // esi@8
  int v34; // ecx@8
  int v35; // esi@8
  int v36; // ecx@8
  int v37; // esi@8
  int v38; // ecx@8
  int v39; // esi@8
  int v40; // ecx@8

  v4 = pData;
  v5 = a1 & 0xFFFF;
  v3 = a1 >> 16;
  if (pData)
  {
    for ( i = uSize; i; v3 %= 0xFFF1u )
    {
      v8 = i;
      if ( i >= 0x15B0 )
        v8 = 0x15B0;
      i -= v8;
      if ( (signed int)v8 >= 16 )
      {
        v9 = v8 >> 4;
        v8 += 16 * (-(signed)(v9));
        do
        {
          v10 = v4[0];
          v11 = v10 + v5;
          v12 = v11 + v3;
          v13 = v4[1] + v11;
          v14 = v13 + v12;
          v15 = v4[2] + v13;
          v16 = v15 + v14;
          v17 = v4[3] + v15;
          v18 = v17 + v16;
          v19 = v4[4] + v17;
          v20 = v19 + v18;
          v21 = v4[5] + v19;
          v22 = v21 + v20;
          v23 = v4[6] + v21;
          v24 = v23 + v22;
          v25 = v4[7] + v23;
          v26 = v25 + v24;
          v27 = v4[8] + v25;
          v28 = v27 + v26;
          v29 = v4[9] + v27;
          v30 = v29 + v28;
          v31 = v4[10] + v29;
          v32 = v31 + v30;
          v33 = v4[11] + v31;
          v34 = v33 + v32;
          v35 = v4[12] + v33;
          v36 = v35 + v34;
          v37 = v4[13] + v35;
          v38 = v37 + v36;
          v39 = v4[14] + v37;
          v40 = v39 + v38;
          v5 = v4[15] + v39;
          v3 = v5 + v40;
          --v9;
          v4 += 16;
        }
        while ( v9 );
      }
      for ( ; v8; --v8 )
      {
        v5 += *v4++;
        v3 += v5;
      }
      v5 %= 0xFFF1u;
    }
    result = v5 | (v3 << 16);
  }
  else
  {
    result = 1;
  }
  return result;
}



//----- (MM7.exe::004C3190) --------------------------------------------------------
extern int call_delete(int result, unsigned int a2);
extern void *__stdcall call_new(int a1, int a2, int a3);
int class19_fn0(struct class19 *_this, int a2, const char *a3, int a4)
{
  int v4; // edi@1
  int v5; // esi@1

  v4 = a2;
  v5 = _this;
  if ( a3 && *(_BYTE *)a3 == "1.1.3"[0] && a4 == 56 )
  {
    if (_this)
    {
     _this->pStatus = 0;

     if (!_this->pFunction1)
     {
      _this->pFunction1 = call_new;
      _this->dword_000028 = 0;
     }
     if (!_this->pFunction2)
       _this->pFunction2 = call_delete;

     _this->class20_obj = (_this->pFunction1)(_this->dword_000028, 1, 24);

      if (_this->class20_obj)
      {
       _this->class20_obj->class21_obj = 0;
       _this->class20_obj->dword_00000C = 0;
       if (v4 < 0)
       {
        v4 = -v4;
        _this->class20_obj->dword_00000C = 1;
       }

       if (v4 < 8 || v4 > 15)
       {
        class19_fn1(_this);
        return -2;
       }
       else
       {
        _this->class20_obj->dword_000010 = v4;
        _this->class20_obj->class21_obj = class19_AllocClass21Obj(_this,
                                                                  _this->class20_obj->dword_00000C == 0 ? sub_4C57C0_MaybeCalcHash : 0,
                                                                  1 << v4);
        if (_this->class20_obj->class21_obj)
        {
         class19_fn2(_this);
         return 0;
        }
        else
        {
         class19_fn1(_this);
         return -4;
        }
       }
      }
      else return -4;
    }
    else return -2;
  }
  else return -6;
}

//----- (MM7.exe::004C3150) --------------------------------------------------------
int class19_fn1(struct class19 *_this)
{
  struct class20 *v2; // eax@2
  struct class21 *v3; // ecx@4

  if (!_this)
    return -2;

  v2 = _this->class20_obj;
  if (_this && v2 && _this->pFunction2)
  {
   v3 = v2->class21_obj;
   if (v3)
     class21_fn0(v3, _this);

   (_this->pFunction2)(_this->dword_000028, _this->class20_obj);
   _this->class20_obj = 0;
   return 0;
  }
  else return -2;
}

//----- (MM7.exe::004C3110) --------------------------------------------------------
int class19_fn2(struct class19 *_this)
{
  struct class20 *v1; // eax@2

  if (!_this)
    return -2;

  v1 = _this->class20_obj;
  if (_this->class20_obj)
  {
   _this->dword_000014 = 0;
   _this->dword_000008 = 0;
   _this->pStatus = 0;
   v1->dword_000000 = v1->dword_00000C ? 7 : 0;
   class21_fn1(v1->class21_obj, _this, 0);
   return 0;
  }
  else return -2;
}

//----- (MM7.exe::004C32D0) --------------------------------------------------------
int class19_fn3(struct class19 *_this, int a2)
{
  int v3; // ebx@4
  signed int v4; // ebp@4
  int v5; // edi@4
  struct class20 *v6; // eax@5
  //struct class20 *v8; // eax@7
  int v9; // ecx@7
  int v16; // eax@17
  struct class20 *v17; // eax@22
  int v18; // eax@25
  int v19; // ecx@26
  int v20; // edx@26
  int v21; // edx@26
  int v22; // eax@27
  int v23; // ecx@28
  int v24; // eax@29
  int v25; // ecx@30
  int v26; // eax@31
  int v27; // eax@32
  int v28; // ecx@32
  int v29; // edx@32
  int v30; // eax@32
  int v31; // edx@33
  signed int result; // eax@36
  int v34; // ecx@37
  int v35; // ecx@37
  int v37; // edx@40
  int v38; // edx@40
  int v40; // ecx@43
  int v42; // ecx@46
  int v43; // edx@46
  int v44; // eax@46
  int v45; // eax@46
  int v46; // eax@47
  int v47; // [sp+10h] [bp-4h]@4

 if (!_this || !_this->class20_obj || !_this->pCompressedData)
   return -2;

 v5 = -5;
 v3 = ((a2 != 4) - 1) & 0xFFFFFFFB;
 v4 = 5;
 v47 = ((a2 != 4) - 1) & 0xFFFFFFFB;

 while ( 2 )
 {
  v6 = _this->class20_obj;

  switch (v6->dword_000000)
  {
   case 0:
     if (!_this->uCompressedDataSize)
       goto LABEL_36;

     _this->uCompressedDataSize--;
     v5 = v3;

     _this->dword_000008++;
     v6->dword_000004 = *_this->pCompressedData++;

     v9 = v6->dword_000004 & 0x0F;
     if (v9 != 8)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "unknown compression method";
      v6->dword_000004 = v4;
      return -3;
     }
     else if ((unsigned int)((v6->dword_000004 / 16) + 8) > v6->dword_000010)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "invalid window size";
      v6->dword_000004 = v4;
      return -3;
     }

     v6->dword_000000 = 1;

LABEL_12:
     if (!_this->uCompressedDataSize)
       return v5;

     v5 = v3;
     _this->dword_000008++;
     v9 = *_this->pCompressedData++;
     _this->uCompressedDataSize--;

     if ((v9 + v6->dword_000004 * 256) % 0x1F)
     {
      v6->dword_000000 = 13;
      _this->pStatus = "incorrect header check";
      v6->dword_000004 = 5;
      return -3;
     }

     if (!(v9 & 0x20))
     {
      v6->dword_000000 = 7;
      v3 = v47;
      v4 = 5;
      continue;
     }
     v3 = v47;
     v4 = 5;
     _this->class20_obj->dword_000000 = 2;

LABEL_35:
     if (_this->uCompressedDataSize)
     {
      v34 = _this->pCompressedData;
      _this->dword_000008++;
      _this->uCompressedDataSize--;
      v5 = v3;
      _this->class20_obj->dword_000008 = (int)(*_this->pCompressedData) << 24;
      v35 = _this->class20_obj;
      _this->pCompressedData++;
      _this->class20_obj->dword_000000 = 3;

LABEL_38:
      if (_this->uCompressedDataSize)
      {
       v37 = _this->pCompressedData;
       _this->uCompressedDataSize--;

       _this->dword_000008++;
       v5 = v3;
       _this->class20_obj->dword_000008 += (int)(*_this->pCompressedData) << 16;

LABEL_41:
       if (_this->uCompressedDataSize)
       {
        v40 = _this->pCompressedData;
        _this->uCompressedDataSize--;
        _this->dword_000008++;
        v5 = v3;
        _this->class20_obj->dword_000008 += (int)(*_this->pCompressedData) << 8;

LABEL_44:
        if (_this->uCompressedDataSize)
        {
         v42 = _this->pCompressedData;
         v43 = _this->dword_000008 + 1;
         _this->uCompressedDataSize--;

         v44 = _this->class20_obj;
         _this->dword_000008++;
         _this->class20_obj->dword_000008 += *_this->pCompressedData++;

         v45 = _this->class20_obj;
         _this->dword_00002C = _this->class20_obj->dword_000008;
         _this->class20_obj->dword_000000 = 6;
         result = 2;
        }
        else
        {
         result = v5;
        }
       }
       else
       {
        result = v5;
       }
      }
      else
      {
       result = v5;
      }
     }
     else
     {
LABEL_36:
      result = v5;
     }
     return result;

   case 1:
     goto LABEL_12;

   case 7:
    v16 = class21_fn2(v6->class21_obj, _this, v5);

    v5 = v16;
    if ( v16 == -3 )
    {
     _this->class20_obj->dword_000000 = 13;
     _this->class20_obj->dword_000004 = 0;
    }
    else
    {
     if (!v16)
       v5 = v3;
     if (v5 != 1)
       goto LABEL_36;
     v5 = v3;

     class21_fn1(_this->class20_obj->class21_obj, _this, &_this->class20_obj->dword_000004);
     v17 = _this->class20_obj;

     if (_this->class20_obj->dword_00000C)
       _this->class20_obj->dword_000000 = 12;
     else
     {
      _this->class20_obj->dword_000000 = 8;

LABEL_25:
      v18 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      v19 = _this->class20_obj;
      _this->dword_000008++;
      v20 = _this->pCompressedData;
      _this->uCompressedDataSize--;
      v5 = v3;

      _this->class20_obj->dword_000008 = (unsigned int)(*_this->pCompressedData++) << 24;
      v21 = _this->class20_obj;
      _this->class20_obj->dword_000000 = 9;

LABEL_27:
      v22 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      v23 = _this->pCompressedData;
      _this->dword_000008++;
      _this->uCompressedDataSize--;
      v5 = v3;

      _this->class20_obj->dword_000008 += (unsigned int)(*_this->pCompressedData++) << 16;
      _this->class20_obj->dword_000000 = 10;


LABEL_29:
      v24 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      v25 = _this->pCompressedData;
      _this->dword_000008++;
      _this->uCompressedDataSize--;
      v5 = v3;

      _this->class20_obj->dword_000008 += (unsigned int)(*_this->pCompressedData++) << 8;
      _this->class20_obj->dword_000000 = 11;

LABEL_31:

      v26 = _this->uCompressedDataSize;
      if (!_this->uCompressedDataSize)
        goto LABEL_36;

      v28 = _this->pCompressedData;
      v29 = _this->dword_000008 + 1;
      v30 = _this->class20_obj;
      _this->uCompressedDataSize--;
      _this->dword_000008++;

      v5 = v3;
      _this->class20_obj->dword_000008 += *_this->pCompressedData++;
      v27 = _this->class20_obj;

      if (_this->class20_obj->dword_000004 == _this->class20_obj->dword_000008)
      {
       _this->class20_obj->dword_000000 = 12;
       return 1;
      }
 
      _this->class20_obj->dword_000000 = 13;
      v31 = _this->class20_obj;
      _this->pStatus = "incorrect data check";
      _this->class20_obj->dword_000004 = v4;
     }
    }
    continue;

  case 8:
    goto LABEL_25;

  case 9:
    goto LABEL_27;

  case 0xA:
    goto LABEL_29;

  case 0xB:
    goto LABEL_31;

  case 2:
    goto LABEL_35;

  case 3:
    goto LABEL_38;

  case 4:
    goto LABEL_41;

  case 5:
    goto LABEL_44;

  case 6:
    _this->class20_obj->dword_000000 = 13;
    v46 = _this->class20_obj;
    _this->pStatus = "need dictionary";
    _this->class20_obj->dword_000004 = 0;
    return -2;

  case 0xC:
    return 1;
  case 0xD:
    return -3;

  default:
    return -2;
  }
 }
}


//----- (MM7.exe004C4A30) --------------------------------------------------------
struct class21 *class19_AllocClass21Obj(struct class19 *_this, int (__fastcall *pSomeFn)(unsigned int, int, unsigned int), int a3)
{
 int result; // eax@1
 struct class21 *v6; // esi@1
 int v8; // eax@5

 result = (_this->pFunction1)(_this->dword_000028, 1, 64);
 v6 = result;
 if (result)
 {
  v6->pArray_8x1440 = (_this->pFunction1)(_this->dword_000028, 8, 1440);
  if (v6->pArray_8x1440)
  {
   v8 = (_this->pFunction1)(_this->dword_000028, 1, a3);
   //*(_DWORD *)(v6 + 40) = v8;
   v6->dword_000028 = v8;
   if (v8)
   {
    v6->dword_00002C = a3 + v8;
    v6->pfn_000038 = pSomeFn;
    v6->dword_000000 = 0;
    class21_fn1(v6, _this, 0);
    return v6;
   }
   else
   {
    (_this->pFunction2)(_this->dword_000028, v6->pArray_8x1440);
    (_this->pFunction2)(_this->dword_000028, v6);
    return 0;
   }
  }
  else
  {
   (_this->pFunction2)(_this->dword_000028, v6);
   return 0;
  }
 }
 return result;
}

//----- (MM7.exe::004C5790) --------------------------------------------------------
int class21_fn0(struct class21 *_this, struct class19 *pParent)
{
  int v3; // esi@1
  int v4; // edi@1

  v3 = pParent;
  v4 = _this;
  class21_fn1(_this, pParent, 0);

  (pParent->pFunction2)(pParent->dword_000028, _this->dword_000028);
  (pParent->pFunction2)(pParent->dword_000028, _this->pArray_8x1440);
  (pParent->pFunction2)(pParent->dword_000028, _this);
  return 0;
}

//----- (MM7.exe::004C49C0) --------------------------------------------------------
int class21_fn1(struct class21 *_this, struct class19 *pParent, int *a3)
{
 int result; // eax@8

 if (a3)
   *a3 = _this->dword_00003C;

 if (_this->dword_000000 == 4 || _this->dword_000000)
  (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
 else if (_this->dword_000000 == 6)
   (pParent->pFunction2)(pParent->dword_000028, _this->class27_obj);

 _this->dword_000000 = 0;
 _this->pDecompressionBufferHead = _this->dword_000028;
 _this->pDecompressionBufferTail = _this->dword_000028;

 _this->dword_00001C = 0;
 _this->dword_000020 = 0;

 if (_this->pfn_000038)
 {
  result = (_this->pfn_000038)(0, 0, 0);
  pParent->dword_000030 = result;
  _this->dword_00003C = result;

  return result;
 }
 return 0;
}

//----- (MM7.exe::004C4AD0) --------------------------------------------------------
extern unsigned char byte_4D8410[];
extern int *dword_4F2688;
int class21_fn2(struct class21 *_this, struct class19 *pParent, int a3)
{
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  int v6; // ebp@1
  unsigned int v8; // esi@6
  unsigned int   uDataSize; // eax@7
  unsigned char *pDataPtr; // edi@7
  int v11; // edx@9
  int v12; // ebp@13
  int v13; // ecx@13
  const void *v15; // eax@17
  unsigned int v16; // edi@17
  unsigned int v17; // esi@17
  int v18; // edx@19
  unsigned int v19; // edi@23
  int v20; // ecx@24
  void *v21; // edx@25
  void *v22; // ecx@25
  unsigned int v23; // eax@26
  unsigned int v24; // esi@26
  unsigned int v25; // edx@31
  unsigned int v26; // esi@31
  int v27; // eax@31
  int v28; // eax@34
  unsigned int v29; // eax@35
  unsigned int v30; // eax@42
  int v31; // edx@46
  int v32; // ecx@46
  unsigned int v33; // edi@48
  int v36; // edx@51
  int v37; // eax@52
  int v38; // ecx@52
  unsigned int v41; // edi@55
  char v43; // cl@61
  int v44;
  int v47; // ST14_4@65
  int v48; // ecx@65
  int v50; // edx@71
  unsigned int v51; // eax@72
  int v52; // edx@72
  int v53; // ecx@72
  int v54; // eax@72
  int v55; // eax@73
  int v56; // ecx@74
  int v57; // eax@76
  int v58; // eax@76
  int v59; // edx@78
  unsigned int v60; // edi@80
  int v61; // eax@80
  int v62; // ecx@83
  unsigned int v64; // ecx@87
  int v68; // eax@91
  const void *v69; // ebp@91
  int v70; // edi@91
  unsigned int v71; // eax@92
  void *v72; // ecx@92
  const void *v73; // edi@92
  int v74; // eax@93
  int result; // eax@97
  int v76; // ebp@97
  int v77; // esi@97
  int v78; // esi@98
  int v79; // ecx@98
  int v80; // esi@99
  int v81; // ecx@99
  int v82; // edi@100
  int v83; // esi@100
  int v85; // esi@102
  int v86; // ecx@102
  int v87; // ebp@103
  int v88; // esi@103
  int v89; // edi@104
  int v90; // esi@104
  int v91; // edi@105
  int v92; // edx@105
  unsigned int v93; // eax@106
  int v94; // edx@107
  int v95; // ecx@107
  const void *v96; // edi@110
  int v97; // ecx@110
  int v98; // ecx@111
  int v99; // edx@111
  const void *v100; // edi@112
  int v101; // edx@112
  const void *v102; // edi@115
  int v103; // edx@115
  const void *v104; // edi@116
  int v105; // ecx@116
  void *v106; // ecx@119
  const void *v107; // ebp@120
  const void *v108; // ebp@124
  int v109; // edx@124
  int v110; // edi@127
  int v111; // esi@127
  int v112; // edi@128
  int v113; // esi@128

  const void *v114; // [sp+10h] [bp-38h]@1
  unsigned int v115; // [sp+14h] [bp-34h]@1
  void *v116; // [sp+18h] [bp-30h]@1
  unsigned int v117; // [sp+1Ch] [bp-2Ch]@1
  int v118; // [sp+1Ch] [bp-2Ch]@65
  int v119; // [sp+1Ch] [bp-2Ch]@72
  int v120; // [sp+1Ch] [bp-2Ch]@80
  int v121; // [sp+1Ch] [bp-2Ch]@87
  int v122; // [sp+20h] [bp-28h]@1
  unsigned int v123; // [sp+24h] [bp-24h]@4
  int v124; // [sp+28h] [bp-20h]@34
  int v125; // [sp+2Ch] [bp-1Ch]@14
  int v126; // [sp+30h] [bp-18h]@14
  int v127; // [sp+34h] [bp-14h]@14

  int v128; // [sp+38h] [bp-10h]@14
  unsigned int v129; // [sp+3Ch] [bp-Ch]@72
  unsigned int *v130; // [sp+40h] [bp-8h]@87
  unsigned int *v131; // [sp+44h] [bp-4h]@87
  int v132; // [sp+4Ch] [bp+4h]@31

 v114 = pParent->pCompressedData;
 v115 = pParent->uCompressedDataSize;
 v122 = pParent;
 v3 = _this->pDecompressionBufferHead;
 v4 = _this->pDecompressionBufferTail;
 v6 = _this->dword_00001C;
 v116 = _this->pDecompressionBufferTail;
 v117 = _this->dword_000020;

 if (v4 >= v3)
   v123 = _this->dword_00002C - (unsigned int)_this->pDecompressionBufferTail;
 else
   v123 = _this->pDecompressionBufferHead - _this->pDecompressionBufferTail - 1;

 while (2)
 {
  switch (_this->dword_000000)
  {
   case 0:
     v8 = v117;

     if (v6 >= 3)
     {
      pDataPtr = v114;
LABEL_12:

      _this->bDecompressionComplete = v8 & 1;
      switch ((v117 & 7) >> 1)
      {
       case 0u:
         v12 = v6 - 3;
         _this->dword_000000 = 1;
         v13 = v12 & 7;
         v6 = v12 - v13;
         v117 = v8 >> 3 >> v13;
         continue;

        case 1u:
          sub_4C8340((int)&v128, (int)&v127, (int)&v126, (int)&v125, pParent);
          _this->class27_obj = AllocateClass27(v128, v127, v126, v125, pParent);
          if (_this->class27_obj)
          {
           v117 = v8 >> 3;
           v6 -= 3;
           _this->dword_000000 = 6;
           continue;
          }
          _this->dword_00001C = v6;
          _this->dword_000020 = v8;

          v78 = pParent->pCompressedData;
          pParent->uCompressedDataSize = v115;
          v79 = pParent->dword_000008;
          pParent->pCompressedData = pDataPtr;
          pParent->dword_000008 = pDataPtr + v79 - v78;

          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, -4);
        break;

        case 2u:
              v117 = v8 >> 3;
              v6 -= 3;
              _this->dword_000000 = 3;
              continue;
        case 3u:
              _this->dword_000000 = 9;
              pParent->pStatus = "invalid block type";
              _this->dword_00001C = v6 - 3;
              _this->dword_000020 = v8 >> 3;
              v80 = pParent->dword_000008;
              v81 = (int)(pDataPtr - pParent->pCompressedData);
              pParent->uCompressedDataSize = v115;
              pParent->dword_000008 = v81 + v80;
              pParent->pCompressedData = pDataPtr;
              _this->pDecompressionBufferTail = v116;
              return class21_fn3(_this, pParent, -3);
            default:
              continue;
          }
        }
        else
        {
          uDataSize = v115;
          pDataPtr = v114;
          while ( uDataSize-- )
          {
            a3 = 0;
            v11 = *pDataPtr++ << v6;
            v6 += 8;
            v115 = uDataSize;
            v8 |= v11;
            v117 = v8;
            v114 = pDataPtr;
            if ( (unsigned int)v6 >= 3 )
              goto LABEL_12;
          }
          _this->dword_00001C = v6;
          _this->dword_000020 = v8;
          v76 = pParent->pCompressedData;
          v77 = pParent->dword_000008;
          pParent->uCompressedDataSize = 0;
          pParent->pCompressedData = pDataPtr;
          pParent->dword_000008 = pDataPtr + v77 - v76;
          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, a3);
        }
        return result;
      case 1:
        v17 = v117;
        v16 = v115;
        v15 = v114;
        if ( (unsigned int)v6 >= 0x20 )
          goto LABEL_20;
        do
        {
          if ( !v16 )
          {
            _this->dword_00001C = v6;
            _this->dword_000020 = v17;
            v82 = pParent->pCompressedData;
            v83 = pParent->dword_000008;
            pParent->uCompressedDataSize = 0;
            pParent->pCompressedData = v15;
            pParent->dword_000008 = (char *)v15 + v83 - v82;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, a3);
          }
          a3 = 0;
          v18 = *(_BYTE *)v15 << v6;
          --v16;
          v6 += 8;
          v115 = v16;
          v17 |= v18;
          v15 = (char *)v15 + 1;
          v114 = v15;
        }
        while ( (unsigned int)v6 < 0x20 );
LABEL_20:
        if ( (unsigned __int16)v17 != ~v17 >> 16 )
        {
          _this->dword_000000 = 9;
          pParent->pStatus = "invalid stored block lengths";
          _this->dword_00001C = v6;
          _this->dword_000020 = v17;
          pParent->uCompressedDataSize = v16;
          goto LABEL_127;
        }
        v6 = 0;
        _this->class27_obj = v17;
        v117 = 0;
        if ( (_WORD)v17 )
        {
         _this->dword_000000 = 2;
          continue;
        }
LABEL_47:
        _this->dword_000000 = _this->bDecompressionComplete ? 7 : 0;
        continue;
      case 2:
        v19 = v115;
        if ( !v115 )
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v117;
          v85 = pParent->dword_000008;
          v86 = (int)((char *)v114 - pParent->pCompressedData);
          pParent->pCompressedData = v114;
          pParent->uCompressedDataSize = 0;
          pParent->dword_000008 = v86 + v85;
          _this->pDecompressionBufferTail = v116;
          return class21_fn3(_this, pParent, a3);
        }
        v20 = v123;
        if ( v123
          || (v22 = _this->dword_00002C, v21 = v116, v116 == v22)
          && (v23 = _this->pDecompressionBufferHead, v24 = _this->dword_000028, v23 != v24)
          && ((v21 = _this->dword_000028, v116 = _this->dword_000028, v24 >= v23) ? (v20 = (int)((char *)v22 - v24)) : (v20 = v23 - v24 - 1),
              v123 = v20,
              v20) )
          goto LABEL_42;
        _this->pDecompressionBufferTail = v21;
        v27 = class21_fn3(_this, pParent, a3);
        v25 = _this->pDecompressionBufferTail;
        v26 = _this->pDecompressionBufferHead;
        v132 = v27;
        v116 = _this->pDecompressionBufferTail;
        if ( v25 >= v26 )
          v20 = _this->dword_00002C - v25;
        else
          v20 = v26 - v25 - 1;
        v28 = _this->dword_00002C;
        v123 = v20;
        v124 = v28;
        if ( v25 == v28 )
        {
          v29 = _this->dword_000028;
          if ( v26 != v29 )
          {
            v25 = _this->dword_000028;
            v116 = _this->dword_000028;
            if ( v29 >= v26 )
              v20 = v124 - v29;
            else
              v20 = v26 - v29 - 1;
            v123 = v20;
          }
        }
        if ( !v20 )
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v117;
          v87 = pParent->pCompressedData;
          v88 = pParent->dword_000008;
          pParent->uCompressedDataSize = v115;
          pParent->pCompressedData = v114;
          pParent->dword_000008 = (char *)v114 + v88 - v87;
          _this->pDecompressionBufferTail = v25;
          return class21_fn3(_this, pParent, v132);
        }
        v19 = v115;
LABEL_42:
        v30 = _this->class27_obj;
        a3 = 0;
        if ( v30 > v19 )
          v30 = v19;
        if ( v30 > v20 )
          v30 = v20;
        memcpy(v116, v114, 4 * (v30 >> 2));
        v31 = v123 - v30;
        memcpy((char *)v116 + 4 * (v30 >> 2), (char *)v114 + 4 * (v30 >> 2), v30 & 3);
        v114 = (char *)v114 + v30;
        v32 = (char *)_this->class27_obj - v30;
        v115 -= v30;
        v116 = (char *)v116 + v30;
        v123 = v31;
        _this->class27_obj = v32;
        if ( !v32 )
          goto LABEL_47;
        continue;
      case 3:
        v33 = v117;
        if ( (unsigned int)v6 >= 0xE )
          goto LABEL_52;

        uDataSize = v115;
        pDataPtr = v114;
        do
        {
         if (!uDataSize)
         {
            _this->dword_00001C = v6;
            _this->dword_000020 = v33;
            v89 = pParent->pCompressedData;
            v90 = pParent->dword_000008;
            pParent->pCompressedData = v114;
            pParent->uCompressedDataSize = 0;
            pParent->dword_000008 = (char *)v114 + v90 - v89;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, a3);
         }

         a3 = 0;
         v36 = *pDataPtr++ << v6;
         v6 += 8;
         v115 = --uDataSize;
         v33 |= v36;
         v114 = pDataPtr;
        }
        while ( (unsigned int)v6 < 0xE );
LABEL_52:
        v37 = v33 & 0x3FFF;
        _this->class27_obj = v37;
        v38 = v33 & 0x1F;
        if ( (unsigned int)v38 > 0x1D || (v37 & 0x3E0u) > 0x3A0 )
        {
          v93 = v115;
          _this->dword_000000 = 9;
          pParent->pStatus = "too many length or distance symbols";
          _this->dword_00001C = v6;
          _this->dword_000020 = v33;
LABEL_126:
          pParent->uCompressedDataSize = v93;
          v15 = v114;
LABEL_127:
          v110 = pParent->pCompressedData;
          v111 = pParent->dword_000008;
          pParent->pCompressedData = v15;
          pParent->dword_000008 = (char *)v15 + v111 - v110;
          _this->pDecompressionBufferTail = v116;
          result = class21_fn3(_this, pParent, -3);
        }
        else
        {
         _this->dword_00000C = (pParent->pFunction1)(pParent->dword_000028, (((unsigned int)v37 >> 5) & 0x1F) + v38 + 258, 4);
          if (!_this->dword_00000C)
          {
           _this->dword_00001C = v6;
           _this->dword_000020 = v33;
           v91 = pParent->pCompressedData;
           pParent->uCompressedDataSize = v115;
           v92 = pParent->dword_000008;
           pParent->pCompressedData = v114;
           pParent->dword_000008 = (char *)v114 + v92 - v91;
            _this->pDecompressionBufferTail = v116;
            return class21_fn3(_this, pParent, -4);
          }
          v41 = v33 >> 14;
          v6 -= 14;
          _this->dword_000008 = 0;
          _this->dword_000000 = 4;
LABEL_57:
          if (_this->dword_000008 < (unsigned int)(((unsigned int)_this->class27_obj >> 10) + 4) )
          {
            do
            {
              if ( (unsigned int)v6 < 3 )
              {
                pDataPtr = v114;
                do
                {
                  if ( !v115 )
                  {
                    _this->dword_00001C = v6;
                    _this->dword_000020 = v41;
                    v94 = pParent->dword_000008;
                    v95 = (int)((char *)v114 - pParent->pCompressedData);
                    pParent->pCompressedData = v114;
                    pParent->dword_000008 = v95 + v94;
                    pParent->uCompressedDataSize = 0;
                    _this->pDecompressionBufferTail = v116;
                    return class21_fn3(_this, pParent, a3);
                  }
                  --v115;
                  v43 = v6;
                  v6 += 8;
                  a3 = 0;
                  v41 |= *pDataPtr++ << v43;
                  v114 = pDataPtr;
                }
                while ( (unsigned int)v6 < 3 );
              }
              v44 = v41 & 7;
              v6 -= 3;
              v41 >>= 3;
              _this->dword_00000C[*(_DWORD *)&byte_4D8410[4 * _this->dword_000008 + 1712]] = v44;
              _this->dword_000008++;
            }
            while (_this->dword_000008 < (unsigned int)(((unsigned int)_this->class27_obj >> 10) + 4) );
          }
          if (_this->dword_000008 < 0x13u )
          {
            do
            {
              _this->dword_00000C[*(_DWORD *)&byte_4D8410[4 * _this->dword_000008 + 1712]] = 0;
              _this->dword_000008++;
            }
            while ( (unsigned int)_this->dword_000008 < 0x13 );
          }
          v48 = _this->dword_00000C;
          _this->dword_000010 = 7;
          v118 = sub_4C7C60(_this->dword_00000C, &_this->dword_000010, &_this->dword_000014, _this->pArray_8x1440, pParent);
          if ( v118 )
          {
           (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
            if ( v118 == -3 )
              _this->dword_000000 = 9;
            _this->dword_00001C = v6;
            _this->dword_000020 = v41;
            v96 = pParent->pCompressedData;
            pParent->uCompressedDataSize = v115;
            v97 = pParent->dword_000008;
            pParent->pCompressedData = v114;
            pParent->dword_000008 = (char *)v114 - v96 + v97;
            _this->pDecompressionBufferTail = v116;
            result = class21_fn3(_this, pParent, v118);
          }
          else
          {
           _this->dword_000008 = 0;
           _this->dword_000000 = 5;
LABEL_68:
            while ( _this->dword_000008 < (((unsigned int)_this->class27_obj >> 5) & 0x1F) + ((unsigned int)_this->class27_obj & 0x1Fu) + 258 )
            {
              if (v6 < _this->dword_000010)
              {
               pDataPtr = v114;
                while ( v115 )
                {
                  a3 = 0;
                  --v115;
                  v50 = *pDataPtr++ << v6;
                  v6 += 8;
                  v41 |= v50;
                  v114 = pDataPtr;
                  if ( v6 >= _this->dword_000010)
                    goto LABEL_72;
                }
                goto LABEL_111;
              }
LABEL_72:
              v53 = _this->dword_000014;
              v54 = v41 & dword_4F2688[_this->dword_000010];
              v52 = *(_BYTE *)(v53 + 8 * v54 + 1);
              v119 = *(_BYTE *)(v53 + 8 * v54 + 1);
              v51 = *(_DWORD *)(v53 + 8 * v54 + 4);
              v129 = v51;
              if ( v51 >= 0x10 )
              {
                v56 = 7;
                if ( v51 != 18 )
                  v56 = v51 - 14;
                v123 = v56;
                v58 = -(v51 != 18);
                LOBYTE(v58) = v58 & 0xF8;
                v124 = v52 + v56;
                v57 = v58 + 11;
                if ( v6 < (unsigned int)(v52 + v56) )
                {
                  while ( v115 )
                  {
                    a3 = 0;
                    --v115;
                    v59 = *pDataPtr++ << v6;
                    v6 += 8;
                    v41 |= v59;
                    v114 = pDataPtr;
                    if ( v6 >= (unsigned int)v124 )
                    {
                      v52 = v119;
                      goto LABEL_80;
                    }
                  }
LABEL_111:
                  _this->dword_00001C = v6;
                  _this->dword_000020 = v41;
                  v98 = pParent->dword_000008;
                  v99 = (int)((char *)v114 - pParent->pCompressedData);
                  pParent->pCompressedData = v114;
                  pParent->dword_000008 = v99 + v98;
                  pParent->uCompressedDataSize = 0;
                  _this->pDecompressionBufferTail = v116;
                  return class21_fn3(_this, pParent, a3);
                }
LABEL_80:
                v60 = v41 >> v52;
                v61 = (v60 & dword_4F2688[v123]) + v57;
                v41 = v60 >> v123;
                v120 = v61;
                v6 -= v52 + v123;
                v123 = _this->dword_000008;
                if ( v123 + v61 > (((unsigned int)_this->class27_obj >> 5) & 0x1F) + ((unsigned int)_this->class27_obj & 0x1Fu) + 258 )
                  goto LABEL_112;
                if ( v129 == 16 )
                {
                  v55 = v123;
                  if ( v123 < 1 )
                  {
LABEL_112:
                   (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
                    _this->dword_000000 = 9;
                    pParent->pStatus = "invalid bit length repeat";
                    _this->dword_00001C = v6;
                    _this->dword_000020 = v41;
                    v100 = pParent->pCompressedData;
                    pParent->uCompressedDataSize = v115;
                    v101 = pParent->dword_000008;
                    pParent->pCompressedData = v114;
                    pParent->dword_000008 = (char *)v114 - v100 + v101;
                    _this->pDecompressionBufferTail = v116;
                    return class21_fn3(_this, pParent, -3);
                  }
                  v62 = _this->dword_00000C[v123 - 1];
                }
                else
                {
                  v55 = v123;
                  v62 = 0;
                }
                do
                {
                  ++v55;
                  _this->dword_00000C[v55 - 1] = v62;
                }
                while ( v120-- != 1 );
              }
              else
              {
                v6 -= v52;
                v41 >>= v52;
                _this->dword_00000C[_this->dword_000008] = v51;
                v55 = _this->dword_000008 + 1;
              }
              _this->dword_000008 = v55;
            }
            v64 = _this->class27_obj;
            _this->dword_000014 = 0;
            v124 = 9;
            v123 = 6;
            v121 = sub_4C81E0(
                     (v64 & 0x1F) + 257,
                     ((v64 >> 5) & 0x1F) + 1,
                     _this->dword_00000C,
                     (unsigned int *)&v124,
                     &v123,
                     &v131,
                     &v130,
                     _this->pArray_8x1440,
                     pParent);
            (pParent->pFunction2)(pParent->dword_000028, _this->dword_00000C);
            if ( v121 )
            {
              if ( v121 == -3 )
                _this->dword_000000 = 9;
              _this->dword_00001C = v6;
              _this->dword_000020 = v41;
              v102 = pParent->pCompressedData;
              v103 = pParent->dword_000008;
              pParent->uCompressedDataSize = v115;
              pParent->pCompressedData = v114;
              pParent->dword_000008 = (char *)v114 - v102 + v103;
              _this->pDecompressionBufferTail = v116;
              result = class21_fn3(_this, pParent, v121);
            }
            else
            {
             _this->class27_obj = AllocateClass27(v124, v123, v131, v130, pParent);
              if (!_this->class27_obj)
              {
                _this->dword_00001C = v6;
                _this->dword_000020 = v41;
                v104 = pParent->pCompressedData;
                pParent->uCompressedDataSize = v115;
                v105 = pParent->dword_000008;
                pParent->pCompressedData = v114;
                pParent->dword_000008 = (char *)v114 - v104 + v105;
                _this->pDecompressionBufferTail = v116;
                return class21_fn3(_this, pParent, -4);
              }
              _this->dword_000000;
LABEL_91:
              _this->dword_00001C = v6;
              _this->dword_000020 = v41;
              v69 = pParent->pCompressedData;
              v70 = pParent->dword_000008;
              pParent->uCompressedDataSize = v115;
              pParent->pCompressedData = v114;
              pParent->dword_000008 = (char *)v114 - v69 + v70;
              _this->pDecompressionBufferTail = v116;
              v68 = class21_fn4(_this, pParent, a3);
              if ( v68 != 1 )
                return class21_fn3(_this, pParent, v68);
              a3 = 0;
              (pParent->pFunction2)(pParent->dword_000028, _this->class27_obj);
              v71 = _this->pDecompressionBufferHead;
              v73 = pParent->pCompressedData;
              v6 = _this->dword_00001C;
              v115 = pParent->uCompressedDataSize;
              v72 = _this->pDecompressionBufferTail;
              v114 = pParent->pCompressedData;
              v117 = _this->dword_000020;
              v116 = _this->pDecompressionBufferTail;
              if ( (unsigned int)v72 >= v71 )
                v74 = _this->dword_00002C - (_DWORD)v72;
              else
                v74 = v71 - (_DWORD)v72 - 1;
              v123 = v74;
              if (!_this->bDecompressionComplete)
              {
                _this->dword_000000 = 0;
                continue;
              }
              _this->dword_000000 = 7;
LABEL_119:
              _this->pDecompressionBufferTail = v72;
              v68 = class21_fn3(_this, pParent, a3);
              v106 = _this->pDecompressionBufferTail;
              if (_this->pDecompressionBufferHead != v106 )
              {
                _this->dword_00001C = v6;
                _this->dword_000020 = v117;
                v107 = pParent->pCompressedData;
                pParent->uCompressedDataSize = v115;
                pParent->pCompressedData = v73;
                pParent->dword_000008 += (char *)v73 - v107;
                _this->pDecompressionBufferTail = v106;
                return class21_fn3(_this, pParent, v68);
              }
              _this->dword_000000 = 8;
LABEL_124:
              _this->dword_00001C = v6;
              _this->dword_000020 = v117;
              v108 = pParent->pCompressedData;
              pParent->uCompressedDataSize = v115;
              v109 = pParent->dword_000008;
              pParent->pCompressedData = v73;
              pParent->dword_000008 = (char *)v73 - v108 + v109;
              _this->pDecompressionBufferTail = v106;
              result = class21_fn3(_this, pParent, 1);
            }
          }
        }
        return result;
      case 4:
        v41 = v117;
        goto LABEL_57;
      case 5:
        v41 = v117;
        goto LABEL_68;
      case 6:
        v41 = v117;
        goto LABEL_91;
      case 7:
        v72 = v116;
        v73 = v114;
        goto LABEL_119;
      case 8:
        v106 = v116;
        v73 = v114;
        goto LABEL_124;
      case 9:
        v93 = v115;
        _this->dword_00001C = v6;
        _this->dword_000020 = v117;
        goto LABEL_126;
      default:
        _this->dword_00001C = v6;
        _this->dword_000020 = v117;
        v112 = pParent->pCompressedData;
        v113 = pParent->dword_000008;
        pParent->uCompressedDataSize = v115;
        pParent->pCompressedData = v114;
        pParent->dword_000008 = (char *)v114 + v113 - v112;
        _this->pDecompressionBufferTail = v116;
        return class21_fn3(_this, pParent, -2);
    }
  }
}

//----- (MM7.ee::004C8370) --------------------------------------------------------
int class21_fn3(struct class21 *_this, struct class19 *pParent, int a3)
{
 int i;
  unsigned int v6;
  unsigned int v7; // eax@3
  unsigned int uDecompressedBufferLen; // esi@3
  int v10; // edx@8
  int v11; // eax@9
  int v12; // eax@10
  int v13; // ecx@10
  const void *v14; // esi@11
  unsigned int v15; // eax@13
  unsigned int v16; // edi@13
  //int (__fastcall *v17)(_DWORD, _DWORD, _DWORD); // eax@18
  int v18; // edx@18
  int v19; // eax@19
  unsigned int v21; // [sp+10h] [bp-Ch]@3
  int v22; // [sp+10h] [bp-Ch]@13
  void *v23; // [sp+14h] [bp-8h]@1
  void *v24; // [sp+14h] [bp-8h]@10
  int v25; // [sp+18h] [bp-4h]@1
  int v26; // [sp+18h] [bp-4h]@11

  v6 = _this->pDecompressionBufferTail;
  v25 = _this->pDecompressionBufferHead;
  if (_this->pDecompressionBufferHead > _this->pDecompressionBufferTail)
    v6 = _this->dword_00002C;
  v7 = pParent->uDecompressedDataSize;
  uDecompressedBufferLen = v6 - (unsigned int)_this->pDecompressionBufferHead;
  v21 = uDecompressedBufferLen;
  if (uDecompressedBufferLen > pParent->uDecompressedDataSize)
  {
   v21 = pParent->uDecompressedDataSize;
   uDecompressedBufferLen = pParent->uDecompressedDataSize;
  }
  if (uDecompressedBufferLen)
  {
    if (a3 == -5)
      a3 = 0;
  }
  v10 = uDecompressedBufferLen + pParent->dword_000014;
  pParent->uDecompressedDataSize = v7 - uDecompressedBufferLen;
  pParent->dword_000014 = v10;

  if (_this->pfn_000038)
  {
   v11 = (_this->pfn_000038)(_this->dword_00003C, _this->pDecompressionBufferHead, uDecompressedBufferLen);
   _this->dword_00003C = v11;
   pParent->dword_00002C = v11;
  }

  memcpy(pParent->pDecompressedData, _this->pDecompressionBufferHead, uDecompressedBufferLen);
  v12 = v21 + v25;
  v13 = _this->dword_00002C;
  v24 = pParent->pDecompressedData + v21;
  if ( v21 + v25 == v13 )
  {
    v14 = _this->dword_000028;
    v26 = _this->dword_000028;
    if ( _this->pDecompressionBufferTail == v13 )
      _this->pDecompressionBufferTail = v14;
    v15 = pParent->uDecompressedDataSize;
    v16 = _this->pDecompressionBufferTail - (_DWORD)v14;
    v22 = _this->pDecompressionBufferTail - (_DWORD)v14;
    if ( v16 > v15 )
    {
      v22 = pParent->uDecompressedDataSize;
      v16 = pParent->uDecompressedDataSize;
    }
    if ( v16 )
    {
      if ( a3 == -5 )
        a3 = 0;
    }
    v18 = v16 + pParent->dword_000014;
    pParent->uDecompressedDataSize = v15 - v16;
    pParent->dword_000014 = v18;
    if (_this->pfn_000038)
    {
     v19 = (_this->pfn_000038)(_this->dword_00003C, v14, v16);
     _this->dword_00003C = v19;
     pParent->dword_00002C = v19;
    }
    memcpy(v24, v14, v16);
    v24 = (char *)v24 + v22;
    v12 = v22 + v26;
  }

 pParent->pDecompressedData = v24;
 _this->pDecompressionBufferHead = v12;
 return a3;
}

//----- (MM7.exe::004C74A0) --------------------------------------------------------
int class21_fn4(struct class21 *_this, struct class19 *pParent, int a3)
{
  struct class27 *v3; // eax@1
  unsigned char *v4; // edx@1
  unsigned int v5; // ecx@1
  unsigned int v6; // ebx@1
  unsigned char *v7; // ebp@1
  signed int v11; // eax@8
  unsigned int v12; // ecx@8
  int v13; // ebx@8
  int v14; // ecx@8
  int v15; // ecx@9
  unsigned int v17; // eax@14
  char v18; // cl@16
  int v19; // ecx@16
  unsigned char *v20; // eax@17
  int v21; // ecx@17
  int v22; // ecx@17
  int v23; // ecx@18
  int v24; // ecx@20
  unsigned int v25; // eax@25
  char v26; // cl@27
  int v27; // ecx@27
  int v28; // ecx@28
  unsigned int v29; // eax@29
  char v30; // cl@31
  int v31; // ecx@31
  int v32; // ecx@32
  int v33; // ecx@33
  unsigned int v34; // eax@36
  char v35; // cl@38
  int v36; // ecx@38
  unsigned int v37; // eax@40
  unsigned int v38; // eax@46
  unsigned int v39; // ecx@46
  int v40; // eax@48
  unsigned int v41; // eax@51
  int v42; // eax@51
  unsigned int v44; // ecx@55
  int v45; // eax@57
  unsigned int v47; // eax@68
  unsigned int v48; // ecx@68
  int v49; // eax@70
  unsigned int v50; // eax@73
  int v51; // eax@73
  int v52; // ecx@74
  unsigned int v53; // ecx@77
  int v54; // eax@79
  int result; // eax@86
  int v56; // ebx@86
  int v57; // ecx@86
  int v58; // ebx@88
  int v59; // ecx@88
  int v60; // ebx@89
  int v61; // ecx@89
  int v62; // eax@92
  int v63; // ebx@93
  int v64; // ebx@95
  int v65; // ecx@95
  int v66; // ebx@96
  int v67; // ecx@96
  int v68; // ebx@97
  int v69; // ecx@97

  unsigned int v70; // [sp+10h] [bp-18h]@1
  struct class27 *v71; // [sp+14h] [bp-14h]@1
  unsigned int v72; // [sp+18h] [bp-10h]@1
  unsigned int v73; // [sp+1Ch] [bp-Ch]@4
  unsigned int v74; // [sp+20h] [bp-8h]@14
  int v75; // [sp+20h] [bp-8h]@17
  unsigned int v76; // [sp+20h] [bp-8h]@25
  unsigned int v77; // [sp+20h] [bp-8h]@29
  unsigned int v78; // [sp+20h] [bp-8h]@36
  int v79; // [sp+24h] [bp-4h]@41
  int v80; // [sp+2Ch] [bp+4h]@51

  v3 = _this->class27_obj;
  v7 = pParent->pCompressedData;
  v6 = _this->dword_00001C;
  v72 = pParent->uCompressedDataSize;
  v5 = _this->pDecompressionBufferHead;
  v70 = _this->dword_000020;
  v4 = _this->pDecompressionBufferTail;
  v71 = _this->class27_obj;
  if ( v4 >= v5 )
    v73 = _this->dword_00002C - (unsigned int)v4;
  else
    v73 = v5 - (unsigned int)v4 - 1;
  while ( 2 )
  {
    switch (v3->dword_000000)
    {
      case 0:
        if ( v73 >= 0x102 )
        {
          if ( v72 >= 0xA )
          {
            _this->dword_000020 = v70;
            _this->dword_00001C = v6;
            v13 = pParent->pCompressedData;
            _this->class27_obj = v72;
            v14 = pParent->dword_000008;
            pParent->pCompressedData = v7;
            pParent->dword_000008 = v7 - v13 + v14;
            _this->pDecompressionBufferTail = v4;
            v11 = LOD_DoDecompression(v71->byte_000010, v71->byte_000011,
                                      v71->ptr_000014,
                                      v71->ptr_000018, _this, pParent);
            v7 = pParent->pCompressedData;
            v6 = _this->dword_00001C;
            v72 = pParent->uCompressedDataSize;
            v12 = _this->pDecompressionBufferHead;
            v70 = _this->dword_000020;
            v4 = _this->pDecompressionBufferTail;
            a3 = v11;
            v15 = v4 >= v12 ? _this->dword_00002C - (unsigned int)v4 : v12 - (unsigned int)v4 - 1;
            v73 = v15;
            if ( v11 )
            {
              v71->dword_000000 = v11 != 1 ? 9 : 7;
              v3 = v71;
              continue;
            }
          }
        }
        v3 = v71;
        v71->dword_000000 = 1;
        v71->dword_000008 = v71->ptr_000014;
        v71->dword_00000C = v71->byte_000010;
        goto LABEL_14;
      case 1:
LABEL_14:
        v17 = v3->dword_00000C;
        v74 = v17;
        if ( v6 >= v17 )
          goto LABEL_17;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v18 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v19 = ((unsigned int)(*v7++) << v18) | v70;
          v17 = v74;
          v70 = v19;
        }
        while ( v6 < v74 );
LABEL_17:
        v20 = v71->dword_000008 + 8 * (v70 & dword_4F2688[v17]);
        v75 = v20;
        v22 = v20[1];
        v70 >>= v22;
        v6 -= v22;
        v21 = *v20;
        if (*v20)
        {
          if ( v21 & 0x10 )
          {
            v3 = v71;
            v71->dword_000008 = v21 & 0xF;
            v24 = *(_DWORD *)(v75 + 4);
            v71->dword_000000 = 2;
            v71->dword_000004 = v24;
          }
          else
          {
            if ( !(v21 & 0x40) )
              goto LABEL_22;
            v3 = v71;
            if ( !(v21 & 0x20) )
            {
             v71->dword_000000 = 9;
              pParent->pStatus = "invalid literal/length code";
LABEL_88:
              _this->dword_000020 = v70;
              _this->dword_00001C = v6;
              v58 = pParent->dword_000008;
              _this->class27_obj = v72;
              v59 = v7 - (unsigned int)pParent->pCompressedData;
              pParent->pCompressedData = v7;
              pParent->dword_000008 = v59 + v58;
              _this->pDecompressionBufferTail = v4;
              return class21_fn3(_this, pParent, -3);
            }
            v71->dword_000000 = 7;
          }
        }
        else
        {
          v23 = *(_DWORD *)(v20 + 4);
          v3 = v71;
          v71->dword_000008 = v23;
          v71->dword_000000 = 6;
        }
        continue;
      case 2:
        v25 = v3->dword_000008;
        v76 = v25;
        if ( v6 >= v25 )
          goto LABEL_28;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v26 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v27 = ((unsigned int)(*v7++) << v26) | v70;
          v25 = v76;
          v70 = v27;
        }
        while ( v6 < v76 );
LABEL_28:
        v71->dword_000004 += v70 & dword_4F2688[v25];
        v70 >>= v76;
        v6 -= v76;
        v3 = v71;
        v28 = v71->byte_000011;
        v71->dword_000000 = 3;
        v71->dword_00000C = v28;
        v71->dword_000008 = v71->ptr_000018;
LABEL_29:
        v29 = v3->dword_00000C;
        v77 = v29;
        if ( v6 < v29 )
        {
          while ( v72 )
          {
            v30 = v6;
            --v72;
            v6 += 8;
            a3 = 0;
            v31 = ((unsigned int)(*v7++) << v30) | v70;
            v29 = v77;
            v70 = v31;
            if ( v6 >= v77 )
              goto LABEL_32;
          }
LABEL_86:
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v56 = pParent->dword_000008;
          v57 = v7 - (unsigned int)pParent->pCompressedData;
          _this->class27_obj = 0;
          pParent->pCompressedData = v7;
          pParent->dword_000008 = v57 + v56;
          _this->pDecompressionBufferTail = v4;
          return class21_fn3(_this, pParent, a3);
        }
LABEL_32:
        v75 = v71->dword_000008 + 8 * (v70 & dword_4F2688[v29]);
        v32 = *(unsigned char *)(v75 + 1);
        v6 -= v32;
        v70 >>= v32;
        v21 = *(unsigned char *)v75;
        if ( v21 & 0x10 )
        {
          v3 = v71;
          v71->dword_000008 = v21 & 0xF;
          v33 = *(_DWORD *)(v75 + 4);
          v71->dword_000000 = 4;
          v71->dword_00000C = v33;
        }
        else
        {
          if ( v21 & 0x40 )
          {
           v71->dword_000000 = 9;
            pParent->pStatus = "invalid distance code";
            goto LABEL_88;
          }
LABEL_22:
          v71->dword_00000C = v21;
          v3 = v71;
          v71->dword_000008 = v75 + 8 * *(_DWORD *)(v75 + 4);
        }
        continue;
      case 3:
        goto LABEL_29;
      case 4:
       v34 = v3->dword_000008;
        v78 = v34;
        if ( v6 >= v34 )
          goto LABEL_39;
        do
        {
          if ( !v72 )
            goto LABEL_86;
          v35 = v6;
          --v72;
          v6 += 8;
          a3 = 0;
          v36 = ((unsigned int)(*v7++) << v35) | v70;
          v34 = v78;
          v70 = v36;
        }
        while ( v6 < v78 );
LABEL_39:
        v71->dword_00000C += v70 & dword_4F2688[v34];
        v70 >>= v78;
        v6 -= v78;
        v71->dword_000000 = 5;


      case 5:
        v37 = v71->dword_00000C;
        if ((unsigned int)v4 - (unsigned int)_this->dword_000028 >= v37 )
          v79 = v4 - v37;
        else
         v79 = (unsigned int)v4 + (unsigned int)_this->dword_00002C - (unsigned int)_this->dword_000028 - v71->dword_00000C;
        v3 = v71;
        if ( !v71->dword_000004 )
        {
LABEL_65:
         v3->dword_000000 = 0;
          continue;
        }
        while ( v73 )
        {
LABEL_62:
          a3 = 0;
          *v4++ = *(unsigned char *)v79++;
          --v73;
          if ( v79 == _this->dword_00002C )
            v79 = _this->dword_000028;
          if (!--v3->dword_000004)
            goto LABEL_65;
        }
        if ((unsigned int)v4 == _this->dword_00002C )
        {
          v38 = _this->pDecompressionBufferHead;
          v39 = _this->dword_000028;
          if ( v38 != v39 )
          {
            v4 = _this->dword_000028;
            v40 = v39 >= v38 ? _this->dword_00002C - v39 : v38 - v39 - 1;
            v73 = v40;
            if ( v40 )
              goto LABEL_100;
          }
        }
        _this->pDecompressionBufferTail = v4;  //28 == head, 2c == tail
        v42 = class21_fn3(_this, pParent, a3); // 28 == head == tail, 2c
        v4 = _this->pDecompressionBufferTail;
        v80 = v42;
        v41 = _this->pDecompressionBufferHead;

        if (v4 >= v41)
          v73 = _this->dword_00002C - (unsigned int)v4;
        else
          v73 = v41 - (unsigned int)v4 - 1;

        if ((unsigned int)v4 == _this->dword_00002C )
        {
          v44 = _this->dword_000028;
          if ( v41 != v44 )
          {
            v4 = _this->dword_000028;
            if ( v44 >= v41 )
              v45 = _this->dword_00002C - v44;
            else
              v45 = v41 - v44 - 1;
            v73 = v45;
          }
        }
        if ( v73 )
        {
LABEL_100:
          v3 = v71;
          goto LABEL_62;
        }
LABEL_89:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v60 = pParent->pCompressedData;
        _this->class27_obj = v72;
        v61 = pParent->dword_000008;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v7 - v60 + v61;
         _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, v80);


      case 6:
        if ( v73 )
          goto LABEL_84;
        if ((unsigned int)v4 != _this->dword_00002C
          || (v47 = _this->pDecompressionBufferHead, v48 = _this->dword_000028, v47 == v48)
          || ((v4 = _this->dword_000028, v48 >= v47) ? (v49 = _this->dword_00002C - v48) : (v49 = v47 - v48 - 1),
              v73 = v49,
              !v49) )
        {
          _this->pDecompressionBufferTail = v4;
          v51 = class21_fn3(_this, pParent, a3);
          v4 = _this->pDecompressionBufferTail;
          v80 = v51;
          v50 = _this->pDecompressionBufferHead;
          v52 = v4 >= v50 ? _this->dword_00002C - (unsigned int)v4 : v50 - (unsigned int)v4 - 1;
          v73 = v52;
          if ((unsigned int)v4 == _this->dword_00002C )
          {
            v53 = _this->dword_000028;
            if ( v50 != v53 )
            {
              v4 = _this->dword_000028;
              if ( v53 >= v50 )
                v54 = _this->dword_00002C - v53;
              else
                v54 = v50 - v53 - 1;
              v73 = v54;
            }
          }
          if ( !v73 )
            goto LABEL_89;
        }
        v3 = v71;
LABEL_84:
        a3 = 0;
        *v4++ = v3->dword_000008;
        --v73;
        v3->dword_000000 = 0;
        continue;
      case 7:
        if ( v6 > 7 )
        {
          v6 -= 8;
          --v7;
          ++v72;
        }
        _this->pDecompressionBufferTail = v4;
        v62 = class21_fn3(_this, pParent, a3);
        v4 = _this->pDecompressionBufferTail;
        if ( _this->pDecompressionBufferHead == v4 )
        {
          *(_DWORD *)v71 = 8;
LABEL_95:
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v64 = pParent->dword_000008;
          pParent->uCompressedDataSize = v72;
          v65 = v7 - (unsigned int)pParent->pCompressedData;
          pParent->pCompressedData = v7;
          pParent->dword_000008 = v65 + v64;
          _this->pDecompressionBufferTail = v4;
          result = class21_fn3(_this, pParent, 1);
        }
        else
        {
          _this->dword_00001C = v6;
          _this->dword_000020 = v70;
          v63 = pParent->pCompressedData;
          pParent->uCompressedDataSize = v72;
          pParent->pCompressedData = v7;
          pParent->dword_000008 += (unsigned int)v7 - v63;
          _this->pDecompressionBufferTail = v4;
          result = class21_fn3(_this, pParent, v62);
        }
        return result;
      case 8:
        goto LABEL_95;
      case 9:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v66 = pParent->pCompressedData;
        _this->class27_obj = v72;
        v67 = pParent->dword_000008;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v7 - v66 + v67;
        _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, -3);
      default:
        _this->dword_000020 = v70;
        _this->dword_00001C = v6;
        v68 = pParent->dword_000008;
        _this->class27_obj = v72;
        v69 = v7 - (unsigned int)pParent->pCompressedData;
        pParent->pCompressedData = v7;
        pParent->dword_000008 = v69 + v68;
        _this->pDecompressionBufferTail = v4;
        return class21_fn3(_this, pParent, -2);
    }
  }
}

//----- (004C84C0) --------------------------------------------------------
signed int __fastcall LOD_DoDecompression(int a1, int a2, int a3, int a4, struct class21 *pClass21, struct class19 *pClass19)
{
  unsigned int v6; // eax@1
  unsigned int v7; // ecx@1
  unsigned char *pDataPtr;
  unsigned char *v9; // ebp@1
  unsigned int v10; // esi@1
  int v11; // edx@6
  int v12; // edx@8
  unsigned char *v13; // edi@8
  int v14; // ecx@9
  unsigned int v15; // eax@10
  unsigned int v16; // esi@10
  int v17; // ecx@10
  int v18; // ecx@13
  int v19; // eax@14
  int v20; // edx@14
  unsigned int v21; // esi@14
  int v22; // edx@15
  int v23; // edx@17
  int v24; // edi@17
  int v25; // ecx@17
  int v26; // ecx@19
  int v27; // ecx@19
  int v28; // edx@20
  int v29; // ebx@23
  int v30; // edx@24
  int v31; // ecx@24
  int v32; // ebx@24
  char v33; // cl@24
  int v34; // ecx@25
  int v35; // ecx@25
  int v36; // ebp@25
  char v37; // bl@25
  char v38; // bl@25
  int v39; // edi@26
  int v40; // ecx@32
  unsigned int v41; // edx@37
  int v43; // edx@37
  int v44; // ecx@39
  int v46; // ebx@41
  int v47; // esi@41
  int v48; // eax@41
  int v49; // ecx@43
  int v50; // ebx@45
  int v51; // esi@45
  int v52; // eax@45
  int v53; // edx@46
  int v54; // ebx@48
  int v55; // esi@48
  int v56; // eax@48
  unsigned int v57; // [sp+10h] [bp-1Ch]@1
  int v58; // [sp+14h] [bp-18h]@2
  int v59; // [sp+1Ch] [bp-10h]@1
  int v60; // [sp+1Ch] [bp-10h]@14
  int v61; // [sp+1Ch] [bp-10h]@37
  int v62; // [sp+20h] [bp-Ch]@1
  int v63; // [sp+24h] [bp-8h]@4
  int v64; // [sp+28h] [bp-4h]@4
  int a;

  pDataPtr = pClass19->pCompressedData;
  v59 = a1;
  v57 = pClass19->uCompressedDataSize;
  v9 = pClass21->pDecompressionBufferTail;
  v7 = pClass21->pDecompressionBufferHead;
  v10 = pClass21->dword_000020;
  v6 = pClass21->dword_00001C;
  v62 = pClass19->pCompressedData;
  if ( v9 >= v7 )
    v58 = pClass21->dword_00002C - (unsigned int)v9;
  else
    v58 = v7 - (unsigned int)v9 - 1;
  v64 = dword_4F2688[a2];
  v63 = dword_4F2688[v59];

  a = 0xffff;
  while ( 1 )
  {
   a = v57;
    if ( v6 < 0x14 )
    {
      do
      {
        --v57;
        v11 = (unsigned int)(*pDataPtr++) << v6;
        v6 += 8;
        v10 |= v11;
      }
      while ( v6 < 0x14 );
      v62 = pDataPtr;
    }
    v13 = (char *)a3 + 8 * (v10 & v63);
    v12 = *v13;
    if (v12)
      break;
    v14 = v13[1];
    v10 >>= v14;
    v6 -= v14;
    *v9 = v13[4];
LABEL_33:
    ++v9;
    --v58;
LABEL_34:
    if ( (unsigned int)v58 < 0x102 || v57 < 0xA )
    {
      v44 = pClass19->uCompressedDataSize - v57;
      if ( v6 >> 3 < v44 )
        v44 = v6 >> 3;
      v46 = (unsigned int)(pDataPtr) - v44;
      pClass21->dword_000020 = v10;
      pClass21->dword_00001C = v6 - 8 * v44;
      v47 = pClass19->pCompressedData;
      v48 = pClass19->dword_000008;
      pClass19->uCompressedDataSize = v57 + v44;
      pClass19->pCompressedData = v46;
      pClass19->dword_000008 = v46 - v47 + v48;
      pClass21->pDecompressionBufferTail = v9;
      return 0;
    }
  }
  v17 = v13[1];
  v16 = v10 >> v17;
  v15 = v6 - v17;
  if ( v12 & 0x10 )
  {
LABEL_14:
    v20 = v12 & 0xF;
    v19 = v15 - v20;
    v60 = *(unsigned int *)(v13 + 4) + (v16 & dword_4F2688[v20]);
    v21 = v16 >> v20;
    if ( (unsigned int)v19 < 0xF )
    {
      do
      {
        --v57;
        v22 = (unsigned int)(*pDataPtr++) << v19;
        v19 += 8;
        v21 |= v22;
      }
      while ( (unsigned int)v19 < 0xF );
      v62 = pDataPtr;
    }
    v24 = a4 + 8 * (v21 & v64);
    v25 = *(_BYTE *)(v24 + 1);
    v23 = *(_BYTE *)v24;
    v16 = v21 >> v25;
    v15 = v19 - v25;
    if ( !(v23 & 0x10) )
    {
      while ( !(v23 & 0x40) )
      {
        v26 = *(_DWORD *)(v24 + 4) + (v16 & dword_4F2688[v23]);
        v23 = *(_BYTE *)(v24 + 8 * v26);
        v24 += 8 * v26;
        v27 = *(_BYTE *)(v24 + 1);
        v16 >>= v27;
        v15 -= v27;
        if ( v23 & 0x10 )
          goto LABEL_20;
      }
      v43 = pClass19->uCompressedDataSize;
      pClass19->pStatus = "invalid distance code";
      v61 = v43 - v57;
      v41 = v15 >> 3;
      if ( v15 >> 3 >= v61 )
LABEL_47:
        v41 = v61;
LABEL_48:
      v54 = (unsigned int)(pDataPtr) - v41;
      pClass21->dword_000020 = v16;
      pClass21->dword_00001C = v15 - 8 * v41;
      v55 = pClass19->pCompressedData;
      v56 = pClass19->dword_000008;
      pClass19->uCompressedDataSize = v57 + v41;
      pClass19->pCompressedData = v54;
      pClass19->dword_000008 = v54 - v55 + v56;
      pClass21->pDecompressionBufferTail = v9;
      return -3;
    }
LABEL_20:
    v28 = v23 & 0xF;
    if ( v15 < v28 )
    {
      while ( 1 )
      {
        --v57;
        v29 = (unsigned int)(*pDataPtr++) << v15;
        v15 += 8;
        v16 |= v29;
        ++v62;
        if ( v15 >= v28 )
          break;
      }
    }
    v6 = v15 - v28;
    v32 = *(unsigned int *)(v24 + 4) + (v16 & dword_4F2688[v28]);
    v33 = v28;
    v30 = v60;
    v10 = v16 >> v33;
    v58 -= v60;
    v31 = pClass21->dword_000028;
    if ( (unsigned int)v9 - v31 < (unsigned int)v32 )
    {
      v39 = v32 + v31 - (unsigned int)v9;
      v34 = pClass21->dword_00002C - v39;
      if ( v60 > (unsigned int)v39 )
      {
        v30 = v60 - v39;
        do
        {
          *v9++ = *(_BYTE *)v34++;
          --v39;
        }
        while ( v39 );
        v34 = pClass21->dword_000028;
      }
    }
    else
    {
      v35 = v9 - v32;
      v36 = v9 + 1;
      v37 = *(_BYTE *)v35++;
      *(_BYTE *)(v36 - 1) = v37;
      v9 = v36 + 1;
      v38 = *(_BYTE *)v35;
      v34 = v35 + 1;
      v9[-1] = v38;
      v30 = v60 - 2;
    }
    do
    {
      *v9++ = *(_BYTE *)v34++;
      --v30;
    }
    while ( v30 );
    pDataPtr = v62;
    goto LABEL_34;
  }
  while ( !(v12 & 0x40) )
  {
    v13 += 8 * (*(unsigned int *)(v13 + 4) + (v16 & dword_4F2688[v12]));
    v12 = *v13;
    if (!v12)
    {
      v40 = v13[1];
      *v9 = v13[4];
      v10 = v16 >> v40;
      v6 = v15 - v40;
      goto LABEL_33;
    }
    v18 = v13[1];
    v16 >>= v18;
    v15 -= v18;
    if ( v12 & 0x10 )
      goto LABEL_14;
  }
  if ( !(v12 & 0x20) )
  {
    v53 = pClass19->uCompressedDataSize;
    pClass19->pStatus = "invalid literal/length code";
    v61 = v53 - v57;
    v41 = v15 >> 3;
    if ( v15 >> 3 >= v61 )
      goto LABEL_47;
    goto LABEL_48;
  }
  v49 = pClass19->uCompressedDataSize - v57;
  if ( v15 >> 3 < v49 )
    v49 = v15 >> 3;
  v50 = (unsigned int)(pDataPtr) - v49;
  pClass21->dword_000020 = v16;
  pClass21->dword_00001C = v15 - 8 * v49;
  v51 = pClass19->pCompressedData;
  v52 = pClass19->dword_000008;
  pClass19->uCompressedDataSize = v57 + v49;
  pClass19->pCompressedData = v50;
  pClass19->dword_000008 = v50 - v51 + v52;
  pClass21->pDecompressionBufferTail = v9;
  return 1;
}

//----- (004C7460) --------------------------------------------------------
struct class27 *__fastcall AllocateClass27(int a1, int a2, unsigned int *a3, unsigned int *a4, struct class19 *pParent)
{
 struct class27 *result;

 result = (pParent->pFunction1)(pParent->dword_000028, 1, 28);
 if ( result )
 {
  result->dword_000000 = 0;
  result->byte_000010 = a1;
  result->byte_000011 = a2;
  result->ptr_000014 = a3;
  result->ptr_000018 = a4;
 }
 return result;
}

//----- (004C7C60) --------------------------------------------------------
signed int __fastcall sub_4C7C60(int *pSomeIndices, unsigned int *a2, int *a3, unsigned int *class21_pArray_8x1440, struct class19 *pParent)
{
  unsigned int *p19x4Buffer; // edi@1
  signed int result; // eax@2
  signed int v10; // eax@3

  int v13[256];   //some local struct or array
  v13[0] = 0;

  p19x4Buffer = (pParent->pFunction1)(pParent->dword_000028, 19, 4);
  if (p19x4Buffer)
  {
    v10 = sub_4C7D10(pSomeIndices, 0x13u, 0x13u, 0, 0, a3, a2, class21_pArray_8x1440, v13, p19x4Buffer);
    if (v10 == -3)
    {
     pParent->pStatus = "oversubscribed dynamic bit lengths tree";
     (pParent->pFunction2)(pParent->dword_000028, p19x4Buffer);
     result = v10;
    }
    else
    {
      if (v10 == -5 || !*a2)
      {
       pParent->pStatus = "incomplete dynamic bit lengths tree";
       v10 = -3;
      }
      (pParent->pFunction2)(pParent->dword_000028, p19x4Buffer);
      result = v10;
    }
  }
  else return -4;
  return result;
}

//----- (004C81E0) --------------------------------------------------------
signed int __fastcall sub_4C81E0(unsigned int uNumIndices, int a2, int *pSomeIndices, unsigned int *a4, unsigned int *a5, int **a6, int **a7, unsigned *pResultBuffer, struct class19 *pParent)
{
  unsigned int *p288x4Buffer; // eax@1
  signed int v14; // eax@3
  int v17; // ecx@10
  int v19; // [sp+10h] [bp-8h]@1
  unsigned int v20; // [sp+14h] [bp-4h]@1

  v20 = a2;
  v19 = 0;
  p288x4Buffer = (pParent->pFunction1)(pParent->dword_000028, 288, 4);
  if (!p288x4Buffer)
    return -4;
  //v14 = sub_4C7D10(pSomeIndices, uNumIndices, 0x101u, 0x4D956C, 0x4D95E8, a6, a4, a8, (int)&v19, p288x4Buffer);
  v14 = sub_4C7D10(pSomeIndices, uNumIndices, 0x101u, &byte_4D8410[0x115C], &byte_4D8410[0x11D8], a6, a4, pResultBuffer, (int)&v19, p288x4Buffer);
  if ( v14 )
  {
    if ( v14 == -3 )
    {
     pParent->pStatus = "oversubscribed literal/length tree";
     (pParent->pFunction2)(pParent->dword_000028, p288x4Buffer);
      return -3;
    }
    if ( v14 == -4 )
      goto LABEL_20;
LABEL_18:
    pParent->pStatus = "incomplete literal/length tree";
    goto LABEL_19;
  }
  if ( !*a4 )
    goto LABEL_18;
  //v14 = sub_4C7D10(pSomeIndices + uNumIndices, v20, v14, 0x4D9664, 0x4D96DC, a7, a5, pResultBuffer, (int)&v19, p288x4Buffer);
  v14 = sub_4C7D10(pSomeIndices + uNumIndices, v20, v14, &byte_4D8410[0x1254], &byte_4D8410[0x12CC], a7, a5, pResultBuffer, (int)&v19, p288x4Buffer);
  if ( !v14 )
  {
    if ( *a5 || uNumIndices <= 0x101 )
    {
     (pParent->pFunction2)(pParent->dword_000028, p288x4Buffer);
      return 0;
    }
    goto LABEL_14;
  }
  if ( v14 == -3 )
  {
   pParent->pStatus = "oversubscribed distance tree";
    (pParent->pFunction2)(pParent->dword_000028, p288x4Buffer);
    return -3;
  }
  if ( v14 == -5 )
  {
   pParent->pStatus = "incomplete distance tree";
LABEL_19:
    v14 = -3;
    goto LABEL_20;
  }
  if ( v14 != -4 )
  {
LABEL_14:
    pParent->pStatus = "empty distance tree with lengths";
    goto LABEL_19;
  }
LABEL_20:
    (pParent->pFunction2)(pParent->dword_000028, p288x4Buffer);
  return v14;
}

//----- (004C7D10) --------------------------------------------------------
signed int __fastcall sub_4C7D10(int *pSomeIndices, unsigned int uNumIndices, unsigned int a3, int a4, int a5, unsigned int *pOutSomething, unsigned int *a7, int *a8, int *a9, unsigned int *pOutBuffer)
{
  int v10; // edx@1
  signed int result; // eax@5
  int *v15; // eax@6
  signed int v16; // ecx@6
  unsigned int v17; // ebp@6
  int v18; // eax@9
  int *v19; // edi@11
  signed int v20; // esi@11
  signed int v21; // edi@16
  int *v22; // ebx@17
  int v23; // edi@18
  int v24; // ecx@20
  int v25; // edi@20
  int v26; // ecx@22
  int v27; // esi@22
  int v28; // edi@23
  int v29; // ebx@24
  unsigned int v30; // edi@25
  int *v31; // esi@25
  int v32; // ecx@26
  int v33; // esi@27
  int v34; // ebx@29
  unsigned int v35; // edi@29
  int v36; // ecx@29
  int v37; // esi@30
  int v39; // edx@31
  int v40; // ecx@34
  int v41; // edx@37
  signed int v42; // eax@39
  int v43; // ecx@39
  int v44; // eax@40
  int *v45; // ebp@40
  int v46; // eax@42
  unsigned int v47; // edi@42
  int v49; // edx@44
  int v50; // eax@45
  int v51; // ST34_4@46
  unsigned int v52; // eax@46
  int v53; // ecx@46
  int v54; // esi@53
  char v55; // dl@53
  unsigned int v56; // eax@55
  signed int v57; // edx@55
  int v58; // ecx@56
  unsigned int i; // eax@58
  int *v60; // eax@60
  signed int v61; // edx@60
  int v62; // edx@63
  unsigned int v63; // [sp+10h] [bp-104h]@6
  signed int v64; // [sp+14h] [bp-100h]@9
  signed int v65; // [sp+18h] [bp-FCh]@29
  int v66; // [sp+1Ch] [bp-F8h]@26
  unsigned int *pOutBufferPtr; // [sp+1Ch] [bp-F8h]@29
  int v68; // [sp+20h] [bp-F4h]@1
  int v69; // [sp+20h] [bp-F4h]@30
  int v70; // [sp+24h] [bp-F0h]@20
  unsigned int v71; // [sp+24h] [bp-F0h]@29
  int v72; // [sp+28h] [bp-ECh]@31
  int *v73; // [sp+2Ch] [bp-E8h]@30
  int v74; // [sp+30h] [bp-E4h]@14
  int v75; // [sp+34h] [bp-E0h]@57
  signed int v76; // [sp+3Ch] [bp-D8h]@29
  int v77; // [sp+40h] [bp-D4h]@29
  unsigned int v78; // [sp+44h] [bp-D0h]@1
  int v79; // [sp+44h] [bp-D0h]@29
  int v80; // [sp+48h] [bp-CCh]@20
  int *v81; // [sp+4Ch] [bp-C8h]@45
  int v82; // [sp+50h] [bp-C4h]@37
  int v83; // [sp+54h] [bp-C0h]@35

  int v84_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  v68 = pSomeIndices;
  v10 = 0;
  v78 = uNumIndices;
  v51 = 0;
  v75 = 0;

  for (i = 0; i < uNumIndices; ++i)
    v84_array[pSomeIndices[i]]++;

  if (v84_array[0] == uNumIndices)
  {
   *pOutSomething = 0;
   *a7 = 0;
   return 0;
  }

  v16 = 1;
  v15 = &v84_array[1];
  v17 = *a7;
  v63 = *a7;
  do
  {
    if ( *v15 )
      break;
    ++v16;
    ++v15;
  }
  while ( (unsigned int)v16 <= 0xF );
  v18 = v16;
  v64 = v16;
  if ( v17 < v16 )
  {
    v63 = v16;
    v17 = v16;
  }
  v20 = 15;
  v19 = &v84_array[15];
  do
  {
    if ( *v19 )
      break;
    --v20;
    --v19;
  }
  while ( v20 );
  v74 = v20;
  if ( v17 > v20 )
  {
    v63 = v20;
    v17 = v20;
  }
  *a7 = v17;
  v21 = 1 << v16;
  if ( v16 < (unsigned int)v20 )
  {
   v22 = &v84_array[v16];
    do
    {
      v23 = v21 - *v22;
      if ( v23 < 0 )
        return -3;
      ++v16;
      ++v22;
      v21 = 2 * v23;
    }
    while ( v16 < (unsigned int)v20 );
  }
  v70 = 4 * v20;
  v24 = v84_array[v20];
  v25 = v21 - v24;
  v80 = v25;
  if ( v25 < 0 )
    return -3;
  v84_array[17] = 0;
  v84_array[v20] = v25 + v24;
  v26 = 0;
  v27 = v20 - 1;
  if ( v27 )
  {
    v28 = 0;
    do
    {
      v29 = v84_array[1 + v28 / 4];

      v28 += 4;
      v26 += v29;
      --v27;

      v84_array[17 + v28  / 4] = v26;
    }
    while ( v27 );
  }
  v31 = pSomeIndices;
  v30 = 0;
  do
  {
    v32 = *v31++;
    v66 = v31;
    if ( v32 )
    {
      v33 = v84_array[16 + v32];
      pOutBuffer[v33] = v30;
      v84_array[16 + v32] = v33 + 1;
      v31 = v66;
    }
    ++v30;
  }
  while ( v30 < v78 );
  v35 = 0;
  v65 = -1;
  v36 = v84_array[16 + v70 / 4];
  v71 = 0;
  v79 = v36;
  pOutBufferPtr = pOutBuffer;
  v34 = -v17;
  v84_array[16] = 0;
  v84_array[18 + 0] = 0;

  v77 = 0;
  v76 = 0;
  if ( v18 > v74 )
  {
LABEL_65:
    if ( v80 == v10 || v74 == 1 )
      return 0;
    result = -5;
  }
  else
  {
   v37 = 0;
    v69 = v18 - 1;
    v73 = &v84_array[v18];
    while ( 1 )
    {
      v39 = *v73 - 1;
      v72 = *v73 - 1;
      if ( *v73 )
        break;
LABEL_64:
      v10 = 0;
      ++v18;
      ++v73;
      v64 = v18;
      ++v69;
      if ( v18 > v74 )
        goto LABEL_65;
    }
    while ( 1 )
    {
      v40 = v34 + v17;
      if ( v18 > v40 )
        break;
LABEL_49:
      BYTE1(v75) = v18 - v34;
      if ((unsigned int)pOutBufferPtr < (unsigned int)pOutBuffer + v79 * 4)
      {
        v37 = *pOutBufferPtr;
        if ( v37 >= a3 )
        {
          v54 = 4 * (v37 - a3);
          v55 = *(_BYTE *)(v54 + a5);
          v37 = *(_DWORD *)(v54 + a4);
          LOBYTE(v75) = v55 + 80;
        }
        else
        {
          LOBYTE(v75) = (unsigned int)v37 < 0x100 ? 0 : 96;
        }
        ++pOutBufferPtr;
      }
      else
      {
        LOBYTE(v75) = -64;
      }
      v57 = 1 << (v18 - v34);
      v56 = v35 >> v34;
      if (v56 < v76 )
      {
        v58 = v77 + 8 * v56;
        do
        {
          v56 += v57;
          *(_DWORD *)v58 = v75;
          *(_DWORD *)(v58 + 4) = v37;
          v58 += 8 * v57;
        }
        while ( v56 < v76 );
      }
      for ( i = 1 << v69; i & v35; i >>= 1 )
        v35 ^= i;
      v61 = v65;
      v35 ^= i;
      v60 = &v84_array[16 + v65];
      v71 = v35;
      if ((v35 & ((1 << v34) - 1)) != v84_array[16 + v65] )
      {
        do
        {
          --v61;
          v34 -= v63;
          --v60;
        }
        while ( (v35 & ((1 << v34) - 1)) != *v60 );
        v65 = v61;
      }
      v17 = v63;
      v62 = v72--;
      v18 = v64;
      if ( !v62 )
        goto LABEL_64;
      v39 = v72;
    }
    v83 = v39 + 1;
    while ( 1 )
    {
      v34 += v17;
      ++v65;
      v41 = v74 - v34;
      v82 = v17 + v40;
      if ( v74 - v34 > v17 )
        v41 = v17;
      v43 = v18 - v34;
      v42 = 1 << (v18 - v34);
      if ( v42 > (unsigned int)v83 )
      {
        v45 = v73;
        v44 = -1 - v72 + v42;
        if ( v43 < (unsigned int)v41 )
        {
          ++v43;
          for ( ; v43 < (unsigned int)v41; ++v43 )
          {
            v47 = v45[1];
            ++v45;
            v46 = 2 * v44;
            if ( v46 <= v47 )
              break;
            v44 = v46 - v47;
          }
        }
      }
      v76 = 1 << v43;
      v49 = *a9 + (1 << v43);
      if ( (unsigned int)v49 > 0x5A0 )
        break;
      v50 = a8 + 2 * (*a9);
      *a9 = v49;
      v77 = v50;
      v81 = &v84_array[18 + v65];
      *v81 = v50;
      if ( v65 )
      {
        v35 = v71;
        LOBYTE(v51) = v43;
        v84_array[16 + v65] = v71;
        BYTE1(v51) = v63;
        v52 = v71 >> (v34 - (_BYTE)v63);
        v53 = *(v81 - 1);
        v37 = ((v77 - v53) >> 3) - v52;
        *(_DWORD *)(v53 + 8 * v52) = v51;
        *(_DWORD *)(v53 + 8 * v52 + 4) = v37;
      }
      else
      {
        v35 = v71;
        *pOutSomething = v50;
      }
      v40 = v82;
      LOBYTE(v18) = v64;
      if ( v64 <= v82 )
        goto LABEL_49;
      v17 = v63;
      v18 = v64;
    }
    result = -4;
  }
  return result;
}

//----- (004C8340) --------------------------------------------------------
extern int dword_4F1490;
extern int dword_4F1494;
extern char unk_4F1498;
extern char unk_4F2498;
int __fastcall sub_4C8340(int a1, int a2, int a3, int a4, int a5)
{
  *(_DWORD *)a1 = dword_4F1490;
  *(_DWORD *)a2 = dword_4F1494;
  *(_DWORD *)a3 = &unk_4F1498;
  *(_DWORD *)a4 = &unk_4F2498;
  return 0;
}