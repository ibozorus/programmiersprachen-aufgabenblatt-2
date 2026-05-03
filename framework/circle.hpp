#ifndef BUW_CIRCLE_HPP
#define BUW_CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

namespace buw {
    class Circle {
    private:
        Vec2 center_;
        float radius_;
        Color color_;

    public:
        Circle(Vec2 const &center, float radius, Color const &color);
        float circumference() const;
        void draw(Window const& window) const;
        void draw(Window const& window, double thickness) const;
    };
}

#endif //BUW_CIRCLE_HPP
