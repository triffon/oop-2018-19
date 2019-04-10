#include "bitarray.h"

void BitArray::set(index i, bit x) {
  if (x)
    setBit(i);
  else
    resetBit(i);
}

bit BitArray::get(index i) const {
  return (a & mask1(i)) != 0;
}

void BitArray::flip(index i) {
  a ^= mask1(i);
}

void BitArray::setBit(index i) {
  a |= mask1(i);
}

void BitArray::resetBit(index i) {
  a &= mask0(i);
}

bits BitArray::mask1(index i) const {
  return 1 << i;
}

bits BitArray::mask0(index i) const {
  return ~mask1(i);
}

std::ostream& operator<<(std::ostream& os, BitArray const& ba) {
  for(int i = 0; i < ba.size(); i++)
    os << ba.get(i);
  return os << std::endl;
}
