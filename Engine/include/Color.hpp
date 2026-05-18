#pragma once

namespace HE {

struct Color {
  float r, g, b, a;
};

inline Color ColorFromRGB(int r, int g, int b, float a = 1.0f) {
  return Color{r / 255.0f, g / 255.0f, b / 255.0f, a};
}

}  // namespace HE
