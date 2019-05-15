#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int a = 0, b = 0, c = 0;
  std::cin >> a;
  std::cout << "a = " << a << std::endl;
  std::cin >> b;
  std::cout << "b = " << b << std::endl;
  // std::cout << "\rerror\n";
  std::cin >> c;
  std::cout << "c = " << c << std::endl;

  const int MAX = 100;
  char s[MAX];
  // !!! std::cin >> s[0]; 
  std::cin.get(); // изчистване на символа за нов ред
  std::cin.get(s, MAX);
  std::cout << strlen(s) << " -> '" << s << "'" << std::endl;
  std::cin.getline(s, MAX);
  std::cout << strlen(s) << " -> '" << s << "'" << std::endl;
  return 0;
}
