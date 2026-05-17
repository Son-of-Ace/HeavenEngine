#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "Renderer2D.hpp"

namespace HE {

// clang-format off
Renderer2D::Renderer2D()
    : shader(HE_ENGINE_ROOT "shaders/Vertex.glsl", HE_ENGINE_ROOT "shaders/Fragment.glsl") {}
// clang-format on

// Rendering
void Renderer2D::BeginFrame(const glm::mat4& viewProjection) {
  m_ViewProjection = viewProjection;
  m_Sd.Clear();
}

void Renderer2D::EndFrame() {
  shader.Use();
  shader.SetMat4("u_ViewProjection", m_ViewProjection);

  glDisable(GL_SCISSOR_TEST);
  glDisable(GL_BLEND);

  m_vao.Bind();

  m_ebo->SetData(m_Sd.GetIndices().size() * sizeof(uint32_t), m_Sd.GetIndices().data());
  m_vbo->SetData(m_Sd.GetVertices().size() * sizeof(float), m_Sd.GetVertices().data());

  uint32_t triCount = m_Sd.GetTriangleIndexCount();
  uint32_t lineCount = m_Sd.GetIndices().size() - triCount;

  // Shapes
  glDrawElements(GL_TRIANGLES, triCount, GL_UNSIGNED_INT, (void*)0);

  // Lines
  glDrawElements(GL_LINES, lineCount, GL_UNSIGNED_INT, (void*)(triCount * sizeof(uint32_t)));
}

void Renderer2D::Init() {
  m_vao.Bind();

  // Reserve 40 kb's worth of indices and vertices data on the GPU
  m_ebo = std::make_unique<HE::ElementBuffer>(10000 * sizeof(uint32_t), GL_DYNAMIC_DRAW);
  m_ebo->Bind();

  m_vbo = std::make_unique<HE::VertexBuffer>(10000 * sizeof(float), GL_DYNAMIC_DRAW);
  m_vbo->Bind();

  // Position
  m_vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
  m_vao.EnableAttribute(0);

  // Color
  m_vao.AddAttribute(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
  m_vao.EnableAttribute(1);

  // UVs
  m_vao.AddAttribute(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
  m_vao.EnableAttribute(2);
}

void Renderer2D::DrawLine(glm::vec3 start, glm::vec3 end, glm::vec4 color) {
  m_Sd.DrawLine(start, end, color);
}

void Renderer2D::DrawQuad(const Transform& transform, const Material& material) {
  m_Sd.DrawQuad(transform, material);
}

}  // namespace HE
