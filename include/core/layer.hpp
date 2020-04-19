#ifndef LAYER_HPP
#define LAYER_HPP

#include "tensor.hpp"
#include <map>
#include <string>

#include <memory>

namespace core {

  struct Port {
    Port();
    Port(const TensorShape& _shape, std::shared_ptr<Tensor> _tensor);
    TensorShape _shape;
    std::shared_ptr<Tensor> _tensor;
  };

  class Layer {
   public:
    Layer();
    bool AddInputPort(const Port& port, const std::string& lable);
    bool AddOutputPort(const Port& port, const std::string& lable);

    bool ConnectInputPort(const std::string& port_lable, std::shared_ptr<Tensor> tensor);
    bool ConnectOutputPort(const std::string& port_lable, std::shared_ptr<Tensor> tensor);

    virtual bool checkRequirements();
    virtual bool execute() = 0;

   protected:
    std::map<std::string, Port> _inputs;
    std::map<std::string, Port> _outputs;
  };

}  // namespace core

#endif  // LAYER_HPP