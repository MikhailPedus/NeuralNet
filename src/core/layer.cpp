#include "core/layer.hpp"

#include <iostream>

namespace core {
  Port::Port() : _tensor(nullptr) { }
  Port::Port(const TensorShape& shape, std::shared_ptr<Tensor> tensor) : _shape(shape), _tensor(tensor) {}
    
  Layer::Layer() {}

  bool Layer::AddInputPort(const Port& port, const std::string& lable) {
    if (_inputs.find(lable) != _inputs.end()) {
      std::cout << "Port with lable: " << lable << " already exist" << std::endl;
      return false;
    }
    _inputs[lable] = port;
    return true;
  }
  bool Layer::AddOutputPort(const Port& port, const std::string& lable) {
    if (_outputs.find(lable) != _outputs.end()) {
      std::cout << "Port with lable: " << lable << " already exist"
                << std::endl;
      return false;
    }
    _outputs[lable] = port;
    return true;
  }

  bool Layer::ConnectInputPort(const std::string& port_lable, std::shared_ptr<Tensor> tensor) {
    auto iter = _inputs.find(port_lable);
    if (iter == _inputs.end()) {
      std::cout << "Port with lable: " << port_lable << " does not exist"
                << std::endl;
      return false;
    }
    if (iter->second._shape != tensor->_shape) {
      std::cout << "Inconsistent shapes" << std::endl;
      return false;
    }
    iter->second._tensor = tensor;
    return true;
  }

  bool Layer::ConnectOutputPort(const std::string& port_lable, std::shared_ptr<Tensor> tensor) {
    auto iter = _outputs.find(port_lable);
    if (iter == _outputs.end()) {
      std::cout << "Port with lable: " << port_lable << " does not exist"
                << std::endl;
      return false;
    }
    if (iter->second._shape != tensor->_shape) {
      std::cout << "Inconsistent shapes" << std::endl;
      return false;
    }
    iter->second._tensor = tensor;
    return true;
  }

  bool Layer::checkRequirements() {
    if (_inputs.empty()) {
      std::cout << "Inputs empty" << std::endl;
      return false;
    }

    if (_outputs.size() != 1) {
      std::cout << "Outputs empty" << std::endl;
      return false;
    }
    
    for (auto iter = _inputs.begin(); iter != _inputs.end(); ++iter) {
      if (!iter->second._tensor) {
        std::cout << "Tensor for input " << iter->first << " does not added" << std::endl;
        return false;
      }
      if (!iter->second._tensor->_data) {
        std::cout << "Memory for input tensor " << iter->first
                  << " does not alocated"
                  << std::endl;
        return false;
      }
    }

    for (auto iter = _outputs.begin(); iter != _outputs.end(); ++iter) {
      if (!iter->second._tensor) {
        std::cout << "Tensor for output " << iter->first << " does not added"
                  << std::endl;
        return false;
      }
      if (!iter->second._tensor->_data) {
        std::cout << "Memory for output tensor " << iter->first << " does not alocated"
                  << std::endl;
        return false;
      }
    }

    return true;
  }

  }  // namespace core