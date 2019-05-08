#ifndef __STACK_H
#define __STACK_H

#include "abstract_stack.h"

const int MAX_STACK = 200;

class Stack : public AbstractStack<int> {
  // представяне
  int a[MAX_STACK];  // памет за стека
  int top;           // връх на стека
                     // индекс на последно включения елемент в стека

  // проверка за пълен стек
  bool full() const;

public:
  // създаване на празен стек
  Stack();

  // проверка за празнота на стек
  bool empty() const;

  // включване на елемент и връща дали е било успешно
  bool push(int const& x);

  // изключване на елемент
  int pop();

  // поглеждане на последно включения елемент
  int peek() const;
};

#endif
