#include "core/layers/AddLayer.hpp"

#include <iostream>
#include <vector>

namespace core {

  LayerAdd::LayerAdd() : Layer() {}

  bool LayerAdd::execute() {
    if (!checkRequirements())
      return false;


    if (_inputs.begin()->second._tensor->_element_type != TensorElementType::FP32) {
      std::cout
          << "Only FP32 element type is supported in eltwise Add layer"
          << std::endl;
      return false;
    }

    std::vector<float*> input_ptrs;
    input_ptrs.reserve(_inputs.size());

    for (auto iter = _inputs.begin(); iter != _inputs.end(); ++iter) {
      input_ptrs.emplace_back(iter->second._tensor->getDataPtr<float>());
    }
    float* output_ptr = _outputs.begin()->second._tensor->getDataPtr<float>();

    for (size_t i = 0; i < _inputs.begin()->second._shape.getSize(); ++i) {
      *output_ptr = 0;
      for (size_t j = 0; j < input_ptrs.size(); ++j) {
        *output_ptr += *input_ptrs[j];
        input_ptrs[j]++;
      }
      output_ptr++;
    }
    return true;
  }

}  // namespace core