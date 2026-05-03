#include <vec2.hpp> //access to our own buw::Vec2 datatype
#include <window.hpp> //access to our own buw::Window datatype

#include <GLFW/glfw3.h> //access to GLFW key and mouse constants which we did not wrap further 

#include <cmath> //access to std::sin and std::cos
#include <vector>

#include "circle.hpp"
#include "rectangle.hpp"

int main(int argc, char *argv[]) {
    buw::Window win{std::make_pair(800, 800)};
    buw::Circle circle{
        buw::Vec2{400.0f, 400.0f},
        300.0f,
        buw::Color{}
    };
    double const center_x = 400.0;
    double const center_y = 400.0;
    double const radius  = 300.0;
    //this is basically a main/draw-loop
    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }
        double t = win.get_time();

        double seconds = t;
        double minutes = t / 60.0;
        double hours = t / 3600.0;
        //berechne winkel in radiant
        double hours_angle = (2 * std::numbers::pi * hours) / 12.0;
        double minutes_angle = (2 * std::numbers::pi * minutes) / 60.0;
        double seconds_angle = (2 * std::numbers::pi * seconds) / 60.0;

        circle.draw(win, 1.0);
        //Stunden
        win.draw_line(center_x, center_y,
                          center_x + (radius * 0.5) * std::sin(hours_angle),
                          center_y - (radius * 0.5) * std::cos(hours_angle),
                          0.0, 0.0, 0.0, 5.0);
        //Minuten
        win.draw_line(center_x, center_y,
                 center_x + (radius * 0.75) * std::sin(minutes_angle),
                 center_y - (radius * 0.75) * std::cos(minutes_angle),
                 0.0, 0.0, 0.0, 2.5);
        //Sekunden
        win.draw_line(center_x, center_y,
                 center_x + (radius * 0.9) * std::sin(seconds_angle),
                 center_y - (radius * 0.9) * std::cos(seconds_angle),
                 1.0, 0.0, 0.0, 1.0);
        win.update();
    }

    return 0;
}
