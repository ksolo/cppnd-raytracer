#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

namespace raytracer
{
class color {
    static constexpr double epsilon = 0.0001;
    // private members
    double _red;
    double _green;
    double _blue;

    // private methods
    bool epsilon_compare(double a, double b);
public:
    // constructor
    color(double red, double green, double blue);

    // getters
    double red() const;
    double green() const;
    double blue() const;

    // operators
    color operator+(color &rhs);
    bool operator==(color &rhs);
};
}

#endif //RAYTRACER_COLOR_H
