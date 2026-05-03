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

    void Rectangle::draw(Window const& window) const {
        draw(window, 1.0);
    }

    void Rectangle::draw(Window const& window, double thickness) const {

        window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
        window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
        window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
        window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    }

    bool Rectangle::is_inside(Vec2 const& point) const {
        return point.x >= min_.x && point.x <= max_.x
            && point.y >= min_.y && point.y <= max_.y;
    }
}
