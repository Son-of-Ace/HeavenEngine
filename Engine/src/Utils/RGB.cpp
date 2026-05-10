#include "RGB.hpp"

glm::vec4 RGB::rgb(int r, int g, int b) {
  return glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}
