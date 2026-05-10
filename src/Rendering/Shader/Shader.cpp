#include <glad/glad.h>
#include <stdexcept>
#include <string>

#include "Shader.hpp"
#include "ShaderUtils.hpp"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
  const std::string vertexShaderLoad = LoadShader(vertexShaderPath);
  const std::string fragmentShaderLoad = LoadShader(fragmentShaderPath);

  const char* vertexShaderSource = vertexShaderLoad.c_str();
  const char* fragmentShaderSource = fragmentShaderLoad.c_str();

  int succes;
  char infoLog[512];

  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  shaderProgram = glCreateProgram();

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

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &succes);
  if (!succes) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

    std::string errorMsg = "!!!RUNTIME ERROR!!! -> SHADER PROGRAM LINKING FAILED!\n";
    errorMsg += infoLog;

    throw std::runtime_error(errorMsg);
  }

  glUseProgram(vertexShader);
  glUseProgram(fragmentShader);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::Use() { glUseProgram(shaderProgram); }

void Shader::SetColor(const RGB& color) {
  GLint location = glGetUniformLocation(shaderProgram, "uColor");
  glUniform3f(location, color.r, color.g, color.b);
}

void Shader::Bind() {}

Shader::~Shader() { glDeleteProgram(shaderProgram); }
