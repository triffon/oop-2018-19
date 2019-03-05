#ifndef __POINT3D_H
#define __POINT3D_H

#include "point2d.h"

class Point3D {
  // Ниво 0
  // double x, y, z;
  Point2D p; // проекция върху Oxy
  double z;  // разстояние до Oxy

public:
  // Ниво 1: конструктори
  Point3D();
  Point3D(double x, double y, double z);

  // Ниво 1: селектори
  double getX() const  { return p.getX(); }
  double getY() const  { return p.getY(); }
  double getZ() const  { return z; }
  Point2D getP() const { return p; }

  // Ниво 1: мутатори
  void setX(double x)  { p.setX(x); }
  void setY(double y)  { p.setY(y); }
  void setZ(double z)  { this->z = z; }
  void setP(Point2D p) { this->p = p; }

  // Ниво 2: операции
  void print() const;
  double distanceToOrigin() const;
  double distanceTo(Point3D p) const;
  void translate(Point3D v);
  void reflect();
  // домашно
  // симетрия относно ос
  // симетрия относно точка
  // ротация относно точка с ъгъл

};

#endif
