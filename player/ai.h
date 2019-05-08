#ifndef __AI_H
#define __AI_H

#include "../common/printable.h"

class AI : virtual public Printable {
private:
  char* algorithm;
  double threshold;

  void setAlgorithm(char const* algo);
  void copy(AI const& ai);

public:
  AI(char const* algo = "<неизвестен>", double t = 0);

  AI(AI const&);
  AI& operator=(AI const&);
  ~AI();

  char const* getAlgorithm() const { return algorithm; }
  double getThreshold() const { return threshold; }

  void print(std::ostream& os = std::cout) const;
  
};

std::ostream& operator<<(std::ostream& os, AI const& ai);

#endif
