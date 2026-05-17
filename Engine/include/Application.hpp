#pragma once
struct GLFWwindow;

#include <glm/glm.hpp>

#include "Renderer.hpp"

namespace HE {

struct AppConfig {
  const char* title;
  uint32_t width;
  uint32_t height;
};

class Application {
 public:
  virtual ~Application();
  virtual AppConfig GetAppConfig();
  virtual void OnStart(GLFWwindow* window);
  virtual void OnUpdate(float dt);
  virtual void OnRender(Renderer& renderer);
  virtual void OnShutdown();
};

}  // namespace HE
