#include "core/layer.hpp"

#include <iostream>

namespace core {
  Port::Port() : _tensor(nullptr) { }

  Layer::Layer() {}
  Layer::Layer(const std::vector<Port>& inputs,
               const std::vector<Port>& outputs)
      : _inputs(inputs), _outputs(outputs) {}
    
  void Layer::AddInputPort(const Port& port) {
    _inputs.emplace_back(port);
  }
  void Layer::AddOutputPort(const Port& port) {
    _outputs.emplace_back(port);
  }

  bool Layer::ConnectInputPort(size_t port_id, std::shared_ptr<Tensor> tensor) {
    if (_inputs.size() <= port_id) {
      std::cout << "Incorrect port id: " << port_id << std::endl;
      return false;
    }
    if (_inputs[port_id]._shape != tensor->_shape) {
      std::cout << "Inconsistent shapes" << std::endl;
      return false;
    }
    _inputs[port_id]._tensor = tensor;
    return true;
  }

  bool Layer::ConnectOutputPort(size_t port_id, std::shared_ptr<Tensor> tensor) {
    if (_outputs.size() <= port_id) {
      std::cout << "Incorrect port id: " << port_id << std::endl;
      return false;
    }
    if (_outputs[port_id]._shape != tensor->_shape) {
      std::cout << "Inconsistent shapes" << std::endl;
      return false;
    }
    _outputs[port_id]._tensor = tensor;
    return true;
  }

  }  // namespace core