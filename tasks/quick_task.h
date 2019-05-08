#include "task.h"

class QuickTask : public Task {
  bool finished;
public:
  QuickTask(char const* n);

  unsigned getExecutionTime() const { return 1; }

  unsigned getProgress() const { return finished; }

  unsigned work(unsigned t);

  void print(std::ostream& os = std::cout) const;
};
