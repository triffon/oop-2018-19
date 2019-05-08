#include <iostream>

#include "quick_task.h"

void testQuickTask() {
  QuickTask qt("лицева опора");
  qt.print();
  qt.work(1);
  std::cout << std::endl;
  qt.print();
}

int main() {
  testQuickTask();
}
