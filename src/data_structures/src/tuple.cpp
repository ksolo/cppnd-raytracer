#include "data_structures/tuple.h"
#include <cmath>

namespace raytracer {
    using std::pow;
    using std::sqrt;

    tuple::tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) {}

    tuple tuple::point(double x, double y, double z) { return tuple(x, y, z, 1.0); }

    tuple tuple::vector(double x, double y, double z) { return tuple(x, y, z, 0.0); }

    double tuple::x() const { return _x; }

    double tuple::y() const { return _y; }

    double tuple::z() const { return _z; }

    double tuple::w() const { return _w; }

    bool tuple::epsilon_compare(double a, double b) {
        return abs(a - b) <= epsilon;
    }

    bool tuple::operator==(tuple &other) {
        return (
                epsilon_compare(x(), other.x()) &&
                epsilon_compare(y(), other.y()) &&
                epsilon_compare(z(), other.z()) &&
                epsilon_compare(w(), other.w())
        );
    }

    tuple tuple::operator+(tuple &other) {
        return tuple(x() + other.x(), y() + other.y(), z() + other.z(), w() + other.w());
    }

    tuple tuple::operator-(tuple &other) {
        return tuple(x() - other.x(), y() - other.y(), z() - other.z(), w() - other.w());
    }

    tuple tuple::operator*(double scalar) {
        return tuple(x() * scalar, y() * scalar, z() * scalar, w() * scalar);
    }

    tuple tuple::operator/(double scalar) {
        return tuple(x() / scalar, y() / scalar, z() / scalar, w() / scalar);
    }

    tuple tuple::operator-() {
        return tuple(-x(), -y(), -z(), -w());
    }

    bool tuple::is_point() { return w() == 1.0; }

    bool tuple::is_vector() { return w() == 0.0; }

    double tuple::magnitude() {
        return sqrt(pow(x(), 2) + pow(y(), 2) + pow(z(), 2) + pow(w(), 2));
    }

    tuple tuple::normalize() {
        return raytracer::tuple(
                x() / magnitude(),
                y() / magnitude(),
                z() / magnitude(),
                w() / magnitude());
    }
}