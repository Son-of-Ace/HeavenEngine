#pragma once

#include "EditorPanel.hpp"

namespace HE::Editor {

class ProjectPanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::Begin("Project");
    ImGui::End();
  }
};

}  // namespace HE::Editor
