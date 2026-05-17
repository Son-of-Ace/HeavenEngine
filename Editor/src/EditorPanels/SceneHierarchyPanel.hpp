#pragma once

#include "EditorPanel.hpp"

namespace HE::Editor {

class SceneHierarchyPanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::Begin("Scene Hierarchy");
    ImGui::End();
  }
};

}  // namespace HE::Editor
