#include "circle.hpp"

#include <numbers>
#include <cmath>

namespace buw {
    Circle::Circle(Vec2 const& center, float radius, Color const& color):
            center_{center}
          , radius_{radius}
          , color_{color} {
    }
    float Circle::circumference() const {
        return 2.0f * std::numbers::pi * radius_;
    }

    void Circle::draw(Window const& window) const {
        int const segments = 64;
        for (int i = 0; i < segments; ++i) {
            double angle1 = 2.0 * std::numbers::pi * i       / segments;
            double angle2 = 2.0 * std::numbers::pi * (i + 1) / segments;

            double x1 = center_.x + radius_ * std::cos(angle1);
            double y1 = center_.y + radius_ * std::sin(angle1);
            double x2 = center_.x + radius_ * std::cos(angle2);
            double y2 = center_.y + radius_ * std::sin(angle2);

            window.draw_line(x1, y1, x2, y2, color_.r, color_.g, color_.b);
        }
    }
}
