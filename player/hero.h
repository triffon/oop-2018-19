#ifndef __HERO_H
#define __HERO_H

#include <iostream>

#include "player.h"

class Hero : public Player {
  unsigned level;

public:
  Hero(char const* n = "<Анонимен>",
       int s = 0,
       unsigned lvl = 1);

  unsigned getLevel() const { return level; }

  void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, Hero const& h);

#endif
