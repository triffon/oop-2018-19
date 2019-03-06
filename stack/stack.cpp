#include "stack.h"

Stack::Stack() {
  top = EMPTY_STACK;
}

bool Stack::empty() const {
  return top == EMPTY_STACK;
}

void Stack::push(int x) {
  a[++top] = x;
}

int Stack::pop() {
  return a[top--];
}

int Stack::peek() const {
  return a[top];
}
