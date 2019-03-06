#ifndef __STACK_H
#define __STACK_H

const int MAX_STACK = 100;
const int EMPTY_STACK = -1;

class Stack {
  // представяне
  int a[MAX_STACK];  // памет за стека
  int top;           // връх на стека
                     // индекс на последно включения елемент в стека

public:
  // създаване на празен стек
  Stack();

  // проверка за празнота на стек
  bool empty() const;

  // включване на елемент
  void push(int x);

  // изключване на елемент
  int pop();

  // поглеждане на последно включения елемент
  int peek() const;
};

#endif
