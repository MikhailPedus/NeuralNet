#include "core/activation_func.hpp"

#include <numeric>
#include <cmath>

namespace core {

std::ostream& operator<<(std::ostream& stream, const ActivationFunctType& act_func_type) {
  switch (act_func_type) { 
    case ActivationFunctType::Sigmoid :
      stream << "SIGMOID";
      break;
    default:
      stream << "UNDEF";
      break;
  }
  return stream;
}

activationSigmoid::activationSigmoid() : activationFunc() {}

float activationSigmoid::activate(const std::vector<float>& inputs) {
  return 1.f / (1.f + std::exp(std::accumulate(inputs.begin(), inputs.end(), 0)));
}

}  //namespace core