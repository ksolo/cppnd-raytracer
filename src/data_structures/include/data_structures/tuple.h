#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

namespace raytracer
{
class tuple {
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
private:
    double _x;
    double _y;
    double _z;
    double _w;
};
}

#endif
