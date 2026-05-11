#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>
#include <print>

#include "Renderer2D.hpp"
#include "../../Utils/RGB.hpp"

// clang-format off
Renderer2D::Renderer2D()
    : fragment("../Engine/shaders/Vertex.glsl", "../Engine/shaders/Fragment.glsl") {}
// clang-format on

// Drawing Shapes
void Renderer2D::DrawQuad(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) {
  fragment.Use();
  fragment.SetColor(color);

  uint32_t offset = vertices.size() / 3;
  
  // Top Left
  vertices.push_back(pos.x - size.x * 0.5f);
  vertices.push_back(pos.y + size.y * 0.5f);
  vertices.push_back(0.0f);

  // Top Right
  vertices.push_back(pos.x + size.x * 0.5f);
  vertices.push_back(pos.y + size.y * 0.5f);
  vertices.push_back(0.0f);

  // Bottom Right
  vertices.push_back(pos.x + size.x * 0.5f);
  vertices.push_back(pos.y - size.y * 0.5f);
  vertices.push_back(0.0f);

  // Bottom Left
  vertices.push_back(pos.x - size.x * 0.5f);
  vertices.push_back(pos.y - size.y * 0.5f);
  vertices.push_back(0.0f);

  // Indices
  indices.push_back(offset + 0);
  indices.push_back(offset + 1);
  indices.push_back(offset + 2);

  indices.push_back(offset + 1);
  indices.push_back(offset + 2);
  indices.push_back(offset + 3);
}

void Renderer2D::DrawTriangle(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color) {
  fragment.Use();
  fragment.SetColor(color);

  uint32_t offset = vertices.size() / 3;
  
  // Top
  vertices.push_back(pos.x);
  vertices.push_back(pos.y + size.y);
  vertices.push_back(0.0f);

  // Bottom Left
  vertices.push_back(pos.x - size.x * 0.5f);
  vertices.push_back(pos.y);
  vertices.push_back(0.0f);

  // Bottom Right
  vertices.push_back(pos.x + size.x * 0.5f);
  vertices.push_back(pos.y);
  vertices.push_back(0.0f);

  indices.push_back(offset + 0);
  indices.push_back(offset + 1);
  indices.push_back(offset + 2);
}

// Rendering
void Renderer2D::BeginFrame() {
  vertices.clear();
  indices.clear();
}

void Renderer2D::EndFrame() {
  fragment.Use();

  m_vao.Bind();

  m_ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);
  m_ebo->SetData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data());

  m_vbo->Bind(GL_ARRAY_BUFFER);
  m_vbo->SetData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data());

  glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, (void*)0);
}

void Renderer2D::Init() {
    m_vao.Bind();

    m_ebo = std::make_unique<IndexBuffer>(10000 * sizeof(uint32_t), GL_DYNAMIC_DRAW);
    m_ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);

    m_vbo = std::make_unique<VertexBuffer>(10000 * sizeof(float), GL_DYNAMIC_DRAW);
    m_vbo->Bind(GL_ARRAY_BUFFER);

    m_vao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    m_vao.EnableAttribute(0);
}

void Renderer2D::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  BeginFrame();

  DrawTriangle({0, 0}, {1, 1}, RGB::rgb(255, 0, 0));

  EndFrame();
}
