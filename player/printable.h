#ifndef __PRINTABLE_H
#define __PRINTABLE_H

#include <iostream>

class Printable {
public:
  // извежда информация за обекта
  virtual void print(std::ostream& os = std::cout) const = 0;
};

std::ostream& operator<<(std::ostream& os, Printable const& p) {
  p.print(os);
  return os << std::endl;
}


#endif
