#include "Vis.h"

#include "mm7_unparsed_data.h"
#include "mm7_unparsed_functions.h"

#include "Game.h"




//----- (MM7.exe::004C04AF) --------------------------------------------------------
Vis::Vis()
{
 struct Vis_stru0 local_0C;
 //float v3; // [sp+Ch] [bp-60h]@1
 //float v4; // [sp+10h] [bp-5Ch]@1
 //float v5; // [sp+14h] [bp-58h]@1
 //float v6; // [sp+38h] [bp-34h]@1

 struct Vis_stru0 local_3C;
 //float v7; // [sp+3Ch] [bp-30h]@1
 //float v8; // [sp+40h] [bp-2Ch]@1
 //float v9; // [sp+44h] [bp-28h]@1
 //float v10; // [sp+68h] [bp-4h]@1

 local_3C.vPosition = Vec3<float>(65536.0f, 0.0f, 0.0f);
 local_3C.flt_00002C = 0.0f;
 memcpy(&struct_00200C, &local_3C, sizeof(struct Vis_stru0));
 
 local_0C.vPosition = Vec3<float>(0.0f, 65536.0f, 0.0f);
 local_0C.flt_00002C = 0.0f;
 memcpy(&struct_00203C, &local_0C, sizeof(struct Vis_stru0));
 
 local_0C.vPosition = Vec3<float>(65536.0f, 0.0f, 0.0f);
 local_0C.flt_00002C = 0.0f;
 memcpy(&struct_00206C, &local_0C, sizeof(struct Vis_stru0));
 
 local_3C.vPosition = Vec3<float>(0.0f, 65536.0f, 0.0f);
 local_3C.flt_00002C = 0.0f;
 memcpy(&struct_00209C, &local_3C, sizeof(struct Vis_stru0));

 dword_0020CC = 512;
}




//----- (004C05CC) --------------------------------------------------------
Result::Code Vis::PickKeyboard(unnamed_F93E6C *a3, unnamed_F93E6C *a4)
{
 class25_obj.uNumPointers = 0;
 Vis_sub_4C06F8(this, dword_0020CC, &class25_obj, a3);

 if (uCurrentlyLoadedLevelType == 1)
   Vis_sub_4C0D32_DoSomeOtherPicking_Indoor(this, dword_0020CC, &class25_obj, a4);
 else
   Vis_sub_4C0DEA_DoSomeOtherPicking_Outdoor(this, dword_0020CC, &class25_obj, a4);

 class25_create_object_pointers(&class25_obj, 1);
 class25_sort_object_pointers(class25_obj.array_001804, 0, class25_obj.uNumPointers - 1);

 return Result::Success;
}

//----- (004C0646) --------------------------------------------------------
Result::Code Vis::PickMouse(float fDepth, float fMouseX, float fMouseY, unnamed_F93E6C *a5, unnamed_F93E6C *a6)
{
 struct Vis_stru0 pMouseRay[2];
 CastRayAtMousePosition(pMouseRay, pOldCamera, fMouseX, fMouseY, fDepth);

 class25_obj.uNumPointers = 0;
 Vis_sub_4C1542(this, fDepth, fMouseX, fMouseY, &class25_obj, a5);

 if (uCurrentlyLoadedLevelType == 1)
   Vis_sub_4C16B4_DoPicking_Indoor(this, fDepth, pMouseRay, &class25_obj, a6);
 else
   Vis_sub_4C17CF_DoPicking_Outdoor(this, fDepth, pMouseRay, &class25_obj, a6, 0);

 class25_create_object_pointers(&class25_obj, 0);
 class25_sort_object_pointers(class25_obj.array_001804, 0, class25_obj.uNumPointers - 1);
  
 return Result::Success;
}

//----- (004C06F8) --------------------------------------------------------
void Vis_sub_4C06F8(struct Vis *_this, float a2, struct class25 *a3, struct unnamed_F93E6C *a4)
{
  int v4; // ST18_4@5
 struct RenderBillboardD3D3 *v7; // [sp+24h] [bp-8h]@2

 for (unsigned int i = 0; i < pD3DRenderer->uNumBillboardsToDraw; ++i)
   if (Vis_is_part_of_selection(i, a4))
   {
    if (Vis_IsRayIntersectsSprite(_this, a2, i))
    {
     v7 = &pBillboardRenderListD3D3[i];
     v4 = pBillboardRenderList[v7->uParentBillboardID].sZValue;

     a3->array_000004[a3->uNumPointers].uBillboardID = v7->uParentBillboardID;
     a3->array_000004[a3->uNumPointers].sZValue = v4;
     a3->array_000004[a3->uNumPointers++].dword_000008 = 1;
    }
   }
}


//----- (004C1026) --------------------------------------------------------
int __thiscall Vis_sub_4C1026(struct Vis *_this, struct12 *a2, int a3, float a4)
{
  _UNKNOWN *v4; // eax@4
  signed int v5; // ecx@4
  int v6; // ecx@7
  int v7; // edi@7
  int v8; // eax@9
  _UNKNOWN *v9; // edx@9
  int v10; // esi@10
  _UNKNOWN *v11; // eax@13
  int v12; // edx@13
  double v13; // st7@14
  int v14; // ebx@14
  void *v15; // ebx@15
  float v16; // ST04_4@18
  float v17; // ST00_4@19
  int result; // eax@21
  int v19; // ecx@24

  struct Vis_stru0 local_20[2];
  //int v20; // [sp+20h] [bp-70h]@17

  void *v21; // [sp+80h] [bp-10h]@1
  int v22; // [sp+84h] [bp-Ch]@10
  float v23; // [sp+88h] [bp-8h]@16
  float v24; // [sp+8Ch] [bp-4h]@16
  int v25; // [sp+98h] [bp+8h]@7

  v21 = _this;

  class25_F8FE00.uNumPointers = 0;
  if (~byte_F91E08_Is_class25_F8FE00_ctor_called_and_other_dirty_hacks & 2)
  {
    byte_F91E08_Is_class25_F8FE00_ctor_called_and_other_dirty_hacks |= 2;
    v4 = (char *)&array_F8F200[0].flt_00002C;
    v5 = 64;
    do
    {
      *(float *)v4 = 0.0;
      v4 = (char *)v4 + 48;
      --v5;
    }
    while ( v5 );
  }

  v6 = (int)a2;
  v25 = 0;
  v7 = *(_BYTE *)(v6 + 93);
  if ( uCurrentlyLoadedLevelType == 1 )
  {
    if ( v7 > 0 )
    {
      v8 = dword_6BE63C;
      v9 = (char *)&array_F8F200[0].vPosition.y;
      do
      {
        v10 = v25++;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)));
        *((float *)v9 - 1) = (double)v22;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)) + 2);
        *(float *)v9 = (double)v22;
        v9 = (char *)v9 + 48;
        v22 = *(_WORD *)(v8 + 6 * *(_WORD *)(2 * v10 + *(_DWORD *)(v6 + 48)) + 4);
        *((float *)v9 - 11) = (double)v22;
      }
      while ( v25 < v7 );
    }
  }
  else
  {
    if ( v7 > 0 )
    {
      v12 = (int)&pClass51_global->pBModels[((unsigned int)a3 >> 9)] + 72;
      v11 = (char *)&array_F8F200[0].vPosition.y;
      do
      {
        *((float *)v11 - 1) = (double)*(signed int *)(*(_DWORD *)v12 + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v25));
        v13 = (double)*(signed int *)(*(_DWORD *)v12 + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v25) + 4);
        v14 = v25++;
        *(float *)v11 = v13;
        v11 = (char *)v11 + 48;
        *((float *)v11 - 11) = (double)*(signed int *)(*(_DWORD *)v12
                                                     + 12 * *(_WORD *)(*(_DWORD *)(v6 + 48) + 2 * v14)
                                                     + 8);
      }
      while ( v25 < v7 );
    }
  }
  sub_436523((RenderVertex *)array_F8F200, v7);
  class08_sub_436BB7(pGame->class08_obj, (RenderVertex *)array_F8F200, v7, 1);
  v15 = v21;
  Vis_sort_some_objects(_this, array_F8F200, 0, v7 - 1);
  if (array_F8F200[0].flt_00000C > (double)a4)
    return result = 0;

  Vis_sub_4C1495(_this, array_F8F200, v7, &v23, &v24);
  if (sub_4C12C3_FindSomeBillboard(array_F8F200, v7, v23, v24))
    return result = 0;

  if (_this->CastRayAtMousePosition(local_20, pOldCamera, v23, v24, a4), uCurrentlyLoadedLevelType != 1)
  {
   v17 = a4;
   Vis_sub_4C17CF_DoPicking_Outdoor((Vis *)v15, SLOBYTE(v17), local_20, &class25_F8FE00, &stru_F93E44, 1);
  }
  else
  {
   v16 = a4;
   Vis_sub_4C16B4_DoPicking_Indoor((Vis *)v15, SLOBYTE(v16), local_20, &class25_F8FE00, &stru_F93E44);
  }
  class25_create_object_pointers(&class25_F8FE00, 0);
  class25_sort_object_pointers(class25_F8FE00.array_001804, 0, class25_F8FE00.uNumPointers - 1);
  if (!class25_F8FE00.uNumPointers)
    return result = 0;

  result = sub_4C2551((int)&class25_F8FE00, 2, a3);
  if (!result)
    return result = 0;

  if (class25_F8FE00.uNumPointers > 1 && (class25_F8FE00.uNumPointers <= 0 ? (v19 = 0) : (v19 = (int)class25_F8FE00.array_001804), result != v19))
    return result = 0;

  return result;
}


//----- (004C12C3) --------------------------------------------------------
bool __stdcall sub_4C12C3_FindSomeBillboard(struct Vis_stru0 *a1, int a2, float fX, float fY)
{
  double v7; // st7@9
  float v10; // [sp+10h] [bp-8h]@9
  signed int v11; // [sp+14h] [bp-4h]@1
  float v12; // [sp+28h] [bp+10h]@9
  float v13; // [sp+2Ch] [bp+14h]@9
 int i;

  v11 = -1;

 if (!pD3DRenderer->uNumBillboardsToDraw)
   return false;

 for (i = 0; i < pD3DRenderer->uNumBillboardsToDraw; ++i)
   if ( IsPointInsideD3DBillboard(&pBillboardRenderListD3D3[i], fX, fY) )
   {
    if (v11 == -1 ||
        pBillboardRenderList[pBillboardRenderListD3D3[i].uParentBillboardID].sZValue < (unsigned int)pBillboardRenderList[pBillboardRenderListD3D3[v11].uParentBillboardID].sZValue)
      v11 = i;
   }


  if (v11 == -1)
    return false;

  v7 = 3.402823466385289e38;
  LODWORD(v13) = 0x7F7FFFFF;
  v12 = -3.402823466385289e38;
  v10 = -3.402823466385289e38;

  for (i = 0; i < a2; ++i)
  {
      if (a1[i].flt_000018 < v7 )
        v7 = a1[i].flt_000018;

      if (a1[i].flt_000018 > (double)v12 )
        v12 = a1[i].flt_000018;

      if (a1[i].flt_00001C < (double)v13 )
        v13 = a1[i].flt_00001C;

      if (a1[i].flt_00001C > (double)v10 )
        v10 = a1[i].flt_00001C;
  }

 if (v7 < pBillboardRenderListD3D3[v11].pQuad[0].x ||
     pBillboardRenderListD3D3[v11].pQuad[0].y > (double)v13 ||
     pBillboardRenderListD3D3[v11].pQuad[3].x < (double)v12 ||
     pBillboardRenderListD3D3[v11].pQuad[1].y < (double)v10 )
   return false;
 else return true;
}


//----- (004C1495) --------------------------------------------------------
void Vis_sub_4C1495(struct Vis *_this, struct Vis_stru0 *Src, int a3, float *a4, float *a5)
{
 if (~byte_F8E9F8 & 0x01)
 {
  int i;

  byte_F8E9F8 |= 1;
  for (i = 0; i < 64; ++i)
    array_F8DDF8[i].flt_00002C = 0;

  atexit(0);
 }

 memcpy(array_F8DDF8, Src, a3 * sizeof(struct Vis_stru0));

 Vis_sort_some_objects_2(_this, array_F8DDF8, 0, a3 - 1);
 *a4 = (array_F8DDF8[a3 - 1].vPosition.y - array_F8DDF8[0].flt_000018) * 0.5 + array_F8DDF8[0].flt_000018;

 Vis_sort_some_objects_3(_this, array_F8DDF8, 0, a3 - 1);
 *a5 = (array_F8DDF8[a3 - 1].vPosition.z - array_F8DDF8[0].flt_00001C) * 0.5 + array_F8DDF8[0].flt_00001C;
}

//----- (004C1542) --------------------------------------------------------
void Vis_sub_4C1542(struct Vis *_this, float fDepth, float fX, float fY, struct class25 *pClass25, struct unnamed_F93E6C *a6)
{
  int v6; // ST1C_4@6
  int v9; // [sp+24h] [bp-8h]@2

 for (unsigned int i = 0; i < pD3DRenderer->uNumBillboardsToDraw; ++i)
 {
  v9 = (int)&pBillboardRenderListD3D3[i];

  if (Vis_is_part_of_selection(i, a6))
    if (IsPointInsideD3DBillboard(&pBillboardRenderListD3D3[i], fX, fY))
      if (Vis_IsRayIntersectsSprite(_this, fDepth, i))
      {
       v6 = pBillboardRenderList[pBillboardRenderListD3D3[i].uParentBillboardID].sZValue;


       pClass25->array_000004[pClass25->uNumPointers].uBillboardID = pBillboardRenderListD3D3[i].uParentBillboardID;
       pClass25->array_000004[pClass25->uNumPointers].sZValue = v6;
       pClass25->array_000004[pClass25->uNumPointers++].dword_000008 = 1;
      }
 }
}


//----- (004C1930) --------------------------------------------------------
char __thiscall Vis_sub_4C1930(Vis *_this, float a2, int a3)
{
  return Vis_IsRayIntersectsSprite(_this, a2, a3);
}

void loc_4C19F7()
{
}
//----- (004C1944) --------------------------------------------------------
struct class25_stru0 *Vis_sub_4C1944(Vis *_this, int a2, unsigned int a3, int a4, int a5, int a6)
{
  //float v6; // ST00_4@3
  //signed int result; // eax@4

  struct unnamed_F93E6C local_18;
  //int v8; // [sp+18h] [bp-20h]@3
  //int v9; // [sp+1Ch] [bp-1Ch]@3
  //int v10; // [sp+20h] [bp-18h]@3
  //int v11; // [sp+24h] [bp-14h]@3
  //int v12; // [sp+28h] [bp-10h]@3
  __int64 v13; // [sp+2Ch] [bp-Ch]@3

  //void *v14; // [sp+34h] [bp-4h]@1


 local_18.dword_000000 = 1;
 local_18.dword_000004 = a2;
 local_18.dword_000008 = a6;
 local_18.dword_00000C = a5;
 local_18.dword_000010 = a4;
 v13 = a3;
  
 class25_F8BDE8.uNumPointers = 0;
 Vis_sub_4C06F8(_this, a3, &class25_F8BDE8, &local_18);

 class25_create_object_pointers(&class25_F8BDE8, 1);
 class25_sort_object_pointers(class25_F8BDE8.array_001804, 0, class25_F8BDE8.uNumPointers - 1);

 if (!class25_F8BDE8.uNumPointers)
   return 0;
 else
   return class25_F8BDE8.array_001804[1];
}

//----- (004C1A02) --------------------------------------------------------
void Vis_sub_4C1A02(struct Vis *_this)
{
 struct Vis_stru0 local_08;
  //float v4; // [sp+8h] [bp-C0h]@1
  //float v5;
  //float v6;
  //int _14[8];
  //float v7;

 struct Vis_stru0 local_38;
  //float v4; // [sp+38h] [bp-90h]@1
  //float v5;
  //float v6;
  //int _14[8];
  //float v7;

 struct Vis_stru0 local_68;
  //float v4; // [sp+68h] [bp-60h]@1
  //float v5; // [sp+6Ch] [bp-5Ch]@1
  //float v6; // [sp+70h] [bp-58h]@1
  //int _14[8];
  //float v7; // [sp+94h] [bp-34h]@1

 struct Vis_stru0 local_98;
  //float v4; // [sp+98h] [bp-30h]@1
  //float v5; // [sp+9Ch] [bp-2Ch]@1
  //float v6; // [sp+A0h] [bp-28h]@1
  //int _14[8];
  //float v7; // [sp+C4h] [bp-4h]@1

 local_68.vPosition = Vec3<float>(65536.0f, 0.0f, 0.0f);
 local_68.flt_00002C = 0.0f;
 //memcpy(&local0_08[0], &local0_68, 0x30u);
  
 local_98.vPosition = Vec3<float>(0.0f, 65536.0f, 0.0f);
 local_98.flt_00002C = 0.0f;
 //memcpy(&local0_08[1], &local0_98, 0x30u);

 //memcpy(_this->flt_00200C, &local0_08, 0x60u);
 memcpy(&_this->struct_00200C, &local_68, sizeof(struct Vis_stru0));
 memcpy(&_this->struct_00203C, &local_98, sizeof(struct Vis_stru0));



 local_98.vPosition = Vec3<float>(65536.0f, 0.0f, 0.0f);
 local_98.flt_00002C = 0.0f;
 //memcpy(&local0_08[0], &local0_98, 0x30u);

 local_68.vPosition = Vec3<float>(0.0f, 65536.0f, 0.0f);
 local_68.flt_00002C = 0.0f;
 //memcpy(&local0_08[1], &local0_68, 0x30u);

 //memcpy(_this->flt_00206C, &local0_08, 0x60u);
 memcpy(&_this->struct_00206C, &local_98, sizeof(struct Vis_stru0));
 memcpy(&_this->struct_00209C, &local_68, sizeof(struct Vis_stru0));
}

//----- (004C1ABA) --------------------------------------------------------
bool Vis_sort_some_objects(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight)
{
 struct Vis_stru0 *v4; // edx@2
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8

  struct Vis_stru0 local_04;
  //char v11; // [sp+4h] [bp-6Ch]@8

  struct Vis_stru0 local_34;
  //char v12; // [sp+34h] [bp-3Ch]@2
  //float v13; // [sp+40h] [bp-30h]@4

  int v14; // [sp+64h] [bp-Ch]@7
  void *v15; // [sp+68h] [bp-8h]@1
  const void *v16; // [sp+6Ch] [bp-4h]@2

  v15 = _this;
  if (sRight <= sLeft)
    return true;

    v4 = pArray;
    v16 = &pArray[sRight];
    v6 = sLeft - 1;
    memcpy(&local_34, &pArray[sRight], sizeof(struct Vis_stru0));

    for ( i = sRight; ; i = v14 )
    {
      v7 = (int)&v4[v6].flt_00000C;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < local_34.flt_00000C);

      v8 = (int)&v4[i].flt_00000C;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > local_34.flt_00000C);
      v14 = i;
      if ( v6 >= i )
        break;

      v9 = &v4[i];
      memcpy(&local_04, &pArray[v6], sizeof(struct Vis_stru0));
      v4 = pArray;
      memcpy(&pArray[v6], v9, sizeof(struct Vis_stru0));
      memcpy((void *)v9, &local_04, sizeof(struct Vis_stru0));
    }

    memcpy(&local_04, &v4[v6], sizeof(struct Vis_stru0));
    memcpy(&v4[v6], v16, sizeof(struct Vis_stru0));
    memcpy((void *)v16, &local_04, sizeof(struct Vis_stru0));
    Vis_sort_some_objects(_this, v4, sLeft, v6 - 1);
    Vis_sort_some_objects(_this, pArray, v6 + 1, sRight);

  return true;
}

//----- (004C1BAA) --------------------------------------------------------
signed int __thiscall sub_4C1BAA_Vis_get_object_zbuf_val(struct Vis *_this, struct class25_stru0 *a2)
{
  signed int v2; // eax@1
  signed int result; // eax@3
  char v4; // [sp-18h] [bp-1Ch]@4
  int v5; // [sp-14h] [bp-18h]@4
  int v6; // [sp-10h] [bp-14h]@4
  int v7; // [sp-Ch] [bp-10h]@4
  char *v11; // [sp+Ch] [bp+8h]@4

  v2 = a2->dword_000008;
  if ( v2 <= 0 || v2 > 2 )
  {
    v11 = &v4;
    Game_sub_40E2C8(&v4, "Undefined type requested for: CVis::get_object_zbuf_val()", (int)((char *)&a2 + 3));
    sub_466D09(0, *(int *)&v4, v5, v6, v7, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp", __LINE__);
    result = -1;
  }
  else
    result = a2->sZValue;

  return result;
}

//----- (004C1BF1) --------------------------------------------------------
signed int __thiscall Vis_sub_4C1BF1_LooksLikeFindTopmostZObject(struct Vis *_this)
{
 if (!_this->class25_obj.uNumPointers)
   return -1;
 else
   return sub_4C1BAA_Vis_get_object_zbuf_val(_this, _this->class25_obj.array_001804[0]);
}


//----- (004C248E) --------------------------------------------------------
Result::Code Vis::CastRayAtMousePosition(struct Vis_stru0 *a1, OldCamera *pCamera, float fMouseX, float fMouseY, float fDepth)
{
  //int v7; // esi@1
  //int v9; // ST04_4@1
  //int v10; // eax@1
  
  struct Vis_stru0 local_2C;
  //float v11; // [sp+2Ch] [bp-74h]@1
  //float v12; // [sp+30h] [bp-70h]@1
  //float v13; // [sp+34h] [bp-6Ch]@1
  //float v14; // [sp+58h] [bp-48h]@1

  struct Vis_stru0 local_5C;
  //float v15; // [sp+5Ch] 000000
  //float v16; // [sp+60h] 000004
  //float v17; // [sp+64h] 000008
  //float v18; // [sp+88h] 00002C

  //int v19; // [sp+8Ch] [bp-14h]@1
  //int v20; // [sp+90h] [bp-10h]@1
  //int v21; // [sp+94h] [bp-Ch]@1
  //int v22; // [sp+98h] [bp-8h]@1
  //int v23; // [sp+9Ch] [bp-4h]@1
  //int v24;
  Vec3<int> v24;

 RotateVector(sub_48B561(fDepth),
              pOldCamera->sRotationY + sub_46A0A1(fMouseX), pOldCamera->sRotationX + sub_46A0F6(fMouseY),
              //pOldCamera->sPosX, pOldCamera->sPosY, pOldCamera->sPosZ,
              Vec3<int>(pOldCamera->sPosX, pOldCamera->sPosY, pOldCamera->sPosZ),
              &v24);//&v24, &v22, &v21);
 
 local_2C.vPosition = v24;
 local_2C.flt_00002C = 0.0;

 local_5C.vPosition = Vec3<float>((float)pOldCamera->sPosX, (float)pOldCamera->sPosY, (float)pOldCamera->sPosZ);
 local_5C.flt_00002C = 0.0;

 memcpy(&a1[0], &local_5C, sizeof(struct Vis_stru0));
 memcpy(&a1[1], &local_2C, sizeof(struct Vis_stru0));

 return Result::Success;
}



//----- (004C288E) --------------------------------------------------------
bool Vis_sort_some_objects_2(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight)
{
 struct Vis_stru0 *v4;
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8

  struct Vis_stru0 local_04;
  //char v11; // [sp+4h] [bp-6Ch]@8

  struct Vis_stru0 local_34;
  //char v12; // [sp+34h] [bp-3Ch]@2
  //float v13; // [sp+4Ch] [bp-24h]@4

  int v14; // [sp+64h] [bp-Ch]@7
  void *v15; // [sp+68h] [bp-8h]@1
  const void *v16; // [sp+6Ch] [bp-4h]@2

  v15 = _this;
  if (sRight <= sLeft)
    return true;


    v4 = pArray;
    v16 = &pArray[sRight];
    v6 = sLeft - 1;
    memcpy(&local_34, &pArray[sRight], sizeof(struct Vis_stru0));

    for ( i = sRight; ; i = v14 )
    {
      v7 = (int)&v4[v6].flt_000018;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < local_34.flt_000018);

      v8 = (int)&v4[i].flt_000018;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > local_34.flt_000018);

      v14 = i;
      if ( v6 >= i )
        break;
      v9 = &v4[i];
      memcpy(&local_04, &pArray[v6], sizeof(struct Vis_stru0));
      v4 = pArray;
      memcpy(&pArray[v6], v9, sizeof(struct Vis_stru0));
      memcpy((void *)v9, &local_04, sizeof(struct Vis_stru0));
    }

    memcpy(&local_04, &v4[v6], sizeof(struct Vis_stru0));
    memcpy(&v4[v6], v16, sizeof(struct Vis_stru0));
    memcpy((void *)v16, &local_04, sizeof(struct Vis_stru0));
    Vis_sort_some_objects_2(_this, v4, sLeft, v6 - 1);
    Vis_sort_some_objects_2(_this, pArray, v6 + 1, sRight);

 return true;
}

//----- (004C297E) --------------------------------------------------------
bool Vis_sort_some_objects_3(struct Vis *_this, struct Vis_stru0 *pArray, int sLeft, int sRight)
{
 struct Vis_stru0 *v4;
  int i; // ecx@2
  int v6; // ebx@2
  int v7; // esi@3
  int v8; // esi@5
  const void *v9; // eax@8

  struct Vis_stru0 local_04;
  //char v11; // [sp+4h] [bp-6Ch]@8

  struct Vis_stru0 local_34;
  //char v12; // [sp+34h] [bp-3Ch]@2
  //float v13; // [sp+50h] [bp-20h]@4

  int v14; // [sp+64h] [bp-Ch]@7
  const void *v16; // [sp+6Ch] [bp-4h]@2

 if (sRight <= sLeft)
   return true;


    v4 = pArray;
    v16 = &pArray[sRight];
    v6 = sLeft - 1;
    memcpy(&local_34, &pArray[sRight], sizeof(struct Vis_stru0));

    for ( i = sRight; ; i = v14 )
    {
      v7 = (int)&v4[v6].flt_00001C;
      do
      {
        v7 += 48;
        ++v6;
      }
      while ( *(float *)v7 < local_34.flt_00001C);

      v8 = (int)&v4[v6].flt_00001C;
      do
      {
        v8 -= 48;
        --i;
      }
      while ( *(float *)v8 > local_34.flt_00001C);

      v14 = i;
      if ( v6 >= i )
        break;
      v9 = &v4[i];
      memcpy(&local_04, &pArray[v6], sizeof(struct Vis_stru0));
      v4 = pArray;
      memcpy(&pArray[v6], v9, sizeof(struct Vis_stru0));
      memcpy((void *)v9, &local_04, sizeof(struct Vis_stru0));
    }

    memcpy(&local_04, &v4[v6], sizeof(struct Vis_stru0));
    memcpy(&v4[v6], v16, sizeof(struct Vis_stru0));
    memcpy((void *)v16, &local_04, sizeof(struct Vis_stru0));

    Vis_sort_some_objects_3(_this, v4, sLeft, v6 - 1);
    Vis_sort_some_objects_3(_this, pArray, v6 + 1, sRight);

 return true;
}

//----- (004C0791) --------------------------------------------------------
bool Vis_is_part_of_selection(unsigned int uD3DBillboardID, struct unnamed_F93E6C *a2)
{
  int v2; // esi@1
  int v3; // eax@2
  int v4; // edx@2
  int v5; // ecx@2
  int v7; // esi@5
  void *v8; // ecx@7
  signed int v10; // eax@10
  signed int v12; // eax@18
  int v13; // edi@18
  char v14; // zf@26
  int v15; // eax@26
  int v17; // [sp-1Ch] [bp-28h]@7
  char v18; // [sp-18h] [bp-24h]@7
  int v19; // [sp-14h] [bp-20h]@15
  int v20; // [sp-10h] [bp-1Ch]@15
  int v21; // [sp-Ch] [bp-18h]@15
  char *v24; // [sp+14h] [bp+8h]@7
  char *v25; // [sp+14h] [bp+8h]@14

  v2 = (int)a2;
 if (a2->dword_000000 != 1 )
 {
  if (a2->dword_000000 != 2)
    return true;

  if (uCurrentlyLoadedLevelType != 1)
  {
    v14 = *(_WORD *)(uD3DBillboardID + 292) == 0;
    v15 = *(_DWORD *)(uD3DBillboardID + 28);
  }
  else
  {
   v14 = *(_WORD *)(dword_6BE64C + 36 * *(_WORD *)(uD3DBillboardID + 72) + 26) == 0;
   v15 = *(_DWORD *)(uD3DBillboardID + 44);
  }

  if (a2->dword_000004 != 1)
      return true;

    if ( v14 || v15 & a2->dword_00000C)
      return false;

    if ((v15 & a2->dword_000008) == 0)
      return false;
    return true;
  }

  v4 = a2->dword_000010;
  v3 = (pBillboardRenderList[pBillboardRenderListD3D3[uD3DBillboardID].uParentBillboardID].sZValue & 0xFFFF) >> 3;
  v5 = pBillboardRenderList[pBillboardRenderListD3D3[uD3DBillboardID].uParentBillboardID].sZValue & 7;
  if ( v4 & 2 )
  {
    if (v5 == a2->dword_000004)
      return false;
    return true;
  }

  if ( v4 & 4 )
  {
    v7 = a2->dword_000004;
    if ( v5 != v7 )
      return true;

    if ( v7 != 5 )
    {
      v8 = &v18;
      v24 = &v18;
      v17 = (int)((char *)&uD3DBillboardID + 3);
      Game_sub_40E2C8(v8, "Unsupported \"exclusion if no event\" type in CVis::is_part_of_selection", v17);
      sub_466D09(&a2, *(int *)&v18, v19, v20, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp", __LINE__);
      return true;
    }

    if ( pLevelDecorations[v3].word_000014 || pLevelDecorations[v3].word_000016)
      return true;
    v10 = sub_44C2F4_SomeDecorationTypeCheck(&pLevelDecorations[v3]);

    if ( v10 == 0 )
      return false;
    return true;
  }




  if (v5 == a2->dword_000004)
  {
    if ( v5 != 3 )
    {
      v8 = &v18;
      v25 = &v18;
      v17 = (int)((char *)&uD3DBillboardID + 3);
      Game_sub_40E2C8(v8, "Default case reached in VIS", v17);
      sub_466D09(&a2, *(int *)&v18, v19, v20, v21, "E:\\WORK\\MSDEV\\MM7\\MM7\\Code\\Vis.cpp", __LINE__);
      return true;
    }
    v13 = (int)&pActors[v3];
    v12 = 1 << *(_BYTE *)(v13 + 176);
    if ( v12 & a2->dword_00000C || !(v12 & a2->dword_000008) || v4 & 8 && !sub_438BDF(*(_WORD *)(v13 + 96), 1) )
      return false;
    if ( !(*(_BYTE *)(v2 + 16) & 1) )
      return true;
    v10 = Actor_GetActorsRelation((Actor *)v13, 0);

    if ( v10 == 0 )
      return false;
    return true;
  }
  return false;
}

void loc_4C0D27()
{
}
//----- (004C091D) --------------------------------------------------------
bool Vis_IsRayIntersectsSprite(struct Vis *_this, float fDepth, int a3)
{
  int v3; // eax@3
  //signed int v5; // ecx@4
  //float v6; // ST04_4@6
  //float v7; // ST00_4@7
  int v8; // eax@10
  unsigned int v9; // eax@12
  int v10; // eax@17
  double v11; // st6@18
  double v12; // st7@18
  double v13; // st4@18
  float v14; // ST0C_4@22
  float v15; // ST08_4@22
  //float v16; // ST04_4@23
  //float v17; // ST00_4@24
  signed int v18; // eax@27
  unsigned int v19; // eax@29
  double v20; // st6@32
  double v21; // st7@32
  int v22; // eax@32
  double v23; // st7@36
  //void *v24; // esi@40
  float v25; // ST08_4@40
  //float v26; // ST04_4@41
  //float v27; // ST00_4@42
  int v28; // eax@45
  unsigned int v29; // eax@47
  char result; // al@48

  struct Vis_stru0 pPickingRay[2];
  //int v31; // [sp+20h] [bp-DCh]@5

  struct Vis_stru0 local_80[2];
  //int v32; // [sp+80h] [bp-7Ch]@22

  float v33; // [sp+E0h] [bp-1Ch]@33
  float v34; // [sp+E4h] [bp-18h]@32
  int v35; // [sp+E8h] [bp-14h]@5
  int v36; // [sp+ECh] [bp-10h]@5
  unsigned int v37; // [sp+F0h] [bp-Ch]@5
  float v38; // [sp+F4h] [bp-8h]@17
  //void *v39; // [sp+F8h] [bp-4h]@1
  signed int v40; // [sp+108h] [bp+Ch]@17
  float v41; // [sp+108h] [bp+Ch]@32


  class25_F91E10.uNumPointers = 0;

  v3 = pBillboardRenderListD3D3[a3].uParentBillboardID;
  if (v3 == -1)
    return false;

  if (pBillboardRenderList[v3].GetFloatZ() > fDepth)
  {
LABEL_49:
    return false;
  }
  else
  {
    v37 = pBillboardRenderList[v3].sZValue & 0xFFFF0000;
    GetD3DBillboardCenter(pBillboardRenderListD3D3[a3].pQuad, 4, (float *)&v35, (float *)&v36);
    _this->CastRayAtMousePosition(pPickingRay, pOldCamera, *(float *)&v35, *(float *)&v36, fDepth);

    if (uCurrentlyLoadedLevelType == 1)
      Vis_sub_4C16B4_DoPicking_Indoor(_this, fDepth, pPickingRay, &class25_F91E10, &stru_F93E44);
    else
      Vis_sub_4C17CF_DoPicking_Outdoor(_this, fDepth, pPickingRay, &class25_F91E10, &stru_F93E44, 0);

    class25_create_object_pointers(&class25_F91E10, 0);
    class25_sort_object_pointers(class25_F91E10.array_001804, 0, class25_F91E10.uNumPointers - 1);

    if (class25_F91E10.uNumPointers)
    {
     if (class25_F91E10.uNumPointers <= 0)
       v8 = 0;
     else v8 = (int)class25_F91E10.array_001804;

     v9 = *(_DWORD *)(v8 + 4);

     LOWORD(v9) = 0;

     if (v9 > v37)
       return 1;
    }
    else if ((double)(pOldViewport->uScreenX) <= *(float *)&v35 &&
             (double)pOldViewport->uScreenZ >= *(float *)&v35 &&
             (double)pOldViewport->uScreenY <= *(float *)&v36 &&
             (double)pOldViewport->uScreenW >= *(float *)&v36)
      return 1;

      v40 = 0;
      v10 = (int)&pBillboardRenderListD3D3[a3].pQuad[0].y;
      LODWORD(v38) = (int)&pBillboardRenderListD3D3[a3].pQuad[0].y;
      while ( 1 )
      {
        v12 = *(float *)(v10 - 4);
        v11 = *(float *)v10;
        v13 = *(float *)(v10 - 4);

        class25_F91E10.uNumPointers = 0;
        if ( v13 >= (double)(pOldViewport->uScreenX))
        {
          if ( v12 <= (double)pOldViewport->uScreenZ )
          {
            if ( v11 >= (double)pOldViewport->uScreenY )
            {
              if ( v11 <= (double)pOldViewport->uScreenW )
              {
                v14 = v11;
                v15 = v12;
                _this->CastRayAtMousePosition(local_80, pOldCamera, SLODWORD(v15), v14, fDepth);

                if ( uCurrentlyLoadedLevelType == 1 )
                  Vis_sub_4C16B4_DoPicking_Indoor(_this, fDepth, local_80, &class25_F91E10, &stru_F93E44);
                else
                  Vis_sub_4C17CF_DoPicking_Outdoor(_this, fDepth, local_80, &class25_F91E10, &stru_F93E44, 0);

                class25_create_object_pointers(&class25_F91E10, 0);
                class25_sort_object_pointers(class25_F91E10.array_001804, 0, class25_F91E10.uNumPointers - 1);
                if ( !class25_F91E10.uNumPointers )
                  break;
                v18 = class25_F91E10.uNumPointers <= 0 ? 0 : (int)class25_F91E10.array_001804;
                v19 = *(_DWORD *)(v18 + 4);
                LOWORD(v19) = 0;
                if ( v19 > v37 )
                  break;
              }
            }
          }
        }
        ++v40;
        v10 = LODWORD(v38) + 32;
        LODWORD(v38) += 32;
        if ( v40 >= 4 )
        {
          if ( uCurrentlyLoadedLevelType != 2 )
            return false;
          v21 = pBillboardRenderListD3D3[a3].pQuad[0].x;
          v20 = pBillboardRenderListD3D3[a3].pQuad[3].x;
          v22 = *(int *)(&pBillboardRenderListD3D3[a3].pQuad[0].y);
          v34 = pBillboardRenderListD3D3[a3].pQuad[3].x;
          LODWORD(v38) = v22;
          v41 = pBillboardRenderListD3D3[a3].pQuad[1].y;
          if ( v21 > v20 )
          {
            v33 = v21;
            v21 = v34;
            v20 = v33;
          }
          if ( v38 > (double)v41 )
            v41 = v38;

          class25_F91E10.uNumPointers = 0;
          v23 = (v20 - v21) * 0.5;
          if ( v23 < (double)(pOldViewport->uScreenX)
            || v23 > (double)pOldViewport->uScreenZ
            || (double)pOldViewport->uScreenY > v41
            || (double)pOldViewport->uScreenW < v41
            || ((v25 = v23, _this->CastRayAtMousePosition(local_80, pOldCamera, SLODWORD(v25), v41, fDepth), uCurrentlyLoadedLevelType != 1) ? (Vis_sub_4C17CF_DoPicking_Outdoor(_this, fDepth, local_80, &class25_F91E10, &stru_F93E44, 0)) : (Vis_sub_4C16B4_DoPicking_Indoor(_this, fDepth, local_80, &class25_F91E10, &stru_F93E44)),
                (class25_create_object_pointers(&class25_F91E10, 0),
                 class25_sort_object_pointers(class25_F91E10.array_001804, 0, class25_F91E10.uNumPointers - 1),
                 class25_F91E10.uNumPointers)
             && (class25_F91E10.uNumPointers <= 0 ? (v28 = 0) : (v28 = (int)class25_F91E10.array_001804),
                 v29 = *(_DWORD *)(v28 + 4),
                 LOWORD(v29) = 0,
                 v29 <= v37)) )
            return false;
          break;
        }
      }

    result = 1;
  }
  return result;
}

//----- (004C0D32) --------------------------------------------------------
int Vis_sub_4C0D32_DoSomeOtherPicking_Indoor(Vis *_this, float a2, class25 *a3, struct unnamed_F93E6C *a4)
{
  int result; // eax@1
  int v5; // esi@2
  int v6; // edi@4
  int v7; // eax@6
  int v8; // eax@6
  int v9; // ST18_4@7
  int v10; // ST1C_4@7
  int v11; // ecx@7
  unsigned __int8 v12; // sf@8
  unsigned __int8 v13; // of@8
  int v14; // [sp+18h] [bp-8h]@1
  void *v15; // [sp+1Ch] [bp-4h]@1

  result = 0;
  v15 = _this;
  v14 = 0;
  if (class37_global0.dword_000000 > 0)
  {
    do
    {
      v5 = word_51B77C[2 * result];
      if ( v5 >= 0 )
      {
        if ( v5 < dword_6BE640 )
        {
          v6 = (int)(ptr_6BE644 + v5);
          if ( !sub_436455(ptr_6BE644 + v5) )
          {
            if ( Vis_is_part_of_selection(v6, a4) )
            {
              v8 = 8 * v5;
              LOBYTE(v8) = 8 * v5 | 6;
              v7 = Vis_sub_4C1026(_this, (struct12 *)v6, v8, a2);
              if ( v7 )
              {
                v9 = *(_DWORD *)(v7 + 4);
                v10 = *(_DWORD *)(v7 + 8);
                v11 = 3 * *(_DWORD *)(a3 + 8196);
                *(_DWORD *)(a3 + 12 * *(_DWORD *)(a3 + 8196) + 4) = *(_DWORD *)v7;
                *(_DWORD *)(a3 + 4 * v11 + 8) = v9;
                *(_DWORD *)(a3 + 4 * v11 + 12) = v10;
                ++*(_DWORD *)(a3 + 8196);
              }
            }
          }
        }
      }
      result = v14 + 1;
      compile_error();//v13 = __SETO__(v14 + 1, class37_global0.dword_000000);
      v12 = v14++ + 1 - class37_global0.dword_000000 < 0;
    }
    while ( v12 ^ v13 );
  }
  return result;
}

//----- (004C0DEA) --------------------------------------------------------
void __thiscall Vis_sub_4C0DEA_DoSomeOtherPicking_Outdoor(struct Vis *_this, float a2, class25 *a3, struct unnamed_F93E6C *a4)
{
  int v7; // eax@3
  int v12; // eax@8
  int v13; // eax@8
  int v14; // ecx@9

  struct struct12 local_10;
  //int v15[0x60/4]; // [sp+10h] [bp-84h]@1

  int v16; // [sp+70h] [bp-24h]@9
  int v17; // [sp+74h] [bp-20h]@9
  int v18; // [sp+78h] [bp-1Ch]@9
  int v19; // [sp+7Ch] [bp-18h]@1
  int v21; // [sp+84h] [bp-10h]@6
  int v23; // [sp+8Ch] [bp-8h]@5

  v19 = 0;

  v7 = 0;
 for (unsigned int i = 0; i < pClass51_global->uNumBModels; ++i)
 {
  BSPModel *pModel = &pClass51_global->pBModels[i];
      LOBYTE(v7) = sub_479089(i, &v19);
      if (v7)
      {
        if (v19)
        {
          v23 = 0;
          if (pClass51_global->pBModels[i].uNumFaces > 0)
          {
            v21 = 0;
            do
            {
             BSPModel::Face *pFace = pModel->pFaces + (v21 / 308);
              if ( Vis_is_part_of_selection((unsigned int)pFace, a4) )
              {
                sub_4C0EF2_BSPModel_Face_To_struct12(&local_10, pFace);
                v13 = 8 * (v23 | (i << 6));
                LOBYTE(v13) = v13 | 6;
                v12 = Vis_sub_4C1026(_this, &local_10, v13, a2);
                if ( v12 )
                {
                  v16 = *(_DWORD *)v12;
                  v17 = *(_DWORD *)(v12 + 4);
                  v14 = *(_DWORD *)(a3 + 8196);
                  v18 = *(_DWORD *)(v12 + 8);
                  v14 *= 3;
                  *(_DWORD *)(a3 + 4 * v14 + 4) = v16;
                  *(_DWORD *)(a3 + 4 * v14 + 8) = v17;
                  *(_DWORD *)(a3 + 4 * v14 + 12) = v18;
                  ++*(_DWORD *)(a3 + 8196);
                }
              }
              ++v23;
              v21 += 308;
            }
            while ( v23 < pModel->uNumFaces);
          }
        }
      }
  }
}







//----- (MM7.exe::004C055C) --------------------------------------------------------
class25::class25()
{
 for (unsigned int i = 0; i < 512; ++i)
 {
  array_000004[i].uBillboardID = -1;
  array_000004[i].sZValue = -1;
  array_000004[i].dword_000008 = 0;

  array_001804[i] = nullptr;
 }

 uNumPointers = 0;
}



//----- (004C1C0C) --------------------------------------------------------
char __stdcall sub_4C1C0C(Vis_stru0 *pRayOrigin, Vis_stru0 *pRayEnd, float *pDepth, RenderVertex *pRay_SomePoint, struct12 *a5, int a6)
{
  int v6; // eax@1
  double v8; // st7@3
  double v9; // st5@6
  double v10; // st6@10
  signed int v12; // ST1E_4@11
  float v15; // [sp+30h] [bp+18h]@10

  v6 = a5->uFaceAttributes;
  if (v6 & 0x0001 ||
      v6 & 0x2000)
    return 0;

  v8 = pRayEnd->vPosition.x * a5->pFaceNormalf[0] +
       pRayEnd->vPosition.y * a5->pFaceNormalf[1] +
       pRayEnd->vPosition.z * a5->pFaceNormalf[2];
  if (v8 >= 0.0)
    return 0;

  v9 = -(pRayOrigin->vPosition.x * a5->pFaceNormalf[0] +
         pRayOrigin->vPosition.y * a5->pFaceNormalf[1] +
         pRayOrigin->vPosition.z * a5->pFaceNormalf[2] +
         a5->fNormalDistance);

  if ( v8 <= 0.0 )
  {
    if ( v9 > 0.0 )
      return 0;
  }
  else
  {
    if ( v9 < 0.0 )
      return 0;
  }
  v10 = v9 / v8;
  v15 = v10;
  if (v10 > *pDepth)
    return 0;

 pRay_SomePoint->x = v10 * pRayEnd->vPosition.x + pRayOrigin->vPosition.x;
 pRay_SomePoint->y = v10 * pRayEnd->vPosition.y + pRayOrigin->vPosition.y;
 pRay_SomePoint->z = v10 * pRayEnd->vPosition.z + pRayOrigin->vPosition.z;
 
 LOWORD(v12) = (signed __int64)pRay_SomePoint->x;
 HIWORD(v12) = (signed __int64)pRay_SomePoint->y;
 //if (!sub_4C1D2B(a5, v12, pRay_SomePoint->z, a6))
 if (!sub_4C1D2B(a5, Vec3<short>(pRay_SomePoint->x, pRay_SomePoint->y, pRay_SomePoint->z), a6))
   return 0;

 *pDepth = v15;
 return 1;
}



//----- (0043AA99) --------------------------------------------------------
void RotateVector(int sDepth, int sRotationY, int sRotationX, Vec3<int> vPosition, Vec3<int> *pOut)
{
 //int cos_z = class59_SinCos(pClass59_global, sRotationX),
 //    cos_y = class59_SinCos(pClass59_global, sRotationY),
 //    sin_y = class59_SinCos(pClass59_global, sRotationY - pClass59_global->uIntegerHalfPi),
 //    sin_z = class59_SinCos(pClass59_global, sRotationX - pClass59_global->uIntegerHalfPi);
 float cosf_x = cosf(3.14159265f * sRotationX / 2048.0f),
       cosf_y = cosf(3.14159265f * sRotationY / 2048.0f),
       sinf_x = sinf(3.14159265f * sRotationX / 2048.0f),
       sinf_y = sinf(3.14159265f * sRotationY / 2048.0f);

 pOut->x = vPosition.x + ((unsigned __int64)((double)sDepth * cosf_y * cosf_x) >> 16);
 pOut->y = vPosition.y + ((unsigned __int64)((double)sDepth * sinf_y * cosf_x) >> 16);
 pOut->z = vPosition.z + ((unsigned __int64)((double)sDepth * sinf_x) >> 16);
}



//----- (004C16B4) --------------------------------------------------------
int Vis_sub_4C16B4_DoPicking_Indoor(Vis *_this, float a2, Vis_stru0 *pRay, class25 *a4, struct unnamed_F93E6C *a5)
{
  int result; // eax@1
  int v6; // edi@2
  int v7; // esi@4
  int v8; // eax@7
  //int v9; // eax@7
  //int v10; // ecx@7
  //int v11; // edi@7
  unsigned __int8 v12; // sf@8
  unsigned __int8 v13; // of@8
  RenderVertex local_0C;
  //char v14; // [sp+Ch] [bp-44h]@6
  //float v15; // [sp+18h] [bp-38h]@7
  //float v16; // [sp+38h] [bp-18h]@1
  int v17; // [sp+3Ch] [bp-14h]@7
  int v18; // [sp+40h] [bp-10h]@7
  int v20; // [sp+48h] [bp-8h]@1
  void *v21; // [sp+4Ch] [bp-4h]@1

  result = 0;
  v21 = _this;
  v20 = 0;
  local_0C.flt_00002C = 0.0;
  if (class37_global0.dword_000000 > 0 )
  {
    do
    {
      v6 = word_51B77C[2 * result];
      if ( v6 >= 0 )
      {
        if ( v6 < dword_6BE640 )
        {
          v7 = 96 * v6;
          if ( Vis_is_part_of_selection((unsigned int)(v6 + ptr_6BE644), a5) )
          {
            if ( !sub_436455(v7/96 + ptr_6BE644) )
            {
              if ( sub_4C1C0C(pRay, pRay + 1, &a2, &local_0C, v7/96 + ptr_6BE644, -1) )
              {
                sub_436523(&local_0C, 1);
                v8 = sub_48B561(local_0C.flt_00000C);
                LOWORD(v8) = 0;
                v18 = (8 * v6 | 6) + v8;
                v17 = (int)(ptr_6BE644 + v7/96);

                a4->array_000004[a4->uNumPointers].uBillboardID = (unsigned int)(ptr_6BE644 + v7/96);
                a4->array_000004[a4->uNumPointers].sZValue = v18;
                a4->array_000004[a4->uNumPointers++].dword_000008 = 2;
              }
            }
          }
        }
      }
      result = v20 + 1;
      compile_error();//v13 = __SETO__(v20 + 1, class37_global0.dword_000000);
      v12 = v20++ + 1 - class37_global0.dword_000000 < 0;
    }
    while ( v12 ^ v13 );
  }
  return result;
}



//----- (004C17CF) --------------------------------------------------------
char Vis_sub_4C17CF_DoPicking_Outdoor(Vis *_this, float a2, Vis_stru0 *pRay, class25 *a4, struct unnamed_F93E6C *a5, bool a6)
{
  int v6; // eax@1
  int v7; // ecx@1
  //int v8; // esi@1
  //int v9; // ebx@3
  //int v10; // esi@10
  int v11; // eax@12
  //int v12; // eax@12
  //int v13; // edi@12

  struct struct12 local_10;
  //char v17[0x60]; // [sp+10h] [bp-B8h]@1

  RenderVertex cRay_SomePoint;
  //char v18; // [sp+70h] [bp-58h]@11
  //float v19; // [sp+7Ch] [bp-4Ch]@12
  //float v20; // [sp+9Ch] [bp-2Ch]@1

  //int v21; // [sp+A0h] [bp-28h]@12
  int v22; // [sp+A4h] [bp-24h]@12
  //int v23; // [sp+A8h] [bp-20h]@12
  int v24; // [sp+ACh] [bp-1Ch]@8
  void *v25; // [sp+B0h] [bp-18h]@1
  //int v26; // [sp+B4h] [bp-14h]@9
  int v27; // [sp+B8h] [bp-10h]@1
  int v28; // [sp+BCh] [bp-Ch]@2
  int v29; // [sp+C0h] [bp-8h]@1
  int v30; // [sp+C4h] [bp-4h]@8
 int i;

  v25 = _this;
  v7 = 0;
  v27 = 0;
  v29 = 0;

  cRay_SomePoint.flt_00002C = 0.0;

  i = 0;
  if ( pClass51_global->uNumBModels > 0 )
  {
    v28 = 0;
    BSPModel *pBModel;
    while ( 1 )
    {
      pBModel = &pClass51_global->pBModels[i];
      LOBYTE(v6) = sub_479089(v7, &v27);
      if ( a6 )
        break;
      if ( v6 )
        goto LABEL_8;
LABEL_15:
      v28 += 188;
      v7 = v29 + 1;
      ++i;
      //v15 = __SETO__(v29 + 1, pClass51_global->uNumBModels);
      //v14 = v29++ + 1 - pClass51_global->uNumBModels < 0;
      //if ( !(v14 ^ v15) )
      if (++v29 >= pClass51_global->uNumBModels)
        return v6;
    }
    if (!v6 || !v27)
      goto LABEL_15;

LABEL_8:
    v30 = 0;
    v24 = v6 = pBModel->uNumFaces;

    for (unsigned int j = 0; j < pBModel->uNumFaces; ++j)
    {
     BSPModel::Face *pStru2 = pBModel->pFaces + j;

     if (Vis_is_part_of_selection((unsigned int)pStru2, a5))
     {
          sub_4C0EF2_BSPModel_Face_To_struct12(&local_10, pStru2);
          if ( sub_4C1C0C(pRay, pRay + 1, &a2, &cRay_SomePoint, &local_10, v29) )
          {
            sub_436523(&cRay_SomePoint, 1);
            v11 = sub_48B561(cRay_SomePoint.flt_00000C);

            LOWORD(v11) = 0;
            v22 = (8 * (v30 | (v29 << 6)) | 6) + v11;

            a4->array_000004[a4->uNumPointers].uBillboardID = (unsigned int)pStru2;
            a4->array_000004[a4->uNumPointers].sZValue = v22;
            a4->array_000004[a4->uNumPointers++].dword_000008 = 2;
          }
        }

    }
    goto LABEL_15;
  }
  return 0;
}








//----- (004C0EF2) --------------------------------------------------------
void sub_4C0EF2_BSPModel_Face_To_struct12(struct12 *_this, BSPModel::Face *a2)
{
 _this->pFaceNormal[0] = a2->pFaceNormal[0];
 _this->pFaceNormal[1] = a2->pFaceNormal[1];
 _this->pFaceNormal[2] = a2->pFaceNormal[2];
 _this->sNormalDistance = a2->sNormalDistance;

 _this->pFaceNormalf[0] = (float)(a2->pFaceNormal[0] & 0xFFFF) / 65535.0f + (float)(a2->pFaceNormal[0] >> 16);
 _this->pFaceNormalf[1] = (float)(a2->pFaceNormal[1] & 0xFFFF) / 65535.0f + (float)(a2->pFaceNormal[1] >> 16);
 _this->pFaceNormalf[2] = (float)(a2->pFaceNormal[2] & 0xFFFF) / 65535.0f + (float)(a2->pFaceNormal[2] >> 16);
 _this->fNormalDistance = (float)(a2->sNormalDistance & 0xFFFF) / 65535.0f + (float)(a2->sNormalDistance >> 16);

 _this->zCalc1 = a2->zCalc1;
 _this->zCalc2 = a2->zCalc2;
 _this->zCalc3 = a2->zCalc3;
 _this->uFaceAttributes = a2->uFaceAttributes;

 _this->uTextureID = a2->uTextureID;

 _this->cBoundingBoxX = a2->cBoundingBoxX;
 _this->cBoundingBoxY = a2->cBoundingBoxY;
 _this->cBoundingBoxZ = a2->cBoundingBoxZ;

 _this->pVertexIDs = a2->pVertexIDs;
 _this->pXInterceptDisplacements = a2->pXInterceptDisplacements;
 _this->pYInterceptDisplacements = a2->pYInterceptDisplacements;
 _this->pZInterceptDisplacements = a2->pZInterceptDisplacements;

 _this->uPolygonType = a2->uPolygonType;
 _this->uNumVertices = a2->uNumVertices;
}



//----- (00436455) --------------------------------------------------------
char __stdcall sub_436455(struct12 *a1)
{
  char v2; // [sp+8h] [bp-30h]@1

  sub_43648F((int)&v2, dword_6BE63C + 6 * *a1->pVertexIDs);
  return sub_438258(a1, (int)&v2);
}

//----- (00438258) --------------------------------------------------------
char __stdcall sub_438258(struct12 *a1, int a2)
{
  char result; // al@2

  if ( (*(float *)(a2 + 8) - (double)pOldCamera->sPosZ) * (double)a1->pFaceNormal[2]
     + (*(float *)(a2 + 4) - (double)pOldCamera->sPosY) * (double)a1->pFaceNormal[1]
     + (*(float *)(a2 + 0) - (double)pOldCamera->sPosX) * (double)a1->pFaceNormal[0] < 0.0
    || (result = 1, a1->uFaceAttributes & 1) )
    result = 0;
  return result;
}






//----- (004C1EE5) --------------------------------------------------------
char __stdcall sub_4C1EE5_IntersectBModel(int *a1, int *a2, short *a3, short *a4, Vec3<short> *a5, struct struct12 *a6)
{
  int v6; // ecx@1
  int v7; // ecx@2
  int v8; // edx@3
  int v9; // ecx@4
  char v10; // zf@6
  int v11; // ecx@6
  int v12; // edx@7
  int v13; // edx@8
  int v14; // ecx@9
  int v15; // edx@11
  int v16; // edx@12
  int v17; // ecx@13
  int v19; // [sp+14h] [bp+8h]@3
  int v20; // [sp+14h] [bp+8h]@8
  int v21; // [sp+14h] [bp+8h]@12
  signed int v22; // [sp+24h] [bp+18h]@2
  signed int v23; // [sp+24h] [bp+18h]@7
  signed int v24; // [sp+24h] [bp+18h]@11

  v6 = *(_DWORD *)(a6 + 44);
  if ( BYTE1(v6) & 1 )
  {
    v7 = (int)a5;
    v22 = 0;
    *(_DWORD *)a1 = a5->x;
    *(_DWORD *)a2 = a5->y;
    if ( *(_BYTE *)(a6 + 93) )
    {
      v8 = (int)a4 + 2;
      v19 = a3 - a4;
      do
      {
        v9 = 2 * v22;
        *(_WORD *)(a3 + 4 * v22) = *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 52))
                                 + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v22 + *(_DWORD *)(a6 + 48)));
        *(_WORD *)(v8 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v9)
                           + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48)) + 2);
        *(_WORD *)(v19 + v8) = *(_WORD *)(v9 + *(_DWORD *)(a6 + 52) + 2)
                             + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48) + 2));
        ++v22;
        *(_WORD *)v8 = *(_WORD *)(v9 + *(_DWORD *)(a6 + 56) + 2)
                     + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v9 + *(_DWORD *)(a6 + 48) + 2) + 2);
        v8 += 4;
      }
      while ( v22 < *(_BYTE *)(a6 + 93) );
    }
  }
  else
  {
    v10 = (BYTE1(v6) & 2) == 0;
    v11 = (int)a5;
    if ( v10 )
    {
      v15 = a5->y;
      v24 = 0;
      *(_DWORD *)a1 = a5->y;
      *(_DWORD *)a2 = a5->z;
      if ( *(_BYTE *)(a6 + 93) )
      {
        v16 = (int)a4 + 2;
        v21 = a3 - a4;
        do
        {
          v17 = 2 * v24;
          *(_WORD *)(a3 + 4 * v24) = *(_WORD *)(2 * v24 + *(_DWORD *)(a6 + 56))
                                   + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v24 + *(_DWORD *)(a6 + 48)) + 2);
          *(_WORD *)(v16 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 60) + v17)
                              + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48)) + 4);
          *(_WORD *)(v21 + v16) = *(_WORD *)(*(_DWORD *)(a6 + 56) + v17 + 2)
                                + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48) + 2) + 2);
          ++v24;
          *(_WORD *)v16 = *(_WORD *)(*(_DWORD *)(a6 + 60) + v17 + 2)
                        + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v17 + *(_DWORD *)(a6 + 48) + 2) + 4);
          v16 += 4;
        }
        while ( v24 < *(_BYTE *)(a6 + 93) );
      }
    }
    else
    {
      v12 = a5->x;
      v23 = 0;
      *(_DWORD *)a1 = a5->x;
      *(_DWORD *)a2 = a5->z;
      if ( *(_BYTE *)(a6 + 93) )
      {
        v13 = (int)a4 + 2;
        v20 = a3 - a4;
        do
        {
          v14 = 2 * v23;
          *(_WORD *)(a3 + 4 * v23) = *(_WORD *)(2 * v23 + *(_DWORD *)(a6 + 52))
                                   + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(2 * v23 + *(_DWORD *)(a6 + 48)));
          *(_WORD *)(v13 - 2) = *(_WORD *)(*(_DWORD *)(a6 + 60) + v14)
                              + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48)) + 4);
          *(_WORD *)(v20 + v13) = *(_WORD *)(*(_DWORD *)(a6 + 52) + v14 + 2)
                                + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2));
          ++v23;
          *(_WORD *)v13 = *(_WORD *)(*(_DWORD *)(a6 + 60) + v14 + 2)
                        + *(_WORD *)(dword_6BE63C + 6 * *(_WORD *)(v14 + *(_DWORD *)(a6 + 48) + 2) + 4);
          v13 += 4;
        }
        while ( v23 < *(_BYTE *)(a6 + 93) );
      }
    }
  }
  return 1;
}

//----- (004C2186) --------------------------------------------------------
Result::Code __stdcall sub_4C2186_IntersectBModel(int *a1, int *a2, short *a3, short *a4, Vec3<short> *a5, struct struct12 *a6, unsigned int uModelID)
{
 if (a6->uFaceAttributes & 0x0100) // xy plane polygon
 {
  *a1 = a5->x;
  *a2 = a5->y;

  for (unsigned int i = 0; i < a6->uNumVertices; ++i)
  {
   a3[i * 2] = a6->pXInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].x;
   a4[i * 2] = a6->pYInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].y;

   a3[i * 2 + 1] = a6->pXInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].x;
   a4[i * 2 + 1] = a6->pYInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].y;
  }
 }
 else if (a6->uFaceAttributes & 0x0200) // xz plane polygon
 {
  *a1 = a5->x;
  *a2 = a5->z;

  for (unsigned int i = 0; i < a6->uNumVertices; ++i)
  {
   a3[i * 2] = a6->pXInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].x;
   a4[i * 2] = a6->pZInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].z;

   a3[i * 2 + 1] = a6->pXInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].x;
   a4[i * 2 + 1] = a6->pZInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].z;
  }
 }
 else  // yz plane polygon
 {
  *a1 = a5->y;
  *a2 = a5->z;

  for (unsigned int i = 0; i < a6->uNumVertices; ++i)
  {
   a3[i * 2] = a6->pYInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].y;
   a4[i * 2] = a6->pZInterceptDisplacements[i] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i]].z;

   a3[i * 2 + 1] = a6->pYInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].y;
   a4[i * 2 + 1] = a6->pZInterceptDisplacements[i + 1] + (short)pClass51_global->pBModels[uModelID].pVertices[a6->pVertexIDs[i + 1]].z;
  }
 }

 return Result::Success;
}
