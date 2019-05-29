#include <cstring>
#include "student.h"

Student::Student(char const* n,
                 unsigned f,
                 double g) {
  setName(n);
  setFN(f);
  setGrade(g);
}

void Student::setName(char const* n) {
  strncpy(name, n, MAX_NAME);
  name[MAX_NAME - 1] = '\0';
}

void Student::setFN(unsigned f) {
  if (f >= MIN_FN && f <= MAX_FN)
    fn = f;
  else
    fn = INVALID_FN;
}

void Student::setGrade(double g) {
  if (g >= MIN_GRADE && g <= MAX_GRADE)
    grade = g;
  else
    grade = INVALID_GRADE;
}

std::ostream& operator<<(std::ostream& os, Student const& s) {
  return os << s.getFN() << DELIMITER
            << s.getName() << DELIMITER
            << s.getGrade() << std::endl;
}

std::istream& operator>>(std::istream& is, Student& s) {
  unsigned fn;
  double grade;
  char name[MAX_NAME] = "";
  is >> fn;
  // прочитаме разделителя
  is.get();
  is.getline(name, MAX_NAME, DELIMITER);
  is >> grade;
  // прочитаме новия ред
  is.get();
  s.setName(name);
  s.setFN(fn);
  s.setGrade(grade);
  return is;
}

void Student::read() {
  std::cout << "Моля, въведете име: ";
  std::cin.getline(name, MAX_NAME);
  std::cout << "Моля, въведете Ф№: ";
  unsigned f;
  std::cin >> f;
  setFN(f);
  std::cout << "Моля, въведете оценка: ";
  double g;
  std::cin >> g;
  setGrade(g);
  // изчистваме новия ред от буфера
  std::cin.get();
}
