#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

namespace raytracer
{
class tuple {
    static constexpr double epsilon = 0.0001;
    double _x;
    double _y;
    double _z;
    double _w;

    bool epsilon_compare(double a, double b);

public:
    tuple(double x, double y, double z, double w);
    static tuple point(double x, double y, double z);
    static tuple vector(double x, double y, double z);
    double x() const;
    double y() const;
    double z() const;
    double w() const;

    bool is_point();
    bool is_vector();

    bool operator==(tuple &other);
    tuple operator+(tuple &other);
};
}

#endif
