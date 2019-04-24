#ifndef __BOT_H
#define __BOT_H

#include <iostream>
#include "player.h"

class Bot : public Player {
private:
  unsigned difficulty;

public:
  Bot(char const* n = "<Анонимен>", int s = 0, unsigned d = 1);


  unsigned getDifficulty() const { return difficulty; }

  void print(std::ostream& os = std::cout) const;

};


#endif
