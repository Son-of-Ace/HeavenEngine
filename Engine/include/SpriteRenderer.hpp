#pragma once

#include "Material.hpp"
#include "Component.hpp"

namespace HE {

class SpriteRenderer : public Component {
 public:
  HE::Material* material;
};

}  // namespace HE
