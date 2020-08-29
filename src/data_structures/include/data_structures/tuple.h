#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

namespace raytracer {
class tuple {
    static constexpr double epsilon = 0.0001;
    double _x;
    double _y;
    double _z;
    double _w;

    bool epsilon_compare(double a, double b);

public:
    // constructor
    tuple(double x, double y, double z, double w);

    // factory methods
    static tuple point(double x, double y, double z);
    static tuple vector(double x, double y, double z);

    // getters
    double x() const;
    double y() const;
    double z() const;
    double w() const;

    // operators
    bool operator==(tuple &other);
    tuple operator+(tuple &other);
    tuple operator-(tuple &other);
    tuple operator*(double scalar);
    tuple operator/(double scalar);
    tuple operator-();

    // methods
    bool is_point();
    bool is_vector();

    double magnitude();
    double dot(tuple &other);

    tuple normalize();
    tuple cross(tuple &other);
};
}

#endif
