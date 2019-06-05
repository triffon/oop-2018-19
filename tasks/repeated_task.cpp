#include "repeated_task.h"

RepeatedTask::RepeatedTask(char const* n, Task const& t, unsigned r) :
  SimpleTask(n, r), current(nullptr) {
  prototype = t.clone();
  reset();
}

RepeatedTask::RepeatedTask(RepeatedTask const& rt) : SimpleTask(rt) {
  copy(rt);
}

RepeatedTask& RepeatedTask::operator=(RepeatedTask const& rt) {
  if (&rt != this) {
    SimpleTask::operator=(rt);
    destroy();
    copy(rt);
  }
  return *this;
}

RepeatedTask::~RepeatedTask() {
  destroy();
}

void RepeatedTask::copy(RepeatedTask const& rt) {
  prototype = rt.prototype->clone();
  current = rt.current->clone();
}

void RepeatedTask::destroy() {
  delete prototype;
  delete current;
}

void RepeatedTask::print(std::ostream& os) const {
  os << "Повтаряща се ";
  Task::print(os);
  os << ", която повтаря " << getRepetitions() << " пъти задачата: (";
  current->print(os);
  os << ") и вече са изпълнени " << getRepetitionProgress() << " повторения";
}

unsigned RepeatedTask::getExecutionTime() const {
  return getRepetitions() * prototype->getExecutionTime();
}

unsigned RepeatedTask::getProgress() const {
  return getRepetitionProgress() * prototype->getExecutionTime() +
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
  // "изработваме" едно повторение
  reset();
  SimpleTask::work();
  // има ли още задачи и време?
  if (isFinished() || t == 0)
    // не
    return t;

  // има още задачи за повтаряне
  // фаза 2: изпълняваме някакъв брой повторения на current
  unsigned leftRepetitions = SimpleTask::work(t / prototype->getExecutionTime());
  (t %= prototype->getExecutionTime())
     += leftRepetitions * prototype->getExecutionTime();

  // има ли още задачи?
  if (isFinished() || t == 0)
    // не
    return t;

  // фаза 3: изпълняваме докъдето можем current
  return current->work(t);
}
