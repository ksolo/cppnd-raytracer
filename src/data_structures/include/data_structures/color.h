#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

namespace raytracer
{
class color {
    // private members
    double _red;
    double _green;
    double _blue;
public:
    // constructor
    color(double red, double green, double blue);

    // getters
    double red() const;
    double green() const;
    double blue() const;
};
}

#endif //RAYTRACER_COLOR_H
