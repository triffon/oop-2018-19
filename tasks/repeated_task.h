#ifndef __REPEATED_TASK_H
#define __REPEATED_TASK_H

#include "task.h"

class RepeatedTask : public Task {
  Task* repeatTask;
  unsigned repetitions;
  unsigned repetitionProgress;
public:
  RepeatedTask(char const* n, Task const& t, unsigned r);

  unsigned getExecutionTime() const;

  unsigned getProgress() const;

  unsigned work(unsigned t = 1);

  void print(std::ostream& os = std::cout) const;
};

#endif
