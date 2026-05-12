#version 420 core

out vec4 FragColor;

uniform vec4 uColor;

in vec4 Color;

void main() {
    FragColor = Color;
}
