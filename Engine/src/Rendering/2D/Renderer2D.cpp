#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <glm/trigonometric.hpp>
#include <memory>

#include "Renderer2D.hpp"
#include "Material/Material.hpp"
#include "ShapeDrawer2D.hpp"

#include "Utils/RGB.hpp"
#include "Components/Transform.hpp"

namespace HE::Renderer {

// clang-format off
Renderer2D::Renderer2D()
    : fragment("Engine/shaders/Vertex.glsl", "Engine/shaders/Fragment.glsl") {}
// clang-format on

ShapeDrawer sd;

// Rendering
void Renderer2D::BeginFrame() {
  sd.GetVertices().clear();
  sd.GetIndices().clear();
}

void Renderer2D::EndFrame() {
  fragment.Use();

  m_vao.Bind();

  m_ebo->SetData(GL_ELEMENT_ARRAY_BUFFER, sd.GetIndices().size() * sizeof(uint32_t), sd.GetIndices().data());
  m_vbo->SetData(GL_ARRAY_BUFFER, sd.GetVertices().size() * sizeof(float), sd.GetVertices().data());

  glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(sd.GetIndices().size()), GL_UNSIGNED_INT, (void*)0);
}

void Renderer2D::Init() {
  m_vao.Bind();

  // Reserve 40 kb's worth of indice and vertice data on the GPU
  m_ebo = std::make_unique<HE::Core::IndexBuffer>(10000 * sizeof(uint32_t), GL_DYNAMIC_DRAW);
  m_ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);

  m_vbo = std::make_unique<HE::Core::VertexBuffer>(10000 * sizeof(float), GL_DYNAMIC_DRAW);
  m_vbo->Bind(GL_ARRAY_BUFFER);

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

// Test (Temporary)
void Renderer2D::SubmitQuad(HE::Core::Transform& transform, HE::Core::Material& material) {
  sd.DrawQuad(transform, material);
}

}  // namespace HE::Renderer
