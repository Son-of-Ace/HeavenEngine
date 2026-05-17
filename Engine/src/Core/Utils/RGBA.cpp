#include "RGBA.hpp"

glm::vec4 RGBA::rgba(int r, int g, int b, float a) {
  return glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a);
}
