#include <iostream>
#include <cmath>

#include "rational.h"

void testRational() {
  Rational r1, r2(1, 2);

  r1.print();std::cout << std::endl;
  std::cout << r2.toDouble() << std::endl;
  r2.read();
  r2.print();std::cout << std::endl;
  std::cout << r2.toDouble() << std::endl;
  Rational r3(1, 2);
  add(r2, r3).print();std::cout << std::endl;
  subtract(r2, r3).print();std::cout << std::endl;
  multiply(r2, r3).print();std::cout << std::endl;
  divide(r2, r3).print();std::cout << std::endl;
}

Rational rationalExp(int k, int n) {
  Rational result = 0, yi = 1;
  for(int i = 0; i <= n; i++, yi = multiply(yi, Rational(k, i)))
    // result да е сумата до <i
    // yi да е i-тия общ член
    result = add(result, yi);
  
  // !!! result.denom = 0;
    // result да е сумата до i включително
    // yi да е (i+1)-вия общ член
  return result;
}

void testExp() {
  int k;
  std::cout << "k = ";std::cin >> k;
  int n;
  std::cout.precision(10);
  std::cout << "n = ";std::cin >> n;
  for(int i = 0; i <= n; i++) {
    Rational result = rationalExp(k, i);
    std::cout << "result = ";result.print();std::cout << std::endl;
    std::cout << "result ≈ " << result.toDouble() << std::endl;
    std::cout << "exp(k) = " << exp(k) << std::endl;
  }
  // !!!  std::cout << numer;
}

int main() {
  //testRational();
  testExp();
  const Rational ONE_HALF(1, 2);
  // !!! ONE_HALF.read();
  return 0;
}
