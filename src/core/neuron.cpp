#include "core/neuron.hpp"

#include <iostream>

namespace core {

  Neuron::Neuron(ActivationFunctType type) : _weight(0) {
    switch (type) { 
      case ActivationFunctType::Sigmoid :
        _activation = std::make_unique<activationSigmoid>();
        break;
      default:
        std::cout << "Unsupported activation function type: " << type << std::endl;
        break;
    }
  }
  float Neuron::activate() {

    return 0;
  }

} // namespace core