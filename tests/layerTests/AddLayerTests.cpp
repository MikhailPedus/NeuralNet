#include "gtest/gtest.h"

#include<memory>

#include "../../include/core/layers/AddLayer.hpp"

TEST(AddLayerTest, test) {
  core::TensorShape shape(2,2,3);
  float fill_value = 1;
  std::shared_ptr<core::Tensor> input_1_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorPrecision::FP32);
  std::shared_ptr<core::Tensor> input_2_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorPrecision::FP32);
  std::shared_ptr<core::Tensor> output_tensor = std::make_shared<core::Tensor>(
      shape, core::TensorOrder::HWC, core::TensorPrecision::FP32);
  
  core::Port input_1_port;
  input_1_port._shape = shape;
  input_1_port._tensor = input_1_tensor;

  core::Port input_2_port;
  input_2_port._shape = shape;
  input_2_port._tensor = input_2_tensor;

  core::Port output_port;
  output_port._shape = shape;
  output_port._tensor = output_tensor;

  std::shared_ptr<core::Layer> addLayer = std::make_shared<core::LayerAdd>();

  input_1_port._tensor->allocate();
  auto input_1_data_ptr = input_1_tensor->getDataPtr<float>();
  for (size_t i = 0; i < shape.getSize(); ++i) {
    input_1_data_ptr[i] = fill_value;
  }

  addLayer->AddInputPort(input_1_port);
  
  input_2_port._tensor->allocate();
  auto input_2_data_ptr = input_2_tensor->getDataPtr<float>();
  for (size_t i = 0; i < shape.getSize(); ++i) {
    input_2_data_ptr[i] = fill_value;
  }
  addLayer->AddInputPort(input_2_port);

  output_port._tensor->allocate();
  addLayer->AddOutputPort(output_port);

  addLayer->execute();

  auto result_ptr = output_tensor->getDataPtr<float>();
  //check result
  for (size_t i = 0; i < shape.getSize(); ++i) {
    EXPECT_EQ(result_ptr[i], fill_value*2);
  }

};
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}