#include "VertexBuffer.hpp"

namespace HE::Core {

VertexBuffer::VertexBuffer(size_t size, GLenum usage) : m_size(size), m_usage(usage) {
  glGenBuffers(1, &m_id);
}

VertexBuffer::~VertexBuffer() {
  glDeleteBuffers(1, &m_id);
}

void VertexBuffer::Bind(GLenum target) {
  glBindBuffer(target, m_id);
}

void VertexBuffer::Unbind(GLenum target) {
  glBindBuffer(target, 0);
}

void VertexBuffer::SetData(GLenum target, size_t size, const GLvoid* data) {
  glBufferData(target, size, data, m_usage);
}

}  // namespace HE::Core
