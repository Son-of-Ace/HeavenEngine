#pragma once

#include <memory>

#include "Shader/Shader.hpp"

#include "Buffer/VertexArray.hpp"
#include "Buffer/VertexBuffer.hpp"
#include "Buffer/IndexBuffer.hpp"

using namespace HeavenEngine::General::Buffer;

namespace HeavenEngine::Rendering::Engine2D {

class Renderer2D {
 public:
  // Setup
  Renderer2D();

  void Init();
  void Render();

  void BeginFrame();
  void EndFrame();

 private:
  Shader fragment;

  VertexArray m_vao;
  std::unique_ptr<VertexBuffer> m_vbo;
  std::unique_ptr<IndexBuffer> m_ebo;
};

}  // namespace HeavenEngine::Rendering::Engine2D
