#include <iostream>
#include "stack.h"

Stack::Stack() {
  top = EMPTY_STACK;
}

bool Stack::empty() const {
  return top == EMPTY_STACK;
}

bool Stack::push(int x) {
  if (full()) {
    std::cerr << "Опит за добавяне в пълен стек!\n";
    return false;
  }
  
  a[++top] = x;
  return true;
}

int Stack::pop() {
  if (empty()) {
    std::cerr << "Опит за изваждане от празен стек!\n";
    return 0;
  }
  
  return a[top--];
}

int Stack::peek() const {
  if (empty()) {
    std::cerr << "Опит за поглеждане в празен стек!\n";
    return 0;
  }

  return a[top];
}

bool Stack::full() const {
  return top == MAX_STACK - 1;
}
