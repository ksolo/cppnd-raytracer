#include "data_structures/tuple.h"

namespace raytracer
{
   tuple::tuple(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) {}

   tuple tuple::point(double x, double y, double z) { return tuple(x, y, z, 1.0); }
   tuple tuple::vector(double x, double y, double z) { return tuple(x, y, z, 0.0); }

   double tuple::x() const { return _x; }
   double tuple::y() const { return _y; }
   double tuple::z() const { return _z; }
   double tuple::w() const { return _w; }

   bool tuple::operator==(tuple &other)
   {
       return (
            x() == other.x() &&
            y() == other.y() &&
            z() == other.z() &&
            w() == other.w()
       );
   }

   bool tuple::is_point() { return w() == 1.0; }
   bool tuple::is_vector() { return w() == 0.0; }
}
