#include "quick_task.h"
#include "simple_task.h"
#include "repeated_task.h"

TEST_CASE("Quick task requires exactly one unit of work to finish") {
  QuickTask qt("лицева опора");

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
  SimpleTask st("подготовка за контролно", 5);

  SUBCASE("Simple task is not finished without work") {
    CHECK(!st.isFinished());
  }

  CHECK(st.work(2) == 0);
  
  SUBCASE("Simple task is not finished after < n units of time") {
    CHECK(!st.isFinished());
    CHECK(st.work(2) == 0);
    CHECK(!st.isFinished());
  }
  
  SUBCASE("Simple task does take more than n units of time") {
    CHECK(st.work(4) == 1);
    CHECK(st.work(3) == 3);
    CHECK(st.isFinished());
  }
}


TEST_CASE("Simple task reports progress correctly") {
  SimpleTask st("подготовка за контролно", 5);

  SUBCASE("Simple task has progress 0 without work") {
    CHECK(st.getProgress() == 0);
  }

  CHECK(st.work(2) == 0);
  
  SUBCASE("Simple task reports correctly progress before being finished") {
    CHECK(st.getProgress() == 2);
    CHECK(st.work(2) == 0);
    CHECK(st.getProgress() == 4);
  }
  
  SUBCASE("Simple task reports correctly progress after being finished") {
    CHECK(st.work(4) == 1);
    CHECK(st.getProgress() == 5);
    CHECK(st.work(3) == 3);
    CHECK(st.getProgress() == 5);
  }
}

TEST_CASE("Repeated quick task requires exactly n units to finish") {
  RepeatedTask rt("Лекция по ООП", QuickTask("Учебен час по ООП"), 3);

  SUBCASE("Repeated task is not finished without work") {
    CHECK(!rt.isFinished());
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated task is not finished after < n units of time") {
    CHECK(!rt.isFinished());
    CHECK(rt.work(1) == 0);
    CHECK(!rt.isFinished());
  }
  
  SUBCASE("Repeated task does take more than n units of time") {
    CHECK(rt.work(4) == 2);
    CHECK(rt.work(3) == 3);
    CHECK(rt.isFinished());
  }
}


TEST_CASE("Repeated quick task reports progress correctly") {
  RepeatedTask rt("Лекция по ООП", QuickTask("Учебен час по ООП"), 3);

  SUBCASE("Repeated quick task is not finished without work") {
    CHECK(rt.getProgress() == 0);
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated quick task reports progress correctly before finishing") {
    CHECK(rt.getProgress() == 1);
    CHECK(rt.work(1) == 0);
    CHECK(rt.getProgress() == 2);
  }
  
  SUBCASE("Repeated quick task reports progress correctly after finishing") {
    CHECK(rt.work(4) == 2);
    CHECK(rt.getProgress() == 3);
    CHECK(rt.work(3) == 3);
    CHECK(rt.getProgress() == 3);
  }
}


TEST_CASE("Repeated simple task reports progress correctly") {
  RepeatedTask rt("Курс по ООП", SimpleTask("Лекция по ООП", 3), 15);

  SUBCASE("Repeated simple task is not finished without work") {
    CHECK(rt.getProgress() == 0);
  }

  CHECK(rt.work(2) == 0);
  
  SUBCASE("Repeated simple task reports progress correctly before finishing first repetition") {
    CHECK(rt.getProgress() == 2);
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated simple task reports progress correctly when finishing first repetition exactly") {
    CHECK(rt.getProgress() == 3);
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated simple task reports progress correctly after starting second iteration") {
    CHECK(rt.getProgress() == 4);
  }

  CHECK(rt.work(3) == 0);

  SUBCASE("Repeated simple task reports progress correctly after jumping over one repetition") {
    CHECK(rt.getProgress() == 7);
  }

  CHECK(rt.work(10) == 0);
  
  SUBCASE("Repeated simple task reports progress correctly after jumping over everal repetitions") {
    CHECK(rt.getProgress() == 17);
  }

  CHECK(rt.work(26) == 0);

  SUBCASE("Repeated simple task reports progress correctly on last repeition") {
    CHECK(rt.getProgress() == 43);
  }

  
  SUBCASE("Repeated simple task reports progress correctly after being finished") {
    CHECK(rt.work(2) == 0);
    CHECK(rt.getProgress() == 45);
    CHECK(rt.work(5) == 5);
    CHECK(rt.getProgress() == 45);
  }

  SUBCASE("Repeated simple task reports progress correctly after being finished") {
    CHECK(rt.work(5) == 3);
    CHECK(rt.getProgress() == 45);
    CHECK(rt.work(15) == 15);
    CHECK(rt.getProgress() == 45);
  }
}

TEST_CASE("Repeated simple task takes exactly n * m units to finish") {
  RepeatedTask rt("Курс по ООП", SimpleTask("Лекция по ООП", 3), 15);

  CHECK(!rt.isFinished());
  CHECK(rt.work(2) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(1) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(1) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(3) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(10) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(26) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(5) == 3);
  CHECK(rt.isFinished());
  CHECK(rt.work(15) == 15);
  CHECK(rt.isFinished());
}

TEST_CASE("Repeated repeated quick task reports progress correctly") {
  RepeatedTask rt("Курс по ООП",
                  RepeatedTask("Лекция по ООП",
                               QuickTask("Учебен час по ООП"), 3), 15);

  SUBCASE("Repeated repeated quick task is not finished without work") {
    CHECK(rt.getProgress() == 0);
  }

  CHECK(rt.work(2) == 0);
  
  SUBCASE("Repeated repeated quick task reports progress correctly before finishing first repetition") {
    CHECK(rt.getProgress() == 2);
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated repeated quick task reports progress correctly when finishing first repetition exactly") {
    CHECK(rt.getProgress() == 3);
  }

  CHECK(rt.work(1) == 0);
  
  SUBCASE("Repeated repeated quick task reports progress correctly after starting second iteration") {
    CHECK(rt.getProgress() == 4);
  }

  CHECK(rt.work(3) == 0);

  SUBCASE("Repeated repeated quick task reports progress correctly after jumping over one repetition") {
    CHECK(rt.getProgress() == 7);
  }

  CHECK(rt.work(10) == 0);
  
  SUBCASE("Repeated repeated quick task reports progress correctly after jumping over everal repetitions") {
    CHECK(rt.getProgress() == 17);
  }

  CHECK(rt.work(26) == 0);

  SUBCASE("Repeated repeated quick task reports progress correctly on last repeition") {
    CHECK(rt.getProgress() == 43);
  }

  
  SUBCASE("Repeated repeated quick task reports progress correctly after being finished") {
    CHECK(rt.work(2) == 0);
    CHECK(rt.getProgress() == 45);
    CHECK(rt.work(5) == 5);
    CHECK(rt.getProgress() == 45);
  }

  SUBCASE("Repeated repeated quick task reports progress correctly after being finished") {
    CHECK(rt.work(5) == 3);
    CHECK(rt.getProgress() == 45);
    CHECK(rt.work(15) == 15);
    CHECK(rt.getProgress() == 45);
  }
}

TEST_CASE("Repeated repeated quick task takes exactly n * m * k units to finish") {
  RepeatedTask rt("Курс по ООП",
                  RepeatedTask("Лекция по ООП",
                               QuickTask("Учебен час по ООП"), 3), 15);

  CHECK(!rt.isFinished());
  CHECK(rt.work(2) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(1) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(1) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(3) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(10) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(26) == 0);
  CHECK(!rt.isFinished());
  CHECK(rt.work(5) == 3);
  CHECK(rt.isFinished());
  CHECK(rt.work(15) == 15);
  CHECK(rt.isFinished());
}
