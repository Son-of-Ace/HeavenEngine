#pragma once

#include <imgui.h>

#include "EditorState.hpp"

namespace HE::Editor {

class EditorPanel {
 public:
  virtual void Init() = 0;
  virtual void Render(EditorState& editorState) = 0;
};

}  // namespace HE::Editor
