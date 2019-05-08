#include "task.h"

void Task::print(std::ostream& os) const {
  os << "задача '" << getName() << "', която изисква "
     << getExecutionTime() << " единици време"
     << " и е с прогрес " << getProgress();
}

Task::Task(char const* n) : Named(n) {}
