#include <iostream>
#include "rstack.h"

ResizingStack::ResizingStack() {
  top = EMPTY_STACK;
}

bool ResizingStack::empty() const {
  return top == EMPTY_STACK;
}

bool ResizingStack::push(int x) {
  if (full()) {
    std::cerr << "Опит за добавяне в пълен стек!\n";
    return false;
  }
  
  a[++top] = x;
  return true;
}

int ResizingStack::pop() {
  if (empty()) {
    std::cerr << "Опит за изваждане от празен стек!\n";
    return 0;
  }
  
  return a[top--];
}

int ResizingStack::peek() const {
  if (empty()) {
    std::cerr << "Опит за поглеждане в празен стек!\n";
    return 0;
  }

  return a[top];
}

bool ResizingStack::full() const {
  return top == MAX_STACK - 1;
}
