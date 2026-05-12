#pragma once

#include "Material/Material.hpp"
#include "Transform/Transform.hpp"

using namespace HeavenEngine::General::Material;
using namespace HeavenEngine::General::Transform;

namespace HeavenEngine {

class Sprite {
    Transform transform;
    Material material;
};

}  // namespace HeavenEngine
