#pragma once

#include <imgui.h>

namespace HE::Editor {

static ImVec4 rgb(int r, int g, int b) {
  return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

}  // namespace HE::Editor
