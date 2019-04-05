#ifndef __LSTACK_CPP
#define __LSTACK_CPP

#include <iostream>

template <typename T>
struct StackElement {
  T data;
  StackElement* next;
};

template <typename T>
class LinkedStack {
  // представяне
  StackElement<T>* top; // указател към връх на стека

  void copy(LinkedStack const& ls);

  void erase();
  
public:
  // създаване на празен стек
  LinkedStack();

  // конструктор за копиране
  LinkedStack(LinkedStack const& ls);

  // операция за присвояване
  LinkedStack& operator=(LinkedStack const& ls);

  // проверка за празнота на стек
  bool empty() const;

  // включване на елемент и връща дали е било успешно
  bool push(T const& x);

  // изключване на елемент
  T pop();

  // поглеждане на последно включения елемент
  T peek() const;

  ~LinkedStack();
};

template <typename T>
LinkedStack<T>::LinkedStack() {
  top = nullptr;
}

template <typename T>
bool LinkedStack<T>::empty() const {
  return top == nullptr;
}

template <typename T>
bool LinkedStack<T>::push(T const& x) {
  // !!! top = new StackElement;
  StackElement<T>* p = new StackElement<T>;
  p->data = x;
  p->next = top;
  top = p;
  return true;
}

template <typename T>
T LinkedStack<T>::pop() {
  if (empty()) {
    std::cerr << "Опит за изваждане от празен стек!\n";
    return 0;
  }
  
  T result = peek();
  StackElement<T>* p = top;
  top = top->next;
  delete p;
  return result;
}

template <typename T>
T LinkedStack<T>::peek() const {
  if (empty()) {
    std::cerr << "Опит за поглеждане в празен стек!\n";
    return 0;
  }

  return top->data;
}

template <typename T>
void LinkedStack<T>::copy(LinkedStack<T> const& ls) {
  top = nullptr;
    // !!! top = ls.top;
  /*
  !!! LinkedStack tmp = ls;
  while (!tmp.empty()) {
    push(tmp.pop());
  }
  */
  StackElement<T>* p = ls.top;
  LinkedStack<T> tmp;
  while (p != nullptr) {
    tmp.push(p->data);
    p = p->next;
  }
  while (!tmp.empty())
    push(tmp.pop());
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T> const& ls)  {
  copy(ls);
}

template <typename T>
void LinkedStack<T>::erase() {
  // !!! delete top;
  while (!empty()) {
    pop();
  }
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
  erase();
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> const& ls) {
  if (this != &ls) {
    erase();
    copy(ls);
  }
  return *this;
}

#endif
