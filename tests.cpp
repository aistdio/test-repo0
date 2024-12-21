#include "tests.h"
#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

bool test_1_body_contains()
{
  Candle candle{ 15.25, 27.65, 13.25, 23.65 };

  return candle.body_contains(23.65);
}

bool test_2_body_contains()
{
  Candle candle{ 0.0, 5.0, 0.0, 0.0 }; //совпали open и close

  return !candle.body_contains(1.0);
}

bool test_3_body_contains()
{
  Candle candle{ -30.0, -36.0, -29.0, -35.0 }; //некорректные high и low

  return !candle.body_contains(-36.0);
}

void initTests()
{
  tests.push_back(test_1_body_contains);
  tests.push_back(test_2_body_contains);
  tests.push_back(test_3_body_contains);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}