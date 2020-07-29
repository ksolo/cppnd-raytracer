#include "data_structures/color.h"

namespace raytracer
{
    color::color(double red, double green, double blue): _red(red), _green(green), _blue(blue) {}

    double color::red() const { return _red; }
    double color::green() const { return _green; }
    double color::blue() const { return _blue; }
}