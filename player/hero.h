#ifndef __HERO_H
#define __HERO_H

#include <iostream>

#include "player.h"

class Hero : virtual public Player {
  unsigned level;

public:
  Hero(char const* n = "<Анонимен>",
       int s = 0,
       unsigned lvl = 1);

  virtual unsigned getLevel() const { return level; }

  void print(std::ostream& os = std::cout) const;

protected:
  void printDirect(std::ostream& os = std::cout) const;
};

#endif
