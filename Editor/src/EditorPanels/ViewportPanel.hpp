#pragma once

#include <glad/glad.h>
#include <stdint.h>

#include "EditorPanel.hpp"
#include "Camera.hpp"

#include "FrameBuffer.hpp"

#include "RGBA.hpp"

namespace HE::Editor {

class ViewportPanel : public EditorPanel {
 public:
  void Init() override {
    glm::vec4 vpColor = RGBA::rgba(50, 50, 50);
    glClearColor(vpColor.r, vpColor.g, vpColor.b, vpColor.a);
    m_FrameBuffer.Create(1, 1);
  }

  void PreRender(Camera& camera) {
    ImGui::Begin("Viewport");
    ImVec2 viewportSize = ImGui::GetContentRegionAvail();
    viewportSize.x = std::max(viewportSize.x, 1.0f);
    viewportSize.y = std::max(viewportSize.y, 1.0f);

    if (viewportSize.x != m_ViewportSize.x || viewportSize.y != m_ViewportSize.y) {
      m_ViewportSize = viewportSize;
      m_FrameBuffer.Resize(viewportSize.x, viewportSize.y);

      glViewport(0, 0, viewportSize.x, viewportSize.y);
      camera.Resize(viewportSize.x, viewportSize.y);
    }

    m_FrameBuffer.Bind();
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void PostRender() {
    m_FrameBuffer.Unbind();

    ImTextureID texID = (ImTextureID)(intptr_t)m_FrameBuffer.GetColorAttatchment();
    ImGui::Image(texID, m_ViewportSize, {0, 1}, {1, 0});
    ImGui::End();
  }

  void Render(EditorState& editorState) override {
  }

  ImVec2 GetViewportSize() {
    return m_ViewportSize;
  }

 private:
  HE::FrameBuffer m_FrameBuffer;
  ImVec2 m_ViewportSize = {1, 1};
};

}  // namespace HE::Editor
