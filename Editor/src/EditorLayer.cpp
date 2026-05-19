#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "EditorLayer.hpp"

namespace HE::Editor {

Transform dirtTrans;
Transform grassTrans;

Material dirtMat;
Material grassMat;

void DrawGrid(Renderer& renderer, const float halfWidth, const float halfHeight, const glm::vec2& camPos) {
  Color gridColor = ColorFromRGB(80, 80, 80, 0.7f);

  float step = 1.0f;

  float left = camPos.x - halfWidth;
  float right = camPos.x + halfWidth;
  float bottom = camPos.y - halfHeight;
  float top = camPos.y + halfHeight;

  float startX = floor(left / step) * step;
  float startY = floor(bottom / step) * step;

  for (float x = startX; x <= right; x += step) {
    renderer.DrawLine({x, bottom, 0}, {x, top, 0}, gridColor);
  }

  for (float y = startY; y <= top; y += step) {
    renderer.DrawLine({left, y, 0}, {right, y, 0}, gridColor);
  }
}

EditorLayer::~EditorLayer() {
}

AppConfig EditorLayer::GetAppConfig() {
  return {"Heaven Editor", 2560, 1440};
}

void EditorLayer::OnStart(GLFWwindow* window) {
  m_EditorUI.Init(window);

  dirtTrans.position = {0.0f, -4.5f, 0.0f};
  dirtTrans.scale = {30.0f, 1.0f, 0.0f};

  grassTrans.position = {0.0f, -3.5f, 0.0f};
  grassTrans.scale = {30.0f, 1.0f, 0.0f};

  dirtMat.color = ColorFromRGB(80, 40, 0);
  grassMat.color = ColorFromRGB(31, 229, 20);
}

void EditorLayer::OnUpdate(float dt) {
}

void EditorLayer::OnRender(Renderer& renderer) {
  m_EditorUI.BeginFrame();
  m_EditorUI.RenderPanels();
  m_EditorUI.PreRenderViewport(m_EditorCamera);

  renderer.BeginFrame(m_EditorCamera.GetViewProjection());
  renderer.DrawQuad(dirtTrans, dirtMat);
  renderer.DrawQuad(grassTrans, grassMat);
  DrawGrid(renderer, m_EditorCamera.GetHalfWidth(), m_EditorCamera.GetHalfHeight(), m_EditorCamera.GetPosition());
  renderer.EndFrame();

  m_EditorUI.PostRenderViewport();
  m_EditorUI.EndFrame();
}

void EditorLayer::OnShutdown() {
  m_EditorUI.Terminate();
}

}  // namespace HE::Editor
