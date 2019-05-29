#ifndef __SUSI_H
#define __SUSI_H

#include <fstream>
#include <string>
#include "student.h"

const unsigned MAX_STUDENTS = 10000;
const char DEFAULT_STUDENTS_FILE[] = "students.txt";
const char DEFAULT_BOOK_FILE[] = "main.bk";

class SUSI {
  Student students[MAX_STUDENTS];
  std::string studentsFile;
  std::string bookFile;
  std::fstream bfile;
  unsigned countStudents;

private:
  unsigned calculatePosition(unsigned fn) const {
    return fn - MIN_FN;
  }

public:
  SUSI(std::string sf = DEFAULT_STUDENTS_FILE,
       std::string bf = DEFAULT_BOOK_FILE);

  void readStudentsFromStdin();
  void writeStudentsToFile();
  void readPassingStudentsFromFile();
  void writeStudentsToBook();
  void writeStudentToBook(Student const& s);
  Student readStudentFromBook(unsigned fn);
  void increaseGradeInBook(unsigned fn);
};

#endif
