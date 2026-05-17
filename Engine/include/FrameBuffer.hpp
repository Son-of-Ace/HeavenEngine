#pragma once

#include <glad/glad.h>

namespace HE {

class FrameBuffer {
 public:
  void Create(uint32_t width, uint32_t height);
  void Resize(uint32_t width, uint32_t height);
  void Bind();
  void Unbind();

  GLuint GetColorAttatchment();

 private:
  GLuint m_FBO = 0;
  GLuint m_ColorAttatchment = 0;

  uint32_t m_Width;
  uint32_t m_Height;
};

}  // namespace HE
