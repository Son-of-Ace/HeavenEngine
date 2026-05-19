#include "VertexBuffer.hpp"

namespace HE {

VertexBuffer::VertexBuffer(size_t size, GLenum usage) : m_Size(size), m_Usage(usage) {
  glGenBuffers(1, &m_ID);
}

VertexBuffer::~VertexBuffer() {
  if (m_ID) {
    glDeleteBuffers(1, &m_ID);
  }
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept {
  m_ID = other.m_ID;
  m_Size = other.m_Size;
  m_Usage = other.m_Usage;

  other.m_ID = 0;
  other.m_Size = 0;
  other.m_Usage = 0;
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
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

void VertexBuffer::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetData(size_t size, const GLvoid* data) {
  glBufferData(GL_ARRAY_BUFFER, size, data, m_Usage);
}

}  // namespace HE
