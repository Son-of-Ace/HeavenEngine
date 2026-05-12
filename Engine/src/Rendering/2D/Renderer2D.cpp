#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <glm/trigonometric.hpp>
#include <memory>

#include "Renderer2D.hpp"
#include "Drawing/ShapeDrawer2D.hpp"

#include "Utils/RGB.hpp"
#include "Transform/Transform.hpp"

using namespace HeavenEngine::General::Transform;

namespace HeavenEngine::Rendering::Engine2D {

// clang-format off
Renderer2D::Renderer2D()
    : fragment("shaders/Vertex.glsl", "shaders/Fragment.glsl") {}
// clang-format on

ShapeDrawer sd;

// Transforms
Transform quadTransform1;
Material quadMat1;

Transform quadTransform2;
Material quadMat2;

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
  m_ebo = std::make_unique<IndexBuffer>(10000 * sizeof(uint32_t), GL_DYNAMIC_DRAW);
  m_ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);

  m_vbo = std::make_unique<VertexBuffer>(10000 * sizeof(float), GL_DYNAMIC_DRAW);
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

  // Transforms
  quadTransform1.position = {-0.5f, 0.0f, 0.0f};
  quadTransform1.rotation = {glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)};
  quadTransform1.scale = {1.0f, 2.0f, 0.0f};

  quadMat1.color = RGB::rgb(0, 123, 255);
  quadMat1.textureID = 0;

  quadTransform2.position = {0.5f, 0.0f, 0.0f};
  quadTransform2.rotation = {glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)};
  quadTransform2.scale = {1.0f, 2.0f, 0.0f};

  quadMat2.color = RGB::rgb(157, 0, 255);
  quadMat2.textureID = 0;
}

void Renderer2D::Render() {
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  BeginFrame();

  sd.DrawQuad(quadTransform1, quadMat1);
  sd.DrawQuad(quadTransform2, quadMat2);

  EndFrame();
}

}  // namespace HeavenEngine::Rendering::Engine2D
