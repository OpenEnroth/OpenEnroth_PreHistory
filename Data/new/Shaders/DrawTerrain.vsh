
float4x4 mViewProjection: register(c0);
/*cbuffer cb0
{
 float4x4 mViewProjection: packoffset(c0);
};*/
float4   vLODSize:        register(c4);  // x   1 / lod_width    mapping vertex pos to uv
                                         // y   1 / lod_height
                                         // zw  unused

Texture2D<float4> tHeightmap: register(t0);

SamplerState sHeightmapSampler: register(s0);


struct Input
{
 float2 vPos: SV_Position0;
};


struct Output
{
 float4 vPos:    SV_Position0;
 float4 vNormal: NORMAL0;
 float3 vUV:     TEXCOORD0;
};


Output main(in Input vsin)
{
 Output vsout;

// float2 vCentreUV = vsin.vPos * vLODSize.xy;
 float2 vCentreUV = vsin.vPos * vLODSize.xy;
// float4 vCentreHeight = tHeightmap.Load(float3(vCentreUV, 0));
 float4 vCentreHeight = tHeightmap.Load(float3(vsin.vPos + float2(128, 128), 0));

// vsout.vPos = mul(mViewProjection, float4(vsin.vPos.x, vCentreHeight.x * 32 - 100, vsin.vPos.y, 1));
// vsout.vPos = mul(mViewProjection, float4(vsin.vPos.x, -300, vsin.vPos.y, , 1));
 float4 vPos = float4(vsin.vPos.x, 64 * vCentreHeight.x, vsin.vPos.y, 1);
 vsout.vPos = mul(mViewProjection, vPos);
 vsout.vUV.xy = vCentreUV;
 vsout.vUV.z = vCentreHeight.x;

/*
 float4 vUpHeight = tHeightmap.Sample(sHeightmapSampler, (vsin.vPos + float2(0, 1) * vLODSize.xy);
 float4 vLeftHeight = tHeightmap.Sample(sHeightmapSampler, (vsin.vPos + float2(1, 0) * vLODSize.xy);
 float4 vBottomHeight = tHeightmap.Sample(sHeightmapSampler, (vsin.vPos + float2(0, -1) * vLODSize.xy);
 float4 vRightUpHeight = tHeightmap.Sample(sHeightmapSampler, (vsin.vPos + float2(0, -1) * vLODSize.xy);

  do normal calculation here
*/
 vsout.vNormal = float4(0, 0, 0, 0);

 return vsout;
}