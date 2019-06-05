#include "simple_task.h"

SimpleTask::SimpleTask(char const* n, unsigned et) :
  Task(n), executionTime(et), progress(0) {}

void SimpleTask::print(std::ostream& os) const {
  os << "Проста ";
  Task::print(os);
}

unsigned SimpleTask::work(unsigned t) {
  if (isFinished() || t == 0)
    return t;

  // executionTime > progress

  unsigned spentEffort = std::min(t, executionTime - progress);
  progress += spentEffort;
  return t - spentEffort;
}
