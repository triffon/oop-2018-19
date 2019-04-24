#ifndef __BOSS_H
#define __BOSS_H

#include "bot.h"
#include "hero.h"

class Boss : public Bot, public Hero {
private:
  unsigned damage;

public:
  Boss(char const* n = "<анонимен>", int s = 0,
       char const* algo = "<неизвестен>", double t = 0,
       unsigned d = 1, unsigned lvl = 1, unsigned dmg = 10);

  unsigned getDamage() const { return damage; }

  void print(std::ostream& os = std::cout) const;
};

#endif
