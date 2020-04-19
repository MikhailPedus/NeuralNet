#include "gtest/gtest.h"

#include <memory>

#include "../../include/core/layers/AddLayer.hpp"

TEST(AddLayerTest, test) {
  core::TensorShape shape(2,2,3);
  float fill_value = 1;
  std::shared_ptr<core::Tensor> input_1_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorElementType::FP32);
  std::shared_ptr<core::Tensor> input_2_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorElementType::FP32);
  std::shared_ptr<core::Tensor> output_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorElementType::FP32);
  
  core::Port input_1_port;
  input_1_port._shape = shape;
  
  core::Port input_2_port;
  input_2_port._shape = shape;
  
  core::Port output_port;
  output_port._shape = shape;
  
  std::shared_ptr<core::Layer> addLayer = std::make_shared<core::LayerAdd>();

  addLayer->AddInputPort(input_1_port, "input_1");
  addLayer->AddInputPort(input_2_port, "input_2");
  addLayer->AddOutputPort(output_port, "output");

  input_1_tensor->allocate();
  auto input_1_data_ptr = input_1_tensor->getDataPtr<float>();
  for (size_t i = 0; i < shape.getSize(); ++i) {
    input_1_data_ptr[i] = fill_value;
  }

  input_2_tensor->allocate();
  auto input_2_data_ptr = input_2_tensor->getDataPtr<float>();
  for (size_t i = 0; i < shape.getSize(); ++i) {
    input_2_data_ptr[i] = fill_value;
  }

  output_tensor->allocate();

  addLayer->ConnectInputPort("input_1", input_1_tensor);
  addLayer->ConnectInputPort("input_2", input_2_tensor);
  
  addLayer->ConnectOutputPort("output", output_tensor);

  addLayer->execute();

  auto result_ptr = output_tensor->getDataPtr<float>();
  //check result
  for (size_t i = 0; i < shape.getSize(); ++i) {
    EXPECT_EQ(result_ptr[i], fill_value*2);
  }
};
