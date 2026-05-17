#pragma once

#include "EditorPanel.hpp"

namespace HE::Editor {

class ToolbarPanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 1));

    ImGui::BeginChild("Toolbar", ImVec2(0, 50), false, ImGuiWindowFlags_NoScrollbar);

    float toolBarHeight = 50.0f;
    float textHeight = ImGui::GetTextLineHeight();
    ImGui::SetCursorPos(ImVec2(20.0f, (toolBarHeight - textHeight) * 0.5f));
    ImGui::Text("Heaven Engine");

    float buttonWidth = 80.0f;
    float windowWidth = ImGui::GetWindowSize().x;
    ImGui::SetCursorPos(ImVec2((windowWidth - buttonWidth) * 0.5f, (toolBarHeight - ImGui::GetFrameHeight()) * 0.5f));
    if (ImGui::Button("Play", ImVec2(buttonWidth, 0))) {
    }

    ImGui::EndChild();

    ImGui::PopStyleColor();
  }
};

}  // namespace HE::Editor
