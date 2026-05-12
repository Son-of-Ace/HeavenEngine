#include "FlappyBird.hpp"

HE::Core::Transform birdTransform;
HE::Core::Material birdMaterial;

void FlappyBird::Init() {
  birdTransform.position = {0.0f, 0.0f, 0.0f};
  birdTransform.rotation = {glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f)};
  birdTransform.scale = {0.1f, 0.1f, 0.0f};
  birdMaterial.color = RGB::rgb(0, 123, 255);
  birdMaterial.textureID = 0;
}

void FlappyBird::Update() {
  birdTransform.position.y -= 0.001f;
  birdTransform.rotation.z += 0.008f;
}

void FlappyBird::Render(HE::Renderer::Renderer2D& renderer) {
  renderer.SubmitQuad(birdTransform, birdMaterial);
}
