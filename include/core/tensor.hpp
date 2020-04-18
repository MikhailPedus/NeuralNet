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

enum class TensorPrecision {
  UINT8,
  FP32,
  UINT64,
  UNDEF
};

size_t getPrecisionSize(const TensorPrecision& precision);

struct Tensor {
  Tensor(const TensorShape& shape,
         const TensorOrder& order,
         const TensorPrecision& precision);
  ~Tensor();
  bool allocate();

  template <typename T>
  T* getDataPtr() {
    return reinterpret_cast<T*>(_data);
  }

  TensorShape _shape;
  TensorOrder _order;
  TensorPrecision _precision;
  void* _data;
};

}  // namespace core

#endif  // TENSOR_HPP