#include <glad/glad.h>

#include "Shader.hpp"
#include "ShaderUtils.hpp"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
  const std::string vertexShaderLoad = LoadShader(vertexShaderPath);
  const std::string fragmentShaderLoad = LoadShader(fragmentShaderPath);

  const char* vertexShaderSource = vertexShaderLoad.c_str();
  const char* fragmentShaderSource = fragmentShaderLoad.c_str();

  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  shaderProgram = glCreateProgram();

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glUseProgram(vertexShader);
  glUseProgram(fragmentShader);
}

void Shader::Use() { glUseProgram(shaderProgram); }

void Shader::Bind() {}

Shader::~Shader() { glDeleteProgram(shaderProgram); }
