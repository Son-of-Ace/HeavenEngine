#include "Camera.hpp"

#include "glad/glad.h"
#include "glm/ext/matrix_clip_space.hpp"

Camera::Camera(const GLsizei width, const GLsizei height) {
  Resize(width, height);
}

glm::mat4 Camera::GetViewProjection() const {
  return m_Projection;
}

const float Camera::GetAspect() const {
  return m_Aspect;
}

const float Camera::GetSize() const {
  return m_Size;
}

void Camera::Resize(const GLsizei width, const GLsizei height, const float size) {
  m_Width = width;
  m_Height = height;
  m_Size = size;

  const float aspect = (float)width / (float)height;
  m_Aspect = aspect;

  m_Projection = glm::ortho(-aspect * size, aspect * size, -size, size);
}
