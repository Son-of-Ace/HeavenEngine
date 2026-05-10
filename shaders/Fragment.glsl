#version 420 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform vec3 uColor;

/* Textures:
void main() { FragColor = texture(texture1, TexCoord) * vec4(Color, 1.0); }
*/
void main() { FragColor = vec4(uColor, 1.0); }
