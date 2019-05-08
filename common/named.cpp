#include <cstring>
#include "named.h"

Named::Named(char const* n) : name(nullptr) {
  setName(n);
}

Named::Named(Named const& named) : name(nullptr) {
  setName(named.name);
}

Named& Named::operator=(const Named &named) {
  if (&named != this)
    setName(named.name);
  return *this;
}

Named::~Named() {
  delete[] name;
}

void Named::setName(char const* n)  {
  delete[] name;
  const int NAME_LENGTH = strlen(n);
  name = new char[NAME_LENGTH + 1];
  strcpy(name, n);
}
