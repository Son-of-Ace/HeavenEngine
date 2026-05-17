#include <Application.hpp>
#include <Engine.hpp>

extern HE::Application* CreateApplication();

int main() {
  HE::Application* app = CreateApplication();
  HE::Run(app);
  delete app;
}
