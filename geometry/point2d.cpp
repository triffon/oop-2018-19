#include <iostream>
#include <cmath>
#include "point2d.h"

Point2D::Point2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

void Point2D::print() const {
  std::cout << '(' << getX()
            << ", " << getY() << ')';
}

double Point2D::distanceToOrigin() const {
  return distanceTo(Point2D());
}

double Point2D::distanceTo(Point2D p) const {
  return std::sqrt(pow(getX() - p.getX(), 2) +
                   pow(getY() - p.getY(), 2));
}

void Point2D::translate(Point2D p) {
  setX(getX() + p.getX());
  setY(getY() + p.getY());
}

void Point2D::reflect() {
  setX(-getX());
  setY(-getY());
}
