#pragma once

#include "glad/glad.h"

#include <glm/ext/matrix_float4x4.hpp>

class Camera {
 public:
  Camera(GLsizei width, GLsizei height);
  void Resize(GLsizei width, GLsizei height, const float size = 5.0f);
  void Zoom(float scrollDelta);

  glm::mat4 GetViewProjection() const;
  const float GetAspect() const;
  const float GetSize() const;
  const float GetHalfWidth() const;
  const float GetHalfHeight() const;
  const float GetPanSpeed() const;
  glm::vec2 GetPosition() const;

  void SetPosition(const glm::vec2& pos);
  void Move(float deltaX, float deltaY);

 private:
  GLsizei m_Width = 1.0f;
  GLsizei m_Height = 1.0f;
  float m_Aspect;
  float m_Size;
  float m_HalfWidth;
  float m_HalfHeight;

  float m_ZoomSpeed = 1.0f;
  float m_MinZoom = 1.0f;
  float m_MaxZoom = 150.0f;

  float m_PanSpeed = 0.05f;

  glm::mat4 m_Projection = glm::mat4(1.0f);
  glm::vec2 m_Position{0.0f, 0.0f};
};
