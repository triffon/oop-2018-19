#ifndef __CLONEABLE_H
#define __CLONEABLE_H

template <typename T>
class Cloneable {
public:
  virtual T* clone() const = 0;
};

#endif
