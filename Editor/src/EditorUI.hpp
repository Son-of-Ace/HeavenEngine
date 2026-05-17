#pragma once

#include <glad/glad.h>

#include "imgui.h"

#include "EditorState.hpp"
#include "EditorSettings.hpp"

#include "EditorPanels/InspectorPanel.hpp"
#include "EditorPanels/ProjectPanel.hpp"
#include "EditorPanels/SceneHierarchyPanel.hpp"
#include "EditorPanels/ToolbarPanel.hpp"
#include "EditorPanels/ConsolePanel.hpp"
#include "EditorPanels/MenubarPanel.hpp"
#include "EditorPanels/ViewportPanel.hpp"

#include "ImGui/ImGuiSetup.hpp"

namespace HE::Editor {

class EditorUI {
 public:
  void Init(GLFWwindow* window);
  void BeginFrame();
  void RenderPanels();
  void EndFrame();
  void Terminate();

  void PreRenderViewport(Camera& camera);
  void PostRenderViewport();
  ImVec2 GetViewportSize();

 private:
  EditorState m_EditorState;
  EditorSettings m_EditorSettings;

  // Panels
  InspectorPanel m_InspectorPanel;
  ProjectPanel m_ProjectPanel;
  SceneHierarchyPanel m_SceneHierarchyPanel;
  ToolbarPanel m_ToolbarPanel;
  ConsolePanel m_ConsolePanel;
  MenubarPanel m_MenubarPanel;
  ViewportPanel m_ViewportPanel;

  // ImGui
  ImGuiSetup m_ImSetup;

  GLuint m_ViewportTexture;
  ImVec2 m_ViewportSize;
};

}  // namespace HE::Editor
