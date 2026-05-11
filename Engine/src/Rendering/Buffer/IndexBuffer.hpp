#pragma once

#include <glad/glad.h>
#include <cstddef>

class IndexBuffer {
 public:
  IndexBuffer(std::size_t size, GLenum usage);
  ~IndexBuffer();

  void SetData(GLenum target, size_t size, const GLvoid* data);
  void Bind(GLenum target);
  void Unbind(GLenum target);

 private:
  GLuint m_id;
  size_t m_size;
  GLenum m_usage;
};
