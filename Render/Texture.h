#pragma once

enum TextureFormat
{
 TF_R8G8B8A8_int = 0,
 TF_R8G8_int,
 TF_R16_float,
 TF_R16G16B16A16_float,
 TF_R16B16_float,
 TF_R32G32B32A32_float,
 TF_R32G32_float,
 TF_D16_float,
 TF_D32_float,
 TF_undefined
};


class Texture
{
 public:
   enum TextureFormat eFormat;
};