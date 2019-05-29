#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../common/doctest.h"
#include "quick_task.h"

#include "task_tests.h"

void testQuickTask() {
  QuickTask qt("лицева опора");
  qt.print();
  qt.work(1);
  std::cout << std::endl;
  qt.print();
}

/*
int main() {
  testQuickTask();
}
*/
