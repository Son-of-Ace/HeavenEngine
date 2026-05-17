#include "EditorUI.hpp"

namespace HE::Editor {

void EditorUI::Init(GLFWwindow* window) {
  m_ImSetup.Init(window, m_EditorSettings);

  m_InspectorPanel.Init();
  m_ProjectPanel.Init();
  m_SceneHierarchyPanel.Init();
  m_ConsolePanel.Init();
  m_MenubarPanel.Init();
  m_ViewportPanel.Init();
  m_ToolbarPanel.Init();
}

void EditorUI::BeginFrame() {
  m_ImSetup.BeginFrame();
}

void EditorUI::RenderPanels() {
  m_MenubarPanel.Render(m_EditorState);
  m_ToolbarPanel.Render(m_EditorState);

  m_ImSetup.BeginDockspace();

  m_InspectorPanel.Render(m_EditorState);
  m_ProjectPanel.Render(m_EditorState);
  m_SceneHierarchyPanel.Render(m_EditorState);
  m_ConsolePanel.Render(m_EditorState);
}

void EditorUI::EndFrame() {
  m_ImSetup.EndFrame();
}

void EditorUI::PreRenderViewport(Camera& camera) {
  m_ViewportPanel.PreRender(camera);
}

void EditorUI::PostRenderViewport() {
  m_ViewportPanel.PostRender();
}

ImVec2 EditorUI::GetViewportSize() {
  return m_ViewportPanel.GetViewportSize();
}

void EditorUI::Terminate() {
  m_ImSetup.Terminate();
}

}  // namespace HE::Editor
