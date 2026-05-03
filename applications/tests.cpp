#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

#include "circle.hpp"
#include "mat2.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

TEST_CASE("factorial computes n!") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(10) == 3628800);
}

// Vec2
TEST_CASE("Vec2 default initialization") {
    buw::Vec2 a;
    CHECK(0.0f == a.x);
    CHECK(0.0f == a.y);
}

TEST_CASE("Vec2 aggregate initialization") {
    buw::Vec2 b{5.1f, -9.3f};
    CHECK(5.1f == doctest::Approx(b.x));
    CHECK(-9.3f == doctest::Approx(b.y));
    buw::Vec2 c{10, -71};
    CHECK(10.0f == doctest::Approx(c.x));
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
    a += b += c; // b={3,1}, dann a={4,3}
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
    a -= b -= c; // b={2,1}, dann a={8,8}
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
    (a *= 2.0) *= 3.0; // a erst *2, dann *3 → a={6,12}
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
    buw::Vec2 &result = (a /= 2.0);
    CHECK(&result == &a);
}

TEST_CASE("Vec2 operator/= erlaubt Method Chaining") {
    buw::Vec2 a{24.0f, 12.0f};
    (a /= 2.0) /= 3.0; // a erst /2, dann /3 → a={4,2}
    CHECK(a.x == doctest::Approx(4.0f));
    CHECK(a.y == doctest::Approx(2.0f));
}

// ── operator+ ─────────────────────────────────────────────
TEST_CASE("Vec2 operator+ addiert Komponenten korrekt") {
    buw::Vec2 a{1.0f, 2.0f};
    buw::Vec2 b{3.0f, 4.0f};
    buw::Vec2 c = a + b;
    CHECK(c.x == doctest::Approx(4.0f));
    CHECK(c.y == doctest::Approx(6.0f));
}

TEST_CASE("Vec2 operator+ mit Nullvektor aendert nichts") {
    buw::Vec2 a{5.0f, -3.0f};
    buw::Vec2 c = a + buw::Vec2{0.0f, 0.0f};
    CHECK(c.x == doctest::Approx(5.0f));
    CHECK(c.y == doctest::Approx(-3.0f));
}

TEST_CASE("Vec2 operator+ veraendert Operanden nicht") {
    buw::Vec2 a{1.0f, 2.0f};
    buw::Vec2 b{3.0f, 4.0f};
    a + b;
    CHECK(a.x == doctest::Approx(1.0f));
    CHECK(b.x == doctest::Approx(3.0f));
}

// ── operator- ─────────────────────────────────────────────
TEST_CASE("Vec2 operator- subtrahiert Komponenten korrekt") {
    buw::Vec2 a{5.0f, 7.0f};
    buw::Vec2 b{2.0f, 3.0f};
    buw::Vec2 c = a - b;
    CHECK(c.x == doctest::Approx(3.0f));
    CHECK(c.y == doctest::Approx(4.0f));
}

TEST_CASE("Vec2 operator- veraendert Operanden nicht") {
    buw::Vec2 a{5.0f, 7.0f};
    buw::Vec2 b{2.0f, 3.0f};
    a - b;
    CHECK(a.x == doctest::Approx(5.0f));
    CHECK(b.x == doctest::Approx(2.0f));
}

TEST_CASE("Vec2 operator- von sich selbst ergibt Nullvektor") {
    buw::Vec2 a{3.0f, -1.0f};
    buw::Vec2 c = a - a;
    CHECK(c.x == doctest::Approx(0.0f));
    CHECK(c.y == doctest::Approx(0.0f));
}

// ── operator* (Vec2 * s) ───────────────────────────────────
TEST_CASE("Vec2 operator* skaliert korrekt (v * s)") {
    buw::Vec2 v{2.0f, 3.0f};
    buw::Vec2 result = v * 2.0;
    CHECK(result.x == doctest::Approx(4.0f));
    CHECK(result.y == doctest::Approx(6.0f));
}

TEST_CASE("Vec2 operator* mit 0.0 ergibt Nullvektor (v * s)") {
    buw::Vec2 v{5.0f, 3.0f};
    buw::Vec2 result = v * 0.0;
    CHECK(result.x == doctest::Approx(0.0f));
    CHECK(result.y == doctest::Approx(0.0f));
}

TEST_CASE("Vec2 operator* veraendert Operand nicht (v * s)") {
    buw::Vec2 v{2.0f, 3.0f};
    v * 5.0;
    CHECK(v.x == doctest::Approx(2.0f));
    CHECK(v.y == doctest::Approx(3.0f));
}

// ── operator* (s * Vec2) ───────────────────────────────────
TEST_CASE("Vec2 operator* skaliert korrekt (s * v)") {
    buw::Vec2 v{2.0f, 3.0f};
    buw::Vec2 result = 2.0 * v;
    CHECK(result.x == doctest::Approx(4.0f));
    CHECK(result.y == doctest::Approx(6.0f));
}

TEST_CASE("Vec2 operator* Kommutativitaet: s*v == v*s") {
    buw::Vec2 v{3.0f, -1.0f};
    buw::Vec2 lhs = 3.0 * v;
    buw::Vec2 rhs = v * 3.0;
    CHECK(lhs.x == doctest::Approx(rhs.x));
    CHECK(lhs.y == doctest::Approx(rhs.y));
}

// ── operator/ ─────────────────────────────────────────────
TEST_CASE("Vec2 operator/ teilt korrekt") {
    buw::Vec2 v{6.0f, 9.0f};
    buw::Vec2 result = v / 3.0;
    CHECK(result.x == doctest::Approx(2.0f));
    CHECK(result.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2 operator/ mit 1.0 aendert nichts") {
    buw::Vec2 v{5.0f, -2.0f};
    buw::Vec2 result = v / 1.0;
    CHECK(result.x == doctest::Approx(5.0f));
    CHECK(result.y == doctest::Approx(-2.0f));
}

TEST_CASE("Vec2 operator/ veraendert Operand nicht") {
    buw::Vec2 v{6.0f, 9.0f};
    v / 3.0;
    CHECK(v.x == doctest::Approx(6.0f));
    CHECK(v.y == doctest::Approx(9.0f));
}

// Mat2
// ── operator*= ────────────────────────────────────────────
TEST_CASE("Mat2 operator*= mit Einheitsmatrix aendert nichts") {
    buw::Mat2 m{3.0, 5.1, 4.0, -1.4};
    buw::Mat2 identity{};
    m *= identity;
    CHECK(m.e_00 == doctest::Approx(3.0));
    CHECK(m.e_10 == doctest::Approx(5.1));
    CHECK(m.e_01 == doctest::Approx(4.0));
    CHECK(m.e_11 == doctest::Approx(-1.4));
}

TEST_CASE("Mat2 operator*= multipliziert korrekt") {
    buw::Mat2 a{2.0, 1.0, 0.0, 3.0};
    buw::Mat2 b{1.0, 2.0, 3.0, 4.0};
    a *= b;
    CHECK(a.e_00 == doctest::Approx(5));
    CHECK(a.e_10 == doctest::Approx(8));
    CHECK(a.e_01 == doctest::Approx(9));
    CHECK(a.e_11 == doctest::Approx(12));
}

// ── operator* ─────────────────────────────────────────────
TEST_CASE("Mat2 operator* mit Einheitsmatrix aendert nichts") {
    buw::Mat2 m{2.0, 3.0, 4.0, 5.0};
    buw::Mat2 identity{};
    buw::Mat2 result = m * identity;
    CHECK(result.e_00 == doctest::Approx(m.e_00));
    CHECK(result.e_10 == doctest::Approx(m.e_10));
    CHECK(result.e_01 == doctest::Approx(m.e_01));
    CHECK(result.e_11 == doctest::Approx(m.e_11));
}

TEST_CASE("Mat2 operator* veraendert Operanden nicht") {
    buw::Mat2 a{2.0, 5.0, 0.0, 3.0};
    buw::Mat2 b{7.0, 2.0, 3.0, 4.0};
    a * b;
    CHECK(a.e_00 == doctest::Approx(2.0));
    CHECK(b.e_00 == doctest::Approx(7.0));
    CHECK(a.e_10 == doctest::Approx(5.0));
    CHECK(b.e_10 == doctest::Approx(2.0));
    CHECK(a.e_01 == doctest::Approx(0.0));
    CHECK(b.e_01 == doctest::Approx(3.0));
    CHECK(a.e_11 == doctest::Approx(3.0));
    CHECK(b.e_11 == doctest::Approx(4.0));
}

TEST_CASE("Mat2 operator* Nullmatrix ergibt Nullmatrix") {
    buw::Mat2 m{1.0, 2.0, 3.0, 4.0};
    buw::Mat2 zero{0.0, 0.0, 0.0, 0.0};
    buw::Mat2 result = m * zero;
    CHECK(result.e_00 == doctest::Approx(0.0));
    CHECK(result.e_10 == doctest::Approx(0.0));
    CHECK(result.e_01 == doctest::Approx(0.0));
    CHECK(result.e_11 == doctest::Approx(0.0));
}

// ── operator*(Mat2, Vec2) ──────────────────────────────────
TEST_CASE("Mat2 * Vec2 mit Einheitsmatrix aendert Vektor nicht") {
    buw::Mat2 identity{};
    buw::Vec2 v{3.0f, 4.0f};
    buw::Vec2 result = identity * v;
    CHECK(result.x == doctest::Approx(3.0f));
    CHECK(result.y == doctest::Approx(4.0f));
}

TEST_CASE("Mat2 * Vec2 multipliziert korrekt") {
    buw::Mat2 m{2.0, 0.0, 0.0, 3.0};
    buw::Vec2 v{1.0f, 1.0f};
    buw::Vec2 result = m * v;
    CHECK(result.x == doctest::Approx(2.0f));
    CHECK(result.y == doctest::Approx(3.0f));
}

TEST_CASE("Mat2 * Vec2 mit Nullvektor ergibt Nullvektor") {
    buw::Mat2 m{1.0, 2.0, 3.0, 4.0};
    buw::Vec2 v{0.0f, 0.0f};
    buw::Vec2 result = m * v;
    CHECK(result.x == doctest::Approx(0.0f));
    CHECK(result.y == doctest::Approx(0.0f));
}

TEST_CASE("Mat2 * Vec2 veraendert Operanden nicht") {
    buw::Mat2 m{2.0, 0.0, 0.0, 3.0};
    buw::Vec2 v{1.0f, 1.0f};
    m * v;
    CHECK(v.x == doctest::Approx(1.0f));
    CHECK(v.y == doctest::Approx(1.0f));
    CHECK(m.e_00 == doctest::Approx(2.0));
    CHECK(m.e_10 == doctest::Approx(0.0));
    CHECK(m.e_01 == doctest::Approx(0.0));
    CHECK(m.e_11 == doctest::Approx(3.0));
}

// ── make_rotation_mat2 ────────────────────────────────────
TEST_CASE("make_rotation_mat2 mit phi=0 ergibt Einheitsmatrix") {
    buw::Mat2 m = buw::make_rotation_mat2(0.0);
    CHECK(m.e_00 == doctest::Approx(1.0));
    CHECK(m.e_10 == doctest::Approx(0.0));
    CHECK(m.e_01 == doctest::Approx(0.0));
    CHECK(m.e_11 == doctest::Approx(1.0));
}

TEST_CASE("make_rotation_mat2 mit phi=pi/2 rotiert 90 Grad") {
    buw::Mat2 m = buw::make_rotation_mat2(std::numbers::pi / 2.0);
    buw::Vec2 v{1.0f, 0.0f};
    buw::Vec2 result = m * v;
    CHECK(result.x == doctest::Approx(0.0f).epsilon(1e-6));
    CHECK(result.y == doctest::Approx(1.0f));
}

TEST_CASE("make_rotation_mat2 mit phi=pi rotiert 180 Grad") {
    buw::Mat2 m = buw::make_rotation_mat2(std::numbers::pi);
    buw::Vec2 v{1.0f, 0.0f};
    buw::Vec2 result = m * v;
    CHECK(result.x == doctest::Approx(-1.0f));
    CHECK(result.y == doctest::Approx(0.0f).epsilon(1e-6));
}

TEST_CASE("make_rotation_mat2 mit phi=2*pi ist wieder Einheitsmatrix") {
    buw::Mat2 m = buw::make_rotation_mat2(2.0 * std::numbers::pi);
    buw::Vec2 v{3.0f, 4.0f};
    buw::Vec2 result = m * v;
    CHECK(result.x == doctest::Approx(3.0f).epsilon(1e-5));
    CHECK(result.y == doctest::Approx(4.0f).epsilon(1e-5));
}

// ── Circle::circumference ──────────────────────────────────
TEST_CASE("Circle circumference mit radius=1") {
    buw::Circle c{buw::Vec2{0.0f, 0.0f}, 1.0f, buw::Color{}};
    CHECK(c.circumference() == doctest::Approx(2.0f * std::numbers::pi));
}

TEST_CASE("Circle circumference mit radius=0 ist 0") {
    buw::Circle c{buw::Vec2{0.0f, 0.0f}, 0.0f, buw::Color{}};
    CHECK(c.circumference() == doctest::Approx(0.0f));
}

TEST_CASE("Circle circumference mit radius=5") {
    buw::Circle c{buw::Vec2{1.0f, 2.0f}, 5.0f, buw::Color{}};
    CHECK(c.circumference() == doctest::Approx(2.0f * 5.0f * std::numbers::pi));
}

// ── Rectangle::circumference ───────────────────────────────
TEST_CASE("Rectangle circumference korrekt berechnet") {
    buw::Rectangle r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{4.0f, 3.0f}, buw::Color{}};
    CHECK(r.circumference() == doctest::Approx(14.0f)); // 2*(4+3)
}

TEST_CASE("Rectangle circumference Quadrat") {
    buw::Rectangle r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{5.0f, 5.0f}, buw::Color{}};
    CHECK(r.circumference() == doctest::Approx(20.0f)); // 2*(5+5)
}

TEST_CASE("Rectangle circumference auf const-Objekt aufrufbar") {
    buw::Rectangle const r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{2.0f, 2.0f}, buw::Color{}};
    CHECK(r.circumference() == doctest::Approx(8.0f)); // prueft ob const korrekt
}

// ── Circle::is_inside ──────────────────────────────────────
TEST_CASE("Circle is_inside Punkt im Zentrum") {
    buw::Circle c{buw::Vec2{400.0f, 400.0f}, 100.0f, buw::Color{}};
    CHECK(c.is_inside(buw::Vec2{400.0f, 400.0f}));
}

TEST_CASE("Circle is_inside Punkt auf dem Rand") {
    buw::Circle c{buw::Vec2{0.0f, 0.0f}, 100.0f, buw::Color{}};
    CHECK(c.is_inside(buw::Vec2{100.0f, 0.0f}));
}

TEST_CASE("Circle is_inside Punkt ausserhalb") {
    buw::Circle c{buw::Vec2{0.0f, 0.0f}, 100.0f, buw::Color{}};
    CHECK_FALSE(c.is_inside(buw::Vec2{200.0f, 0.0f}));
}

TEST_CASE("Circle is_inside Punkt knapp ausserhalb") {
    buw::Circle c{buw::Vec2{0.0f, 0.0f}, 100.0f, buw::Color{}};
    CHECK_FALSE(c.is_inside(buw::Vec2{100.1f, 0.0f}));
}

// ── Rectangle::is_inside ──────────────────────────────────
TEST_CASE("Rectangle is_inside Punkt im Inneren") {
    buw::Rectangle r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{100.0f, 100.0f}, buw::Color{}};
    CHECK(r.is_inside(buw::Vec2{50.0f, 50.0f}));
}

TEST_CASE("Rectangle is_inside Punkt auf Ecke") {
    buw::Rectangle r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{100.0f, 100.0f}, buw::Color{}};
    CHECK(r.is_inside(buw::Vec2{0.0f, 0.0f}));
    CHECK(r.is_inside(buw::Vec2{100.0f, 100.0f}));
}

TEST_CASE("Rectangle is_inside Punkt ausserhalb") {
    buw::Rectangle r{buw::Vec2{0.0f, 0.0f}, buw::Vec2{100.0f, 100.0f}, buw::Color{}};
    CHECK_FALSE(r.is_inside(buw::Vec2{150.0f, 50.0f}));
    CHECK_FALSE(r.is_inside(buw::Vec2{-1.0f, 50.0f}));
}

int main(int argc, char *argv[]) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    return ctx.run();
}
