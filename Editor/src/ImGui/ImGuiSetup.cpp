#include <imgui.h>
#include <ImGuiConversions.hpp>
#include <imgui_internal.h>

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

  style.Colors[ImGuiCol_WindowBg] = ToImVec4(settings.windowBGColor);
  style.Colors[ImGuiCol_MenuBarBg] = ToImVec4(settings.menuBarColor);

  style.Colors[ImGuiCol_Tab] = ToImVec4(settings.tabColor);
  style.Colors[ImGuiCol_TabSelected] = ToImVec4(settings.selectedTabColor);
  style.Colors[ImGuiCol_TabDimmed] = ToImVec4(settings.tabColor);
  style.Colors[ImGuiCol_TabDimmedSelected] = ToImVec4(settings.tabColor);

  style.Colors[ImGuiCol_TabDimmedSelectedOverline] = ToImVec4(settings.tabOverlineColor);
  style.Colors[ImGuiCol_TabSelectedOverline] = ToImVec4(settings.tabOverlineSelectedColor);

  style.Colors[ImGuiCol_TabHovered] = ToImVec4(settings.tabHoverColor);
  style.Colors[ImGuiCol_TitleBg] = ToImVec4(settings.titleBgColor);
  style.Colors[ImGuiCol_TitleBgActive] = ToImVec4(settings.titleBgSelectedColor);

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

void ImGuiSetup::InitLayout() {
  ImGui::DockBuilderRemoveNode(m_DockspaceID);
  ImGui::DockBuilderAddNode(m_DockspaceID, ImGuiDockNodeFlags_DockSpace);
  ImGui::DockBuilderSetNodeSize(m_DockspaceID, ImGui::GetMainViewport()->Size);

  ImGuiID left, right, bottom, center;
  ImGui::DockBuilderSplitNode(m_DockspaceID, ImGuiDir_Left, 0.2f, &left, &center);
  ImGui::DockBuilderSplitNode(center, ImGuiDir_Right, 0.25f, &right, &center);
  ImGui::DockBuilderSplitNode(center, ImGuiDir_Down, 0.3f, &bottom, &center);

  ImGui::DockBuilderDockWindow("Scene Hierarchy", left);
  ImGui::DockBuilderDockWindow("Viewport", center);
  ImGui::DockBuilderDockWindow("Inspector", right);
  ImGui::DockBuilderDockWindow("Console", bottom);
  ImGui::DockBuilderDockWindow("Project", bottom);

  ImGui::DockBuilderFinish(m_DockspaceID);
}

void ImGuiSetup::BeginDockspace() {
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() - ImGui::GetStyle().ItemSpacing.y);
  m_DockspaceID = ImGui::GetID("MainDockSpace");

  if (!m_LayoutInitialized) {
    m_LayoutInitialized = true;
    InitLayout();
  }

  ImGui::DockSpace(m_DockspaceID, ImVec2(0, 0));
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
