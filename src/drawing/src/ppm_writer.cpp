#include "drawing/ppm_writer.h"

namespace raytracer
{
    ppm_writer::ppm_writer(std::string &output, std::unique_ptr<raytracer::drawable> &&canvas)
    {
       _canvas = std::move(canvas);
       _outfile = std::ofstream(output);
    }
}
