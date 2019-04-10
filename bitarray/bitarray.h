#ifndef _BITARRAY_H
#define _BITARRAY_H

#include <iostream>

using bit = bool;
using bits = unsigned long;
using index = unsigned;

class BitArray {
  bits a;

  void setBit(index i); // = 1
  void resetBit(index i); // = 0

  bits mask1(index i) const;
  bits mask0(index i) const;

public:
  BitArray(bits init) : a(init) {}

  unsigned size() const { return sizeof(bits) * 8; }

  void set(index i, bit x);
  bit get(index i) const;
  void flip(index i);
};

std::ostream& operator<<(std::ostream& os, BitArray const& ba);

#endif
