#pragma once

#include <glm/ext/vector_float2.hpp>

struct Transform2D {
  glm::vec2 position{0.0f};
  float rotation = 0.0f;
  glm::vec2 scale{1.0f};
};
