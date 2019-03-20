#include <iostream>
#include "player.h"

void anonymousPrint(Player p) {
  p.setName("<Анонимен>");
  p.print();
}

void testPlayer() {
  Player p1("Гандалф Сивия", 45);
  p1.print();
  Player p2;//
  p2 = p1;
  p2.setName("Гандалф Белия");
  p2.setScore(55);
  p1.print();
  p2.print();
  anonymousPrint(p2);
  p1.print();
  p2.print();
}

int main() {
  testPlayer();
  return 0;
}
