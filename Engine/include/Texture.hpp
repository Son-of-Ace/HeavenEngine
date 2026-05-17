#pragma once

#include <glad/glad.h>
#include <string>
#include <cstdint>

namespace HE {

class Texture {
 public:
  Texture() = default;
  Texture(const std::string& path);
  ~Texture();

  void Bind(uint32_t slot = 0) const;
  void Unbind() const;

  GLuint GetID() const {
    return m_ID;
  }

  int GetWidth() const {
    return m_Width;
  }

  int GetHeight() const {
    return m_Height;
  }

 private:
  GLuint m_ID = 0;
  int m_Width = 0;
  int m_Height = 0;
};

}  // namespace HE
