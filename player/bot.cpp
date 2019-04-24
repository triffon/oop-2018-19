#include "bot.h"

Bot::Bot(char const* n,
         int s,
         unsigned d) : Player(n, s),
                       difficulty(d)
{}

void Bot::print(std::ostream& os) const {
  Player::print();
  os << " и е бот с ниво на трудност "
     << getDifficulty();
}
