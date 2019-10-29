#include "mfImGui.h"
#include "mdDevice.h"
#include "mfDeviceContext.h"
#include "mfWindow.h"

mfImGui::mfImGui()
{
}


mfImGui::~mfImGui()
{
}

void mfImGui::Init(mfDevice _Device, mfDeviceContext _DevContext, mfWindow _window)
{
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
#ifdef mfDIRECTX
  ImGui_ImplWin32_Init(_window.getInterface().ID);
  ImGui_ImplDX11_Init(_Device.getInterface().ID, _DevContext.getInterface().ID);
#elif defined mfOPENGL
  mfOutputLOG("mfImGui", "Init()", "Imgui has been Initializated.");
#endif // mfDIRECTX
  ImGui::StyleColorsLight();
}

void mfImGui::Update()
{
#ifdef mfDIRECTX
  ImGui_ImplDX11_NewFrame();
  ImGui_ImplWin32_NewFrame();
#elif defined mfOPENGL
  mfOutputLOG("mfImGui", "Update()", "Update has been Initializated.");
#endif // mfDIRECTX

  ImGui::NewFrame();
}

void mfImGui::Render()
{
  ImGui::Render();

  // Render Draw Data
#ifdef mfDIRECTX
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
#elif defined mfOPENGL
  mfOutputLOG("mfImGui", "Render()", "Render has been Initializated.");
#endif // mfDIRECTX
}
