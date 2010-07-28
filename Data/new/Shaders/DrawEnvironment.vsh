float4x4 mView: register(c0);




struct Input
{
 float2 vPosition: SV_Position0;
};


struct Output
{
 float4 vPosition: SV_Position0;
 float4 vTexCoord: TEXCOORD0;
};


Output main(Input vsin)
{
 Output vsout;
 vsout.vPosition = float4(vsin.vPosition, 1, 1);

 float2 vDescartesXY = float2(vsin.vPosition.x, vsin.vPosition.y);
 vsout.vTexCoord = normalize(mul(mView, float4(vDescartesXY, 1, 1)));
 vsout.vTexCoord.y = vsout.vTexCoord.y;

 return vsout;
}