#ifndef __PLAYER_H
#define __PLAYER_H

const int MAX_NAME = 100;

class Player {
  // !!! char name[MAX_NAME];
  char* name;
  int score;

public:
  
  Player(char const* n = "<Анонимен>", int s = 0);

  char const* getName() const { return name; }
  int getScore() const        { return score; }

  void setName(char const* n);
  void setScore(int s);
  
  void print() const;
};

#endif

