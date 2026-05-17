#include "ElementBuffer.hpp"

namespace HE {

ElementBuffer::ElementBuffer(size_t size, GLenum usage) : m_size(size), m_usage(usage) {
  glGenBuffers(1, &m_id);
}

ElementBuffer::~ElementBuffer() {
  glDeleteBuffers(1, &m_id);
}

void ElementBuffer::Bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void ElementBuffer::Unbind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::SetData(size_t size, const GLvoid* data) {
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, m_usage);
}

}  // namespace HE
