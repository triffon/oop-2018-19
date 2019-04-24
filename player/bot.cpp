#include "bot.h"

Bot::Bot(char const* n, int s,
         char const* algo, double t,
         unsigned d) : Player(n, s), AI(algo, t),
                       difficulty(d)
{}

void Bot::print(std::ostream& os) const {
  Player::print();
  os << " и е бот с ниво на трудност "
     << getDifficulty()
     << ", реализиран от";
  AI::print();
}

std::ostream& operator<<(std::ostream& os, Bot const& b) {
  // разрешаване на нееднозначността: искаме << на Player
  return os << (Player const&)b;
}
