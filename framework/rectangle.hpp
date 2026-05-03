#ifndef BUW_RECTANGLE_HPP
#define BUW_RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

namespace buw {
    class Rectangle {
    private:
        Vec2 min_; // linke obere Ecke
        Vec2 max_; // rechte untere Ecke
        Color color_;

    public:
        Rectangle(Vec2 const &min, Vec2 const &max, Color const &color);

        float circumference() const;

        void draw(Window const& window) const;
    };
}

#endif //BUW_RECTANGLE_HPP
