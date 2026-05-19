#include "ElementBuffer.hpp"

namespace HE {

ElementBuffer::ElementBuffer(size_t size, GLenum usage) {
  m_Size = size;
  m_Usage = usage;

  glGenBuffers(1, &m_ID);
}

ElementBuffer::~ElementBuffer() {
  if (m_ID) {
    glDeleteBuffers(1, &m_ID);
  }
}

ElementBuffer::ElementBuffer(ElementBuffer&& other) noexcept {
  m_ID = other.m_ID;
  m_Size = other.m_Size;
  m_Usage = other.m_Usage;

  other.m_ID = 0;
  other.m_Size = 0;
  other.m_Usage = 0;
}

ElementBuffer& ElementBuffer::operator=(ElementBuffer&& other) noexcept {
  if (this != &other) {
    if (m_ID) {
      glDeleteBuffers(1, &m_ID);
    }

    m_ID = other.m_ID;
    m_Size = other.m_Size;
    m_Usage = other.m_Usage;

    other.m_ID = 0;
    other.m_Size = 0;
    other.m_Usage = 0;
  }

  return *this;
}

void ElementBuffer::Bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ElementBuffer::Unbind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::SetData(size_t size, const GLvoid* data) {
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, m_Usage);
}

}  // namespace HE
