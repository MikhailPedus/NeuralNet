#ifndef NEURON_HPP
#define NEURON_HPP

#include <vector>
#include <memory>

#include "core/activation_func.hpp"

namespace core {

  struct Neuron {
    Neuron(ActivationFunctType type);
    std::vector<std::shared_ptr<Neuron>> _inputs;
    std::unique_ptr<activationFunc> _activation;
    float activate();

    float _weight;
  };

}  // namespace core

#endif  // NEURON_HPP