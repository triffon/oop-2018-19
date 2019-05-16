#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

void testStreams(std::istream& is = std::cin, std::ostream& os = std::cout) {
  int a = 0, b = 0, c = 0;
  is >> a;
  os << "a = " << a << std::endl;
  is >> b;
  os << "b = " << b << std::endl;
  // os << "\rerror\n";
  is >> c;
  os << "c = " << c << std::endl;

  const int MAX = 100;
  char s[MAX];
  // !!! is >> s[0]; 
  is.get(); // изчистване на символа за нов ред
  is.get(s, MAX);
  os << strlen(s) << " -> '" << s << "'" << std::endl;
  is.getline(s, MAX);
  os << strlen(s) << " -> '" << s << "'" << std::endl;
}

void testStringStreams() {
  std::istringstream iss("1 2 3\nHello\nHello");
  std::ostringstream oss;
  testStreams(iss, oss);
  std::cout << "Прихванахме изхода на testStreams():\n" << oss.str() << std::endl;
}

void testFileStreams() {
  const int MAX = 100;
  char s[MAX];
  std::cout << "Въведете име на входен файл: ";
  std::cin.getline(s, MAX);
  std::ifstream ifs(s);
  std::cout << "Въведете име на изходен файл: ";
  std::cin.getline(s, MAX);
  std::ofstream ofs(s);
  testStreams(ifs, ofs);
}


int safeReadInt(char const* prompt = "", std::istream& is = std::cin) {
  int x;
  bool success = false;
  while (!success) {
    std::clog << "state = " << is.rdstate() << std::endl;
    std::cout << prompt;
    is >> x;
    std::clog << "state = " << is.rdstate() << std::endl;
    if (!is) {
      // операции по възстановяване на потока
      is.clear();
      // прочитаме един символ и го изхвърляме
      is.get();
    } else
      success = true;
  }
  return x;
}

void testState() {
  int a = 0, b = 0, c = 0;
  // !!! std::cin.clear(std::ios::badbit);
  std::clog << "state = " << cin.rdstate() << std::endl;
  std::cin >> a;
  std::clog << "state = " << cin.rdstate() << std::endl;
  std::cin >> b;
  std::cin >> c;
  a = safeReadInt("a = ");
  std::cout << "a = " << a << std::endl;
  std::cout << "end\n";
  std::cout << std::setfill('-') << std::setw(40) << '-' << std::endl;
}

int main() {
  // testStringStreams();
  testFileStreams();
  // testState();
  return 0;
}
