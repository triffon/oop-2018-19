#include <iostream>
#include <cmath>

#include "rational.h"
using namespace std;

void testRational() {
  Rational r1, r2(1, 2);

  r1.print();cout << endl;
  cout << r2.toDouble() << endl;
  r2.read();
  r2.print();cout << endl;
  cout << r2.toDouble() << endl;
  Rational r3(1, 2);
  add(r2, r3).print();cout << endl;
  subtract(r2, r3).print();cout << endl;
  multiply(r2, r3).print();cout << endl;
  divide(r2, r3).print();cout << endl;
}

Rational rationalExp(int k, int n) {
  Rational result(0, 1), yi(1, 1);
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
  cout << "k = ";cin >> k;
  int n;
  cout.precision(10);
  cout << "n = ";cin >> n;
  for(int i = 0; i <= n; i++) {
    Rational result = rationalExp(k, i);
    cout << "result = ";result.print();cout << endl;
    cout << "result ≈ " << result.toDouble() << endl;
    cout << "exp(k) = " << exp(k) << endl;
  }
}

int main() {
  //testRational();
  testExp();
  return 0;
}
