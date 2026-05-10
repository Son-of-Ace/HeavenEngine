#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#include "../Buffer/VertexArray.hpp"
#include "../Buffer/VertexBuffer.hpp"
#include "../Buffer/IndexBuffer.hpp"

class Mesh {
 public:
  Mesh(const float* vertices, size_t vertexBufferSize, const uint32_t* indices = nullptr, size_t indexCount = 0);
  void Draw();

 private:
  int m_vertexCount;
  int m_indexCount;

  VertexArray m_vao;
  std::unique_ptr<VertexBuffer> m_vbo;
  std::unique_ptr<IndexBuffer> m_ebo;
};
