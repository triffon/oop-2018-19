#ifndef __PLAYER_H
#define __PLAYER_H

#include "../common/printable.h"
#include "../common/named.h"

const int MAX_NAME = 100;

class Player : virtual public Printable, public Named {
  // !!! char name[MAX_NAME];
  // поне MAX_NAME байта заделени за name
  int score;

public:
  
  Player(char const* n = "<Анонимен>", int s = 0);

  int getScore() const        { return score; }

  void setScore(int s);
  
  virtual void print(std::ostream& = std::cout) const;

  Player& operator()(int s);

  virtual ~Player() {}

  void prettyPrint() const;
};

std::ostream& operator<<(std::ostream& os, Player const& p);

#endif

