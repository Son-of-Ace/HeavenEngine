#include "VertexArray.hpp"

VertexArray::VertexArray() { glGenVertexArrays(1, &m_id); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &m_id); }

void VertexArray::Bind() { glBindVertexArray(m_id); }

void VertexArray::AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
                               const GLvoid* pointer) {
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void VertexArray::EnableAttribute(GLuint index) { glEnableVertexAttribArray(index); }

void VertexArray::Unbind() { glBindVertexArray(0); }
