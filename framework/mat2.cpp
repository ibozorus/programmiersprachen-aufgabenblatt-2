#include "mat2.hpp"

namespace buw {
    Mat2 &Mat2::operator*=(Mat2 const &rightMatrix) {
        Mat2 leftMatrix{*this};
        e_00 = leftMatrix.e_00 * rightMatrix.e_00 + leftMatrix.e_10 * rightMatrix.e_01;
        e_10 = leftMatrix.e_00 * rightMatrix.e_10 + leftMatrix.e_10 * rightMatrix.e_11;
        e_01 = leftMatrix.e_01 * rightMatrix.e_00 + leftMatrix.e_11 * rightMatrix.e_01;
        e_11 = leftMatrix.e_01 * rightMatrix.e_10 + leftMatrix.e_11 * rightMatrix.e_11;
        return *this;
    }

    Mat2 operator*(Mat2 const &m1, Mat2 const &m2) {
        Mat2 m3{m1};
        return m3 *= m2;
    }

    //write your member function and free function definitions for A2.5 and A2.6 here (within the buw namespace}
}
