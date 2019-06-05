#ifndef __QUICK_TASK_H
#define __QUICK_TASK_H

#include "task.h"

class QuickTask : public Task {
  bool finished;
public:
  QuickTask(char const* n);

  unsigned getExecutionTime() const { return 1; }

  unsigned getProgress() const { return finished; }

  unsigned work(unsigned t = 1);

  void print(std::ostream& os = std::cout) const;

  Task* clone() const { return new QuickTask(*this); }
};

#endif
