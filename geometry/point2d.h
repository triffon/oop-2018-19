#ifndef __POINT2D_H
#define __POINT2D_H

class Point2D {
  // Ниво 0
  double x, y;

public:
  // Ниво 1: конструктори
  Point2D();
  Point2D(double x, double y);

  // Ниво 1: селектори
  double getX() const { return x; }
  double getY() const { return y; }

  // Ниво 1: мутатори
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }

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

#endif
