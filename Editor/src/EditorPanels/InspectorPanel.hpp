#pragma once

#include "EditorPanel.hpp"

namespace HE::Editor {

class InspectorPanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::Begin("Inspector");
    ImGui::End();
  }
};

}  // namespace HE::Editor
