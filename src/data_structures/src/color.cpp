#include "data_structures/color.h"
#include <cmath>

namespace raytracer
{
    color::color(double red, double green, double blue): _red(red), _green(green), _blue(blue) {}

    double color::red() const { return _red; }
    double color::green() const { return _green; }
    double color::blue() const { return _blue; }

    color color::operator+(color &rhs) {
        return color(red() + rhs.red(), green() + rhs.green(), blue() + rhs.blue());
    }

    bool color::operator==(color &rhs)
    {
        return (
                epsilon_compare(red(), rhs.red()) &&
                epsilon_compare(green(), rhs.green()) &&
                epsilon_compare(blue(), rhs.blue()));
    }

    bool color::epsilon_compare(double a, double b)
    {
        return std::abs(a - b) < color::epsilon;
    }
}