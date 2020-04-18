#include "core/activation_func.hpp"

namespace core {

template <typename ParentNeuronType, typename Precision>
activationFuncImpl<ParentNeuronType, Precision>::activationFuncImpl(
    ParentNeuronType* parent)
    : activationFunc(parent) {

}

template <typename ParentNeuronType, typename Precision>
Precision  activationFuncImpl<ParentNeuronType, Precision>::activate() {

}

}  //namespace core