#pragma once

#include <Color.hpp>

namespace HE::Editor {

struct EditorSettings {
  // Window colors
  Color windowBGColor = ColorFromRGB(36, 36, 36);
  Color menuBarColor = ColorFromRGB(255, 255, 255);

  // Tab colors
  Color tabColor = ColorFromRGB(50, 50, 50);
  Color selectedTabColor = ColorFromRGB(100, 100, 100);
  Color tabHoverColor = ColorFromRGB(120, 120, 120);
  Color tabBGColor = ColorFromRGB(150, 150, 150);
  Color tabOverlineSelectedColor = ColorFromRGB(255, 255, 255);
  Color tabOverlineColor = ColorFromRGB(200, 200, 200);
  Color titleBgColor = ColorFromRGB(20, 20, 20);
  Color titleBgSelectedColor = ColorFromRGB(60, 60, 60);
};

}  // namespace HE::Editor
