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

std::ostream& operator<<(std::ostream& os, Rational const& r) {
  // !!! numer++;
  return os << r.getNumerator() << '/' << r.getDenominator();
}

double Rational::toDouble() const {
  return (double)numer / denom;
}

// Ниво 2: мутатори
std::istream& operator>>(std::istream& is, Rational& r) {
  char c; // въвеждане на /
  long n, d;
  is >> n >> c >> d;
  r.set(n, d);
  return is;
}

// Ниво 2: аритметични операции
Rational Rational::operator+(Rational const& q) const {
  // !!! cout << this->getNumerator() << endl;
  return Rational(getNumerator() * q.getDenominator() +
                  q.getNumerator() * getDenominator(),
                  getDenominator() * q.getDenominator());
}

Rational Rational::operator-(Rational const& q) const {
  return Rational(getNumerator() * q.getDenominator() -
                  q.getNumerator() * getDenominator(),
                  getDenominator() * q.getDenominator());
}

Rational& Rational::operator*=(Rational const& q) {
  set(getNumerator() * q.getNumerator(), getDenominator() * q.getDenominator());
  return *this;
}

Rational& Rational::operator+=(Rational const& q) {
  return (*this = *this + q);
}

Rational Rational::operator*(Rational const& q) const {
  /*  return Rational(getNumerator() * q.getNumerator(),
                  getDenominator() * q.getDenominator());
  */
  Rational r = *this;
  r *= q;
  return r;
}

Rational Rational::operator/(Rational const& q) const {
  return Rational(getNumerator() * q.getDenominator(),
                  getDenominator() * q.getNumerator());
}

Rational operator*(long n, Rational const& r) {
  // !!!  return r * n;
  //  return r * Rational(n);
  return r.operator*(n);
}

Rational::operator double() const {
  return toDouble();
}
