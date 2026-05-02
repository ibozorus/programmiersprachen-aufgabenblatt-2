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
// ── operator+= ────────────────────────────────────────────
TEST_CASE("Vec2 operator+= addiert Komponenten korrekt") {
  buw::Vec2 a{1.0f, 2.0f};
  buw::Vec2 b{3.0f, 4.0f};
  a += b;
  CHECK(a.x == doctest::Approx(4.0f));
  CHECK(a.y == doctest::Approx(6.0f));
}

TEST_CASE("Vec2 operator+= mit Nullvektor ändert nichts") {
  buw::Vec2 a{5.0f, -3.0f};
  buw::Vec2 zero{0.0f, 0.0f};
  a += zero;
  CHECK(a.x == doctest::Approx(5.0f));
  CHECK(a.y == doctest::Approx(-3.0f));
}

TEST_CASE("Vec2 operator+= mit negativen Werten") {
  buw::Vec2 a{1.0f, 1.0f};
  buw::Vec2 b{-2.0f, -3.0f};
  a += b;
  CHECK(a.x == doctest::Approx(-1.0f));
  CHECK(a.y == doctest::Approx(-2.0f));
}

TEST_CASE("Vec2 operator+= erlaubt Method Chaining") {
  buw::Vec2 a{1.0f, 2.0f};
  buw::Vec2 b{1.0f, 1.0f};
  buw::Vec2 c{2.0f, 0.0f};
  a += b += c;           // b={3,1}, dann a={4,3}
  CHECK(b.x == doctest::Approx(3.0f));
  CHECK(b.y == doctest::Approx(1.0f));
  CHECK(a.x == doctest::Approx(4.0f));
  CHECK(a.y == doctest::Approx(3.0f));
}

// ── operator-= ────────────────────────────────────────────
TEST_CASE("Vec2 operator-= subtrahiert Komponenten korrekt") {
  buw::Vec2 a{5.0f, 7.0f};
  buw::Vec2 b{2.0f, 3.0f};
  a -= b;
  CHECK(a.x == doctest::Approx(3.0f));
  CHECK(a.y == doctest::Approx(4.0f));
}

TEST_CASE("Vec2 operator-= mit sich selbst ergibt Nullvektor") {
  buw::Vec2 a{4.0f, -2.0f};
  a -= a;
  CHECK(a.x == doctest::Approx(0.0f));
  CHECK(a.y == doctest::Approx(0.0f));
}

TEST_CASE("Vec2 operator-= erlaubt Method Chaining") {
  buw::Vec2 a{10.0f, 9.0f};
  buw::Vec2 b{3.0f, 2.0f};
  buw::Vec2 c{1.0f, 1.0f};
  a -= b -= c;           // b={2,1}, dann a={8,8}
  CHECK(b.x == doctest::Approx(2.0f));
  CHECK(b.y == doctest::Approx(1.0f));
  CHECK(a.x == doctest::Approx(8.0f));
  CHECK(a.y == doctest::Approx(8.0f));
}

// ── operator*= ────────────────────────────────────────────
TEST_CASE("Vec2 operator*= skaliert beide Komponenten") {
  buw::Vec2 a{2.0f, 3.0f};
  a *= 3.0;
  CHECK(a.x == doctest::Approx(6.0f));
  CHECK(a.y == doctest::Approx(9.0f));
}

TEST_CASE("Vec2 operator*= mit 1.0 ändert nichts") {
  buw::Vec2 a{4.0f, -5.0f};
  a *= 1.0;
  CHECK(a.x == doctest::Approx(4.0f));
  CHECK(a.y == doctest::Approx(-5.0f));
}

TEST_CASE("Vec2 operator*= mit 0.0 ergibt Nullvektor") {
  buw::Vec2 a{7.0f, 3.0f};
  a *= 0.0;
  CHECK(a.x == doctest::Approx(0.0f));
  CHECK(a.y == doctest::Approx(0.0f));
}

TEST_CASE("Vec2 operator*= mit negativem Skalar spiegelt Vorzeichen") {
  buw::Vec2 a{2.0f, -4.0f};
  a *= -1.0;
  CHECK(a.x == doctest::Approx(-2.0f));
  CHECK(a.y == doctest::Approx(4.0f));
}

TEST_CASE("Vec2 operator*= erlaubt Method Chaining") {
  buw::Vec2 a{1.0f, 2.0f};
  buw::Vec2 b{3.0f, 4.0f};
  (a *= 2.0) *= 3.0;     // a erst *2, dann *3 → a={6,12}
  CHECK(a.x == doctest::Approx(6.0f));
  CHECK(a.y == doctest::Approx(12.0f));
}

// ── operator/= ────────────────────────────────────────────
TEST_CASE("Vec2 operator/= teilt beide Komponenten") {
  buw::Vec2 a{6.0f, 9.0f};
  a /= 3.0;
  CHECK(a.x == doctest::Approx(2.0f));
  CHECK(a.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2 operator/= mit 1.0 ändert nichts") {
  buw::Vec2 a{5.0f, -2.0f};
  a /= 1.0;
  CHECK(a.x == doctest::Approx(5.0f));
  CHECK(a.y == doctest::Approx(-2.0f));
}

TEST_CASE("Vec2 operator/= gibt Referenz auf sich selbst zurück") {
  buw::Vec2 a{8.0f, 4.0f};
  buw::Vec2& result = (a /= 2.0);
  CHECK(&result == &a);
}
TEST_CASE("Vec2 operator/= erlaubt Method Chaining") {
  buw::Vec2 a{24.0f, 12.0f};
  (a /= 2.0) /= 3.0;    // a erst /2, dann /3 → a={4,2}
  CHECK(a.x == doctest::Approx(4.0f));
  CHECK(a.y == doctest::Approx(2.0f));
}
int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
