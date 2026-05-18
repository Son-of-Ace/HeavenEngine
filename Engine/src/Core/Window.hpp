#pragma once

#include <GLFW/glfw3.h>
#include <glm/ext/vector_int2.hpp>

namespace HE {

class Window {
 public:
  Window(int width, int height, const char* title) {
    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(m_Window);
  }
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  ~Window() {
    if (m_Window) {
      glfwDestroyWindow(m_Window);
    }
  }

  GLFWwindow* GetNativeWindow() const {
    return m_Window;
  }

  glm::ivec2 GetSize() const {
    glm::ivec2 size;
    glfwGetWindowSize(m_Window, &size.x, &size.y);
    return size;
  }

 private:
  GLFWwindow* m_Window = nullptr;
};

}  // namespace HE
