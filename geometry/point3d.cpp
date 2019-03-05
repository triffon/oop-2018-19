#include <iostream>
#include "point3d.h"

Point3D::Point3D() {
  p.setX(0);
  p.setY(0);
  z = 0;
}

Point3D::Point3D(double xCoord,
                 double yCoord,
                 double zCoord) {
  p.setX(xCoord);
  p.setY(yCoord);
  z = zCoord;
}

void Point3D::print() const {
  std::cout << '(' << getX()
            << ", " << getY()
            << ", " << getZ()
            << ')';
}

double Point3D::distanceToOrigin() const {
  Point2D q(getP().distanceToOrigin(),
            getZ());
  return q.distanceToOrigin();
}

double Point3D::distanceTo(Point3D q) const {
  Point3D copy = *this;
  copy.reflect();
  q.translate(copy);
  return q.distanceToOrigin();
}

void Point3D::translate(Point3D q) {
  // !!! p.translate(q.getP());
  // !!! getP().translate(q.getP());
  Point2D tmp = getP();
  tmp.translate(q.getP());
  setP(tmp);
  setZ(getZ() + q.getZ());
}


void Point3D::reflect() {
  // !!! p.reflect();
  Point2D tmp = getP();
  tmp.reflect();
  setP(tmp);
  setZ(-getZ());
}
