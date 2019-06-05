#ifndef __CLONEABLE_H
#define __CLONEABLE_H

class Cloneable {
public:
  virtual Cloneable* clone() const = 0;
};

#endif
