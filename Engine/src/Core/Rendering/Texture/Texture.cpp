#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <stdexcept>
#include <print>

namespace HE {

Texture::Texture(const std::string& path) {
  if (path.empty()) {
    return;
  }

  std::print("Loading texture from path: {}", path);

  stbi_set_flip_vertically_on_load(true);

  int channels;
  unsigned char* data = stbi_load(path.c_str(), &m_Width, &m_Height, &channels, STBI_rgb_alpha);
  if (!data) {
    throw std::runtime_error("Failed to load texture: " + path);
  }

  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_2D, m_ID);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  stbi_image_free(data);
  std::print("Texture loaded: ID={} W={} H={} CH={}\n", m_ID, m_Width, m_Height, channels);
}

Texture::~Texture() {
  if (m_ID) glDeleteTextures(1, &m_ID);
}

Texture::Texture(Texture&& other) noexcept {
  m_ID = other.m_ID;
  m_Width = other.m_Width;
  m_Height = other.m_Height;

  other.m_ID = 0;
}

Texture& Texture::operator=(Texture&& other) noexcept {
  if (this != &other) {
    if (m_ID) {
      glDeleteTextures(1, &m_ID);
    }

    m_ID = other.m_ID;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    other.m_ID = 0;
  }

  return *this;
}

void Texture::Bind(uint32_t slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::Unbind() const {
  glBindTexture(GL_TEXTURE_2D, 0);
}

}  // namespace HE
