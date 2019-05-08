#include <iostream>
#include "player.h"

Player::Player(char const* n, int s) : Named(n), score(s) {}

void Player::setScore(int s) {
  score = s;
}

void Player::print(std::ostream& os) const {
  os << "Играчът " << getName()
     << " има " << getScore() << " точки";
}

Player& Player::operator()(int s) {
  setScore(getScore() + s);
  return *this;
}

std::ostream& operator<<(std::ostream& os, Player const& p) {
  p.print(os);
  return os << std::endl;
}

void Player::prettyPrint() const {
  std::cout << "------------------------------ [Играч] ------------------------------\n";
  print();
  std::cout << "\n---------------------------------------------------------------------\n";
}
