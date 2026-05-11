#pragma once

#include <cstdint>
#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>
#include <vector>

#include "../Shader/Shader.hpp"
#include "../Mesh/Mesh.hpp"

class Renderer2D {
 public:
  // Setup
  Renderer2D();

  void Init();
  void Render();

  // Primitive Shapes
  void DrawQuad(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color);
  void DrawTriangle(const glm::vec2& pos, const glm::vec2& size, const glm::vec4& color);

  // TODO:
  // Collects data on a CPU buffer. DOES NOT DRAW ANYTHING!
  void BeginFrame();
  // This is what actually uses those buffers to draw vertices on the GPU!
  void EndFrame();

  // Example:
  /*
    Renderer2D.BeginFrame();

    Renderer2D.DrawQuad();
    Renderer2D.DrawQuad();
    Renderer2D.DrawQuad();

    Renderer2D.EndFrame();
  */

 private:
  Shader fragment;

  VertexArray m_vao;
  std::unique_ptr<VertexBuffer> m_vbo;
  std::unique_ptr<IndexBuffer> m_ebo;

  std::vector<float> vertices;
  std::vector<float> indices;
  uint32_t m_offset;
};
