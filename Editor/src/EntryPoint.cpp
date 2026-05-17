#include <Engine.hpp>
#include "EditorLayer.hpp"

HE::Application* CreateApplication() {
  return new HE::Editor::EditorLayer;
}

extern HE::Application* CreateApplication();

int main() {
  HE::Application* app = CreateApplication();
  HE::Run(app);
  delete app;
}
