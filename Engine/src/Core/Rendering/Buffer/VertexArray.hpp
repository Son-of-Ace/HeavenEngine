#pragma once

#include <glad/glad.h>

namespace HE {

class VertexArray {
 public:
  VertexArray();
  ~VertexArray();

  void Bind();
  void Unbind();
  void AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
  void EnableAttribute(GLuint index);

 private:
  GLuint m_id;
};

}  // namespace HE
