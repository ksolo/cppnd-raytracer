#include <iostream>
#include <string>
#include "drawing/ppm_writer.h"

namespace raytracer
{
    ppm_writer::ppm_writer(std::string &output, std::unique_ptr<raytracer::drawable> &&canvas)
    {
       _canvas = std::move(canvas);
       _outfile = std::ofstream(output);
    }

    ppm_writer::~ppm_writer()
    {
        _outfile.close();
    }

    void ppm_writer::generate_image()
    {
        _outfile << "P3\n";
        _outfile << _canvas->width() << " " << _canvas->height() << "\n";
        _outfile << "255\n";

        int pixel_count = 0;
        const auto& pixels = _canvas->pixels();

        for (auto color : pixels)
        {
            write_pixel(color);
            _outfile << (++pixel_count % 5 == 0 ? '\n' : ' ');
        }
        _outfile << '\n';
        _outfile.flush();
    }

    void ppm_writer::write_pixel(raytracer::color c) {
        _outfile
            << mapped_color_value(c.red())
            << " " << mapped_color_value(c.green())
            << " " << mapped_color_value(c.blue());
    }

    int ppm_writer::mapped_color_value(double color_component)
    {
        static const int max_value = 255;
        if (color_component >= 1.0) { return max_value; }
        if (color_component <= 0.0) { return 0; }
        return max_value * color_component;
    }
}
