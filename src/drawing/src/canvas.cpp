#include "drawing/canvas.h"

namespace raytracer
{
    canvas::canvas(int width, int height) :
        _width(width),
        _height(height)
        {
            for(size_t i=0; i < width*height; i++)
            {
                _pixels.push_back(std::make_unique<raytracer::color>(0,0,0));
            }
        };

    int canvas::width() const { return _width; }
    int canvas::height() const { return _height; }

    std::vector<std::unique_ptr<raytracer::color>> canvas::pixels() const
    {
        return _pixels;
    }
}
