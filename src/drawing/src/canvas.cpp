#include "drawing/canvas.h"

namespace raytracer
{
    canvas::canvas(int width, int height) : _width(width), _height(height){};

    int canvas::width() const { return _width; }
    int canvas::height() const { return _height; }

    std::vector<std::shared_ptr<raytracer::color>> canvas::pixels() const
    {
        return _pixels;
    }
}
