#pragma once

#include <memory>

#include "../General/Shader/Shader.hpp"

#include "../General/Buffer/VertexArray.hpp"
#include "../General/Buffer/VertexBuffer.hpp"
#include "../General/Buffer/IndexBuffer.hpp"

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
