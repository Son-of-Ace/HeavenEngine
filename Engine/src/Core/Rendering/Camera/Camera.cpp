#include "Camera.hpp"

#include "glad/glad.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

Camera::Camera(const GLsizei width, const GLsizei height) {
  Resize(width, height);
}

void Camera::Resize(const GLsizei width, const GLsizei height, const float size) {
  m_Width = width;
  m_Height = height;
  m_Size = size;

  const float aspect = (float)width / (float)height;
  m_Aspect = aspect;

  if (aspect >= 1) {
    m_HalfWidth = size * aspect;
    m_HalfHeight = size;
  } else {
    m_HalfWidth = size;
    m_HalfHeight = size / aspect;
  }

  m_Projection = glm::ortho(-m_HalfWidth, m_HalfWidth, -m_HalfHeight, m_HalfHeight);
}

void Camera::Zoom(float scrollDelta) {
  m_Size += -scrollDelta * m_ZoomSpeed;
  m_Size = glm::clamp(m_Size, m_MinZoom, m_MaxZoom);
  Resize(m_Width, m_Height, m_Size);
}

void Camera::Move(float deltaX, float deltaY) {
  float t = (m_Size - m_MinZoom) / (m_MaxZoom - m_MinZoom);
  float sensitivity = glm::clamp(t, 0.5f, 10.0f);

  m_Position += glm::vec2(deltaX, deltaY) * sensitivity;
}

void Camera::SetPosition(const glm::vec2& pos) {
  m_Position = pos;
}

glm::mat4 Camera::GetViewProjection() const {
  glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-m_Position, 0.0f));
  return m_Projection * view;
}

const float Camera::GetAspect() const {
  return m_Aspect;
}

const float Camera::GetSize() const {
  return m_Size;
}

const float Camera::GetHalfWidth() const {
  return m_HalfWidth;
}

const float Camera::GetHalfHeight() const {
  return m_HalfHeight;
}

const float Camera::GetPanSpeed() const {
  return m_PanSpeed;
}

glm::vec2 Camera::GetPosition() const {
  return m_Position;
}
