#pragma once

#include "EditorTools/ImGuiRGB.hpp"

namespace HE::Editor {

struct EditorSettings {
  // Window colors
  ImVec4 windowBGColor = rgb(36, 36, 36);
  ImVec4 menuBarColor = rgb(255, 255, 255);

  // Tab colors
  ImVec4 tabColor = rgb(50, 50, 50);
  ImVec4 selectedTabColor = rgb(100, 100, 100);
  ImVec4 tabHover = rgb(120, 120, 120);
  ImVec4 tabBG = rgb(150, 150, 150);
  ImVec4 tabOverlineColorSelected = rgb(255, 255, 255);
  ImVec4 tabOverlineColor = rgb(200, 200, 200);
  ImVec4 titleBg = rgb(20, 20, 20);
  ImVec4 titleBgSelected = rgb(60, 60, 60);
};

}  // namespace HE::Editor
