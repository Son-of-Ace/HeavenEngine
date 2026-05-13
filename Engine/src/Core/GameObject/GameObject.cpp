#include "GameObject.hpp"

namespace HE::Core {

template <typename T, typename... Args>
T& AddComponent(Args&&... args) {
}

template <typename T>
void RemoveComponent() {
}

template <typename T>
T* GetComponent() {
}

template <typename T>
bool HasComponent() {
}

}  // namespace HE::Core
