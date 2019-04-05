#ifndef __RATIONAL_H
#define __RATIONAL_H

#include <iostream>

class Rational {
  // Ниво 0: физическо представяне
  // Искаме numer и denom да са несъкратими
  // Инвариант: gcd(numer, denom) == 1
  long numer, denom;

  // Ниво 1: служебни селектори и мутатори
  long gcd(long x, long y);
  void set(long n, long d);

public:
  // Ниво 1: конструктори
  Rational(long n = 0, long d = 1);

  // Ниво 1: селектори
  long getNumerator()   const { return numer; }
  long getDenominator() const { return denom; }

  double toDouble() const;
  
  operator double() const;

  // Ниво 2: аритметични операции
  Rational operator+(Rational const& q) const;
  Rational operator-(Rational const& q) const;
  Rational operator*(Rational const& q) const;
  Rational operator/(Rational const& q) const;

  Rational& operator+=(Rational const& q);
  Rational& operator*=(Rational const& q);

  friend std::istream& operator>>(std::istream& is, Rational& r);
}; // !!! onehalf(1, 2);

Rational operator*(long n, Rational const& r);

// Ниво 2: операции за вход и изход
std::istream& operator>>(std::istream& is, Rational& r);
std::ostream& operator<<(std::ostream& os, Rational const& r);

#endif
