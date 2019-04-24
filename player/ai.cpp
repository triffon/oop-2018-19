#include <cstring>
#include "ai.h"

AI::AI(char const* algo,
       double t) : algorithm(nullptr),
                   threshold(t) {
  setAlgorithm(algo);
}

void AI::setAlgorithm(char const* algo) {
  delete[] algorithm;
  const int ALGORITHM_LENGTH = strlen(algo);
  algorithm = new char[ALGORITHM_LENGTH + 1];
  strcpy(algorithm, algo);  
}

void AI::print(std::ostream& os) const {
  os << "Изкуствен интелект с алгоритъм "
     << algorithm
     << " и праг " << threshold;
}

void AI::copy(AI const& ai) {
  threshold = ai.threshold;
  setAlgorithm(ai.algorithm);
}

AI::AI(AI const& ai) : algorithm(nullptr) {
  copy(ai);
}

AI& AI::operator=(AI const& ai) {
  if (this != &ai)
    copy(ai);
  return *this;
}

AI::~AI() {
  delete[] algorithm;
}

std::ostream& operator<<(std::ostream& os, AI const& ai) {
  ai.print(os);
  return os << std::endl;
}
