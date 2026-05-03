#include "rectangle.hpp"

namespace buw {
    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
            min_{min}
          , max_{max}
          , color_{color} {
    }

    float Rectangle::circumference() const {
        float width  = max_.x - min_.x;
        float height = max_.y - min_.y;
        return 2.0f * (width + height);
    }
}
