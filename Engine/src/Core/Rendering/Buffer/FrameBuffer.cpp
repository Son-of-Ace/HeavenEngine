#include "FrameBuffer.hpp"

#include <stdexcept>

namespace HE {

FrameBuffer::FrameBuffer(uint32_t width, uint32_t height) {
  m_Width = width;
  m_Height = height;

  glGenFramebuffers(1, &m_ID);
  glBindFramebuffer(GL_FRAMEBUFFER, m_ID);

  glGenTextures(1, &m_Texture);
  glBindTexture(GL_TEXTURE_2D, m_Texture);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    throw std::runtime_error("Framebuffer incomplete!\n");
  }
}

FrameBuffer::~FrameBuffer() {
  if (m_Texture) {
    glDeleteTextures(1, &m_Texture);
  }

  if (m_ID) {
    glDeleteFramebuffers(1, &m_ID);
  }
}

FrameBuffer::FrameBuffer(FrameBuffer&& other) noexcept {
  m_ID = other.m_ID;
  m_Texture = other.m_Texture;
  m_Width = other.m_Width;
  m_Height = other.m_Height;

  other.m_ID = 0;
  other.m_Texture = 0;
  other.m_Width = 0;
  other.m_Height = 0;
}

FrameBuffer& FrameBuffer::operator=(FrameBuffer&& other) noexcept {
  if (this != &other) {
    if (m_Texture) {
      glDeleteTextures(1, &m_Texture);
    }

    if (m_ID) {
      glDeleteFramebuffers(1, &m_ID);
    }

    m_ID = other.m_ID;
    m_Texture = other.m_Texture;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    other.m_ID = 0;
    other.m_Texture = 0;
    other.m_Width = 0;
    other.m_Height = 0;
  }

  return *this;
}

void FrameBuffer::Resize(uint32_t width, uint32_t height) {
  if (m_ID == 0) return;
  if (width == m_Width && height == m_Height) return;
  if (width == 0 || height == 0) return;

  m_Width = width;
  m_Height = height;

  glBindTexture(GL_TEXTURE_2D, m_Texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void FrameBuffer::Bind() {
  glBindFramebuffer(GL_FRAMEBUFFER, m_ID);
}

void FrameBuffer::Unbind() {
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLuint FrameBuffer::GetTexture() {
  return m_Texture;
}

}  // namespace HE
