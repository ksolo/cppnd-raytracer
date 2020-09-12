#include <iostream>
#include "drawing/canvas.h"

namespace raytracer
{
    canvas::canvas(int width, int height) :
        _width(width),
        _height(height)
        {
            for(size_t i=0; i < width*height; i++)
            {
                _pixels.push_back(raytracer::color(0,0,0));
            }
        };

    int canvas::width() const { return _width; }
    int canvas::height() const { return _height; }

    std::vector<raytracer::color> canvas::pixels() const
    {
        return _pixels;
    }

    void canvas::write_pixel(int x, int y, raytracer::color c)
    {
        _pixels[int_for_coords(x, y)] = c;
    }

    raytracer::color canvas::pixel_at(int x, int y)
    {
        return _pixels[int_for_coords(x, y)];
    }

    int canvas::int_for_coords(int x, int y)
    {
        return (width() * y) + x;
    }
}
