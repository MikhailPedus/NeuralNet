#ifndef ACTIVATION_FUNC_HPP
#define ACTIVATION_FUNC_HPP

namespace core {

template <typename ParentNeuronType, typename Precision>
class activationFunc {
 public:
  activationFunc(ParentNeuronType* parent);
  virtual ~activationFunc() = default;
  virtual Precision activate() = 0;
};

template <typename ParentNeuronType, typename Precision>
class activationFuncImpl : public activationFunc<ParentNeuronType, Precision> {
 public:
  activationFuncImpl(ParentNeuronType* parent);

  virtual ~activationFuncImpl() = default;
  virtual Precision activate();
};

}  // namespace core

#endif  // ACTIVATION_FUNC_HPP