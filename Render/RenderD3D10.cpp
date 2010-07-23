#include "RenderD3D10.h"
#include "TextureD3D10.h"
#include "..\\Window.h"




unsigned int RenderD3D10::GetPrimaryDepthTarget(Texture **pOut)
{
 if (pOut)
 {
  *pOut = pPrimaryDepthTarget;
  return 0;
 }
 return -1;
}

unsigned int RenderD3D10::GetPrimaryColorTarget(Texture **pOut)
{
 if (pOut)
 {
  *pOut = pPrimaryColorTarget;
  return 0;
 }
 return -1;
}


unsigned int RenderD3D10::CreateTexture(unsigned int uWidth, unsigned int uDepth, enum TextureFormat eFormat, Texture **)
{
 return -1;
}

unsigned int RenderD3D10::CreateTexture(const wchar_t *pName, Texture **)
{
 return -1;
}



unsigned int RenderD3D10::Reset(Window *pOutputWindow, bool bFullscreen, struct Viewport *pOutputArea)
{
 pTargetWindow = pOutputWindow;

 struct Viewport windowClientArea;
 pTargetWindow->GetClientArea(&windowClientArea);

 DXGI_SWAP_CHAIN_DESC sd;
 sd.BufferDesc.Width = windowClientArea.z - windowClientArea.x;
 sd.BufferDesc.Height = windowClientArea.w - windowClientArea.y;
 sd.BufferDesc.RefreshRate.Numerator = 0;
 sd.BufferDesc.RefreshRate.Denominator = 1;
 sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
 sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
 sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

 sd.SampleDesc.Count = 1;
 sd.SampleDesc.Quality = 0;

 sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
 sd.BufferCount = 2;
 sd.OutputWindow = (HWND)(pTargetWindow->GetAPIHandle());
 sd.Windowed = !bFullscreen;
 sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
 sd.Flags = 0;


 HRESULT hr;
 if (pSwapChain)
 {
  pSwapChain->Release();
  pSwapChain = 0;
 }

 hr = pDXGIFactory->CreateSwapChain(pDevice, &sd, &pSwapChain);
 if (FAILED(hr))
   return -1;

 ID3D10Texture2D *pColorRT;
 ID3D10Texture2D *pDepthRT;
 pSwapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), (void **)(&pColorRT));

 D3D10_TEXTURE2D_DESC  sDepthDesc;
 sDepthDesc.Width = sd.BufferDesc.Width;
 sDepthDesc.Height = sd.BufferDesc.Height;
 sDepthDesc.MipLevels = 1;
 sDepthDesc.ArraySize = 1;
 sDepthDesc.Format = DXGI_FORMAT_D32_FLOAT;
 sDepthDesc.SampleDesc.Count = 1;
 sDepthDesc.SampleDesc.Quality = 0;
 sDepthDesc.Usage = D3D10_USAGE_DEFAULT;
 sDepthDesc.BindFlags = D3D10_BIND_DEPTH_STENCIL;
 sDepthDesc.CPUAccessFlags = 0;
 sDepthDesc.MiscFlags = 0;
 pDevice->CreateTexture2D(&sDepthDesc, 0, &pDepthRT);
 
 pPrimaryColorTarget = new TextureD3D10;
 pPrimaryColorTarget->eFormat = TF_R8G8B8A8_int;
 pPrimaryColorTarget->pResource = pColorRT;
 pDevice->CreateRenderTargetView(pColorRT, 0, (ID3D10RenderTargetView **)(&pPrimaryColorTarget->pResourceView));
 
 pPrimaryDepthTarget = new TextureD3D10;
 pPrimaryDepthTarget->eFormat = TF_D32_float;
 pPrimaryDepthTarget->pResource = pDepthRT;
 pDevice->CreateDepthStencilView(pDepthRT, 0, (ID3D10DepthStencilView **)(&pPrimaryDepthTarget->pResourceView));

 pDevice->OMSetRenderTargets(1, (ID3D10RenderTargetView **)(&pPrimaryColorTarget->pResourceView), (ID3D10DepthStencilView *)(pPrimaryDepthTarget->pResourceView));



 D3D10_BLEND_DESC sBlendDesc;
 sBlendDesc.AlphaToCoverageEnable = false;
 sBlendDesc.BlendEnable[0] = true;
 sBlendDesc.BlendEnable[1] = true;
 sBlendDesc.BlendEnable[2] = true;
 sBlendDesc.BlendEnable[3] = true;
 sBlendDesc.BlendEnable[4] = true;
 sBlendDesc.BlendEnable[5] = true;
 sBlendDesc.BlendEnable[6] = true;
 sBlendDesc.BlendEnable[7] = true;
 sBlendDesc.SrcBlend = D3D10_BLEND_SRC_ALPHA;
 sBlendDesc.DestBlend = D3D10_BLEND_INV_SRC_ALPHA;
 sBlendDesc.BlendOp = D3D10_BLEND_OP_ADD;
 sBlendDesc.SrcBlendAlpha = D3D10_BLEND_ZERO;
 sBlendDesc.DestBlendAlpha = D3D10_BLEND_ZERO;
 sBlendDesc.BlendOpAlpha = D3D10_BLEND_OP_ADD;
 sBlendDesc.RenderTargetWriteMask[0] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[1] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[2] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[3] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[4] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[5] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[6] = D3D10_COLOR_WRITE_ENABLE_ALL;
 sBlendDesc.RenderTargetWriteMask[7] = D3D10_COLOR_WRITE_ENABLE_ALL;
 pDevice->CreateBlendState(&sBlendDesc, &pBlendState_Default);



 D3D10_RASTERIZER_DESC sRasterizerDesc;
 sRasterizerDesc.FillMode = D3D10_FILL_SOLID;
 sRasterizerDesc.CullMode = D3D10_CULL_NONE;
 sRasterizerDesc.FrontCounterClockwise = false;
 sRasterizerDesc.DepthBias = 0;
 sRasterizerDesc.DepthBiasClamp = 0;
 sRasterizerDesc.SlopeScaledDepthBias = 0;
 sRasterizerDesc.DepthClipEnable = true;
 sRasterizerDesc.ScissorEnable = false;
 sRasterizerDesc.MultisampleEnable = false;
 sRasterizerDesc.AntialiasedLineEnable = false;
 pDevice->CreateRasterizerState(&sRasterizerDesc, &pRasterizerState_Default);
 pDevice->RSSetState(pRasterizerState_Default);

 defaultViewport.TopLeftX = pOutputArea->x;
 defaultViewport.TopLeftY = pOutputArea->y;
 defaultViewport.Width = pOutputArea->z - pOutputArea->x;
 defaultViewport.Height = pOutputArea->w - pOutputArea->y;
 defaultViewport.MinDepth = 0.0f;
 defaultViewport.MaxDepth = 1.0f;
 pDevice->RSSetViewports(1, &defaultViewport);


 float pClearColor[] = {0, 0, 0, 0};
 pDevice->ClearRenderTargetView((ID3D10RenderTargetView *)(pPrimaryColorTarget->pResourceView), pClearColor);
 pDevice->ClearDepthStencilView((ID3D10DepthStencilView *)(pPrimaryDepthTarget->pResourceView), D3D10_CLEAR_DEPTH, 1, 0);
 pSwapChain->Present(0, 0);

 return 0;
}



unsigned int RenderD3D10::Initialize()
{
 hDXGIDll = LoadLibraryW(L"dxgi.dll");
 hD3D10Dll = LoadLibraryW(L"d3d10.dll");
 if (!hDXGIDll || !hD3D10Dll)
 {
  MessageBoxW(0, L"No Direct3D10 runtime installed", L"Error", 0);
  return -1;
 }

 HRESULT (__stdcall *pCreateDXGIFactory)(const IID &, void **);
 pCreateDXGIFactory = (HRESULT (__stdcall *)(const IID &, void **))(GetProcAddress(hDXGIDll, "CreateDXGIFactory"));

 (pCreateDXGIFactory)(__uuidof(IDXGIFactory), (void **)(&pDXGIFactory));


 IDXGIAdapter *pAdapter;
 for (int i = 0; pDXGIFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i)
 {
  DXGI_ADAPTER_DESC sAdapterDesc;
  pAdapter->GetDesc(&sAdapterDesc);

  IDXGIOutput *pOutput;
  for (int j = 0; pAdapter->EnumOutputs(j, &pOutput) != DXGI_ERROR_NOT_FOUND; ++j)
  {
   DXGI_MODE_DESC pModes[256];
   unsigned int   uNumModes;
   pOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, 0, &uNumModes, pModes);
   pOutput->Release();
  }
  pAdapter->Release();
 }

 HRESULT (__stdcall *pD3D10CreateDevice)(IDXGIAdapter *, D3D10_DRIVER_TYPE, void *, unsigned int, unsigned int, ID3D10Device **);
 pD3D10CreateDevice = (HRESULT (__stdcall *)(IDXGIAdapter *, D3D10_DRIVER_TYPE, void *, unsigned int, unsigned int, ID3D10Device **))GetProcAddress(hD3D10Dll, "D3D10CreateDevice");

 HRESULT hr;
 hr = (pD3D10CreateDevice)(0, D3D10_DRIVER_TYPE_HARDWARE, 0, D3D10_CREATE_DEVICE_SINGLETHREADED, D3D10_SDK_VERSION, &pDevice);
 if (FAILED(hr))
   return -1;
 return 0;
}



RenderD3D10::RenderD3D10()
{
 hDXGIDll = hD3D10Dll = 0;
 pDXGIFactory = 0;
 pDevice = 0;
 pSwapChain = 0;
 pTargetWindow = 0;
}

RenderD3D10::~RenderD3D10()
{
}




Render *CreateDirect3D10Render()
{
 return new RenderD3D10;
}


//#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d10.lib")
#pragma comment(lib, "d3dx10.lib")