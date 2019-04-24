#ifndef __BOT_H
#define __BOT_H

#include <iostream>
#include "player.h"
#include "ai.h"

class Bot : public Player, public AI {
private:
  unsigned difficulty;

public:
  Bot(char const* n = "<Анонимен>", int s = 0,
      char const* algo = "<неизвестен>", double t = 0, unsigned d = 1);


  unsigned getDifficulty() const { return difficulty; }

  void print(std::ostream& os = std::cout) const;

};

std::ostream& operator<<(std::ostream& os, Bot const& b);
#endif
