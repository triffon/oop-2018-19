#include <iostream>
#include <cstring>
#include "player.h"

Player::Player(char const* n, int s) : name(nullptr), score(s) {
  setName(n);
}

Player::Player(Player const& p) : name(nullptr), score(p.score) {
  // !!! name = p.name;
  // !!! name = new char[std::max((int)strlen(p.name) + 1, MAX_NAME)];
  // !!! strcpy(name, p.name);
  setName(p.name);
}

void Player::setName(char const* n) {
  delete[] name;
  const int NAME_LENGTH = strlen(n);
  name = new char[NAME_LENGTH + 1];
  strcpy(name, n);
}

void Player::setScore(int s) {
  score = s;
}

void Player::print() const {
  std::cout << "Играчът " << name
            << " има " << score << " точки"
            << std::endl;
}

Player::~Player() {
  delete[] name;
}

Player& Player::operator=(Player const& p) {
  if (this != &p) {
    setName(p.name);
    score = p.score;
  }
  return *this;
}

Player& Player::operator()(int s) {
  setScore(getScore() + s);
  return *this;
}
