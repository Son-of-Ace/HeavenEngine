#pragma once

#include "EditorPanel.hpp"
#include <Texture.hpp>

namespace HE::Editor {

class ToolbarPanel : public EditorPanel {
 public:
  void Init() override {
    m_Icon = HE::Texture{HE_ENGINE_ROOT "assets/HeavenEngineIcon.png"};
  }

  void Render(EditorState& editorState) override {
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 1));
    ImGui::BeginChild("Toolbar", ImVec2(0, 50), false, ImGuiWindowFlags_NoScrollbar);

    float toolBarHeight = 50.0f;
    float iconSize = 32.0f;
    float padding = 10.0f;
    float textHeight = ImGui::GetTextLineHeight();

    ImGui::SetCursorPos(ImVec2(padding, (toolBarHeight - iconSize) * 0.5f));
    ImTextureID texID = (ImTextureID)(intptr_t)m_Icon.GetID();
    ImGui::Image(texID, ImVec2(iconSize, iconSize));

    ImGui::SameLine();
    ImGui::SetCursorPosY((toolBarHeight - textHeight) * 0.5f);
    ImGui::Text("Heaven Engine");

    float buttonWidth = 80.0f;
    float windowWidth = ImGui::GetWindowSize().x;
    ImGui::SetCursorPos(ImVec2((windowWidth - buttonWidth) * 0.5f, (toolBarHeight - ImGui::GetFrameHeight()) * 0.5f));
    if (ImGui::Button("Play", ImVec2(buttonWidth, 0))) {
    }

    ImGui::EndChild();

    ImGui::PopStyleColor();
  }

 private:
  HE::Texture m_Icon;
};

}  // namespace HE::Editor
