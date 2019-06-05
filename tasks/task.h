#ifndef __TASK_H
#define __TASK_H

#include "../common/printable.h"
#include "../common/named.h"
#include "../common/cloneable.h"

class Task : public Printable, public Named, public Cloneable<Task> {
  
public:

  Task(char const* n);
  
  // извежда собствените член-данни
  void print(std::ostream& os = std::cout) const;

  // време за изпълнение на задачата
  virtual unsigned getExecutionTime() const = 0;

  // прогрес по задачата
  virtual unsigned getProgress() const = 0;

  bool isFinished() const {
    return getProgress() == getExecutionTime();
  }

  // отчита time единици работа по задачата
  // връща броя неизползвани единици време
  virtual unsigned work(unsigned time = 1) = 0;

  
};

#endif
