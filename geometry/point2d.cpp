#ifndef __POINT2D_CPP
#define __POINT2D_CPP

#include <iostream>
#include <cmath>

template <typename T>
class Point2D {
  // Ниво 0
  T x, y;

public:
  // Ниво 1: конструктори
  Point2D(T const& x = 0, T const& y = 0);

  // Ниво 1: селектори
  T getX() const { return x; }
  T getY() const { return y; }

  // Ниво 1: мутатори
  void setX(T const& x) { this->x = x; }
  void setY(T const& y) { this->y = y; }

  // Ниво 2: операции
  void print() const;
  double distanceToOrigin() const;
  double distanceTo(Point2D p) const;
  void translate(Point2D v);
  void reflect();
  // домашно
  // симетрия относно ос
  // симетрия относно точка
  // ротация относно точка с ъгъл
};

template <typename T>
Point2D<T>::Point2D(T const& xCoord, T const& yCoord) : x(xCoord), y(yCoord) {}

template <typename T>
void Point2D<T>::print() const {
  std::cout << '(' << getX()
            << ", " << getY() << ')';
}

template <typename T>
double Point2D<T>::distanceToOrigin() const {
  return distanceTo(Point2D());
}

template <typename T>
double Point2D<T>::distanceTo(Point2D p) const {
  return std::sqrt(pow(getX() - p.getX(), 2) +
                   pow(getY() - p.getY(), 2));
}

template <typename T>
void Point2D<T>::translate(Point2D p) {
  setX(getX() + p.getX());
  setY(getY() + p.getY());
}

template <typename T>
void Point2D<T>::reflect() {
  setX(-getX());
  setY(-getY());
}

#endif
