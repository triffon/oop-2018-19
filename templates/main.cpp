#include <iostream>
#include "../geometry/point2d.h"
#include "../rational/rational.h"

const int MAX = 100;

template <typename T>
unsigned readArray(T* a) {
  unsigned n;
  std::cout << "Брой елементи: ";
  std::cin >> n;
  // !!! a = a / 3;
  for(int i = 0; i < n; i++) {
    std::cout << "Елемент #" << i << " = ";
    std::cin >> a[i];
  }
  return n;
}

template <typename T>
void printArray(T const* a, unsigned n) {
  for(int i = 0; i < n; i++)
    std::cout << a[i] << ' ';
  std::cout << std::endl;
}

template <typename T>
bool findInArray(T const& x, T const* a, unsigned n) {
  int i = 0;
  while (i < n && a[i] != x)
    i++;
  // i == n || a[i] == x
  return i < n;
}

void testReadPrintFindArray() {
  int a[MAX];
  double b[MAX];
  Point2D c[MAX];
  Rational d[MAX];
  unsigned na, nb, nd;
  printArray(a, na = readArray(a));
  printArray(b, nb = readArray(b));
  // !!!! printArray(c, readArray(c));
  printArray(d, nd = readArray(d));

  std::cout << findInArray(1, a, na) << std::endl;
  // !!!  std::cout << findInArray(1, b, nb) << std::endl;
  // std::cout << findInArray(1., b, nb) << std::endl;
  std::cout << findInArray<double>(1, b, nb) << std::endl;
  Rational x(2, 3);
  std::cout << findInArray<Rational>(x, d, nd) << std::endl;
  Point2D p(1, 5);
  Point2D pa[] = { Point2D(3, 5), Point2D(1, 5), Point2D(1, 7), Point2D(2, 15) };
  // !!! std::cout << findInArray(p, pa, 4) << std::endl;
}

int main() {
  testReadPrintFindArray();
  return 0;
}
