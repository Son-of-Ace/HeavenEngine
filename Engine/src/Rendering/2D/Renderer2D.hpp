#pragma once

#include <memory>

#include "Shader/Shader.hpp"
#include "Components/Transform.hpp"
#include "Material/Material.hpp"

#include "Buffer/VertexArray.hpp"
#include "Buffer/VertexBuffer.hpp"
#include "Buffer/IndexBuffer.hpp"

namespace HE::Renderer {

class Renderer2D {
 public:
  // Setup
  Renderer2D();

  void Init();

  void BeginFrame();
  void EndFrame();

  void SubmitQuad(HE::Core::Transform& transform, HE::Core::Material& material);

 private:
  HE::Core::Shader fragment;

  HE::Core::VertexArray m_vao;
  std::unique_ptr<HE::Core::VertexBuffer> m_vbo;
  std::unique_ptr<HE::Core::IndexBuffer> m_ebo;
};

}  // namespace HE::Renderer
