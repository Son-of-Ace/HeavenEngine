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
  int vertexCount;

  VertexArray vao;
  std::unique_ptr<VertexBuffer> vbo;
  std::unique_ptr<IndexBuffer> ebo;
};
