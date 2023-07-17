// Copyright 2023 @saito
#include <iostream>
#include <boost/array.hpp>

#include "../src/sample/sample.hh"
#include "factory_method/factory_method.hh"

int main() {
  constexpr uint8_t kN = 4;
  boost::array<int, kN> arr = {{1, 2, 3, 4}};

  for (int i = 0; i < kN; ++i) {
    std::cout << arr[i] << std::endl;
  }

  const int kSum = Sample::sum(3, 4);
  std::cout << kSum << std::endl;

  factory_method::execute();

  return 0;
}
