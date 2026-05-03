#include "circle.hpp"

#include <numbers>

namespace buw {
    Circle::Circle(Vec2 const& center, float radius, Color const& color):
            center_{center}
          , radius_{radius}
          , color_{color} {
    }
    /*
     *
     *
     */
    float Circle::circumference() const {
        return 2.0f * std::numbers::pi * radius_;
    }
}
