#include "core/layers/AddLayer.hpp"

#include <iostream>

namespace core {

  LayerAdd::LayerAdd() : Layer() {}

  LayerAdd::LayerAdd(const std::vector<Port>& inputs,
                     const std::vector<Port>& outputs)
      : Layer(inputs, outputs) {}

  bool LayerAdd::execute() {
    if (_inputs.size() < 2) {
      std::cout << "required at least 2 inputs" << std::endl;
      return false;
    }
    if (_outputs.size() != 1) {
      std::cout << "required one output" << std::endl;
      return false;
    }
    for (size_t i = 1; i < _inputs.size(); ++i) {
      if (_inputs[0]._shape != _inputs[i]._shape) {
        std::cout << "All inputs must have same shapes" << std::endl;
        return false;
      }
    }
    if (_outputs[0]._shape != _inputs[0]._shape) {
      std::cout << "Output must have same shape with inputs shapes"
                << std::endl;
      return false;
    }
    for (size_t i = 0; i < _inputs.size(); ++i) {
      if (!_inputs[i]._tensor) {
        std::cout << "Tensor for input " << i << " does not added" << std::endl;
        return 0;
      }
      if (!_inputs[i]._tensor->_data) {
        std::cout << "Memory for input tensor " << i << " does not alocated"
                  << std::endl;
        return 0;
      }
    }
    for (size_t i = 0; i < _outputs.size(); ++i) {
      if (!_outputs[i]._tensor) {
        std::cout << "Tensor for output " << i << " does not added" << std::endl;
        return 0;
      }
      if (!_outputs[i]._tensor->_data) {
        std::cout << "Memory for output tensor " << i << " does not alocated"
                  << std::endl;
        return 0;
      }
    }

    std::vector<float*> input_ptrs(_inputs.size(), nullptr);
    for (size_t i = 0; i < _inputs.size(); ++i) {
      input_ptrs[i] = _inputs[i]._tensor->getDataPtr<float>();
    }
    float* output_ptr = _outputs[0]._tensor->getDataPtr<float>();

    for (size_t i = 0; i < _inputs[0]._shape.getSize(); ++i) {
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