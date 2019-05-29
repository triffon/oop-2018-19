#include <fstream>
#include "susi.h"

SUSI::SUSI(std::string sf, std::string bf)
  : studentsFile(sf), bookFile(bf),
    countStudents(0) {}

void SUSI::readStudentsFromStdin() {
  do {
    std::cout << "Моля, въведете брой студенти: ";
    std::cin >> countStudents;
  } while (countStudents < 0 || countStudents > MAX_STUDENTS);
  std::cin.get();
  for(int i = 0; i < countStudents; i++)
    students[i].read();
}

void SUSI::writeStudentsToFile() {
  std::ofstream sfile(studentsFile, std::ios::out | std::ios::app);
  for(int i = 0; i < countStudents; i++)
    sfile << students[i];
}

void SUSI::readPassingStudentsFromFile() {
  std::ifstream sfile(studentsFile);
  while (sfile) {
    sfile >> students[countStudents];
    if (!sfile.eof() && students[countStudents].getGrade() >= PASSING_GRADE)
      countStudents++;
  }
  std::cout << "Брой студенти: " << countStudents << std::endl;
}

void SUSI::writeStudentsToBook() {
  bfile.open(bookFile, std::ios::out | std::ios::ate |
             std::ios::binary);
  for(int i = 0; i < countStudents; i++)
    writeStudentToBook(students[i]);
  bfile.close();
}

void SUSI::writeStudentToBook(Student const& s) {
  bfile.seekp(calculatePosition(s.getFN()) * sizeof(Student));
  bfile.write((const char*)&s, sizeof(Student));
}

Student SUSI::readStudentFromBook(unsigned fn) {
  bfile.open(bookFile, std::ios::in | std::ios::binary);
  bfile.seekg(calculatePosition(fn) * sizeof(Student));
  Student s;
  bfile.read((char*)&s, sizeof(Student));
  bfile.close();
  return s;
}

void SUSI::increaseGradeInBook(unsigned fn) {
  bfile.open(bookFile, std::ios::in | std::ios::out | std::ios::binary);
  bfile.seekg(calculatePosition(fn) * sizeof(Student));
  Student s;
  bfile.read((char*)&s, sizeof(Student));
  s.setGrade(s.getGrade() + 1);
  writeStudentToBook(s);
  bfile.close();
}

