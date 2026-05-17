#pragma once

#include <memory>

#include "Shader.hpp"
#include "Core/Rendering/2D/ShapeDrawer2D.hpp"

#include "Renderer.hpp"

#include "Core/Rendering/Buffer/VertexArray.hpp"
#include "Core/Rendering/Buffer/VertexBuffer.hpp"
#include "Core/Rendering/Buffer/ElementBuffer.hpp"

#include <glm/ext/matrix_float4x4.hpp>

namespace HE {

class Renderer2D : public Renderer {
 public:
  // Setup
  Renderer2D();
  void Init();

  void BeginFrame(const glm::mat4& viewProjection) override;
  void EndFrame() override;
  void DrawLine(glm::vec3 start, glm::vec3 end, glm::vec4 color) override;
  void DrawQuad(const Transform& transform, const Material& material) override;

 private:
  HE::Shader shader;
  ShapeDrawer m_Sd;

  HE::VertexArray m_vao;
  std::unique_ptr<HE::VertexBuffer> m_vbo;
  std::unique_ptr<HE::ElementBuffer> m_ebo;

  glm::mat4 m_ViewProjection{};
};

}  // namespace HE
