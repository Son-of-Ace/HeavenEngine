#pragma once

#include <glad/glad.h>

namespace HE {

class FrameBuffer {
 public:
  FrameBuffer() = default;
  FrameBuffer(uint32_t width, uint32_t height);
  ~FrameBuffer();

  FrameBuffer(const FrameBuffer&) = delete;
  FrameBuffer& operator=(const FrameBuffer&) = delete;

  FrameBuffer(FrameBuffer&& other) noexcept;
  FrameBuffer& operator=(FrameBuffer&& other) noexcept;

  void Resize(uint32_t width, uint32_t height);
  void Bind();
  void Unbind();

  GLuint GetTexture();

 private:
  GLuint m_ID = 0;
  GLuint m_Texture = 0;

  uint32_t m_Width;
  uint32_t m_Height;
};

}  // namespace HE
