#pragma once

#include "../../General/Material/Material.hpp"
#include "../../General/Transform/Transform.hpp"

using namespace HeavenEngine::General::Material;
using namespace HeavenEngine::General::Transform;

namespace HeavenEngine {

class Sprite {
    Transform transform;
    Material material;
};

}  // namespace HeavenEngine
