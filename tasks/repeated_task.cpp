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
