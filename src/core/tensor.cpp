#include "core/tensor.hpp"

#include <iostream>

namespace core {

  TensorShape::TensorShape() : _width(0), _height(0), _channels(0) {}
  TensorShape::TensorShape(size_t width, size_t height, size_t channels) : 
    _width(width),
    _height(height),
    _channels(channels) {
  }

  bool TensorShape::isEmpty() {
    bool ansver = _width | _height | _channels;
    return !ansver;
  }

  size_t TensorShape::getSize() {
    return _width * _height * _channels;
  }

  bool operator==(const TensorShape& sh_1, const TensorShape& sh_2) {
    return sh_1._width == sh_2._width && sh_1._height == sh_2._height &&
           sh_1._channels == sh_2._channels;
  }

  bool operator!=(const TensorShape& sh_1, const TensorShape& sh_2) {
    return !(sh_1 == sh_2);
  }
  size_t getPrecisionSize(const TensorPrecision& precision) {
    switch (precision) { 
    case TensorPrecision::UINT8:
      return 1;
    case TensorPrecision::FP32:
      return 4;
    case TensorPrecision::UINT64:
      return 8;
    default:
      std::cout << "Try to get size for unsupported precision" << std::endl;
    }
    return 0;
  }

  Tensor::Tensor(const TensorShape& shape, const TensorOrder& order, const TensorPrecision& precision) : 
    _shape(shape), _order(order), _precision(precision), _data(nullptr) {

  }
  Tensor::~Tensor() {
    if (_data) {
      free(_data);
    }
  }

  bool Tensor::allocate() {
    
    if (_shape.isEmpty()) {
      std::cout << "Try to allocate memory for empty shape" << std::endl;
      return false;
    }
    if (_data) {
      std::cout << "Already initialized" << std::endl;
      return false;
    }
    _data = malloc(_shape.getSize() * getPrecisionSize(_precision));
  }
} // namespace core
