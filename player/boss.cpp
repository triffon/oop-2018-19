#include "boss.h"

Boss::Boss(char const* n, int s,
           char const* algo, double t,
           unsigned d, unsigned lvl, unsigned dmg) :
  Hero("Boss", s, lvl), Bot(n, s, algo, t, d), damage(dmg) {}

void Boss::print(std::ostream& os) const {
  Hero::print(os);
  Bot::print(os);
  os << " и нанася поражения " << getDamage();
}

