#pragma once

#include <Application.hpp>
#include "EditorUI.hpp"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>

#include "Scene.hpp"

namespace HE::Editor {

class EditorLayer : public HE::Application {
 public:
  ~EditorLayer();
  AppConfig GetAppConfig() override;
  void OnStart(GLFWwindow* window) override;
  void OnUpdate(float dt) override;
  void OnRender(Renderer& renderer) override;
  void OnShutdown() override;

 private:
  HE::Scene m_RuntimeScene;
  HE::Scene m_EditorScene;
  HE::Scene m_ActiveScene;

  Camera m_EditorCamera{1, 1};
  EditorUI m_EditorUI;
};

}  // namespace HE::Editor
