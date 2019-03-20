#include <iostream>
#include "rstack.h"

ResizingStack::ResizingStack() {
  capacity = INITIAL_CAPACITY;
  a = new int[capacity];
  top = EMPTY_STACK;
}

bool ResizingStack::empty() const {
  return top == EMPTY_STACK;
}

bool ResizingStack::push(int x) {
  if (full()) {
    resize();
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
  return top >= capacity - 1;
}

void ResizingStack::resize() {
  int new_capacity = capacity * RESIZE_FACTOR;
  std::clog << "Разширяваме стека до " << new_capacity << " елемента\n";
  int* newa = new int[new_capacity];
  for(int i = 0; i < capacity; i++)
    newa[i] = a[i];
  delete[] a;
  a = newa;
  capacity = new_capacity;
}