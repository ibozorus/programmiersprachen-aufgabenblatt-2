#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>
#include "vec2.hpp"

int factorial(int n)
{
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

TEST_CASE("factorial computes n!")
{
  CHECK(factorial(0) == 1);
  CHECK(factorial(1) == 1);
  CHECK(factorial(5) == 120);
  CHECK(factorial(10) == 3628800);
}
TEST_CASE("Vec2 default initialization") {
  buw::Vec2 a;
  CHECK(0.0f == a.x);
  CHECK(0.0f == a.y);
}

TEST_CASE("Vec2 aggregate initialization") {
  buw::Vec2 b{5.1f, -9.3f};
  CHECK(5.1f  == doctest::Approx(b.x));
  CHECK(-9.3f == doctest::Approx(b.y));
  buw::Vec2 c{10, -71};
  CHECK(10.0f  == doctest::Approx(c.x));
  CHECK(-71 == doctest::Approx(c.y));
}

int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
