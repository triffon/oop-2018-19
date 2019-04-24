#include <iostream>
#include <typeinfo>
#include "player.h"
#include "hero.h"
#include "superhero.h"
#include "bot.h"
#include "boss.h"

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
  Hero g2 = g;
  std::cout << g2;

  SuperHero s("Супермен", 100, 5, "летене", 10);
  std::cout << s;
  s.becomeSuperHero();
  std::cout << s;
  s.stopBeingSuperHero();
  std::cout << s;

  SuperHero s2;
  s2 = s;
  std::cout << s2;
  s2.setPower("хвърчене");
  std::cout << s << s2;
}

Hero* battle(Hero& h1, Hero& h2, unsigned prize) {
  Hero* winner = nullptr;
  std::cout << "Битка между ";
  h1.print();
  std::cout << " и ";
  h2.print();
  std::cout << std::endl;
  if (h1.getLevel() > h2.getLevel())
    winner = &h1;
  if (h1.getLevel() < h2.getLevel())
    winner = &h2;
  if (winner != nullptr) {
    std::cout << "Победител е: " << *winner;
    winner->setScore(winner->getScore() + prize);
  } else
    std::cout << "Няма победител!" << std::endl;
  return winner;
}

void testBattle() {
  Hero g("Гандалф Сивия", 45, 10);
  SuperHero s("Супермен", 100, 5, "летене", 10);
  Hero& h1 = g;
  Hero& h2 = s;
  battle(h1, h2, 20);
  s.becomeSuperHero();
  battle(h1, h2, 20);
  std::cout << typeid(h1).name() << ' ' << typeid(h2).name() << std::endl;
  std::cout << typeid(std::cout).name() << std::endl;
}

void testBinding() {
  Player* pp;
  pp = new Player("Кетнис Евърдийн", 55);
  std::cout << *pp;
  //  pp->print();
  //pp->prettyPrint();
  delete pp;
  pp = new Hero("Гандалф Сивия", 45, 10);
  std::cout << *pp;
  //pp->print();
  //pp->prettyPrint();
  delete pp;
  pp = new SuperHero("Супермен", 100, 5, "летене", 10);
  std::cout << *pp;
  //pp->print();
  //pp->prettyPrint();
  Bot b("HAL 9000", 100, "α-β", 0.7, 9000);
  pp = &b;
  //pp->prettyPrint();
  std::cout << *pp;
  std::cout << b;
  //pp->print();
  //b.print();
}

void testBoss() {
  Boss boss("Саурон", 50, "Тъмни сили", 2.8, 
            100, 20, 1000);
  boss.print();
  std::cout << ((Hero&)boss).getName() << std::endl;
  std::cout << ((Bot&)boss).getName() << std::endl;
}

int main() {
  // testPlayer();
  // testInheritance();
  // testBattle();
  // testBinding();
  testBoss();
  return 0;
}
