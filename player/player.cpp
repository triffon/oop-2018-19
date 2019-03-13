#include <iostream>
#include <cstring>
#include "player.h"

Player::Player(char const* n, int s) : score(s) {
  name = new char[MAX_NAME];
  setName(n);
}

void Player::setName(char const* n) {
  strncpy(name, n, MAX_NAME);
  name[MAX_NAME - 1] = '\0';
}

void Player::setScore(int s) {
  score = s;
}

void Player::print() const {
  std::cout << "Играчът " << name
            << " има " << score << " точки"
            << std::endl;
}
