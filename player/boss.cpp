#include "boss.h"

Boss::Boss(char const* n, int s,
           char const* algo, double t,
           unsigned d, unsigned lvl, unsigned dmg) :
  Player(n, s), Hero(n, s, lvl), Bot(n, s, algo, t, d), damage(dmg) {}

void Boss::print(std::ostream& os) const {
  Player::print(os);
  printDirect(os);
}

void Boss::printDirect(std::ostream& os) const {
  os << ", който е boss";
  Hero::printDirect(os);
  Bot::printDirect(os);
  os << " и нанася поражения " << getDamage();
}
