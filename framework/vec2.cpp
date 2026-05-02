#include "vec2.hpp"

namespace buw {
    Vec2 &Vec2::operator+=(Vec2 const &v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2 &Vec2::operator-=(Vec2 const &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vec2 &Vec2::operator*=(double s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2 &Vec2::operator/=(double s) {
        x /= s;
        y /= s;
        return *this;
    }

    Vec2 operator+(Vec2 const &u, Vec2 const &v) {
        Vec2 u1(u);
        return u1 += v;
    }

    Vec2 operator-(Vec2 const &u, Vec2 const &v) {
        Vec2 u1(u);
        return u1 -= v;
    }

    Vec2 operator*(Vec2 const &v, double s) {
        Vec2 v1(v);
        return v1 *= s;
    }

    Vec2 operator/(Vec2 const &v, double s) {
        Vec2 v1(v);
        return v1 /= s;
    }

    Vec2 operator*(double s, Vec2 const &v) {
        return v * s;
    }

    //write your member function and free function definitions for A2.3 - A2.4 here (within the buw namespace}
}
