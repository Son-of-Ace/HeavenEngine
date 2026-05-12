#pragma once

#include "../Engine/HeavenEngine.hpp"

class FlappyBird : public Game {
  void Init() override;
  void Update() override;
  void Render(HE::Renderer::Renderer2D& renderer) override;
};
