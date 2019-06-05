#ifndef __REPEATED_TASK_H
#define __REPEATED_TASK_H

#include "task.h"

class RepeatedTask : public Task {
  Task const* prototype;
  Task* current;
  unsigned repetitions;
  unsigned repetitionProgress;

  void reset() {
    delete current;
    current = (Task*)prototype->clone();
  }

  void copy(RepeatedTask const&);
  void destroy();
  
public:
  RepeatedTask(char const* n, Task const& t, unsigned r);

  RepeatedTask(RepeatedTask const&);
  RepeatedTask& operator=(RepeatedTask const&);
  ~RepeatedTask();

  unsigned getExecutionTime() const;

  unsigned getProgress() const;

  unsigned work(unsigned t = 1);

  void print(std::ostream& os = std::cout) const;

  Cloneable* clone() const { return new RepeatedTask(*this); }
};

#endif
