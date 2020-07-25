#include "data_structures/tuple.h"

namespace raytracer
{
   tuple::tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) {}
   double tuple::x() const { return _x; }
   double tuple::y() const { return _y; }
   double tuple::z() const { return _z; }
   double tuple::w() const { return _w; }
}
