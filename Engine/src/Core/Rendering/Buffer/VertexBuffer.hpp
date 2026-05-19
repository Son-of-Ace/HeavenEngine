#pragma once

#include <glad/glad.h>
#include <cstddef>

namespace HE {

class VertexBuffer {
 public:
  VertexBuffer(std::size_t size, GLenum usage);
  ~VertexBuffer();

  VertexBuffer(const VertexBuffer&) = delete;
  VertexBuffer& operator=(VertexBuffer&) = delete;

  VertexBuffer(VertexBuffer&& other) noexcept;
  VertexBuffer& operator=(VertexBuffer&& other) noexcept;

  void SetData(size_t size, const GLvoid* data);
  void Bind();
  void Unbind();

 private:
  GLuint m_ID;
  size_t m_Size;
  GLenum m_Usage;
};

}  // namespace HE
