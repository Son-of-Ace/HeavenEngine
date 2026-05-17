#include <Application.hpp>

namespace HE {

Application::~Application() {
}

AppConfig Application::GetAppConfig() {
  return {"", 0, 0};
}

void Application::OnStart(GLFWwindow* window) {
}

void Application::OnUpdate(float dt) {
}

void Application::OnRender(Renderer& renderer) {
}

void Application::OnShutdown() {
}

}  // namespace HE
