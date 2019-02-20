#include <iostream>
#include <cmath>
using namespace std;

struct Rational {
  // Ниво 0: физическо представяне
  // Искаме numer и denom да са несъкратими
  // Инвариант: gcd(numer, denom) == 1
  long numer, denom;

  // Ниво 1: служебни селектори и мутатори
  long gcd(long x, long y) {
    while (x != y)
      if (x > y)
        x -= y;
      else
        y -= x;
    // x == y
    return x;
  }
  
  void set(long n, long d) {
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
  Rational() {
    numer = 0;
    denom = 1;
  }

  Rational(long n, long d) {
    set(n, d);
  }

  // Ниво 1: селектори
  long getNumerator()   { return numer; }
  long getDenominator() { return denom; }

  void print() {
    cout << numer << '/' << denom;
  }

  double toDouble() {
    return (double)numer / denom;
  }

  // Ниво 2: мутатори
  void read() {
    char c; // въвеждане на /
    long n, d;
    cin >> n >> c >> d;
    set(n, d);
  }
};


// Ниво 2: аритметични операции
Rational add(Rational p, Rational q) {
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
