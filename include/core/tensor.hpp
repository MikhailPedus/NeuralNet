#ifndef TENSOR_HPP
#define TENSOR_HPP

namespace core {

struct TensorShape {
  TensorShape();
  TensorShape(size_t width, size_t height, size_t channels);
  bool isEmpty();
  size_t getSize();

  size_t _width;
  size_t _height;
  size_t _channels;
};

bool operator==(const TensorShape& sh_1, const TensorShape& sh_2);
bool operator!=(const TensorShape& sh_1, const TensorShape& sh_2);

enum class TensorOrder {
  HWC,
  UNDEF
};

enum class TensorElementType {
  UINT8,
  FP32,
  UINT64,
  NEURON,
  UNDEF
};

size_t getPrecisionSize(const TensorElementType& element_type);

struct Tensor {
  Tensor(const TensorShape& shape,
         const TensorOrder& order,
         const TensorElementType& element_type);
  ~Tensor();
  bool allocate();

  template <typename T>
  T* getDataPtr() {
    return reinterpret_cast<T*>(_data);
  }

  TensorShape _shape;
  TensorOrder _order;
  TensorElementType _element_type;
  void* _data;
};

}  // namespace core

#endif  // TENSOR_HPP