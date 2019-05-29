#include "quick_task.h"

TEST_CASE("Quick task requires exactly one unit of work to finish") {
  QuickTask qt("тестова задача");

  SUBCASE("Quick task is not finished without work") {
    CHECK(!qt.isFinished());
  }

  SUBCASE("Quick task is finished after one unit of time") {
    CHECK(qt.work(2) == 1);
    CHECK(qt.isFinished());
  }
  
  SUBCASE("Quick task cannot be worked on anymore") {
    CHECK(qt.work(2) == 1);
    CHECK(qt.work(2) == 2);
    CHECK(qt.isFinished());
  }
}

TEST_CASE("Simple task requires exactly n units of time to finish") {
  SimpleTask st("тестова задача", 5);

  SUBCASE("Simple task is not finished without work") {
    CHECK(!st.isFinished());
  }

  SUBCASE("Simple task is not finished after < n units of time") {
    CHECK(st.work(2) == 0);
    CHECK(!st.isFinished());
    CHECK(st.work(2) == 0);
    CHECK(!st.isFinished());
  }
  
  SUBCASE("Simple task does take more than n units of time") {
    CHECK(st.work(2) == 0);
    CHECK(st.work(4) == 1);
    CHECK(st.work(3) == 3);
    CHECK(st.isFinished());
  }
}
