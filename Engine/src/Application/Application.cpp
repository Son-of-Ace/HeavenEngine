#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../../FlappyBird/FlappyBird.hpp"

#include "Application.hpp"

#include "../Rendering/2D/Renderer2D.hpp"
#include "../../Engine/GameTools/Game.hpp"

void window_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void Application::Run() {
  if (!glfwInit()) {
    return;
  }

  GLFWwindow* window = glfwCreateWindow(2560, 1440, "OpenGL Test", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
    glfwTerminate();
    return;
  }

  glfwSetWindowSizeCallback(window, window_size_callback);
  glClearColor(0.0, 0.0, 0.0, 1);

  HE::Renderer::Renderer2D renderer2D;
  renderer2D.Init();

  // Set the game to be played
  Game* game = new FlappyBird;

  game->Init();

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    game->Update();

    renderer2D.BeginFrame();
    game->Render(renderer2D);
    renderer2D.EndFrame();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  delete game;
  glfwTerminate();
  return;
}
