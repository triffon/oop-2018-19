#include "repeated_task.h"

RepeatedTask::RepeatedTask(char const* n, Task const& t, unsigned r) :
  Task(n), repetitions(r), repetitionProgress(0), current(nullptr) {
  prototype = (Task*)t.clone();
  reset();
}

RepeatedTask::RepeatedTask(RepeatedTask const& rt) : Task(rt) {
  copy(rt);
}

RepeatedTask& RepeatedTask::operator=(RepeatedTask const& rt) {
  if (&rt != this) {
    Task::operator=(rt);
    destroy();
    copy(rt);
  }
  return *this;
}

RepeatedTask::~RepeatedTask() {
  destroy();
}

void RepeatedTask::copy(RepeatedTask const& rt) {
  repetitions = rt.repetitions;
  repetitionProgress = rt.repetitionProgress;
  prototype = (Task*)rt.prototype->clone();
  current = (Task*)rt.current->clone();
}

void RepeatedTask::destroy() {
  delete prototype;
  delete current;
}

void RepeatedTask::print(std::ostream& os) const {
  os << "Повтаряща се ";
  Task::print(os);
  os << ", която повтаря " << repetitions << " пъти задачата: (";
  current->print(os);
  os << ") и вече са изпълнени " << repetitionProgress << " повторения";
}

unsigned RepeatedTask::getExecutionTime() const {
  return repetitions * prototype->getExecutionTime();
}

unsigned RepeatedTask::getProgress() const {
  return repetitionProgress * prototype->getExecutionTime() +
    current->getProgress();
}

unsigned RepeatedTask::work(unsigned t) {
  if (isFinished() || t == 0)
    return t;

  // фаза 1: довършваме текущата задача
  t = current->work(t);

  // ще има ли други фази?
  if (!current->isFinished()) // не сме завършили текущата задача
    return t;

  // завършили сме текущата задача
  repetitionProgress++;
  // има ли още задачи и време?
  if (isFinished() || t == 0)
    // не
    return t;

  // има още задачи за повтаряне
  reset();
  
  // фаза 2: изпълняваме някакъв брой повторения на current
  unsigned spentRepetitions = std::min(t / prototype->getExecutionTime(),
                                       repetitions - repetitionProgress);
  repetitionProgress += spentRepetitions;
  t -= spentRepetitions * prototype->getExecutionTime();

  // има ли още задачи?
  if (isFinished() || t == 0)
    // не
    return t;

  // фаза 3: изпълняваме докъдето можем current
  return current->work(t);
}
