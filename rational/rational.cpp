#include <iostream>
#include "rational.h"

using std::cout;
using std::cin;
using std::endl;

void set(int n, int d) {
  cout << "I am the global function set!\n";
}

// Ниво 1: служебни селектори и мутатори
long Rational::gcd(long x, long y) {
  while (x != y)
    if (x > y)
      x -= y;
    else
      y -= x;
  // x == y
  return x;
}
  
void Rational::set(long n, long d) {
  if (d == 0 || n == 0) {
    numer = 0;
    denom = 1;
  } else {
    long g = gcd(n, d);
    numer = n / g;
    denom = d / g;
  }
}
  
// Ниво 1: конструктори
Rational::Rational(long n, long d) {
  set(n, d);
  // !!! ::set(n, d);
}

void Rational::print() const {
  // !!! numer++;
  cout << numer << '/' << denom;
}

double Rational::toDouble() const {
  return (double)numer / denom;
}

// Ниво 2: мутатори
void Rational::read() {
  char c; // въвеждане на /
  long n, d;
  cin >> n >> c >> d;
  set(n, d);
}

// Ниво 2: аритметични операции
Rational add(Rational p, Rational q) {
  // !!! cout << this->getNumerator() << endl;
  return Rational(p.getNumerator() * q.getDenominator() +
                  q.getNumerator() * p.getDenominator(),
                  p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational p, Rational q) {
  return Rational(p.getNumerator() * q.getDenominator() -
                  q.getNumerator() * p.getDenominator(),
                  p.getDenominator() * q.getDenominator());
}

Rational multiply(Rational p, Rational q) {
  return Rational(p.getNumerator() * q.getNumerator(),
                  p.getDenominator() * q.getDenominator());
}

Rational divide(Rational p, Rational q) {
  return Rational(p.getNumerator() * q.getDenominator(),
                  p.getDenominator() * q.getNumerator());
}
