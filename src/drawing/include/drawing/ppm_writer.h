#ifndef RAYTRACER_PPM_WRITER_H
#define RAYTRACER_PPM_WRITER_H

#include <fstream>
#include <memory>
#include "drawable.h"

namespace raytracer
{
class ppm_writer
{
    std::unique_ptr<raytracer::drawable> _canvas;
    std::ofstream _outfile;

public:
    ppm_writer(std::string &output, std::unique_ptr<raytracer::drawable>&& canvas);
    ~ppm_writer();

    void generate_image();
};
}

#endif //RAYTRACER_PPM_WRITER_H
