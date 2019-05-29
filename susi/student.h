#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>

const unsigned MAX_NAME = 40;
const unsigned MIN_FN = 80000;
const unsigned MAX_FN = 89999;
const double MIN_GRADE = 2;
const double MAX_GRADE = 6;
const double PASSING_GRADE = 3;

const char INVALID_NAME[] = "";
const unsigned INVALID_FN = 0;
const double INVALID_GRADE = 0;

const char DELIMITER = '|';

class Student {
  char name[MAX_NAME];
  unsigned fn;
  double grade;

public:
  Student(char const* n = INVALID_NAME,
          unsigned f = INVALID_FN,
          double g = INVALID_GRADE);

  char const* getName() const { return name; }
  unsigned getFN() const { return fn; }
  double getGrade() const { return grade; }

  void setName(char const* n);
  void setFN(unsigned f);
  void setGrade(double g);

  void read();
};

std::ostream& operator<<(std::ostream& os, Student const& s);
std::istream& operator>>(std::istream& is, Student& s);

#endif
