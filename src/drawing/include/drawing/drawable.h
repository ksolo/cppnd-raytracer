#ifndef RAYTRACER_DRAWABLE_H
#define RAYTRACER_DRAWABLE_H

#include <vector>
#include <data_structures/color.h>

namespace raytracer
{
class drawable
{
public:
    virtual int width() const = 0;
    virtual int height() const = 0;
    virtual std::vector<raytracer::color&> pixels() const = 0;
};
}

#endif //RAYTRACER_DRAWABLE_H
