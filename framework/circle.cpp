#include "circle.hpp"

namespace buw {
    Circle::Circle(Vec2 const& center, float radius, Color const& color):
            center_{center}
          , radius_{radius}
          , color_{color} {
    }
}
