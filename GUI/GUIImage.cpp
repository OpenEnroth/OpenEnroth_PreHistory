#include "GUIImage.h"

#include "..\mm7_unparsed_data.h"
#include "..\_lod.h"


Result::Code GUIImage::Initialize(const Rect<float> *pImageRect, const wchar_t *pTexture)
{
 cImageRect = *pImageRect;
 pImageTexture = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(pTexture)];

 return Result::Success;
}


GUIImage::GUIImage():
  GUIControl()
{
}