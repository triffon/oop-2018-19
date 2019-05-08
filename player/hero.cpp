#include <iostream>
#include "hero.h"

Hero::Hero(char const* n, int s,
           unsigned lvl) : level(lvl), Player(n, s) {
}

void Hero::printDirect(std::ostream& os) const {
  os << " и е герой на ниво " << getLevel();
}

void Hero::print(std::ostream& os) const {
  Player::print(os);
  printDirect(os);
}
