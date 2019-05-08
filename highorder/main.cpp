#include <iostream>
#include <cmath>
#include <cstring>

void testtypes() {
  std::cout << (void*)testtypes << std::endl;
  std::cout << (void*)strcpy << std::endl;
  int* p;
  void (*f)(int&, int&) = std::swap;

  // !!! void g(int&, int&);
  // !!! void g(int&, int&) = std::swap;

  int x = 2, y = 3;
  // !!! g(x, y);

  // !!! void (*q)(int, int&) = f;
  f(x, y);
  std::cout << x << ' ' << y << std::endl;

  using ref = int&;
  ref z = x;
  z = 10;
  std::cout << x << std::endl;
}

int plus1(int x) { return x + 1; }
int plus2(int x) { return x + 2; }
int mult2(int x) { return x * 2; }

double plus(double x, double y) { return x + y; }
double mult(double x, double y) { return x * y; }

double log2(double x) { return std::log(x) / std::log(2); }
double id(double x) { return x; }
double const2(double x) { return 2; }

using nextfun = int (*)(int);
using mathfun = double (*)(double);
using mathop  = double (*)(double, double);

template <typename F>
double accumulate(mathop op, double base_value,
                  int a, int b,
                  F f, nextfun next) {
  double result = base_value;
  for(int i = a; i <= b; i = next(i))
    result = op(result, f(i));
  return result;
}

int fact(int n) {
  return accumulate(mult, 1, 1, n, id, plus1);
}

double expt(double x, int n) {
  return accumulate(mult, 1, 1, n, [x](double i) { return x; }, plus1);
}

double termexp(double i) {
  return expt(2, i) / fact(i);
}

double myexp2(int n) {
  return accumulate(plus, 0, 0, n, termexp, plus1);
}

double termsin(double i) {
  int n = i / 2;
  int sign = n % 2 == 0 ? 1 : -1;
  return sign * termexp(i);
}

double mysin2(int n) {
  return accumulate(plus, 0, 1, 2*n + 1, termsin, [](int n) { return n + 2; });
}

void testaccumulate() {
  std::cout << accumulate(plus, 0, 1, 1024, log2, mult2) << std::endl;
  std::cout << accumulate(mult, 1, 5, 50, sin, plus1) << std::endl;
  std::cout << fact(7) << std::endl;
  std::cout << expt(2, 10) << std::endl;
  std::cout << expt(3, 5) << std::endl;
  std::cout << myexp2(10) << std::endl;
  std::cout << exp(2) << std::endl;
  std::cout << mysin2(10) << std::endl;
  std::cout << sin(2) << std::endl;
}

const double EPS = 1E-6;
mathfun function = nullptr;

double derivative(double x) {
  return (function(x + EPS) - function(x)) / EPS;
}

template <typename F>
auto derive(F f) {
  //function = f;
  //return derivative;
  return [f](double x) {
    return (f(x + EPS) - f(x)) / EPS;
  };
}

void testderive() {
  auto mycos = derive(sin);
  std::cout << mycos(5) << std::endl;
  std::cout << cos(5) << std::endl;
  std::cout << derive(exp)(2) << std::endl;
  std::cout << exp(2) << std::endl;
  std::cout << derive(derive(sin))(2) << std::endl;
  std::cout << -sin(2) << std::endl;
}

int main() {
  // testtypes();
  testaccumulate();
  testderive();
  return 0;
}
