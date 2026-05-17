#include "VertexBuffer.hpp"

namespace HE {

VertexBuffer::VertexBuffer(size_t size, GLenum usage) : m_size(size), m_usage(usage) {
  glGenBuffers(1, &m_id);
}

VertexBuffer::~VertexBuffer() {
  glDeleteBuffers(1, &m_id);
}

void VertexBuffer::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetData(size_t size, const GLvoid* data) {
  glBufferData(GL_ARRAY_BUFFER, size, data, m_usage);
}

}  // namespace HE
