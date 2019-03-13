#ifndef __RSTACK_H
#define __RSTACK_H

const int MAX_STACK = 100;
const int EMPTY_STACK = -1;

class ResizingStack {
  // представяне
  int a[MAX_STACK];  // указател към масив в динамичната памет за стека
  int top;           // връх на стека
                     // индекс на последно включения елемент в стека

  // проверка за пълен стек
  bool full() const;

public:
  // създаване на празен стек
  ResizingStack();

  // проверка за празнота на стек
  bool empty() const;

  // включване на елемент и връща дали е било успешно
  bool push(int x);

  // изключване на елемент
  int pop();

  // поглеждане на последно включения елемент
  int peek() const;
};

#endif
