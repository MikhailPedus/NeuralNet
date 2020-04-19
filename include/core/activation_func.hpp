#ifndef ACTIVATION_FUNC_HPP
#define ACTIVATION_FUNC_HPP

#include <vector>
#include <ostream>

namespace core {

enum class ActivationFunctType {
  Sigmoid,
  Undef
};

std::ostream& operator<<(std::ostream& stream, const ActivationFunctType& act_func_type);

class activationFunc {
 public:
  activationFunc();
  virtual ~activationFunc() = default;
  virtual float activate(const std::vector<float>& inputs) = 0;
};

class activationSigmoid : public activationFunc {
 public:
  activationSigmoid();

  virtual ~activationSigmoid() = default;
  virtual float activate(const std::vector<float>& inputs);
};

}  // namespace core

#endif  // ACTIVATION_FUNC_HPP