#include "drawing/canvas.h"

namespace raytracer
{
    canvas::canvas(int width, int height) : _width(width), _height(height){};

    int canvas::width() const { return _width; }
    int canvas::height() const { return _height; }
}