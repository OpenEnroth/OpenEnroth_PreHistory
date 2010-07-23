#pragma once
#include "Texture.h"
#include "RenderD3D10.h"


class TextureD3D10: public Texture
{
 public:
   ID3D10Resource *pResource;
   ID3D10View     *pResourceView;
};