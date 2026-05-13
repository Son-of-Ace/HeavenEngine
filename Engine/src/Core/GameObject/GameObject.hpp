#pragma once

#include <memory>
#include <vector>

#include "Core/Components/Component.hpp"

namespace HE::Core {

class GameObject {
 public:
  template <typename T, typename... Args>
  T& AddComponent(Args&&... args);

  template <typename T>
  void RemoveComponent();

  template <typename T>
  T* GetComponent();

  template <typename T>
  bool HasComponent();

 private:
  std::vector<std::unique_ptr<HE::Core::Component>> components;
};

}  // namespace HE::Core
