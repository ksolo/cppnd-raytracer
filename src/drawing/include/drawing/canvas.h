#ifndef CANVAS_H
#define CANVAS_H

namespace raytracer
{
    class canvas
    {
        const int _width;
        const int _height;
    public:
        canvas(int width, int height);

        int width() const;
        int height() const;
    };
}

#endif