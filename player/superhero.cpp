#include <cstring>
#include "superhero.h"

SuperHero::SuperHero
   (char const* n, int s, unsigned lvl,
    char const* p, unsigned b) :
     Hero(n, s, lvl),
     power(nullptr), boost(b),
     super(false) {
  setPower(p);
}

void SuperHero::setPower(char const* p) {
  delete[] power;
  const int POWER_LENGTH = strlen(p);
  power = new char[POWER_LENGTH + 1];
  strcpy(power, p);
}

unsigned SuperHero::getLevel() const {
  if (super)
    return Hero::getLevel() + boost;
  return Hero::getLevel();
}

void SuperHero::print(std::ostream& os) const {
  Player::print();
  os << " и е супергерой на ниво " << getLevel()
     << " със суперсила " << getPower();
}

SuperHero::SuperHero(SuperHero const& sh) : power(nullptr), Hero(sh) {
  copy(sh);
}

void SuperHero::copy(SuperHero const& sh) {
  boost = sh.boost;
  super = sh.super;
  setPower(sh.power);
}

SuperHero::~SuperHero() {
  delete[] power;
}

SuperHero& SuperHero::operator=(SuperHero const& sh) {
  if (this != &sh) {
    // (Hero&)*this = sh;
    Hero::operator=(sh);
    delete[] power;
    copy(sh);
  }
  return *this;
}

