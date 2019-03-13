#ifndef __RATIONAL_H
#define __RATIONAL_H

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
  Rational();
  Rational(long n, long d);

  // Ниво 1: селектори
  long getNumerator()   const { return numer; }
  long getDenominator() const { return denom; }

  void print() const;
  double toDouble() const;

  // Ниво 2: мутатори
  void read();
}; // !!! onehalf(1, 2);

// Ниво 2: аритметични операции
Rational add(Rational p, Rational q);
Rational subtract(Rational p, Rational q);
Rational multiply(Rational p, Rational q);
Rational divide(Rational p, Rational q);

#endif