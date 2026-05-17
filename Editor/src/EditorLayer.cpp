#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "EditorLayer.hpp"

namespace HE::Editor {

Transform quadTrans;
Material quadMat;

void DrawGrid(Renderer& renderer, const float aspect, const float size) {
  glm::vec4 gridColor = RGBA::rgba(80, 80, 80, 0.7f);

  float xExtent = aspect * size;
  float yExtent = size;
  float step = 1.0f;

  for (float x = -xExtent; x <= xExtent; x += step) {
    renderer.DrawLine({x, -yExtent, 0}, {x, yExtent, 0}, gridColor);
  }

  for (float y = -yExtent; y <= yExtent; y += step) {
    renderer.DrawLine({-xExtent, y, 0}, {xExtent, y, 0}, gridColor);
  }
}

EditorLayer::~EditorLayer() {
}

AppConfig EditorLayer::GetAppConfig() {
  return {"Heaven Editor", 2560, 1440};
}

void EditorLayer::OnStart(GLFWwindow* window) {
  m_EditorUI.Init(window);

  quadTrans.position = {0.0f, 0.0f, 0.0f};
  quadTrans.scale = {1.0f, 1.0f, 0.0f};

  quadMat.color = RGBA::rgba(255, 120, 0);
}

void EditorLayer::OnUpdate(float dt) {
}

void EditorLayer::OnRender(Renderer& renderer) {
  m_EditorUI.BeginFrame();

  m_EditorUI.RenderPanels();
  m_EditorUI.PreRenderViewport(m_EditorCamera);

  renderer.BeginFrame(m_EditorCamera.GetViewProjection());
  DrawGrid(renderer, m_EditorCamera.GetAspect(), m_EditorCamera.GetSize());
  renderer.EndFrame();

  m_EditorUI.PostRenderViewport();
  m_EditorUI.EndFrame();
}

void EditorLayer::OnShutdown() {
  m_EditorUI.Terminate();
}

}  // namespace HE::Editor
