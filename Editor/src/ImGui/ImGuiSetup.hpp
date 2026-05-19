#pragma once

#include <glad/glad.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "EditorSettings.hpp"

namespace HE::Editor {

class ImGuiSetup {
 public:
  void Init(GLFWwindow* window, EditorSettings& settings);
  void InitLayout();
  void BeginFrame();
  void BeginDockspace();
  void EndFrame();
  void Terminate();

 private:
  ImGuiID m_DockspaceID = 0;
  bool m_LayoutInitialized = false;
};

}  // namespace HE::Editor
