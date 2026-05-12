#pragma once

#include "Rendering/2D/Renderer2D.hpp"

class Game {
 public:
  virtual ~Game() = default;

  virtual void Init() = 0;
  virtual void Update() = 0;
  virtual void Render(HE::Renderer::Renderer2D& renderer) = 0;
};
