#ifndef __SIMPLE_TASK_H
#define __SIMPLE_TASK_H

#include "task.h"

class SimpleTask : public Task {
  unsigned executionTime;
  unsigned progress;
public:
  SimpleTask(char const* n, unsigned et);

  unsigned getExecutionTime() const { return executionTime; }

  unsigned getProgress() const { return progress; }

  unsigned work(unsigned t = 1);

  void print(std::ostream& os = std::cout) const;
};

#endif
