#pragma once

#include "Material/Material.hpp"
#include "Component.hpp"

namespace HE::Core {

class SpriteRenderer : public Component {
  HE::Core::Material* material;
};

}  // namespace HE::Core
