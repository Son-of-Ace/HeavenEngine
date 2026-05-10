#pragma once

#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>

class RGB {
 public:
  float r;
  float g;
  float b;

  static glm::vec4 rgb(int r, int g, int b);
};
