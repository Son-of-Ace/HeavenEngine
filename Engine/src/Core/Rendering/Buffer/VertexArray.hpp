#pragma once

#include <glad/glad.h>

namespace HE {

class VertexArray {
 public:
  VertexArray();
  ~VertexArray();

  VertexArray(const VertexArray&) = delete;
  VertexArray& operator=(const VertexArray&) = delete;

  VertexArray(VertexArray&& other) noexcept;
  VertexArray& operator=(VertexArray&& other) noexcept;

  void Bind();
  void Unbind();
  void AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
  void EnableAttribute(GLuint index);

 private:
  GLuint m_ID;
};

}  // namespace HE
