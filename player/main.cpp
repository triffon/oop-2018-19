#include <iostream>
#include "player.h"
#include "hero.h"

void anonymousPrint(Player p) {
  p.setName("<Анонимен>");
  std::cout << p;
}

void testPlayer() {
  Hero p1("Гандалф Сивия", 45, 10);
  std::cout << p1;
  Player p2;//
  p2 = p1;
  p2.setName("Гандалф Белия");
  // p2.setScore(55);
  p2(10);
  std::cout << p1;
  std::cout << p2;
  anonymousPrint(p2);
  std::cout << p1;
  std::cout << p2;
}

void testInheritance() {
  Hero g("Гандалф Сивия", 45, 10);
  Player k("Кетнис Евърдийн", 55);
  std::cout << g;
  std::cout << k;
  Player* pp = &g;
  std::cout << *pp;
  Player& rp = g;
  std::cout << rp;
  Hero* ph = &g;
  Hero& rh = g;
  pp = ph;
  Player& rp2 = rh;
  std::cout << *pp << rp2;
  anonymousPrint(g);
  // !!! ph = pp;
  ph = (Hero*)pp;
  std::cout << *ph;
  // !!! Hero& rh2 = rp2;
  Hero& rh2 = (Hero&)rp2;
  std::cout << rh2;
  pp = &k;
  ph = (Hero*)pp;
  std::cout << *ph;
  std::cout << g.getName() << std::endl;
}

int main() {
  // testPlayer();
  testInheritance();
  return 0;
}
