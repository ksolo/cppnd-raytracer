#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <memory>

#include "data_structures/color.h"

namespace raytracer
{
    class canvas
    {
        const int _width;
        const int _height;
        std::vector<std::shared_ptr<raytracer::color>> _pixels;
    public:
        canvas(int width, int height);

        int width() const;
        int height() const;
        std::vector<std::shared_ptr<raytracer::color>> pixels() const;
    };
}

#endif