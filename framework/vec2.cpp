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

    //write your member function and free function definitions for A2.3 - A2.4 here (within the buw namespace}
}
