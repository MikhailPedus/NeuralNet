#ifndef LAYER_HPP
#define LAYER_HPP

#include "tensor.hpp"
#include <vector>

#include <memory>

namespace core {

  struct Port {
    Port();
    TensorShape _shape;
    std::shared_ptr<Tensor> _tensor;
  };

  class Layer {
   public:
    Layer();
    Layer(const std::vector<Port>& inputs, const std::vector<Port>& outputs);
    void AddInputPort(const Port& port);
    void AddOutputPort(const Port& port);

    bool ConnectInputPort(size_t port_id, std::shared_ptr<Tensor> tensor);
    bool ConnectOutputPort(size_t port_id, std::shared_ptr<Tensor> tensor);

    virtual bool execute() = 0;

   protected:
    std::vector<Port> _inputs;
    std::vector<Port> _outputs;
  };

}  // namespace core

#endif  // LAYER_HPP