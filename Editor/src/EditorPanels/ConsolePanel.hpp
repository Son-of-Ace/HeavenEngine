#pragma once

#include <string>

#include "EditorPanel.hpp"
#include "Console.hpp"

namespace HE::Editor {

class ConsolePanel : public EditorPanel {
 public:
  void Init() override {
  }

  void Render(EditorState& editorState) override {
    ImGui::Begin("Console");
    ImGui::BeginChild("Scrolling");

    for (const std::string& line : Console::GetLogs()) {
      ImGui::TextUnformatted(line.c_str());
    }

    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
      ImGui::SetScrollHereY(1.0f);
    }

    ImGui::EndChild();
    ImGui::End();
  }
};

}  // namespace HE::Editor
