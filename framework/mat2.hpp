#ifndef BUW_MAT2_HPP
#define BUW_MAT2_HPP

#include "vec2.hpp" //access to your own datatype buw::Vec2
#include <array> //access to std::array<T, SIZE>

namespace buw {
    struct Mat2 {
        // matrix layout:
        // e_00 e_10
        // e_01 e_11

        double e_00 = 1.0;
        double e_10 = 0.0;
        double e_01 = 0.0;
        double e_11 = 1.0;

        Mat2 &operator*=(Mat2 const &rightMatrix);
    };

    Mat2 operator*(Mat2 const &m1, Mat2 const &m2);

    //write your Mat2 DTO definition and free function declarations for A2.5 and A2.6 here (within the buw namespaces}
}

#endif //BUW_MAT2_HPP
