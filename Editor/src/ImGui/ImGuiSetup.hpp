#pragma once

#include <glad/glad.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "EditorSettings.hpp"

namespace HE::Editor {

class ImGuiSetup {
 public:
  void Init(GLFWwindow* window, EditorSettings& settings);
  void BeginFrame();
  void BeginDockspace();
  void EndFrame();
  void Terminate();
};

}  // namespace HE::Editor
