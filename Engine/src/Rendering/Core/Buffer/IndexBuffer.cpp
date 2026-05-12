#include "IndexBuffer.hpp"
#include <cstddef>

namespace HE::Core {

IndexBuffer::IndexBuffer(size_t size, GLenum usage) : m_size(size), m_usage(usage) {
  glGenBuffers(1, &m_id);
}

IndexBuffer::~IndexBuffer() {
  glDeleteBuffers(1, &m_id);
}

void IndexBuffer::Bind(GLenum target) {
  glBindBuffer(target, m_id);
}

void IndexBuffer::Unbind(GLenum target) {
  glBindBuffer(target, 0);
}

void IndexBuffer::SetData(GLenum target, size_t size, const GLvoid* data) {
  glBufferData(target, size, data, m_usage);
}

}  // namespace HE::Core
