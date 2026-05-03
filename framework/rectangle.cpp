#include "rectangle.hpp"

namespace buw {
    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
            min_{min}
          , max_{max}
          , color_{color} {
    }
}
