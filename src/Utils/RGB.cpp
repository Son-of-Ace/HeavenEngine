#include "RGB.hpp"

RGB RGB::rgb(float x, float y, float z) {
  RGB color;

  color.r = x / 255.0f;
  color.g = y / 255.0f;
  color.b = z / 255.0f;

  return color;
}
