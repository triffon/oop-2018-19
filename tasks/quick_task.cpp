#include "quick_task.h"

void QuickTask::print(std::ostream& os) const {
  os << "Бърза ";
  Task::print(os);
}

QuickTask::QuickTask(char const* n) :
  Task(n), finished(false) {}

unsigned QuickTask::work(unsigned t) {
  if (finished || t == 0)
    return t;

  finished = true;
  return t - 1;
}
