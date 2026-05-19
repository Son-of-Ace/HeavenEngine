#include "VertexArray.hpp"

namespace HE {

VertexArray::VertexArray() {
  glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray() {
  if (m_ID) {
    glDeleteVertexArrays(1, &m_ID);
  }
}

VertexArray::VertexArray(VertexArray&& other) noexcept {
  m_ID = other.m_ID;

  other.m_ID = 0;
}

VertexArray& VertexArray::operator=(VertexArray&& other) noexcept {
  if (this != &other) {
    if (m_ID) {
      glDeleteVertexArrays(1, &m_ID);
    }

    m_ID = other.m_ID;

    other.m_ID = 0;
  }

  return *this;
}

void VertexArray::Bind() {
  glBindVertexArray(m_ID);
}

void VertexArray::AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
                               const GLvoid* pointer) {
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void VertexArray::EnableAttribute(GLuint index) {
  glEnableVertexAttribArray(index);
}

void VertexArray::Unbind() {
  glBindVertexArray(0);
}

}  // namespace HE
