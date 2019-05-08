#ifndef __NAMED_H
#define __NAMED_H

class Named {
  char* name;
  
public:

  Named(char const* n = "<няма име>");
  Named(Named const& named);
  Named& operator=(Named const& named);
  ~Named();

  char const* getName() const { return name; }
  
  void setName(char const* n);
};

#endif
