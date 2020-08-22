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
        _outfile << "P3" << std::endl;
        _outfile << _canvas->width() << " " << _canvas->height() << std::endl;
        _outfile << "255" << std::endl;

        int pixel_count = 0;
        for (auto color : _canvas->pixels())
        {
            _outfile << formatted_pixel(color.get());
            if (++pixel_count % 5 == 0)
            {
                _outfile << std::endl;
                continue;
            }
            if (color == *_canvas->pixels().end())
            {
                _outfile << std::endl;
                return;
            }
            _outfile << " ";
        }
    }

    std::string ppm_writer::formatted_pixel(raytracer::color *c) {
        std::string result(std::to_string(mapped_color_value(c->red())));
        result.append(" ").append(std::to_string(mapped_color_value(c->green())));
        result.append(" ").append(std::to_string(mapped_color_value(c->blue())));
        return result;
    }

    int ppm_writer::mapped_color_value(double color_component)
    {
        static const int max_value = 255;
        if (color_component >= 1.0) { return max_value; }
        if (color_component <= 0.0) { return 0; }
        return max_value * color_component;
    }
}
