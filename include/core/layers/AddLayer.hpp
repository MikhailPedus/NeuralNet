#ifndef ADD_LAYER_HPP
#define ADD_LAYER_HPP

#include "core/layer.hpp"

namespace core {

  class LayerAdd : public Layer {
   public:
    LayerAdd();
    
    virtual bool execute();
  };

}  // namespace core

#endif  // ADD_LAYER_HPP