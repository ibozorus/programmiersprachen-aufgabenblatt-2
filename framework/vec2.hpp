#ifndef BUW_VEC2_HPP
#define BUW_VEC2_HPP

namespace buw {
    struct Vec2 {
        float x = 0.0f;
        float y = 0.0f;

        Vec2 &operator+=(Vec2 const &v);

        Vec2 &operator-=(Vec2 const &v);

        Vec2 &operator*=(double s);

        Vec2 &operator/=(double s);
    };

    Vec2 operator+(Vec2 const &u, Vec2 const &v);

    Vec2 operator-(Vec2 const &u, Vec2 const &v);

    Vec2 operator*(Vec2 const &v, double s);

    Vec2 operator/(Vec2 const &v, double s);

    Vec2 operator*(double s, Vec2 const &v);

    //write your Vec2 DTO definition and free function declarations for A2.2 - A2.4 here (within the buw namespaces}
}

#endif //BUW_VEC2_HPP
