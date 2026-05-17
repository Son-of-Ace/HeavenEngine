#pragma once

#include "EditorPanel.hpp"

namespace HE::Editor {

class MenubarPanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 1));
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ImVec4(1, 1, 1, 1));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8.0f, 8.0f));

    if (ImGui::BeginMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Open Project")) {
        }

        ImGui::EndMenu();
      }

      if (ImGui::BeginMenu("Window")) {
        ImGui::EndMenu();
      }

      ImGui::EndMenuBar();
    }

    ImGui::PopStyleColor(2);
    ImGui::PopStyleVar();
  }
};

}  // namespace HE::Editor
