#pragma once

#include <Color.hpp>
#include <imgui.h>

#include <glm/ext/vector_float4.hpp>

namespace HE {

inline ImVec4 ToImVec4(const Color& color) {
  return ImVec4(color.r, color.g, color.b, color.a);
}

}  // namespace HE
