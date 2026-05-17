#pragma once

#include "glad/glad.h"

#include <glm/ext/matrix_float4x4.hpp>

class Camera {
 public:
  Camera(GLsizei width, GLsizei height);
  void Resize(GLsizei width, GLsizei height, const float size = 5.0f);

  glm::mat4 GetViewProjection() const;
  const float GetAspect() const;
  const float GetSize() const;

 private:
  GLsizei m_Width = 1.0f;
  GLsizei m_Height = 1.0f;
  float m_Aspect;
  float m_Size;

  glm::mat4 m_Projection = glm::mat4(1.0f);
};
