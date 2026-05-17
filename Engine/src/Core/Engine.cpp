#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine.hpp>

#include "Core/Window.hpp"
#include "Core/Rendering/2D/Renderer2D.hpp"

namespace HE {

void Run(HE::Application* app) {
  if (!glfwInit()) {
    return;
  }

  AppConfig config = app->GetAppConfig();
  Window window(config.width, config.height, config.title);

  if (!window.GetNativeWindow()) {
    glfwTerminate();
    return;
  }

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwTerminate();
    return;
  }

  Renderer2D renderer;
  renderer.Init();

  app->OnStart(window.GetNativeWindow());

  float lastTime = 0.0f;

  while (!glfwWindowShouldClose(window.GetNativeWindow())) {
    float currentTime = (float)glfwGetTime();
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    glfwPollEvents();

    app->OnUpdate(deltaTime);
    app->OnRender(renderer);

    glfwSwapBuffers(window.GetNativeWindow());
  }

  app->OnShutdown();
  glfwTerminate();
}

}  // namespace HE
