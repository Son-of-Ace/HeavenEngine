#include <imgui.h>

#include "ImGuiSetup.hpp"

namespace HE::Editor {

void ImGuiSetup::Init(GLFWwindow* window, EditorSettings& settings) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  ImGuiStyle& style = ImGui::GetStyle();

  style.WindowPadding = ImVec2(0, 0);
  style.FramePadding = ImVec2(10.0f, 6.0f);
  style.WindowBorderSize = 0.0f;

  style.Colors[ImGuiCol_WindowBg] = settings.windowBGColor;
  style.Colors[ImGuiCol_MenuBarBg] = settings.menuBarColor;

  style.Colors[ImGuiCol_Tab] = settings.tabColor;
  style.Colors[ImGuiCol_TabSelected] = settings.selectedTabColor;
  style.Colors[ImGuiCol_TabDimmed] = settings.tabColor;
  style.Colors[ImGuiCol_TabDimmedSelected] = settings.tabColor;

  style.Colors[ImGuiCol_TabDimmedSelectedOverline] = settings.tabOverlineColor;
  style.Colors[ImGuiCol_TabSelectedOverline] = settings.tabOverlineColorSelected;

  style.Colors[ImGuiCol_TabHovered] = settings.tabHover;
  style.Colors[ImGuiCol_TitleBg] = settings.titleBg;
  style.Colors[ImGuiCol_TitleBgActive] = settings.titleBgSelected;

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

void ImGuiSetup::BeginFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGuiViewport* viewport = ImGui::GetMainViewport();

  ImGui::SetNextWindowPos(viewport->Pos);
  ImGui::SetNextWindowSize(viewport->Size);
  ImGui::SetNextWindowViewport(viewport->ID);

  // clang-format off
  ImGuiWindowFlags hostWindowFlags =
      ImGuiWindowFlags_MenuBar |
      ImGuiWindowFlags_NoDocking |
      ImGuiWindowFlags_NoTitleBar |
      ImGuiWindowFlags_NoCollapse |
      ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove |
      ImGuiWindowFlags_NoBringToFrontOnFocus |
      ImGuiWindowFlags_NoNavFocus |
      ImGuiWindowFlags_NoBackground;
  // clang-format on

  ImGui::Begin("DockSpaceWindow", nullptr, hostWindowFlags);
}

void ImGuiSetup::BeginDockspace() {
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() - ImGui::GetStyle().ItemSpacing.y);
  ImGuiID dockspaceID = ImGui::GetID("MainDockSpace");
  ImGui::DockSpace(dockspaceID, ImVec2(0, 0));
}

void ImGuiSetup::EndFrame() {
  ImGui::End();
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiSetup::Terminate() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

}  // namespace HE::Editor
