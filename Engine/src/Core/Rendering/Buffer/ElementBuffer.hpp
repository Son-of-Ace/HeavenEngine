#pragma once

#include <glad/glad.h>
#include <cstddef>

namespace HE {

class ElementBuffer {
 public:
  ElementBuffer(std::size_t size, GLenum usage);
  ~ElementBuffer();

  ElementBuffer(const ElementBuffer&) = delete;
  ElementBuffer& operator=(const ElementBuffer&) = delete;

  ElementBuffer(ElementBuffer&& other) noexcept;
  ElementBuffer& operator=(ElementBuffer&& other) noexcept;

  void SetData(size_t size, const GLvoid* data);
  void Bind();
  void Unbind();

 private:
  GLuint m_ID;
  size_t m_Size;
  GLenum m_Usage;
};

}  // namespace HE
