#ifndef __REPEATED_TASK_H
#define __REPEATED_TASK_H

#include "simple_task.h"

class RepeatedTask : public SimpleTask {
  Task const* prototype;
  Task* current;

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

  Task* clone() const { return new RepeatedTask(*this); }

  unsigned getRepetitions() const { return SimpleTask::getExecutionTime(); }

  unsigned getRepetitionProgress() const { return SimpleTask::getProgress(); }
};

#endif
