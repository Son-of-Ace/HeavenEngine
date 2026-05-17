#pragma once

#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>

class RGBA {
 public:
  float r;
  float g;
  float b;
  float a;

  static glm::vec4 rgba(int r, int g, int b, float a = 1);
};
