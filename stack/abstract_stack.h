#ifndef __ABSTRACT_STACK_H
#define __ABSTRACT_STACK_H

template <typename T>
class AbstractStack {
public:
  // проверка за празнота на стек
  virtual bool empty() const = 0;

  // включване на елемент и връща дали е било успешно
  virtual bool push(T const& x) = 0;

  // изключване на елемент
  virtual T pop() = 0;

  // поглеждане на последно включения елемент
  virtual T peek() const = 0;
};

#endif
