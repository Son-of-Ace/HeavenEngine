#include "FrameBuffer.hpp"

#include <stdexcept>

namespace HE {

void FrameBuffer::Create(uint32_t width, uint32_t height) {
  m_Width = width;
  m_Height = height;

  glGenFramebuffers(1, &m_FBO);
  glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

  glGenTextures(1, &m_ColorAttatchment);
  glBindTexture(GL_TEXTURE_2D, m_ColorAttatchment);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttatchment, 0);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    throw std::runtime_error("Framebuffer incomplete!\n");
  }

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::Resize(uint32_t width, uint32_t height) {
  if (m_FBO == 0) return;
  if (width == m_Width && height == m_Height) return;
  if (width == 0 || height == 0) return;

  m_Width = width;
  m_Height = height;

  glBindTexture(GL_TEXTURE_2D, m_ColorAttatchment);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void FrameBuffer::Bind() {
  glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
}

void FrameBuffer::Unbind() {
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint FrameBuffer::GetColorAttatchment() {
  return m_ColorAttatchment;
}

}  // namespace HE
