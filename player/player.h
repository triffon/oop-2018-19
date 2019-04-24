#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>

const int MAX_NAME = 100;

class Player {
  // !!! char name[MAX_NAME];
  char* name;
  // поне MAX_NAME байта заделени за name
  int score;

public:
  
  Player(char const* n = "<Анонимен>", int s = 0);
  Player(Player const& p);
  Player& operator=(Player const& p);

  char const* getName() const { return name; }
  int getScore() const        { return score; }

  void setName(char const* n);
  void setScore(int s);
  
  virtual void print(std::ostream& = std::cout) const;

  Player& operator()(int s);

  virtual ~Player();

  void prettyPrint() const;
};

std::ostream& operator<<(std::ostream& os, Player const& p);

#endif

