#pragma once

#include "Material.hpp"
#include "Component.hpp"

namespace HE {

class Sprite : public Component {
 private:
  Material* material;
};

}  // namespace HE
