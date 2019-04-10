#include <iostream>

#include "bitarray.h"

void testBitArray() {
  BitArray b = 98743212134;
  std::cout << b;
  b.set(3, 1);
  b.set(6, 0);
  std::cout << b;
}

int main() {
  testBitArray();
  return 0;
}
