#include <iostream>

#include "susi.h"

void testSUSI() {
  SUSI susi;
  susi.readStudentsFromStdin();
  susi.writeStudentsToFile();
  susi.readPassingStudentsFromFile();
  susi.writeStudentsToFile();
  susi.writeStudentsToBook();
  std::cout << susi.readStudentFromBook(80002);
  susi.increaseGradeInBook(80002);
  std::cout << susi.readStudentFromBook(80002);
  std::cout << sizeof(Student) << std::endl;
}

int main() {
  testSUSI();
  return 0;
}
