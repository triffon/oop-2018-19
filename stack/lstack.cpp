#include <iostream>
#include "lstack.h"

LinkedStack::LinkedStack() {
  top = nullptr;
}

bool LinkedStack::empty() const {
  return top == nullptr;
}

bool LinkedStack::push(int x) {
  // !!! top = new StackElement;
  StackElement* p = new StackElement;
  p->data = x;
  p->next = top;
  top = p;
  return true;
}

int LinkedStack::pop() {
  if (empty()) {
    std::cerr << "Опит за изваждане от празен стек!\n";
    return 0;
  }
  
  int result = peek();
  StackElement* p = top;
  top = top->next;
  delete p;
  return result;
}

int LinkedStack::peek() const {
  if (empty()) {
    std::cerr << "Опит за поглеждане в празен стек!\n";
    return 0;
  }

  return top->data;
}
