#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

namespace raytracer
{
class tuple {
public:
    tuple(double x, double y, double z, double w);
    double x() const;
    double y() const;
    double z() const;
    double w() const;
private:
    double _x;
    double _y;
    double _z;
    double _w;
};
}

#endif
