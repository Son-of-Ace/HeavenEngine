#include <glad/glad.h>
#include <stdexcept>
#include <string>

#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "ShaderUtils.hpp"

namespace HE {

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
  const std::string vertexShaderLoad = LoadShader(vertexShaderPath);
  const std::string fragmentShaderLoad = LoadShader(fragmentShaderPath);

  const char* vertexShaderSource = vertexShaderLoad.c_str();
  const char* fragmentShaderSource = fragmentShaderLoad.c_str();

  int succes;
  char infoLog[512];

  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  ID = glCreateProgram();

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes);
  if (!succes) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

    std::string errorMsg = "!!!RUNTIME ERROR!!! -> VERTEX SHADER COMPILATION FAILED!\n";
    errorMsg += infoLog;

    throw std::runtime_error(errorMsg);
  }

  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succes);
  if (!succes) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);

    std::string errorMsg = "!!!RUNTIME ERROR!!! -> FRAGMENT SHADER COMPILATION FAILED!\n";
    errorMsg += infoLog;

    throw std::runtime_error(errorMsg);
  }

  glAttachShader(ID, vertexShader);
  glAttachShader(ID, fragmentShader);
  glLinkProgram(ID);

  glGetProgramiv(ID, GL_LINK_STATUS, &succes);
  if (!succes) {
    glGetProgramInfoLog(ID, 512, NULL, infoLog);

    std::string errorMsg = "!!!RUNTIME ERROR!!! -> SHADER PROGRAM LINKING FAILED!\n";
    errorMsg += infoLog;

    throw std::runtime_error(errorMsg);
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::Use() {
  glUseProgram(ID);
}

void Shader::SetColor(const glm::vec4& color) {
  GLint location = glGetUniformLocation(ID, "uColor");
  glUniform4f(location, color.r, color.g, color.b, color.a);
}

void Shader::SetMat4(const char* valueName, const glm::mat4& value) {
  GLint location = glGetUniformLocation(ID, valueName);
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::Bind() {
}

Shader::~Shader() {
  glDeleteProgram(ID);
}

}  // namespace HE
