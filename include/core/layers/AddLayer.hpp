#ifndef ADD_LAYER_HPP
#define ADD_LAYER_HPP

#include "../layer.hpp"

namespace core {

  class LayerAdd : public Layer {
   public:
    LayerAdd();
    LayerAdd(const std::vector<Port>& inputs, const std::vector<Port>& outputs);
    
    virtual bool execute();
  };

}  // namespace core

#endif  // ADD_LAYER_HPP