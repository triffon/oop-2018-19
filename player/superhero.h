#ifndef __SUPERHERO_H
#define __SUPERHERO_H

#include <iostream>
#include "hero.h"

class SuperHero : public Hero {
  char* power;
  unsigned boost;
  bool super;

  void copy(SuperHero const& sh);

public:
  SuperHero(char const* n = "<Анонимен>",
            int s = 0,
            unsigned lvl = 1,
            char const* p = "неизвестна",
            unsigned b = 1);

  SuperHero(SuperHero const& sh);
  SuperHero& operator=(SuperHero const& sh);
  ~SuperHero();
  
  void becomeSuperHero() { super = true; }
  void stopBeingSuperHero() { super = false; }

  void print(std::ostream& os = std::cout) const;

  char const* getPower() const { return power; }
  unsigned getLevel() const;

  void setPower(char const* p);

};

std::ostream& operator<<(std::ostream& os, SuperHero const& sh);


#endif
