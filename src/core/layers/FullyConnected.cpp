#include <iostream>

#include <cassert>

#include "core/layers/FullyConnected.hpp"

namespace core {

LayerFullyConnected::LayerFullyConnected() : Layer() {}

bool LayerFullyConnected::execute() {
  if (!checkRequirements())
    return false;
  
  
  for (auto iter = _outputs.begin(); iter != _outputs.end(); ++iter) {
    float* output_ptr = iter->second._tensor->getDataPtr<float>();

    for (size_t i = 0; i < iter->second._shape.getSize(); ++i) {
      output_ptr[i] = 0.1;
    }
  }

  return true;
}

}  // namespace core