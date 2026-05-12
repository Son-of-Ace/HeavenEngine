#pragma once

#include <glad/glad.h>
#include <cstddef>

namespace HeavenEngine::General::Buffer {

class VertexBuffer {
 public:
  VertexBuffer(std::size_t size, GLenum usage);
  ~VertexBuffer();

  void SetData(GLenum target, size_t size, const GLvoid* data);
  void Bind(GLenum target);
  void Unbind(GLenum target);

 private:
  GLuint m_id;
  size_t m_size;
  GLenum m_usage;
};

}  // namespace HeavenEngine::General::Buffer
