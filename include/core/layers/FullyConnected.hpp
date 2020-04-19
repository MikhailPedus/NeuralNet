#ifndef FULLYCONNECTED_LAYER_HPP
#define FULLYCONNECTED_LAYER_HPP

#include "core/layer.hpp"

namespace core {

class LayerFullyConnected : public Layer {
 public:
  LayerFullyConnected();

  virtual bool execute();
};

}  // namespace core

#endif  // FULLYCONNECTED_LAYER_HPP