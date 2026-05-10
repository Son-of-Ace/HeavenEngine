#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"

#include "../Rendering/2D/Renderer2D.hpp"

void window_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

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

  Renderer2D renderer2D;
  renderer2D.Init();

  while (!glfwWindowShouldClose(window)) {
    renderer2D.Render();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return;
}
