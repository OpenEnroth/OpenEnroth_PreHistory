#include "GUIImage.h"

#include "..\mm7_unparsed_data.h"
#include "..\_lod.h"



Result::Code GUIImage::OnDraw(float dt)
{
 Render_DrawTransparentRect(pD3DRenderer,
                            cControlArea.x.min, cControlArea.y.min,
                            0, 0, cControlArea.x.Length(), cControlArea.y.Length(),
                            pImageTexture);

 return Result::Success;
}




Result::Code GUIImage::Initialize(const Rect<float> *pImageRect, const wchar_t *pTexture)
{
 cControlArea = *pImageRect;
 pImageTexture = &LODFile_Icons_LOD.aLODHeaders[LODFile_Icons_LOD.LODFile_LoadTexture_New(pTexture)];

 return Result::Success;
}


GUIImage::GUIImage():
  GUIControl(), pImageTexture(0)
{
}