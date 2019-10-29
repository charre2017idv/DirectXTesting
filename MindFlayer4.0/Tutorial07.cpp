/**
 * @LC	   : 15/10/2019
 * @file   : Tutorial07.cpp
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 04/10/2019
 * @brief  : Main document in charge of setting and initializing multiple classes.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include "mfDefines.h"
#include "mfRenderManager.h"
#include "mfResourceManager.h"
#include "mfRenderTarget.h"
#include "mfDepthStencil.h"
#include "mfDepthStencilView.h"
#include "mfTexture.h"
#include "mfVertexShader.h"
#include "mfPixelShader.h"
#include "mfVertexBuffer.h"
#include "mfPixelBuffer.h"
#include "mfConstBuffer.h"
#include "mfInputLayout.h"
#include "mfLoadModel.h"
#include "mfBaseTexture.h"
#include "mfOpenFile.h"
#include "mfMesh.h"
#include "mfViewport.h"
#include "mfWindow.h"
#include "mfSampler.h"
#include "mfMaterial.h"
#include "mfSwapchain.h"
#ifdef mfDIRECTX
#include "mfImGui.h"
#endif // mfDIRECTX
#include "mfCamera.h"
#include "mfRenderToTexture.h"
/**
 * @brief : Structures
 */

struct CBNeverChanges
{
    XMMATRIX mView;
};

struct CBChangeOnResize
{
    XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
    XMMATRIX mWorld;
    XMFLOAT4 vMeshColor;
};

/**
 * Global Variables
 */
/**
 * @brief : 
 */
mfSwapchain Swapchain;
/**
  * @brief  : 
  * @param  : 
  * @bug    : 
  */
mfWindow Window;
/**
 * @brief : Render Target View Object
 */
mfRenderTarget RenderTarget;
/**
 * @brief : Depth Stencil View Object.
 */
mfDepthStencilView DepthStencilView;
/**
 * @brief : Never Changes Buffer Object.
 */
mfConstBuffer NeverChangesBuffer;
mfConstBuffer ChangeOnResizeBuffer;
mfConstBuffer ChangesEveryFrameBuffer;

mfConstBuffer ViewBuffer;
mfConstBuffer ProjBuffer;
/**
 * @brief : Vertex Shader Object.
 */
mfVertexShader VertexShader;
/**
 * @brief : Pixel Shader Object.
 */
mfPixelShader PixelShader;
/**
 * @brief : Input Layout Object.
 */
mfInputLayout InputLayout;
/**
 * @brief : Load Model Object.
 */
mfLoadModel LoadModel;
/**
 * @brief : Open File Objects.
 */
mfOpenFile OpenModelFile;
mfOpenFile OpenTextureFile;
/**
 * @brief : 
 */
mfBaseTexture DepthStencil;
/**
 * @brief : 
 */
mfViewport Viewport;
/**
 * @brief :
 */
mfSampler Sampler;
/**
 * @brief : Mesh Object.
 */
mfMesh Mesh;
/**
 * @brief : 
 */
mfMaterial Materials;
/**
 * @brief : Provides resources from ImGui object class
 */
#ifdef mfDIRECTX
mfImGui Imgui;
#endif // mfDIRECTX
/**
 * @brief : 
 */
mfCamera Camera;
mfCamera SecurityCamera;
/**
 * @brief : 
 */
mfRenderToTexture RenderToTexture;
//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
// HINSTANCE                           g_hInst = NULL;
// HWND                                g_hWnd = NULL;
mf_DRIVER_TYPE                     g_driverType = mf_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;
XMMATRIX                            g_World;
XMFLOAT4                            g_vMeshColor( 0.7f, 0.7f, 0.7f, 1.0f );
bool isMeshLoaded = false;
const char* ModelPath;
//mfBaseTextureDesc TextureDesc;
int texPos = 0;
//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
/**
  * @brief  : Function that initialize the window
  * @param  : HINSTANCE hInstance : Instance that is initialize.
              int nCmdShow : Identifier.
  * @bug    : No Known Bugs.
  */
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK    WndProc( HWND, UINT, WPARAM, LPARAM );
void Render();
void Draw(float t);
void DrawToTexture(float t);


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( lpCmdLine );

    /**
     * @brief : Initialize the module of Render Manager
     */
    mfRenderManager::Prepare();
    /**
     * @brief : Initialize the module of Resource Manager
     */
    mfResourceManager::Prepare();

    mfRegisterClassWindowDesc wndRegisterClass;
    wndRegisterClass.cbSize = sizeof(WNDCLASSEX);
    wndRegisterClass.style = CS_HREDRAW | CS_VREDRAW;
    wndRegisterClass.lpfnWndProc = WndProc;
    wndRegisterClass.cbClsExtra = 0;
    wndRegisterClass.cbWndExtra = 0;
    wndRegisterClass.hInstance = hInstance;
    wndRegisterClass.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    wndRegisterClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndRegisterClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wndRegisterClass.lpszMenuName = NULL;
    wndRegisterClass.lpszClassName = L"TutorialWindowClass";
    wndRegisterClass.hIconSm = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
    mfWindowDesc wndDesc;
    wndDesc.width = SCREEN_WIDTH;
    wndDesc.height = SCREEN_HEIGHT;
    wndDesc.nCmdShow = nCmdShow;

    Window.Init(wndRegisterClass, wndDesc);

    if( FAILED( InitDevice() ) )
    {
        CleanupDevice();
        return 0;
    }

    /**
     * @brief : Initialize ImGui
     */
#ifdef mfDIRECTX
    Imgui.Init
    (
      mfRenderManager::getSingleton().GetDevice(), 
      mfRenderManager::getSingleton().GetDeviceContext(), 
      Window
    );
#endif // mfDIRECTX

    // Main message loop
    MSG msg = {0};
    while( WM_QUIT != msg.message )
    {
      if (msg.message == WM_KEYDOWN)
      {
        XMVECTOR rot;
        Vector3 movement{ 0.0f, 0.0f, 0.0f };
        switch (msg.wParam)
        {
        case VK_LEFT:
        {
          movement.x -= 1;
          break;
        }

        case VK_RIGHT:
        {
          movement.x += 1;
          break;
        }
        case VK_DOWN :
          movement.y -= .001f;
          break;
        case VK_UP:
          movement.y += .001f;
          break;

        case VK_PRIOR :
        {
          movement.z -= 1;
          break;
        }

        case VK_NEXT:
        {
          movement.z += 1;
          break;
        }
        case VK_ESCAPE:
        {
          exit(1);
          break;
        }
        default:
          break;
        }
        Camera.move(&movement);

        CBNeverChanges cbNeverChanges;
        cbNeverChanges.mView = XMMatrixTranspose(Camera.getViewMatrix());
        NeverChangesBuffer.Update(&cbNeverChanges);
        Camera.setProjMatrix(mf_PIDIV4, SCREEN_WIDTH, SCREEN_HEIGHT, 0.01f, 100.0f);
      }

        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            Render();
        }
    }

    CleanupDevice();
    
    /**
     * @brief : Release the Render Manager Module
     */
    mfRenderManager::ShutDown();
    /**
     * @brief : Release the Resource Manager Module
     */
    mfResourceManager::ShutDown();

    return ( int )msg.wParam;
}


//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
HRESULT InitDevice()
{
    HRESULT hr = S_OK;
#ifdef mfDIRECTX
    RECT rc;
    GetClientRect(Window.getInterface().ID, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

#endif // mfDIRECTX


    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    mf_DRIVER_TYPE driverTypes[] =
    {
        mf_DRIVER_TYPE_HARDWARE,
        mf_DRIVER_TYPE_WARP,
        mf_DRIVER_TYPE_REFERENCE,
    };
    UINT numDriverTypes = ARRAYSIZE( driverTypes );

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    UINT numFeatureLevels = ARRAYSIZE( featureLevels );

    // 3) InitSwapchain
    mfSwapchainDesc swapchainDesc;
    swapchainDesc.BufferCount = 1;
    swapchainDesc.Width = SCREEN_WIDTH;
    swapchainDesc.Height = SCREEN_HEIGHT;
    swapchainDesc.Format = mf_FORMAT_R8G8B8A8_UNORM;
    swapchainDesc.Numerator = 60;
    swapchainDesc.Denominator = 1;
    swapchainDesc.BufferUsage = mf_USAGE_RENDER_TARGET_OUTPUT;
#ifdef mfDIRECTX
    swapchainDesc.OutputWindow = Window.getInterface().ID;
#endif // mfDIRECTX
    swapchainDesc.Count = 1;
    swapchainDesc.Quality = 0;
    swapchainDesc.Windowed = TRUE;

    Swapchain.Init(swapchainDesc);

    // 4) Set Device and Swap chain
#ifdef mfDIRECTX
    for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
    {
        g_driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain
        (
          NULL, 
          (D3D_DRIVER_TYPE)g_driverType,
          NULL, 
          createDeviceFlags, 
          featureLevels,
          numFeatureLevels,
          D3D11_SDK_VERSION, 
          &Swapchain.getInterface().Desc,
          &Swapchain.getInterface().ID, 
          &mfRenderManager::getSingleton().GetprtDev(),
          &g_featureLevel, 
          &mfRenderManager::getSingleton().GetprtDevCtx() 
        );
        if( SUCCEEDED( hr ) )
            break;
    }
    if( FAILED( hr ) )
        return hr;
#endif // mfDIRECTX

    // 4.1) Set back buffer
    // Create a render target view
    Swapchain.setBackBuffer();
    // 5) Create Render target view
    /**
     * @brief : Initialization of Render Target
     */
    hr = mfRenderManager::getSingleton().CreateRenderTargetView(Swapchain, RenderTarget);
    // Initialize Render To Texture
    RenderToTexture.Init();
#ifdef mfDIRECTX
    Swapchain.getInterface().backbuffer->Release();
#endif // mfDIRECTX
    if( FAILED( hr ) )
        return hr;
    // 6) Create Depth Stencil Texture
    /**
     * @brief : Initialization of Depth Stencil
     */
    mfBaseTextureDesc depthStencilDesc;
    depthStencilDesc.Tag = "DEPTH_STENCIL";
    depthStencilDesc.ID = mf_DEPTH_STENCIL_TEXTURE;
    depthStencilDesc.Width = SCREEN_WIDTH;
    depthStencilDesc.Height = SCREEN_HEIGHT;
    depthStencilDesc.MipLevels = 1;
    depthStencilDesc.Arraysize = 1;
    depthStencilDesc.TexFormat = mf_FORMAT_D24_UNORM_S8_UINT;
    depthStencilDesc.SamplerDescCount = 1;
    depthStencilDesc.SamplerDescQuality = 0;
    depthStencilDesc.Usage = mf_USAGE_DEFAULT;
    depthStencilDesc.Bindflags = mf_BIND_DEPTH_STENCIL;
    depthStencilDesc.CPUAccessFlags = 0;
    depthStencilDesc.MiscFlags = 0;
    depthStencilDesc.Filepath = NULL;

    DepthStencil.Init(depthStencilDesc);

    // 7) Create Depth Stencil view
    
    /**
     * @brief : Initialization of Depth Stencil View
     */
    mfDepthStencilViewDesc depthStencilViewDesc;
    depthStencilViewDesc.texFormat = depthStencilDesc.TexFormat/*descDepth.Format*/;
    depthStencilViewDesc.ViewDimension = mf_DSV_DIMENSION_TEXTURE2D;
    depthStencilViewDesc.MipSlice = 0;
#ifdef mfDIRECTX
    depthStencilViewDesc.Resource = DepthStencil.getInterface().ID;
#endif // mfDIRECTX

    DepthStencilView.Init(depthStencilViewDesc);
    // Create the shader resource view.
    RenderToTexture.CreateShaderResourceView();
    // 8) Init Viewport
    /**
     * @brief : Initialization of the viewport
     */
    mfViewportDesc ViewportDesc;
    ViewportDesc.Width = (FLOAT)SCREEN_WIDTH;
    ViewportDesc.Height = (FLOAT)SCREEN_HEIGHT;
    ViewportDesc.MinDepth = 0.0f;
    ViewportDesc.MaxDepth = 1.0f;
    ViewportDesc.TopLeftX = 0;
    ViewportDesc.TopLeftY = 0;

    Viewport.Init(ViewportDesc);

    // 9) Init Shader
    // 9.1) Create Vertex Shader
    /**
     * @brief : Initialization for Vertex shader
     */
    mfBaseShaderDesc VertexShaderDesc;
    VertexShaderDesc.FileName = L"Tutorial07.fx";
    VertexShaderDesc.EntryPoint = "VS";
    VertexShaderDesc.ShaderModel = "vs_4_0"; 
#ifdef mfDIRECTX
    VertexShaderDesc.BlobOut = &VertexShader.getInterface().VSBlob;
#endif // mfDIRECTX

    VertexShader.Init(VertexShaderDesc);
    // 9.2) Init Layout
    /**
     * @brief : Initialization for Input Layout
     */
    
    InputLayout.Init(VertexShader);
#ifdef mfDIRECTX
    VertexShader.getInterface().VSBlob->Release();
#endif // mfDIRECTX
    if (FAILED(hr))
      return hr;
    InputLayout.Render();

    // 9.3) Create Pixel Shader
    /**
     * @brief : Initialization for Pixel Shader
     */
    mfBaseShaderDesc PixelShaderDesc;
    PixelShaderDesc.FileName = L"Tutorial07.fx";
    PixelShaderDesc.EntryPoint = "PS";
    PixelShaderDesc.ShaderModel = "ps_4_0";
#ifdef mfDIRECTX
    PixelShaderDesc.BlobOut = &PixelShader.getInterface().PSBlob;
#endif // mfDIRECTX

    PixelShader.Init(PixelShaderDesc);
   
    // 10) Create buffers
    // 10.1) Create Vertex Buffer
    // 10.2) Set Vertex Buffer
    // 10.3) Create Index Buffer
    // 10.4) Set Index Buffer
    /**
     * @brief : Load Model From File
     */
    Mesh.Init(LoadModel.getInterface());

    // 12) Create Constant Buffers

    /**
     * @brief : Initialization of Constant Buffers
     */
    mfBufferDesc NeverChangesBufferDesc;
    NeverChangesBufferDesc.Usage = mf_USAGE_DEFAULT;
    NeverChangesBufferDesc.ByteWidth = sizeof(CBNeverChanges);
    NeverChangesBufferDesc.BindFlags = mf_BIND_CONSTANT_BUFFER;
    NeverChangesBufferDesc.CPUAccessFlags = 0;

    NeverChangesBuffer.Init(NeverChangesBufferDesc);
    ViewBuffer.Init(NeverChangesBufferDesc);
    mfBufferDesc ChangeOnResizeBufferDesc;
    ChangeOnResizeBufferDesc.Usage = mf_USAGE_DEFAULT;
    ChangeOnResizeBufferDesc.ByteWidth = sizeof(CBChangeOnResize);
    ChangeOnResizeBufferDesc.BindFlags = mf_BIND_CONSTANT_BUFFER;
    ChangeOnResizeBufferDesc.CPUAccessFlags = 0;

    ChangeOnResizeBuffer.Init(ChangeOnResizeBufferDesc);
    ProjBuffer.Init(ChangeOnResizeBufferDesc);

    mfBufferDesc ChangesEveryFrameBufferDesc;
    ChangesEveryFrameBufferDesc.Usage = mf_USAGE_DEFAULT;
    ChangesEveryFrameBufferDesc.ByteWidth = sizeof(CBChangesEveryFrame);
    ChangesEveryFrameBufferDesc.BindFlags = mf_BIND_CONSTANT_BUFFER;
    ChangesEveryFrameBufferDesc.CPUAccessFlags = 0;

    ChangesEveryFrameBuffer.Init(ChangesEveryFrameBufferDesc);

    // 14) Create Sample State

    /**
     * @brief : Initialization of Sampler State
     */
    mfSamplerDesc SamplerDesc;
    SamplerDesc.Filter = mf_FILTER_MIN_MAG_MIP_LINEAR;
    SamplerDesc.AddressU = mf_TEXTURE_ADDRESS_WRAP;
    SamplerDesc.AddressV = mf_TEXTURE_ADDRESS_WRAP;
    SamplerDesc.AddressW = mf_TEXTURE_ADDRESS_WRAP;
    SamplerDesc.ComparisionFunc = mf_COMPARISON_NEVER;
    SamplerDesc.MinLOD = 0;
    SamplerDesc.MaxLOD = mf_FLOAT32_MAX;

    Sampler.Init(SamplerDesc);


    mfOpenFileDesc ModelFileDesc;
    ModelFileDesc.hwndOwner = NULL;
    ModelFileDesc.lpstrFilter = L" Obj Files\0*.obj\0 FBX Files\0*.fbx\0 3DS Files\0*.3ds\0  All files\0*.*\0";
    ModelFileDesc.nMaxFile = MAX_PATH;
    ModelFileDesc.lpstrTitle = L"Select a model file";
    ModelFileDesc.lpstrInitialDir = L"Meshes\\";
    ModelFileDesc.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    OpenModelFile.Init(ModelFileDesc);


    mfOpenFileDesc TextureFileDesc;
    TextureFileDesc.hwndOwner = NULL;
    TextureFileDesc.lpstrFilter = L" PNG Files\0*.png\0 JPEG Files\0*.jpeg\0 JPG Files\0*.jpg\0";
    TextureFileDesc.nMaxFile = MAX_PATH;
    TextureFileDesc.lpstrTitle = L"Select a texture file";
    TextureFileDesc.lpstrInitialDir = L"Textures\\";
    TextureFileDesc.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    OpenTextureFile.Init(TextureFileDesc);

    // 15) Init world (mesh) Matrix

    // Initialize the world matrices
    g_World = XMMatrixIdentity();

    /**
     * @brief : Initialization of camera
     */
    mfCameraDesc CameraDesc;
    CameraDesc.Eye = Vector4{ 0.0f, 3.0f, -6.0f, 0.0f };
    CameraDesc.Up = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };
    CameraDesc.Front = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };
    CameraDesc.Right = Vector4{ 1.0f, 0.0f, 0.0f, 0.0f };
    CameraDesc.LookAt = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };

    Camera.Init(CameraDesc);
    Camera.Update();

    CBNeverChanges cbNeverChanges;
    cbNeverChanges.mView = XMMatrixTranspose(Camera.getViewMatrix());
    NeverChangesBuffer.Update(&cbNeverChanges);
    Camera.setProjMatrix(mf_PIDIV4, SCREEN_WIDTH, SCREEN_HEIGHT, 0.01f, 100.0f);
    CBChangeOnResize cbChangesOnResize;
    cbChangesOnResize.mProjection = XMMatrixTranspose(Camera.getProjMatrix());
    ChangeOnResizeBuffer.Update(&cbChangesOnResize);
    /**
     * @brief : Initialization of Security Camera 
     */
    mfCameraDesc SecurityCameraDesc;
    SecurityCameraDesc.Eye = Vector4{ 0.0f, 3.0f, -6.0f, 0.0f };
    SecurityCameraDesc.Up = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };
    SecurityCameraDesc.Front = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };
    SecurityCameraDesc.Right = Vector4{ 1.0f, 0.0f, 0.0f, 0.0f };
    SecurityCameraDesc.LookAt = Vector4{ 0.0f, 1.0f, 0.0f, 0.0f };

    SecurityCamera.Init(SecurityCameraDesc);
    SecurityCamera.Update();

    /**
     * @brief : Initialize the view matrix
     */
    CBNeverChanges View;
    View.mView = XMMatrixTranspose(SecurityCamera.getViewMatrix());
    ViewBuffer.Update(&View);
    SecurityCamera.setProjMatrix(mf_PIDIV4, SCREEN_WIDTH, SCREEN_HEIGHT, 0.01f, 100.0f);
    CBChangeOnResize Projection;
    Projection.mProjection = XMMatrixTranspose(SecurityCamera.getProjMatrix());
    ProjBuffer.Update(&Projection);
    return S_OK;
}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
  mfRenderManager::getSingleton().Destroy();
  Swapchain.Destroy();
  ViewBuffer.Destroy();
  ProjBuffer.Destroy();
  NeverChangesBuffer.Destroy();
  ChangeOnResizeBuffer.Destroy();
  ChangesEveryFrameBuffer.Destroy();
  RenderTarget.Destroy();
  RenderToTexture.Destroy();
  DepthStencil.Destroy();
  Sampler.Destroy();
  DepthStencilView.Destroy();
  VertexShader.Destroy();
  PixelShader.Destroy();
  InputLayout.Destroy();
  Mesh.Destroy();
  Materials.Destroy();
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    PAINTSTRUCT ps;
    HDC hdc;
    if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
    {
      return true;
    }
    switch( message )
    {
        case WM_PAINT:
            hdc = BeginPaint( hWnd, &ps );
            EndPaint( hWnd, &ps );
            break;

        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;
        default:
            return DefWindowProc( hWnd, message, wParam, lParam );
    }

    return 0;
}


//--------------------------------------------------------------------------------------
// Render a frame
//--------------------------------------------------------------------------------------

void Render()
{
    // Update our time
    static float t = 0.0f;
    if( g_driverType == mf_DRIVER_TYPE_REFERENCE )
    {
        t += ( float )mf_PI * 0.0125f;
    }
    else
    {
        static DWORD dwTimeStart = 0;
        DWORD dwTimeCur = GetTickCount();
        if( dwTimeStart == 0 )
            dwTimeStart = dwTimeCur;
        t = ( dwTimeCur - dwTimeStart ) / 1000.0f;
    }

    // Rotate cube around the origin
    g_World = XMMatrixRotationY( t );

    // Modify the color
    g_vMeshColor.x = 1.0f;//( sinf( t * 1.0f ) + 1.0f ) * 0.5f;
    g_vMeshColor.y = 1.0f;//( cosf( t * 3.0f ) + 1.0f ) * 0.5f;
    g_vMeshColor.z = 1.0f;//( sinf( t * 5.0f ) + 1.0f ) * 0.5f;

    //
    // Clear the back buffer
    //
    float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red, green, blue, alpha   

    //
    // Clear the depth buffer to 1.0 (max depth)
    //
    mfRenderManager::getSingleton().ClearDepthStencilView(DepthStencilView);

    //
    // Update variables that change once per frame
    RenderToTexture.Render(DepthStencilView, ClearColor);
    DrawToTexture(t);

    mfRenderManager::getSingleton().ClearRenderTargetView(RenderTarget, ClearColor );
    mfRenderManager::getSingleton().ClearDepthStencilView(DepthStencilView);
    mfRenderManager::getSingleton().OMSetRenderTargets(1, RenderTarget, DepthStencilView);
    Draw(t);
    mfRenderManager::getSingleton().ClearDepthStencilView(DepthStencilView);
}

void Draw(float t)
{
  CBChangesEveryFrame cb;
  //cb.mWorld = XMMatrixTranspose( g_World );
//     cb.mWorld = XMMATRIX(
//       0.02f, 0.0f, 0.0f, 0.0f,
//       0.0f, 0.02f, 0.0f, -1.0f,
//       0.0f, 0.0f, 0.02f, 0.0f,
//       0.0f, 0.0f, 0.0f, 1.0f
//     );

  cb.mWorld = XMMATRIX(
    2.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 2.0f, 0.0f, -1.0f,
    0.0f, 0.0f, 2.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  );
  cb.mWorld *= XMMatrixRotationY(t/*XM_PIDIV4 * 4*/);
  cb.vMeshColor = g_vMeshColor;
  ChangesEveryFrameBuffer.Update(&cb);
  /**
   * @brief : Set primitive topology
   */
  mfRenderManager::getSingleton().IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  NeverChangesBuffer.Render(0, 1);


  ChangeOnResizeBuffer.Render(1, 1);
  ChangesEveryFrameBuffer.Render(2, 1);
  mfRenderManager::getSingleton().PSSetConstantBuffers(2, 1, ChangesEveryFrameBuffer);
  VertexShader.Render();
  PixelShader.Render();
  Sampler.Render();
  Materials.Render(texPos);
  mfRenderManager::getSingleton().Render();

  if (isMeshLoaded)
  {
    mfRenderManager::getSingleton().DrawIndexed(LoadModel.getInterface().IndexSize, 0, 0);
  }

  //
  // Present our back buffer to our front buffer
  //
#ifdef mfDIRECTX
  Imgui.Update();
  ImGui::Begin("Mind Flayer Settings");
  ImGui::SetWindowSize(ImVec2(200, 200), ImGuiSetCond_FirstUseEver);
  ImGui::SetWindowPos(ImVec2(2, 2), ImGuiSetCond_FirstUseEver);
  if (ImGui::Button("Load Mesh") && GetOpenFileName(&OpenModelFile.getInterface().Desc))
  {
    // Clear Raw data for texture paths
    LoadModel.getInterface().textNames.clear();
    // Clear Raw data for Material
    Materials.getInterface().Textures.clear();
    // Reset Material Index
    if (Materials.getInterface().Textures.size() < texPos)
    {
      texPos = 0;
    }
    // Load Model
    OpenModelFile.getFileString();

    ModelPath = OpenModelFile.getInterface().Filepath.c_str();
    LoadModel.Init(ModelPath);
    Mesh.Init(LoadModel.getInterface());
    // Load Texture

    for (int i = 0; i < LoadModel.getInterface().textNames.size(); i++)
    {
      mfBaseTextureDesc tmpText;
      tmpText.ID = mf_FILE_TEXTURE;
      tmpText.Tag = "ALBEDO";
      std::wstring stemp = std::wstring(LoadModel.getInterface().textNames[i].begin(), LoadModel.getInterface().textNames[i].end());
      LPCWSTR sw = stemp.c_str();
      tmpText.Filepath = sw;
      mfTexture tmp;
      tmp.Init(tmpText);
      Materials.Init(tmp);
    }

    isMeshLoaded = true;
  }

  if (ImGui::Button("Load Text") && GetOpenFileName(&OpenTextureFile.getInterface().Desc))
  {
    OpenTextureFile.getFileString();

    mfBaseTextureDesc tmpText;
    tmpText.ID = mf_FILE_TEXTURE;
    tmpText.Tag = "ALBEDO";
    std::wstring stemp = std::wstring(OpenTextureFile.getInterface().Filepath.begin(), OpenTextureFile.getInterface().Filepath.end());
    LPCWSTR sw = stemp.c_str();
    tmpText.Filepath = sw;
    mfTexture tmp;
    tmp.Init(tmpText);
    Materials.Init(tmp);
    OpenTextureFile.getInterface().Filepath.clear();
  }

  if (ImGui::CollapsingHeader("Mesh Textures"))
  {
    if (isMeshLoaded == false)
    {
      ImGui::Text("There are no textures.");
    }
    else
    {
      for (int i = 0; i < Materials.getInterface().Textures.size(); i++)
      {
        //ImGui::SameLine();
#ifdef mfDIRECTX
        if (ImGui::ImageButton(Materials.getInterface().Textures[i].getInterface().ResourceViewID, ImVec2(64, 64)))
        {
          texPos = i;
        }
#endif // mfDIRECTX

      }
    }
  }

  if (ImGui::Button("Exit"))
  {
    exit(1);
  }
  ImGui::End();

  ImGui::Begin("Security Camera");
  ImGui::SetWindowSize(ImVec2(200, 200), ImGuiSetCond_FirstUseEver);
  ImGui::SetWindowPos(ImVec2(2, 2), ImGuiSetCond_FirstUseEver);
  ImGui::Image(RenderToTexture.getInterface().RenderTargetToTexture.getInterface().ResourceViewID, ImVec2(200, 128));
  ImGui::End();
  Imgui.Render();
#endif // mfDIRECTX
  Swapchain.Present(0, 0);
}

void DrawToTexture(float t)
{
  CBChangesEveryFrame cb;

  cb.mWorld = XMMATRIX(
    2.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 2.0f, 0.0f, -1.0f,
    0.0f, 0.0f, 2.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  );
  cb.mWorld *= XMMatrixRotationY(t/*XM_PIDIV4 * 4*/);
  cb.vMeshColor = g_vMeshColor;
  ChangesEveryFrameBuffer.Update(&cb);
  /**
   * @brief : Set primitive topology
   */
  mfRenderManager::getSingleton().IASetPrimitiveTopology(mf_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  ViewBuffer.Render(0, 1);
  ProjBuffer.Render(1, 1);
  ChangesEveryFrameBuffer.Render(2, 1);
  mfRenderManager::getSingleton().PSSetConstantBuffers(2, 1, ChangesEveryFrameBuffer);
  VertexShader.Render();
  PixelShader.Render();
  Sampler.Render();
  Materials.Render(texPos);
  mfRenderManager::getSingleton().Render();

  if (isMeshLoaded)
  {
    mfRenderManager::getSingleton().DrawIndexed(LoadModel.getInterface().IndexSize, 0, 0);
  }

  //
  // Present our back buffer to our front buffer
  //
  Swapchain.Present(0, 0);
}