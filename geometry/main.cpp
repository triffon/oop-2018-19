#include <iostream>

#include "point2d.h"
#include "point3d.h"

void testPoint2D() {
  Point2D p1, p2(3, -4);
  p1.print();std::cout << std::endl;
  p2.print();std::cout << std::endl;
  std::cout << p2.distanceToOrigin() << std::endl;
  Point2D p3 = p2;
  p3.translate(Point2D(2, -8));
  std::cout << p3.distanceToOrigin() << std::endl;
  std::cout << p2.distanceTo(p3) << std::endl;
  std::cout << p3.distanceTo(p2) << std::endl;
}

void testPoint3D() {
  Point3D p1, p2(3, -4, 12);
  p1.print();std::cout << std::endl;
  p2.print();std::cout << std::endl;
  std::cout << p2.distanceToOrigin() << std::endl;
  Point3D p3 = p2;
  p3.translate(Point3D(1, -6, -3));
  std::cout << p3.distanceToOrigin() << std::endl;
  std::cout << p2.distanceTo(p3) << std::endl;
  std::cout << p3.distanceTo(p2) << std::endl;
}

int main() {
  testPoint2D();
  testPoint3D();
  return 0;
}
