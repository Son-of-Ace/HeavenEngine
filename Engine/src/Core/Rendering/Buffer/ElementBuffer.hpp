#pragma once

#include <glad/glad.h>
#include <cstddef>

namespace HE {

class ElementBuffer {
 public:
  ElementBuffer(std::size_t size, GLenum usage);
  ~ElementBuffer();

  void SetData(size_t size, const GLvoid* data);
  void Bind();
  void Unbind();

 private:
  GLuint m_id;
  size_t m_size;
  GLenum m_usage;
};

}  // namespace HE
