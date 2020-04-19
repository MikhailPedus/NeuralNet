#include <memory>

#include "core/layers/FullyConnected.hpp"
#include "core/neuron.hpp"
#include "gtest/gtest.h"

TEST(FullyConnectedTest, FCtest) {
  core::TensorShape input_data_shape(2, 1, 1);
  core::TensorShape output_shape(2, 1, 1);

  core::TensorShape input_weight_shape(2, 1, 1);
  
  float fill_value = 0.5;
  
  std::shared_ptr<core::Tensor> input_data_tensor = std::make_shared<core::Tensor>(
      input_data_shape, core::TensorOrder::HWC, core::TensorElementType::FP32);
  std::shared_ptr<core::Tensor> output_tensor = std::make_shared<core::Tensor>(
      output_shape, core::TensorOrder::HWC, core::TensorElementType::FP32);

  std::vector<std::shared_ptr<core::Tensor>> input_weight_tensors;
  input_weight_tensors.reserve(output_shape.getSize());
  for (size_t i = 0; i < output_shape.getSize(); ++i) {
    input_weight_tensors.emplace_back(std::make_shared<core::Tensor>(input_weight_shape, core::TensorOrder::HWC, 
      core::TensorElementType::FP32));
  }

  core::Port input_data_port;
  input_data_port._shape = input_data_shape;
  input_data_port._tensor = input_data_tensor;

  core::Port output_port;
  output_port._shape = output_shape;
  output_port._tensor = output_tensor;

  std::vector<core::Port> input_weight_ports;
  input_weight_ports.reserve(input_weight_tensors.size());
  for (size_t i = 0; i < input_weight_tensors.size(); ++i) {
    input_weight_ports.emplace_back(input_weight_shape, input_weight_tensors[i]);
  }
  
  std::shared_ptr<core::Layer> fc_layer = std::make_shared<core::LayerFullyConnected>();

  input_data_port._tensor->allocate();
  auto input_data_ptr = input_data_tensor->getDataPtr<float>();
  for (size_t i = 0; i < input_data_shape.getSize(); ++i) {
    input_data_ptr[i] = fill_value;
  }

  fc_layer->AddInputPort(input_data_port, "data");

  for (size_t i = 0; i < input_weight_ports.size(); ++i) {
    input_weight_ports[i]._tensor->allocate();
    auto input_weight_data_ptr = input_weight_tensors[i]->getDataPtr<float>();
    for (size_t j = 0; j < input_weight_shape.getSize(); ++j) {
      input_weight_data_ptr[j] = fill_value;
    }
    fc_layer->AddInputPort(input_weight_ports[i], "weights_" + std::to_string(i));
  }

  output_port._tensor->allocate();
  fc_layer->AddOutputPort(output_port, "output");

  //execute
  fc_layer->execute();

  // check result
  auto result_ptr = output_tensor->getDataPtr<float>();
  EXPECT_EQ(result_ptr[0], 1);
};
